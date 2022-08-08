#include <iostream>


namespace get
{
    void getline1(std::istream& in, std::string& word, char delim = '\n') 
    {
        char ch;
        word = "";
        while (in.get(ch)) {
            word += ch;
            if (ch == delim)
                break;
        }
    }

    void getline2(std::istream& in, std::string& word, char delim ='\n')
    {
        char ch;

        do
        {
            in.get(ch);
            word += ch;
        }
        while(ch != delim);
    }
}

int main()
{
    
}