#include<iostream>

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
    while (text[i] != '\0'){
        if(text[i-1] == '-' && text[i] == '-'){
            return true;
        }
        i++;
    }
    return false;
}

int main(int argc, char *argv[])
{
    for(unsigned int i = 0; i < argc; i = i + 1 )
    {
        if(startsWith(argv[i])){
            cout << argv[i] << endl;
        }
    }

    return 0;
}
