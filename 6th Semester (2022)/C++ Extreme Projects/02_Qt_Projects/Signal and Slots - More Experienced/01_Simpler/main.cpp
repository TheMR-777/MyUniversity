#include "MyLibrary.h"

int main()
{
    // Initialization
    // --------------

    The_Captain captain;

    Client my_agents[] = { "MR_777", "H4ck3R", "Highway" };

    // Connections
    // -----------

    for (const auto& c : my_agents)
    {
        QObject::connect(&captain, &decltype(captain)::broadcast, &c, &std::remove_cvref_t<decltype(c)>::respond_with);
    }

    // Calling Agents
    // --------------

    captain.broadcast("Come on!");
}
