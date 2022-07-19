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
    // cout<<t->data<<" ";
    vector<int> v;
    v.push_back(t->data);
    while (!q.empty())
    {
        bstptr r = q.front();
        q.pop();
        if (r->lchild)
        {
            // cout<<r->lchild->data<<" ";
            q.push(r->lchild);
            v.push_back(r->lchild->data);
        }
        if (r->rchild)
        {
            v.push_back(r->rchild->data);
            // cout<<r->rchild->data<<" ";
            q.push(r->rchild);
        }
    }
    return v;
}
void reversed(bstptr t)
{
    queue<bstptr> q;
    q.push(t);
    vector<int> v;
    v.push_back(t->data);
    while (!q.empty())
    {
        bstptr r = q.front();
        q.pop();
        if (r->lchild)
        {
            v.push_back(r->lchild->data);
            q.push(r->lchild);
        }
        if (r->rchild)
        {
            v.push_back(r->rchild->data);
            q.push(r->rchild);
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
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
    for (int i = 0; i < s.size(); i++)
        // cout<<s[i]<<" ";
        cout << endl;
    reversed(t);
}
