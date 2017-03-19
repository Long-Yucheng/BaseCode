//Author : Long Yucheng
//Mail	 : frank.long.yucheng@gmail.com 

#include <iostream>
#include <stdlib.h>

using namespace std;

struct _node {
    int x;
    _node *next;
    _node():x(0),next(0) {}
    _node(int data):x(data),next(0) {}
};

typedef struct _node NODE;
typedef struct _node* PNODE;

PNODE CreateNode(int data)
{
    PNODE node = new NODE(data);
    return node;
}

void PrintList(PNODE root)
{
    PNODE temp = NULL;
    if (root) {
        cout << root->x << endl;
        temp = root->next;
        while (temp) {
            cout << temp->x << endl;
            if (temp->next) {
                temp = temp->next;
            } else {
                break;
            }
        }
    }
}

bool AddToEnd(PNODE root, PNODE child)
{
    PNODE temp = NULL;
    if (root && child) {
        temp = root->next;
        if (!temp) {
            root->next = child;
            return true;
        }

        while (temp) {
            if (!(temp->next)) {
                temp->next = child;
                return true;
            } else {
                temp = temp->next;
            }
        }

    }

    return false;
}

bool Find(PNODE root, int key)
{
    PNODE temp = root;

    while (temp != NULL && temp->x != key) {
        temp = temp->next;
    }
    return temp;
}

void Delete(PNODE *root, int data)
{
    PNODE pre  = *root;
    PNODE temp = NULL;

    if (pre->x == data) {
        *root = pre->next;
        pre->x = 0;
        pre->next = NULL;
    }

    while (pre->next) {
        if (pre->next->x == data) {
            temp = pre->next->next;
            pre->next->x = 0;
            pre->next->next = NULL;
            pre->next = temp;
            pre = pre->next;
        } else {
            pre = pre->next;
        }
    }
}

int main(int argc, char *argv[])
{
    NODE *root  = CreateNode(18);
    NODE *leaf1 = CreateNode(19);
    NODE *leaf2 = CreateNode(20);
    NODE *leaf3 = CreateNode(21);
    NODE *leaf4 = CreateNode(22);
    NODE *leaf5 = CreateNode(23);
    AddToEnd(root, leaf1);
    AddToEnd(root, leaf2);
    AddToEnd(root, leaf3);
    AddToEnd(root, leaf4);
    AddToEnd(root, leaf5);

    PrintList(root);

    if (Find(root, 19)) {
        cout << "Find it --> " << 19 << endl;
    } else {
        cout << "not find" << endl;
    }

    Delete(&root, 19);
    Delete(&root, 18);
    PrintList(root);

    if (Find(root, 19)) {
        cout << "Find it --> " << 19 << endl;
    } else {
        cout << "not find" << endl;
    }

    return 0;
}

