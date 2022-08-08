#include <QObject>
#include <QDebug>

#include <string_view>
#include <fmt/core.h>

template <class T>
concept acceptable = std::convertible_to<T, std::string_view>;

class Captain : public QObject
{
    Q_OBJECT;
    const std::string_view m_name = "TheMR";

public:

    Captain() = default;
    constexpr explicit Captain(const acceptable auto& data) : m_name(data) {}

    constexpr void call_with(const acceptable auto& msg) const
    {
        emit the_message(msg);
    }

signals:

    void the_message(std::string_view) const;
};


class Client : public QObject
{
    Q_OBJECT;
    const std::string_view m_name = "N/A";

public:

    Client() = default;
    constexpr explicit Client(const acceptable auto& data) : m_name(data) {}

public slots:

    void respond_with(std::string_view msg) const
    {
        fmt::print("It's [ {:7} ], I'm on my way, Respoinding to [ {:^10} ], Out!\n", m_name, msg);
    }
};
