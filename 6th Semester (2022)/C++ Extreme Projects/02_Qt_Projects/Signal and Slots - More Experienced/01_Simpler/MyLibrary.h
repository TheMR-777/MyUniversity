#pragma once
#include <QObject>
#include <QDebug>
#include <fmt/core.h>
using value_type = std::string_view;

template <class T>
concept acceptable = std::convertible_to<T, value_type>;

class The_Captain final : public QObject
{
    Q_OBJECT
    const value_type m_name = "TheMR";

public:
    The_Captain() = default;
    constexpr explicit The_Captain(const acceptable auto& data) : m_name(data) {}

signals:
    void broadcast(value_type) const;
};


class Client final : public QObject
{
    Q_OBJECT;
    const value_type m_name = "N/A";

public:
    Client() = default;
    constexpr Client(const acceptable auto& data) : m_name(data) {}

public slots:
    void respond_with(value_type msg) const
    {
        fmt::print("It's [ {:7} ], I'm on my way, Responding to [ {} ], Out!\n", m_name, msg);
    }
};
