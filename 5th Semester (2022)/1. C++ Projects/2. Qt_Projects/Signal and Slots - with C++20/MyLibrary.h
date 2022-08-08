#include <QObject>
#include <QDebug>

#include <type_traits>


template <class T>
concept acceptable = requires { QStringView(T{}); };

class Sender: public QObject
{
    Q_OBJECT;
    const QStringView m_name = L"N/A";

public:

    constexpr explicit Sender(const acceptable auto& x) : m_name(x) {}

    void broadcast_message(const acceptable auto& msg)
    {
        qInfo() << "Broadcasting message:" << msg << "by, [ " << m_name << " ]" << '\n';
        emit report_me();
    }

signals:

    void report_me();
};

class Reciever: public QObject
{
    Q_OBJECT;
    const QStringView m_name = L"N/A";

public:

    constexpr explicit Reciever(const acceptable auto& x) : m_name(x) {}

public slots:

    void signal_respond()
    {
        qInfo() << "It's [ " << m_name << " ] - Responding by your Mayday Call";
    }
};
