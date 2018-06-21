/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
#include<bits/stdc++.h>
map<int,int> mymap;
void topView(node * root)
{
      fun(root,0);
      for(auto &i:mymap) cout<<i.second<<' ';
}

void fun(node *root,int count)
{
  if(root==NULL) return;
  if(mymap.find(count)==mymap.end())
  {
    mymap[count]=root->data;
  }
  fun(root->left,count-1);
  fun(root->right,count+1);
}
