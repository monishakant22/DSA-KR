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
int find(bstptr l, int k)
{
    if (l == NULL)
        return 0;
    if (k == l->data)
        return 1;
    else if (k > l->data)
        find(l->rc, k);
    else
        find(l->lc, k);
}
void can(bstptr l, int a, int b)
{
    static int k = 0;
    int c, d;
    if (k == 0)
    {
        c = find(l, a);
        d = find(l, b);
        if (c == 1 && d == 1)
            k = 1;
    }
    if (k == 0)
    {
        cout << "elements not found " << endl;
        return;
    }
    if (l)
    {
        if (l->data > a && l->data > b)
            can(l->lc, a, b);
        else if (l->data < a && l->data < b)
            can(l->rc, a, b);
        else if ((l->data < a && l->data > b) || (l->data > a && l->data < b))
        {
            cout << l->data << endl;
            return;
        }
        else
        {
            if (a == l->data)
                cout << a << endl;
            else
                cout << b << endl;
            return;
        }
    }
}
main()
{
    bstptr l;
    int k, a, b;
    while (1)
    {
        cin >> k;
        if (k == -1)
            break;
        insert(l, k);
    }
    while (1)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        can(l, a, b);
    }
}
