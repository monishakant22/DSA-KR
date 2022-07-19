#include <bits/stdc++.h>
using namespace std;

struct bstnode
{
    bstnode *lc;
    int data;
    bstnode *rc;
};
typedef bstnode *bstptr;
int k;
vector<int> v;
bstptr create(bstptr &l, int k)
{
    if (l == NULL)
    {
        l = new bstnode;
        l->data = k;
        l->rc = NULL;
        l->lc = NULL;
    }
    if (k < l->data)
        l->lc = create(l->lc, k);
    else if (k > l->data)
        l->rc = create(l->rc, k);
    return l;
}
void inorder(bstptr l)
{
    if (l == NULL)
        return;
    if (l->data != 0)
        inorder(l->lc);
    cout << l->data << " ";
    inorder(l->rc);
}
queue<int> q;
void levelprint()
{
    int i = 1;
    q.push(v[i]);
    while (!q.empty())
    {
        int s = q.size();
        for (int len = 0; len < s; len++)
        {
            int temp = q.front();
            q.pop();
            cout << temp << " ";

            if (v.size() - 1 >= 2 * i)
                q.push(v[2 * i]);
            if (v.size() - 1 >= ((2 * i) + 1))
                q.push(v[2 * i + 1]);
            i++;
        }
        cout << "/" << endl;
    }
}
int main()
{
    bstptr l = NULL;
    cin >> k;
    l = create(l, k);
    while (cin >> k && k != -1)
        create(l, k);
    v.push_back(-1);
    inorder(l);
    levelprint();
}
