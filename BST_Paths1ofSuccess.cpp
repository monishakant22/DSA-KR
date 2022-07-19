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
void allpaths(bstptr t, vector<int> v, int &max, int &min, int &even, int &odd)
{
    if (t == 0)
    {
        return;
    }
    v.push_back(t->data);
    if (t->lchild == 0 && t->rchild == 0)
    {
        int temp = 0;
        int e = 0, o = 0;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
            temp += v[i];
            if (v[i] % 2 == 0)
                e++;
            else
                o++;
        }
        if (temp > max)
            max = temp;
        if (temp < min)
            min = temp;
        if (e > even)
            even = e;
        if (o > odd)
            odd = o;
        cout << endl;
        return;
    }
    allpaths(t->lchild, v, max, min, even, odd);
    allpaths(t->rchild, v, max, min, even, odd);
}
void paths(bstptr t, int &max, int &min, int &even, int &odd)
{
    vector<int> v;
    allpaths(t, v, max, min, even, odd);
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
    int max = 0;
    int min = INT_MAX;
    int even = 0;
    int odd = 0;
    paths(t, max, min, even, odd);
    cout << endl;
    return 0;
    // 5 8 3 4 1 9 6 7 2 -1
}
