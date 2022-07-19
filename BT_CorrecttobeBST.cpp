#include<bits/stdc++.h>
using namespace std;
struct btnode
{
    btnode *lc;
    int data;
    btnode *rc;
};
typedef btnode *btptr;
void create(btptr &t,int k)
{
    int c;
    if(t==0)
    {
        t=new btnode;
        t->data=k;
        t->lc=t->rc=0;
    }
    //cout<<"Enter Left CHild of "<<k<<" ";
    cin>>c;
    if(c!=0)
        create(t->lc,c);
    //cout<<"Enter Right Child of "<<k<<" ";
    cin>>c;
    if(c!=0)
        create(t->rc,c);
    //return ;
}
void bttoBST(btptr t, btptr &x,btptr &y,int a,int b)
{
    if(t==0)
    return;
    if(t->data==a)
    x=t;
    if(t->data==b)
    y=t;
    bttoBST(t->lc,x,y,a,b);
    bttoBST(t->rc,x,y,a,b);
}
void corect(btptr t,int a,int b)
{
    btptr x=0,y=0;
    bttoBST(t,x,y,a,b);
    swap(x->data,y->data);
}
vector<int> preorder(btptr t) 
{ 
    vector<int>v;
    stack<btptr> s; 
    btptr r=t; 
    while (r!=NULL||s.empty()==false) 
    { 
        while (r!=NULL) 
        { 
            s.push(r); 
            r = r->lc; 
        } 
        r = s.top(); 
        s.pop(); 
        //cout << r->data << " "; 
        v.push_back(r->data);
        r = r->rc; 
    }
    return v;
} 
void preorder(btptr t)
{
    if(t)
    {
        inorder(t->lc);
        cout<<t->data<<" ";
        inorder(t->rc);
    }
}














int main()
{
    btptr t=0;
    int e;
    cin>>e;
    create(t,e);
    vector<int>v;
    
}