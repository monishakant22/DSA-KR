#include <iostream>
using namespace std;
struct bstnode
{
    int data;
    int x;
    bstnode *lc;
    bstnode *rc;
};
typedef bstnode *bstptr;
struct queue
{
    int f;
    int r;
    int size;
    bstptr ds[20];
};
void enqueue(queue &a, bstptr b)
{
    if ((a.r + 1) % a.size == a.f)
        return;
    else
    {
        a.r = (a.r + 1) % a.size;
        a.ds[a.r] = b;
    }
    if (a.f == -1)
        a.f = 0;
}
bstptr dequeue(queue &a)
{
    if (a.f == -1)
        return NULL;
    bstptr t = a.ds[a.f];
    if (a.f == a.r)
    {
        a.f = -1;
        a.r = -1;
    }
    else
        a.f = (a.f + 1) % a.size;
    return t;
}
void create(bstptr &l, int k)
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
        if (k < l->data)
            create(l->lc, k);
        else
            create(l->rc, k);
    }
}
void inorder(bstptr l, int &i)
{
    if (l == NULL)
        return;
    inorder(l->lc, i);
    l->x = i++;
    inorder(l->rc, i);
}
void level(bstptr l, queue &q, int k)
{
    int i, t;
    i = 1;
    bstptr a;
    enqueue(q, l);
    enqueue(q, NULL);
    while (q.f != -1)
    {
        a = dequeue(q);
        if (a == NULL)
        {
            if (q.f == -1)
            {
                for (t = i; t < k; t++)
                    cout << "*";
                return;
            }
            for (t = i; t < k; t++)
                cout << "*";
            i = 1;
            cout << endl;
            enqueue(q, NULL);
            a = dequeue(q);
        }
        for (t = i; t <= a->x; t++)
        {
            if (a->x == t)
                cout << a->data;
            else
                cout << "*";
        }
        i = a->x + 1;
        if (a->lc)
            enqueue(q, a->lc);
        if (a->rc)
            enqueue(q, a->rc);
    }
}
main()
{
    queue q;
    q.f = -1;
    q.r = -1;
    q.size = 50;
    bstptr l = NULL;
    int k;
    while (1)
    {
        cin >> k;
        if (k == -1)
            break;
        create(l, k);
    }
    k = 1;
    inorder(l, k);
    level(l, q, k);
}
