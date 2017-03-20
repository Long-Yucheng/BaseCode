//---------------------------------------------------
//Author : Long Yucheng
//Mail	 : frank.long.yucheng@gmail.com
//---------------------------------------------------
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 1000

class Stack
{
public:
    Stack() {
        top = -1;
    }
    bool push(int x);
    int  pop();
    bool isEmpty();
private:
    int top;
    int data[MAX];
};

bool Stack::push(int x)
{
    if (top >= MAX) {
        cout << "Stack Oerflow" << endl;
        return false;
    } else {
        data[++top] = x;
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        int x = data[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " Popped from stack\n";

    return 0;
}
