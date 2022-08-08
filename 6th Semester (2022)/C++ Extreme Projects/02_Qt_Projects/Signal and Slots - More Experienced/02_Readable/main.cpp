#include "MyLibrary.h"

int main()
{
    The_Captain captain;
    Client my_agents[] = { "MR_777", "H4ck3R", "Highway" };
    
    for (const auto& c : my_agents)
    {
        using client_t = std::remove_cvref_t<decltype(c)>;
        QObject::connect(&captain, &decltype(captain)::broadcast, &c, &client_t::respond_with);
    }
    QObject::connect(&captain, &decltype(captain)::broadcast, [](const acceptable auto& msg) { fmt::print("Anonymous Received: {}\n", msg); });
    
    captain.broadcast("Come on!");
}
