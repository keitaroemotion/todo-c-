#include<iostream>
#include<map>

using namespace std;

// argv ... array of input argument
//
// --list,   -l ... enlist the todo tasks
// --filter, -f ... filter by query
// --date,   -d ... filter by date 
// --add,    -a ... add    [TODO]
// --rm,     -r ... remove [TODO]
//

bool startsWith(char *text)
{
    int i =0;
    while (text[i] != '\0')
    {
        if(text[i-1] == '-' && text[i] == '-')
        {
            return true;
        }
        i++;
    }
    return false;
}

void print(string text)
{
    cout << text << endl;
}

int main(int argc, char *argv[])
{
    map<string, string> argm;
    string              value;

    for(unsigned int i = 0; i < argc; i = i + 1 )
    {
        if(startsWith(argv[i]))
        {
            print(argv[i]);
            char *nextArg = argv[i + 1];

            if(i < argc - 1) 
            {
                value = startsWith(argv[i + 1]) ? "" : argv[i + 1];
            }
            argm[argv[i]] = value;
        }
    }

    if (argm["--list"] != "")
    {
        print(argm["--list"]);
    }

    return 0;
}
