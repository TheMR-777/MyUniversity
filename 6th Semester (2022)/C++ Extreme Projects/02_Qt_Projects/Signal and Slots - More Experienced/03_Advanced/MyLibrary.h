#pragma once
#include <QObject>
#include <QDebug>
#include <fmt/color.h>

inline namespace internals
{
    using value_type = std::string_view;

    template <class T>
    concept acceptable = std::convertible_to<T, value_type>;

    struct Persona : QObject
    {
        const value_type m_name = "TheMR";
    protected:
        Persona() = default;
        constexpr Persona(const acceptable auto& data) : m_name(data) {}
    };
}

struct Captain final : Persona
{
    Captain() = default;
    constexpr Captain(const acceptable auto& data) : Persona(data) {}

signals:
    void broadcast(value_type) const;

private:
    Q_OBJECT
};

struct Client final : Persona
{
    Client() = default;
    constexpr Client(const acceptable auto& data) : Persona(data) {}

public slots:
    void notify_with(const value_type msg) const
    {
        constexpr auto c = fg(fmt::color::blanched_almond) | fmt::emphasis::bold;
        print(c, "It's [ {} ], I'm on my way, Responding to [ {} ]\n", m_name, msg);
    }

private:
    Q_OBJECT
};

struct Agents final : Persona
{
    Agents() = default;
    constexpr Agents(const acceptable auto& data) : Persona(data) {}

public slots:
    void call_with(const value_type msg) const
    {
        constexpr auto c = fg(fmt::color::light_sea_green);
        print(c, "This is Federal Agent: [ {} ], responding to your call [ {} ], out!\n", m_name, msg);
    }

private:
    Q_OBJECT
};
