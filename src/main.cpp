#include <fstream>
#include <iostream>
#include <map>
#include <regex>

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
const string OP_LIST             = "-l";
const string OP_ADD              = "-a";
const string OP_DUE_DATE         = "-t";

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
    string              due_date; //yyyymmdd

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

    if(argm[OP_DUE_DATE] != "")
    {
       if(!regex_match(argm[OP_DUE_DATE], regex("^([\\d]+)$")))
       {
           print("\ndue date format error: \n\n-t [yyyymmdd]\n");
           return 1;
       }
       due_date = argm[OP_DUE_DATE];
    }

    //enlist TODO tags
    if(argm[OP_LIST] != "")
    {
        print(argm[OP_LIST]);
    }
    
    //
    // todo -a "content" -to 20191212 
    //
    if(argm[OP_ADD] != "")
    {
        string content = argm[OP_ADD] + '|' + argm[OP_DUE_DATE];
        writeToFile(TODOS_DSL_FILE_PATH, content);
    }

    return 0;
}
