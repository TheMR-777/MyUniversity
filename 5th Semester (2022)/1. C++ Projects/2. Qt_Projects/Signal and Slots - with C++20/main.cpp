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

    // Developing Connections
    // ----------------------

    for (const auto& x : Vs)
    {
        QObject::connect(&TheMR, &decltype(TheMR)::report_me, &x, &std::remove_all_extents<decltype(Vs)>::type::signal_respond);
    }

    // Broadcasting
    // ------------

    TheMR.broadcast_message<QStringView>(L"Anyone alive?");
}
