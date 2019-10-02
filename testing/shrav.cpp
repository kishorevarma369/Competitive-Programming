#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node *left,*right;
}node;
node *base=NULL;

void add_node(int val,int k)
{
    //
    if(base==NULL)
    {
        base=(node*)malloc(sizeof(node));
        base->val=val;
        base->left=base->right=base;
        return;
    }
    do
    {
        base=base->right;
    }
    while(k--);
    node *prev=base->left;
    node *next=base->right;
    node *pres=(node*)malloc(sizeof(node));
    pres->val=val;
    pres->left=prev;
    pres->right=next;
    prev->right=pres;
    next->left=pres;
    base=pres;
}

void solve()
{
    int n,k,val;
    cin>>k>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        add_node(val,k);
    }
    cout<<(base->left->val)<<'\n';
}

int main()
{
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}