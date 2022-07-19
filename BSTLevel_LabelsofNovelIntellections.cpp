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
void inorder(bstptr t)
{
    if (t)
    {
        inorder(t->lchild);
        cout << t->data << " ";
        inorder(t->rchild);
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
    cout << endl;
    reverse(v.begin(), v.end());
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
        if (r->rchild)
        {
            v.push_back(r->rchild->data);
            q.push(r->rchild);
        }
        if (r->lchild)
        {
            v.push_back(r->lchild->data);
            q.push(r->lchild);
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void squirrelantiClock(bstptr t, bool a)
{
    stack<bstptr> s1, s2;
    s1.push(t);
    int i = 1;
    while (!s1.empty())
    {
        bstptr r = s1.top();
        s1.pop();
        cout << r->data << " ";
        if (a == true ? i % 2 == 0 : i % 2 != 0)
        {
            if (r->rchild)
            {
                s2.push(r->rchild);
            }
            if (r->lchild)
            {
                s2.push(r->lchild);
            }
        }
        else
        {
            if (r->lchild)
            {
                s2.push(r->lchild);
            }
            if (r->rchild)
            {
                s2.push(r->rchild);
            }
        }
        if (s1.empty())
        {
            stack<bstptr> s3;
            while (!s2.empty())
            {
                s3.push(s2.top());
                s2.pop();
            }
            while (!s3.empty())
            {
                s1.push(s3.top());
                s3.pop();
            }
            i++;
        }
    }
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
    reversed(t);
    squirrelantiClock(t, true);
    squirrelantiClock(t, false);
    squirrelantiClock(t, true);
    squirrelantiClock(t, false);
    // 5 8 3 4 1 9 6 7 2 -1
}
