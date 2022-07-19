#include <bits/stdc++.h>
using namespace std;
struct bstnode
{
    bstnode *lchild;
    int data;
    bstnode *rchild;
};
typedef struct bstnode *bstptr;
void insert(bstptr &t, int k)
{
    if (t == 0)
    {
        t = new bstnode;
        t->data = k;
        t->lchild = 0;
        t->rchild = 0;
        return;
    }
    else
    {
        if (k < t->data)
            insert(t->lchild, k);
        else
            insert(t->rchild, k);
    }
}
vector<int> levelorder(bstptr t)
{
    queue<bstptr> q;
    q.push(t);
    cout << t->data << " ";
    vector<int> v;
    v.push_back(t->data);
    while (!q.empty())
    {
        bstptr r = q.front();
        q.pop();
        if (r->lchild)
        {
            cout << r->lchild->data << " ";
            q.push(r->lchild);
            v.push_back(r->lchild->data);
        }
        if (r->rchild)
        {
            v.push_back(r->rchild->data);
            cout << r->rchild->data << " ";
            q.push(r->rchild);
        }
    }
}
int main()
{
    bstptr t = 0;
    int n;
    cin >> n;
    while (n != -1)
    {
        insert(t, n);
        cin >> n;
    }
    vector<int> s = levelorder(t);
    cout << endl;
}
