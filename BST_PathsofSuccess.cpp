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
            // cout<<v[i]<<" ";
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
        // cout<<endl;
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
void left(bstptr t)
{
    if (t == 0)
        return;
    cout << t->data << " ";
    if (t->lchild)
        left(t->lchild);
    else
        left(t->rchild);
}
void right(bstptr t)
{
    if (t == 0)
        return;
    cout << t->data << " ";
    if (t->rchild)
        right(t->rchild);
    else
        right(t->lchild);
}
void sumprint(bstptr t, vector<int> v, int sum)
{
    if (t == 0)
    {
        return;
    }
    v.push_back(t->data);
    if (t->lchild == 0 && t->rchild == 0)
    {
        int temp = 0;
        for (int i = 0; i < v.size(); i++)
            temp += v[i];
        if (temp == sum)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    sumprint(t->lchild, v, sum);
    sumprint(t->rchild, v, sum);
}
void sums(bstptr t, int sum)
{
    vector<int> v;
    sumprint(t, v, sum);
}
void evenprint(bstptr t, vector<int> v, int even)
{
    if (t == 0)
        return;
    v.push_back(t->data);
    if (t->lchild == 0 && t->rchild == 0)
    {
        int temp = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] % 2 == 0)
                temp++;
        }
        if (temp == even)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    evenprint(t->lchild, v, even);
    evenprint(t->rchild, v, even);
}
void evens(bstptr t, int even)
{
    vector<int> v;
    evenprint(t, v, even);
}
void oddprint(bstptr t, vector<int> v, int odd)
{
    if (t == 0)
        return;
    v.push_back(t->data);
    if (t->lchild == 0 && t->rchild == 0)
    {
        int temp = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] % 2 != 0)
                temp++;
        }
        if (temp == odd)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    oddprint(t->lchild, v, odd);
    oddprint(t->rchild, v, odd);
}
void odds(bstptr t, int odd)
{
    vector<int> v;
    oddprint(t, v, odd);
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
    left(t);
    cout << endl;
    right(t);
    cout << endl;
    sums(t, max);
    sums(t, min);
    sums(t, 22);
    // cout<<even<<" "<<odd;
    evens(t, even);
    odds(t, odd);
    return 0;
    // 5 8 3 4 1 9 6 7 2 -1
}
