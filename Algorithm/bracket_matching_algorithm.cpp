//---------------------------------------------------
//Author : Long Yucheng
//Mail	 : frank.long.yucheng@gmail.com
//---------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

bool bracket_matching(char* str)
{
    stack<char> s;
    int size  = strlen(str);
    for (int i=0; i< size; ++i) {
        if ( str[i] == '{' || str[i] == '[' || str[i] == '(') {
            s.push(str[i]);
        } else {
            switch (s.top()) {
            case '{':
                if (str[i] == '}') {
                    s.pop();
                    continue;
                }
                break;
            case '[':
                if (str[i] == ']') {
                    s.pop();
                    continue;
                }
                break;
            case '(':
                if (str[i] == ')') {
                    s.pop();
                    continue;
                }
                break;
            default:
                break;
            }
            break;
        }
    }

    if (s.empty()) {
        return true;
    } else {
        return false;
    }

}

int main(int argc, char *argv[])
{
    char* str = "{[()()]}";
    if (bracket_matching(str)) {
        cout << "OK match" << endl;
    } else {
        cout << "not match" << endl;
    }

    str = "{[(])(])]}";
    if (bracket_matching(str)) {
        cout << "OK match" << endl;
    } else {
        cout << "not match" << endl;
    }
    return 0;
}

