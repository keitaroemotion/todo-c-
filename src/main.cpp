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

char* appendCharToCharArray(char* text, char particle)
{
    size_t len     = strlen(text);
    char* newText  = new char[len + 2];
    strcpy(newText, text);
    newText[len]   = particle;
    newText[len+1] = '\0'; 
    return newText;
}

bool startsWith(char *text)
{
    char* option      = new char[50];
    bool  option_flag = false;

    int i =0;
    while (text[i] != '\0'){
        if(text[i-1] == '-' && text[i] == '-'){
            option_flag = true; 
            cout << option_flag << endl;
        }
        else if(option_flag == true && text[i] == ' ')
        {
        }
        else if(option_flag == true && text[i] != ' ')
        {
            const char *_text = &text[i];
            strcpy(option, _text);
        }
        i++;
    }
    return true;
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
