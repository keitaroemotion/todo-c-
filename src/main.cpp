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

int main(int argc, char *argv[])
{
    for(unsigned int x = 0; x < argc; x = x + 1 )
    {
        cout << argv[x] << endl;
    }

    return 0;
}
