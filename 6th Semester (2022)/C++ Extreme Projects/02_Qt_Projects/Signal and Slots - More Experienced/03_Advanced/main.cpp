#include "MyLibrary.h"

int main()
{
    Captain captain = "TheMR";
    Client my_clients[] = { "Gray", "Noir", "Hary" };
    Agents my__agents[] = { "MR_777", "H4ck3R", "SpyD3R" };
    
    for (const auto& cl : my_clients)
    {
        using client_t = std::remove_cvref_t<decltype(cl)>;
        QObject::connect(&captain, &decltype(captain)::broadcast, &cl, &client_t::notify_with);
    }

    for (const auto& ag : my__agents)
    {
        using agent_t = std::remove_cvref_t<decltype(ag)>;
        QObject::connect(&captain, &decltype(captain)::broadcast, &ag, &agent_t::call_with);
    }

    QObject::connect(&captain, &decltype(captain)::broadcast, [](const acceptable auto& msg) { fmt::print("Anonymous Received: {}\n", msg); });
    
    captain.broadcast("Come on!");
}
