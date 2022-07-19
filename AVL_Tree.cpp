#include <iostream>
using namespace std;
struct bstnode
{
    int data;
    bstnode *lc = NULL, *rc = NULL, *p = NULL;
};
typedef bstnode *bstptr;
void pre(bstptr l)
{
    if (l)
    {
        cout << l->data << " ";
        pre(l->lc);
        pre(l->rc);
    }
}
int hgt(bstptr l)
{
    if (l == NULL)
        return -1;
    return 1 + max(hgt(l->lc), hgt(l->rc));
}
void avl(bstptr &k, bstptr l)
{
    bstptr k3, k2, k1 = NULL;
    k3 = l;
    k2 = k3->p;
    if (k2)
        k1 = k2->p;
    int x, y, z;
    while (k1 != NULL)
    {
        if (abs((hgt(k1->lc)) - (hgt(k1->rc))) > 1)
        {
            (k1->rc == k2) ? x = 1 : x = 0;
            (k2->rc == k3) ? y = 1 : y = 0;
            if (x == 0 && y == 0)
            {
                bstptr t = k1->p;
                if (t != NULL)
                {
                    (t->rc == k1) ? z = 1 : z = 0;
                    (z == 1) ? t->rc = k2, k2->p = t : t->lc = k2, k2->p = t;
                }
                else
                    k = k2, k2->p = t;
                if (k2->rc)
                    k2->rc->p = k1;
                k1->p = k2;
                k1->lc = k2->rc;
                k2->rc = k1;
            }
            else if (x == 1 && y == 1)
            {
                bstptr t = k1->p;
                if (t != NULL)
                {
                    (t->rc == k1) ? z = 1 : z = 0;
                    (z == 1) ? t->rc = k2, k2->p = t : t->lc = k2, k2->p = t;
                }
                else
                    k = k2, k2->p = t;
                if (k2->lc)
                    k2->lc->p = k1;
                k1->p = k2;
                k1->rc = k2->lc;
                k2->lc = k1;
            }
            else if (x == 0 && y == 1)
            {
                bstptr t = k1->p;
                if (t != NULL)
                {
                    (t->rc == k1) ? z = 1 : z = 0;
                    (z == 1) ? t->rc = k3 : t->lc = k3;
                }
                else
                    k = k3;
                k3->p = t;
                k1->lc = k3->rc;
                if (k3->rc)
                    k3->rc->p = k1;
                k2->rc = k3->lc;
                if (k3->lc)
                    k3->lc->p = k2;
                k3->lc = k2;
                k2->p = k3;
                k3->rc = k1;
                k1->p = k3;
            }
            else
            {
                bstptr t = k1->p;
                if (t != NULL)
                {
                    (t->rc == k1) ? z = 1 : z = 0;
                    (z == 1) ? t->rc = k3 : t->lc = k3;
                }
                else
                    k = k3;
                k3->p = t;
                k1->rc = k3->lc;
                if (k3->lc)
                    k3->lc->p = k1;
                k2->lc = k3->rc;
                if (k3->rc)
                    k3->rc->p = k2;
                k3->rc = k2;
                k2->p = k3;
                k3->lc = k1;
                k1->p = k3;
            }
            break;
        }
        else
        {
            k3 = k2;
            k2 = k1;
            k1 = k1->p;
        }
    }
}
void create(bstptr &l, int k, bstptr op, bstptr &u)
{
    if (l == NULL)
    {
        l = new bstnode;
        l->data = k;
        l->p = op;
        u = l;
    }
    else
    {
        if (k > l->data)
            create(l->rc, k, l, u);
        else
            create(l->lc, k, l, u);
    }
}
int main()
{
    bstptr l = NULL, u, t = NULL;
    int k;
    while (cin >> k && k != -1)
        create(l, k, t, u), avl(l, u), pre(l), cout << endl;
}
