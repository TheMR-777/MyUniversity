#include <QObject>
#include <QDebug>

#include <type_traits>
#include <format>
#include <iostream>


template <class T>
concept acceptable = requires { QStringView(T{}); };

class Sender: public QObject
{
    Q_OBJECT;
    const QStringView m_name = L"N/A";

public:

    constexpr explicit Sender(const acceptable auto& x) : m_name(x) {}

    constexpr void broadcast_message(const acceptable auto& msg) const
    {
        qInfo() << "Broadcasting message:" << msg << "by, [ " << m_name << " ]" << '\n';
        emit report_me();
    }

signals:

    void report_me() const;
};

class Reciever: public QObject
{
    Q_OBJECT;
    const QStringView m_name = L"N/A";

public:

    constexpr explicit Reciever(const acceptable auto& x) : m_name(x) {}

public slots:

    void signal_respond() const
    {
        std::format_to(std::ostream_iterator<char>(std::cout), "It's [ {:13} ] - Responding to your Mayday Call\n", m_name.toLatin1().data());
    }
};
