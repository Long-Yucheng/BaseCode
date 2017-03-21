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


class Queue
{
public:
    Queue():head(NULL),tail(NULL) {}
    void initQueue(int data);
    void enQueue(int data);
    int deQueue();
    bool deletefromQueue(int data);
    bool isEmpty();
    void makeEmpty();
    void printQueue();
private:
    Queue(const Queue&);
    Queue& operator=(const Queue&);

private:
    PNODE head;
    PNODE tail;
};

void Queue::initQueue(int data)
{
    head = new NODE(data);
    tail = head;
}

void Queue::enQueue(int data)
{
    if (head && tail) {
        PNODE temp = new NODE(data);
        tail->next = temp;
        tail = temp;
    }
}

int Queue::deQueue()
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


bool Queue::isEmpty()
{
    if (head && tail) {
        return false;
    } else {
        return true;
    }
}

void Queue::makeEmpty()
{
    while (head && tail) {
        deQueue();
    }
}

bool Queue::deletefromQueue(int data)
{
    if (head && tail) {
        PNODE temp = head;
        PNODE pre  = head;
        while (temp) {
            if (temp->x != data) {
                pre  = temp;
                temp = temp->next;
            } else {
                pre->next  = temp->next;
                temp->next = NULL;
                delete temp;
                return true;
            }
        }
    }
    return false;
}

void Queue::printQueue()
{
    PNODE temp = head;
    while (temp) {
        cout << temp->x << endl;
        temp = temp->next;
    }
}


int main(int argc, char *argv[])
{
    Queue s;
    s.initQueue(99);
    s.enQueue(1);
    s.enQueue(2);
    s.enQueue(3);
    s.enQueue(4);
    s.enQueue(5);
    s.enQueue(6);
    s.enQueue(7);
    s.printQueue();
    cout << "================" << endl;
    s.deQueue();
    s.deQueue();
    s.deletefromQueue(4);
    s.printQueue();
    return 0;
}

