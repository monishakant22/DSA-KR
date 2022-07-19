//“Ask yourself, ‘How long am I going to work to make my dreams come true?’
// I suggest you answer, ‘As long as it takes.’”    —Jim Rohn
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
void preorder(bstptr l)
{
    if (l == NULL)
        return;
    cout << l->data << " ";
    preorder(l->lc);
    preorder(l->rc);
}
void postorder(bstptr l)
{
    if (l == NULL)
        return;
    postorder(l->lc);
    postorder(l->rc);
    cout << l->data << " ";
}
main()
{
    bstptr l;
    int k;
    while (1)
    {
        cin >> k;
        if (k == -1)
            break;
        insert(l, k);
    }
    preorder(l);
    cout << endl;
    postorder(l);
}
