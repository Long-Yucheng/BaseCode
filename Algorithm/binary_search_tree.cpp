//---------------------------------------------------
//Author : Long Yucheng
//Mail	 : frank.long.yucheng@gmail.com
//---------------------------------------------------

#include <iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* FindMin(BstNode* root)
{
    BstNode* node = root;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

BstNode* FindMax(BstNode* root)
{
    BstNode* node = root;
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool Insert(BstNode** root, int data) {
    if (*root == NULL) {
        *root = GetNewNode(data);
        return true;
    }

    if (data == (*root)->data) {
        return false;
    }

    if (data < (*root)->data) {
        Insert(&(*root)->left, data);
    }
    else {
        Insert(&(*root)->right, data);
    }

    return true;
}


bool Search(BstNode* root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    else if (data < root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

bool Delete(BstNode** root, int data)
{
    if (*root == NULL) return false;
    if (data < (*root)->data) {
        Delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        Delete(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            delete *root;
            *root = NULL;
            return true;
        }
        else if ((*root)->left == NULL) {
            BstNode* temp = *root;
            *root = (*root)->right;
            delete temp;
        }
        else if ((*root)->right == NULL) {
            BstNode* temp = *root;
            *root = (*root)->left;
            delete temp;
        }
        else {
            BstNode* temp = FindMin((*root)->right);
            (*root)->data = temp->data;
            Delete(&(*root)->right, temp->data);
        }
    }
    return true;
}


void Inorder(BstNode* node)
{
  if (node!=NULL)
  {
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
  }
}

void Preorder(BstNode *node)
{
  if (node!=NULL)
  {
    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
  }
}

void Postorder(BstNode *node)
{
  if (node!=NULL)
  {
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
  }
}


int main(int argc, char* argv[])
{
    BstNode* root;
    root = NULL;
    Insert(&root, 15);
    Insert(&root, 10);
    Insert(&root, 20);
    Insert(&root, 25);
    Insert(&root, 8);
    Insert(&root, 12);

    Inorder(root);

    Delete(&root, 10);
    cout << "\n";
    Inorder(root);


}
