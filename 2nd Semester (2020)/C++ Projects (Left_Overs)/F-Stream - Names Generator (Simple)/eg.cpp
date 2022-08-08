#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Initializing String

        string filename;
    
    // Some Text before Operation

        cout << endl;
        cout << "It's a File Generator with my Logo." << endl;
        cout << "Enter the Filename to generate: ";
        getline(cin, filename);

    // Adding .txt file Extension after name u entered

        filename = filename + ".txt";
    
    // Initializing the Object, from Class of fstream to generate a file

        ofstream LOGO (filename.c_str());

    // Checking if the file is generated

        if (LOGO.is_open())
        {
            cout << "LOGO Generated!" << endl;
            system("timeout 2");
        }
        else
        {
            cout << "LOGO Generation Failed!" << endl;
            system("timeout 2");
        }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // Logo Generation

        LOGO << "EEEEEEEEEEEEEEEEEEEEEElllllll                                                 GGGGGGGGGGGGG                                                               " << endl;
        LOGO << "E::::::::::::::::::::El:::::l                                              GGG::::::::::::G                                                               " << endl;
        LOGO << "E::::::::::::::::::::El:::::l                                            GG:::::::::::::::G                                                               " << endl;
        LOGO << "EE::::::EEEEEEEEE::::El:::::l                                           G:::::GGGGGGGG::::G                                                               " << endl;
        LOGO << "  E:::::E       EEEEEE l::::l     ssssssssss     aaaaaaaaaaaaa         G:::::G       GGGGGGrrrrr   rrrrrrrrr       eeeeeeeeeeee  yyyyyyy           yyyyyyy" << endl;
        LOGO << "  E:::::E              l::::l   ss::::::::::s    a::::::::::::a       G:::::G              r::::rrr:::::::::r    ee::::::::::::ee y:::::y         y:::::y " << endl;
        LOGO << "  E::::::EEEEEEEEEE    l::::l ss:::::::::::::s   aaaaaaaaa:::::a      G:::::G              r:::::::::::::::::r  e::::::eeeee:::::eey:::::y       y:::::y  " << endl;
        LOGO << "  E:::::::::::::::E    l::::l s::::::ssss:::::s           a::::a      G:::::G    GGGGGGGGGGrr::::::rrrrr::::::re::::::e     e:::::e y:::::y     y:::::y   " << endl;
        LOGO << "  E:::::::::::::::E    l::::l  s:::::s  ssssss     aaaaaaa:::::a      G:::::G    G::::::::G r:::::r     r:::::re:::::::eeeee::::::e  y:::::y   y:::::y    " << endl;
        LOGO << "  E::::::EEEEEEEEEE    l::::l    s::::::s        aa::::::::::::a      G:::::G    GGGGG::::G r:::::r     rrrrrrre:::::::::::::::::e    y:::::y y:::::y     " << endl;
        LOGO << "  E:::::E              l::::l       s::::::s    a::::aaaa::::::a      G:::::G        G::::G r:::::r            e::::::eeeeeeeeeee      y:::::y:::::y      " << endl;
        LOGO << "  E:::::E       EEEEEE l::::l ssssss   s:::::s a::::a    a:::::a       G:::::G       G::::G r:::::r            e:::::::e                y:::::::::y       " << endl;
        LOGO << "EE::::::EEEEEEEE:::::El::::::ls:::::ssss::::::sa::::a    a:::::a        G:::::GGGGGGGG::::G r:::::r            e::::::::e                y:::::::y        " << endl;
        LOGO << "E::::::::::::::::::::El::::::ls::::::::::::::s a:::::aaaa::::::a         GG:::::::::::::::G r:::::r             e::::::::eeeeeeee         y:::::y         " << endl;
        LOGO << "E::::::::::::::::::::El::::::l s:::::::::::ss   a::::::::::aa:::a          GGG::::::GGG:::G r:::::r              ee:::::::::::::e        y:::::y          " << endl;
        LOGO << "EEEEEEEEEEEEEEEEEEEEEEllllllll  sssssssssss      aaaaaaaaaa  aaaa             GGGGGG   GGGG rrrrrrr                eeeeeeeeeeeeee       y:::::y           " << endl;
        LOGO << "                                                                                                                                       y:::::y            " << endl;
        LOGO << "                                                                                                                                      y:::::y             " << endl;
        LOGO << "                                                                                                                                     y:::::y              " << endl;
        LOGO << "                                                                                                                                    y:::::y               " << endl;
        LOGO << "                                                                                                                                   yyyyyyy                " << endl;

    // File Completion Code

        LOGO.close();
}