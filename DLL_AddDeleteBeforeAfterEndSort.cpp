#include <bits/stdc++.h>
using namespace std;
struct Dlnode
{
    Dlnode *prev;
    int data;
    Dlnode *next;
};
typedef struct Dlnode *dlptr;
void insert(dlptr &d, int k)
{
    dlptr t = nullptr;
    t = new Dlnode;
    t->data = k;
    t->next = nullptr;
    t->prev = nullptr;
    if (d == 0)
    {
        d = t;
    }
    else
    {
        dlptr q = d;
        while (q->next)
            q = q->next;
        q->next = t;
        t->prev = q;
    }
}
void insertBefore(dlptr dl, int k, int key)
{
    dlptr t = dl;
    while (t->data != k)
    {
        t = t->next;
    }
    dlptr r = new Dlnode;
    r->data = key;
    r->next = 0;
    r->prev = 0;

    r->next = t;
    t->prev->next = r;
    t->prev = r;
}
void insertAfter(dlptr dl, int k, int key)
{
    dlptr t = dl;
    while (t->data != k)
    {
        t = t->next;
    }
    dlptr r = new Dlnode;
    r->data = key;
    r->next = 0;
    r->prev = 0;

    r->prev = t;
    r->next = t->next;
    t->next->prev = r;
    t->next = r;
}
void insertFront(dlptr &dl, int k)
{
    dlptr t = new Dlnode;
    t->data = k;
    t->next = dl;
    t->prev = 0;
    dl->prev = t;
    dl = t;
}
void delPos(dlptr dl, int k)
{
    while (dl->data != k)
    {
        dl = dl->next;
    }
    dl->prev->next = dl->next;
    dl->next->prev = dl->prev;
    delete dl;
}
void deleteFront(dlptr &dl)
{
    dl = dl->next;
    dl->prev = 0;
}
void deleteRear(dlptr dl)
{
    while (dl->next)
        dl = dl->next;
    dl->prev->next = 0;
    dl->prev = 0;
}
void sortit(dlptr &p, int k)
{
    dlptr t, q;
    t = new Dlnode;
    t->data = k;
    t->next = 0;
    if (p == 0)
    {
        p = t;
    }
    else
    {
        if (p->data > k)
        {
            t->next = p;
            p = t;
        }
        else
        {
            q = p;
            while (q->next && q->next->data < k)
            {
                q = q->next;
            }
            t->next = q->next;
            q->next = t;
        }
    }
}
void insertion(dlptr &l)
{
    dlptr p = 0, t = l;
    while (t)
    {
        sortit(p, t->data);
        t = t->next;
    }
    l = p;
}
void print(dlptr t)
{
    if (t == 0)
        return;
    cout << t->data << " ";
    print(t->next);
}
int main()
{
    dlptr dl = nullptr;
    int n;
    cin >> n;
    while (n > 0)
    {
        insert(dl, n);
        cin >> n;
    }
    print(dl);
    cout << endl;
    cin >> n;
    insertFront(dl, n);
    print(dl);
    cout << endl;
    cin >> n;
    insert(dl, n);
    print(dl);
    cout << endl;
    int x, y;
    cin >> x >> y;
    insertBefore(dl, y, x);
    print(dl);
    cout << endl;
    cin >> x >> y;
    insertAfter(dl, y, x);
    print(dl);
    cout << endl;
    deleteFront(dl);
    print(dl);
    cout << endl;
    deleteRear(dl);
    print(dl);
    cout << endl;
    cin >> n;
    delPos(dl, n);
    print(dl);
    cout << endl;
    insertion(dl);
    print(dl);

    return 0;
}
