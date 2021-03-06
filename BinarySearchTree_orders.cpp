#include <iostream>
using namespace std;
struct bstnode
{
    int data;
    bstnode *lchild;
    bstnode *rchild;
};
typedef bstnode *bstptr;
void insert(bstptr &t, int k)
{
    if (t == NULL)
    {
        t = new bstnode;
        t->data = k;
        t->rchild = NULL;
        t->lchild = NULL;
    }
    else
    {
        if (k > t->data)
            insert(t->rchild, k);
        else
            insert(t->lchild, k);
    }
}
void preorder(bstptr t)
{
    if (t == NULL)
        return;
    cout << t->data << " ";
    preorder(t->lchild);
    preorder(t->rchild);
}
void inorder(bstptr t)
{
    if (t == NULL)
        return;
    inorder(t->lchild);
    cout << t->data << " ";
    inorder(t->rchild);
}
void postorder(bstptr t)
{
    if (t == NULL)
        return;
    postorder(t->lchild);
    postorder(t->rchild);
    cout << t->data << " ";
}
void max(bstptr t)
{
    int k = t->data;
    while (t->rchild)
        t = t->rchild;
    cout << t->data << endl;
}
void min(bstptr t)
{
    int k = t->data;
    while (t->lchild)
        t = t->lchild;
    cout << t->data << endl;
}
void find(bstptr t, int k)
{
    if (t == NULL)
    {
        cout << "0" << endl;
        return;
    }
    if (k == t->data)
    {
        cout << "1 " << endl;
        return;
    }
    else if (k > t->data)
        find(t->rchild, k);
    else
        find(t->lchild, k);
}
main()
{
    bstptr t;
    int k;
    while (1)
    {
        cin >> k;
        if (k == -1)
            break;
        insert(t, k);
    }
    preorder(t);
    cout << endl;
    inorder(t);
    cout << endl;
    postorder(t);
    cout << endl;
    max(t);
    min(t);
    find(t, 9);
    find(t, 15);
}
