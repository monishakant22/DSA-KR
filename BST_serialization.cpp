#include <iostream>
using namespace std;
struct bstnode
{
    int data;
    bstnode *lc;
    bstnode *rc;
};
typedef bstnode *bstptr;
void insert(bstptr &l, int k)
{
    if (k == 0)
        return;
    if (l == NULL)
    {
        l = new bstnode;
        l->data = k;
        l->rc = NULL;
        l->lc = NULL;
    }
    else
    {
        if (k > l->data)
            insert(l->rc, k);
        else
            insert(l->lc, k);
    }
}
void create(bstptr &l)
{
    int k;
    cin >> k;
    if (k == 0)
        return;
    if (l == NULL)
    {
        l = new bstnode;
        l->data = k;
        l->rc = NULL;
        l->lc = NULL;
    }
    create(l->lc);
    create(l->rc);
}
void preorder(bstptr l)
{
    if (l == NULL)
    {
        cout << 0 << " ";
        return;
    }
    cout << l->data << " ";
    preorder(l->lc);
    preorder(l->rc);
}
void inorder(bstptr l)
{
    if (l == NULL)
        return;
    inorder(l->lc);
    cout << l->data << " ";
    inorder(l->rc);
}
main()
{
    bstptr l = NULL;
    bstptr s = NULL;
    int k;
    while (1)
    {
        cin >> k;
        if (k == -1)
            break;
        insert(l, k);
    }
    preorder(l);
    create(s);
    cout << endl;
    inorder(s);
}
