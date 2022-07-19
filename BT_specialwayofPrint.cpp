#include <iostream>
using namespace std;
struct bstnode
{
    int data;
    bstnode *lc;
    bstnode *rc;
};
typedef bstnode *bstptr;
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
int size(bstptr l)
{
    if (l == NULL)
        return 0;
    else
        return 1 + size(l->lc) + size(l->rc);
}
void inorder(bstptr l, int &i, int &t, bstptr k)
{
    if (l == NULL)
        return;
    inorder(l->lc, i, t, k);
    if (i < t)
        i++;
    else
        cout << l->data << " ";
    inorder(l->rc, i, t, k);
}
main()
{
    bstptr l = NULL;
    create(l);
    int i = 1;
    int t = 1;
    bstptr k = l;
    while (t <= size(l))
    {
        inorder(l, i, t, k);
        i = 1;
        cout << endl;
        t++;
    }
}
