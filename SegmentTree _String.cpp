//Life is a string of miracles
//ove to win with strong logics
  //                          - KR
#include<bits/stdc++.h>
using namespace std;
string build(vector<string>& s,int i,string a,int l,int h)
{
    if(l==h)
    {
        s[i].push_back(a[l]);
        return s[i];
    }
    else
    {
        int mid=(l+h)/2;
        string x,y;
        x=build(s,2*i+1,a,l,mid);
        y=build(s,2*i+2,a,mid+1,h);
        if(x.length()==1&&y.length()==1)
        {
            if(x==y)
                s[i]=x;
            else
            {
                s[i]+=x;
                s[i]+=y;  
            }
        }
        else
        {
            s[i]+=x;
            s[i]+=y;
            sort(s[i].begin(),s[i].end());
            auto x=unique(s[i].begin(),s[i].end());
            s[i]=string(s[i].begin(),x); 
        }
        sort(s[i].begin(),s[i].end());
        return s[i];
    }
}
string getvalue(vector<string>s,int i,int sl,int sr,int l,int r)
{
    if(l<=sl && r>=sr)
        return s[i];
    if(sr<l || sl>r)
        return "";
    else
    {
        int mid=(sl+sr)/2;
        string x,y,z;
        x=getvalue(s,2*i+1,sl,mid,l,r);
        y=getvalue(s,2*i+2,mid+1,sr,l,r);
        z=x+y;
        sort(z.begin(),z.end());
        auto t=unique(z.begin(),z.end());
        z=string(z.begin(),t);
        return z;
    }
}
void update(vector<string>& s,int i,int sl,int sr,int pos,string x)
{
    if(sl>pos || sr<pos)
    return;
    if(sl==sr)
    {
        s[i]=x;
    }
    else
    {
        int mid=(sl+sr)/2;
        update(s,2*i+1,sl,mid,pos,x); 
        update(s,2*i+2,mid+1,sr,pos,x);
        s[i]=s[2*i+1]+s[2*i+2];
        sort(s[i].begin(),s[i].end());
        auto t=unique(s[i].begin(),s[i].end());
        s[i]=string(s[i].begin(),t);
    } 
}
int main()
{
    string a;
    char c;
    cin>>c;
    while(c!='#')
    {
        a+=c;
        cin>>c;
    }
    int nextPowOf2 = (int)round(pow(2, ceil(log2(a.length()))));
    int treeSize = 2 * nextPowOf2 - 1;
    vector<string>s(treeSize);
    build(s,0,a,0,a.length()-1);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int i,b;
        string x;
        cin>>i>>b>>x;
        if(i==1)
        {
            update(s,0,0,a.length()-1,b-1,x);
        }
        else if(i==2)
        {
            int t=stoi(x);
            --t;
            string er=getvalue(s,0,0,a.length()-1,b-1,t);
            cout<<er.length()<<endl;
        }
    }

    return 0;
}



