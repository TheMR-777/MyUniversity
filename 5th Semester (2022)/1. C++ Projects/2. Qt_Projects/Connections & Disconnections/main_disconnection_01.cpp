#include "MyLibrary.h"
#include <QCoreApplication>

int main()
{
    // The Main Variant
    // ----------------

    auto TheMR = Sender{ L"TheMR" };

    // My Variants
    // -----------

    Reciever Vs[]
    {
        Reciever(L"H4ck3R_777"),
        Reciever(L"CaptainMR"),
        Reciever(L"MR Ghazi"),
        Reciever(L"MR Noir"),
    };

    // Multiversal Linkage
    // -------------------

    QMetaObject::Connection connections[std::size(Vs)];

    // Developing Connections
    // ----------------------

    for (auto [ x,y ] = std::pair{ std::begin(Vs), std::begin(connections) }; x < std::end(Vs) || y < std::end(connections); ++x, ++y)
    {
        *y = QObject::connect(&TheMR, &decltype(TheMR)::report_me, x, &std::remove_all_extents<decltype(Vs)>::type::signal_respond);
    }

    // Broadcasting
    // ------------

    TheMR.broadcast_message<QStringView>(L"Anyone alive?");

    // Breaking Linkage
    // ----------------

    std::ranges::for_each(connections, [](const auto x) { QObject::disconnect(x); });

    // Let's Call
    // ----------

    TheMR.broadcast_message<QStringView>(L"Anyone ready to leave?");
}
