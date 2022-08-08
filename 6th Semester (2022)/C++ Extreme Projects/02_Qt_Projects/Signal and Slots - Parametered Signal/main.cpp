#include "MyLibrary.h"

int main()
{
    // Initialization
    // --------------

    Captain Cap;

    Client my_agents[]
    {
        Client("SpyD3R"),
        Client("H4ck3R"),
        Client("Highway"),
    };

    // Connections
    // -----------

    for (const auto& C : my_agents)
    {
        QObject::connect(&Cap, &decltype(Cap)::the_message, &C, &std::remove_cvref_t<decltype(C)>::respond_with);
    }

    // Calling Agents
    // --------------

    Cap.call_with("Come on!");
}
