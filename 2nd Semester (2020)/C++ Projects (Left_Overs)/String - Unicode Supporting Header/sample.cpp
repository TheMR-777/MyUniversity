#include <iostream>
#include "emoji.h"

int main() 
{
    std::cout << emojicpp::emojize("Emoji :smile: for c++ :+1:") << std::endl;
    system("pause");
    return 0;
}