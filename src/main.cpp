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
const string OP_HELP             = "-h";

bool isOpCode(char *text)
{
    return text[0] == '-';
}

void print(string text)
{
    cout << text << endl;
}

void readFile(string file_path)
{
   string   line;
   ifstream file(file_path);
   if(file.is_open())
   {
       while (getline(file, line))
       {
           cout << line << '\n';
       }
       file.close();
   }
   else
   {
       cout << "\nUnable to open file: " << file_path << "\n\n"; 
   }
}

void writeToFile(string file_path, string content)
{
    ofstream file;
    file.open(file_path, ios_base::app);
    file << content + '\n';
    file.close();
}

void showHelpMenu()
{
    print("");
    print("todo -a [TODO CONTENT] -t [DUE DATE] ... add todo");
    print("todo -l                              ... list todos");
    print("todo -h                              ... help menu");
    print("");
}

bool hasKey(map<string, string> argm, string key)
{
    return (argm.count(key) == 1);
}

int main(int argc, char *argv[])
{
    map<string, string> argm;
    string              value;
    string              due_date; //yyyymmdd

    for(unsigned int i = 0; i < argc; i = i + 1 )
    {
        if(isOpCode(argv[i]))
        {
            char *nextArg = argv[i + 1];

            if(i < argc - 1) 
            {
                value = isOpCode(argv[i + 1]) ? "" : argv[i + 1];
            }
            argm[argv[i]] = value;
        }
    }

    if(argm[OP_DUE_DATE] != "")
    {
       if(!regex_match(argm[OP_DUE_DATE], regex("^([\\d]{8})$")))
       {
           print("\ndue date format error: \n\n-t [yyyymmdd]\n");
           return 1;
       }
       due_date = argm[OP_DUE_DATE];
    }

    //enlist TODO tags
    if(hasKey(argm, OP_LIST))
    {
        readFile(TODOS_DSL_FILE_PATH);
    }
    else if(argm[OP_ADD] != "")
    {
        string content = argm[OP_ADD] + '|' + argm[OP_DUE_DATE];
        writeToFile(TODOS_DSL_FILE_PATH, content);
    }
    else if(hasKey(argm, OP_HELP))
    {
        showHelpMenu();
    }
    else
    {
        showHelpMenu();
    }

    return 0;
}
