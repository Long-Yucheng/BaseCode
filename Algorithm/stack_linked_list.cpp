//---------------------------------------------------
//Author : Long Yucheng
//Mail	 : frank.long.yucheng@gmail.com
//---------------------------------------------------

#include <iostream>
#include <stdlib.h>

using namespace std;

struct _node {
    int x;
    _node *next;
    _node():x(0),next(0) {}
    _node(int data):x(data),next(0) {}
};

typedef struct _node  NODE;
typedef struct _node* PNODE;


class Stack
{
public:
    Stack():head(NULL),tail(NULL) {}
    void initStack();
    void push(int data);
    int  pop();
    int  peek();
    bool isEmpty();
private:
    Stack(const Stack&);
    Stack& operator=(const Stack&);

private:
    PNODE head;
    PNODE tail;
};

void Stack::initStack()
{
    head = new NODE;
    tail = head;
}

void Stack::push(int data)
{
    if (head && tail) {
        PNODE temp = new NODE(data);
        temp->next = head;
        head = temp;
    }
}

int Stack::pop()
{
    if (head && tail) {
        if (head == tail) {
            int data = tail->x;
            head = NULL;
            delete tail;
            tail = NULL;
            return data;
        }

        PNODE p = head;
        head    = head->next;
        p->next = NULL;
        int data = p->x;
        delete p;
        return data;
    }
}


int Stack::peek()
{
    if (head && tail) {
        return head->x;
    }
}

bool Stack::isEmpty()
{
    if (head && tail) {
        return false;
    } else {
        return true;
    }
}


int main(int argc, char *argv[])
{
    Stack s;
    cout << s.isEmpty() << endl;
    s.initStack();
    cout << s.isEmpty() << endl;
    s.push(18);
    s.push(666);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    return 0;
}

