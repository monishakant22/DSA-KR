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
int max(bstptr l)
{
    int k = l->data;
    while (l->rc)
        l = l->rc;
    return l->data;
}
int min(bstptr l)
{
    int k = l->data;
    while (l->lc)
        l = l->lc;
    return l->data;
}
void maxmin(bstptr l, int mn, int mx)
{
    if (l == NULL)
        return;
    maxmin(l->lc, mn, l->data - 1);
    maxmin(l->rc, l->data + 1, mx);
    if (l->rc == NULL && l->lc == NULL)
        cout << l->data << " " << mn << " " << mx << endl;
    else if (l->rc != NULL && l->lc != NULL)
        cout << l->data << " " << max(l->lc) + 1 << " " << min(l->rc) - 1 << endl;
    else if (l->rc != NULL && l->lc == NULL)
        cout << l->data << " " << mn << " " << min(l->rc) - 1 << endl;
    else
        cout << l->data << " " << max(l->lc) + 1 << " " << mx << endl;
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
    maxmin(l, 0, 99999);
}
