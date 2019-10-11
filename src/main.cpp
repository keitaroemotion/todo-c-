#include<fstream>
#include<iostream>
#include<map>

using namespace std;

// argv ... array of input argument
//
// -l ... enlist the todo tasks
// -f ... filter by query
// -d ... filter by date 
// -a ... add    [TODO]
// -r ... remove [TODO]
//
//
const string TODOS_DSL_FILE_PATH = "/usr/local/etc/todo/dsl.txt";
const string OP_LIST             = "-l"
const string OP_ADD              = "-a"

bool startsWith(char *text)
{
    return text[0] == '-';
}

void print(string text)
{
    cout << text << endl;
}

void writeToFile(string file_name, string content)
{
    ofstream file;
    file.open(file_name, ios_base::app);
    file << content + '\n';
    file.close();
}

int main(int argc, char *argv[])
{
    map<string, string> argm;
    string              value;

    for(unsigned int i = 0; i < argc; i = i + 1 )
    {
        if(startsWith(argv[i]))
        {
            char *nextArg = argv[i + 1];

            if(i < argc - 1) 
            {
                value = startsWith(argv[i + 1]) ? "" : argv[i + 1];
            }
            argm[argv[i]] = value;
        }
    }

    //enlist TODO tags
    if(argm[OP_LIST] != "")
    {
        print(argm[OP_LIST]);
    }

    if(argm[OP_ADD] != "")
    {
        writeToFile(TODOS_DSL_FILE_PATH, argm[OP_ADD]);
        print(argm[OP_ADD]);
    }

    return 0;
}
