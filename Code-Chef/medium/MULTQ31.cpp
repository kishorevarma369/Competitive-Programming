#include<bits/stdc++.h>

using namespace std;

struct my
{
  int co;
  vector<int> s;
  my()
  {

  }
  my(int n):s(n,0)
  {
    co=n;
  }
};
typedef struct my myvector;

void fun(int begpos,int endpos,vector<myvector> & v)
{
  int block_size = v[0].s.size() , no_of_blocks = v.size();
  int pres_block_beg_pos = begpos / block_size , pres_block_end_pos = endpos / block_size ;
  int t_beg_pos = begpos , t_end_pos = endpos;
  while( pres_block_beg_pos <= pres_block_end_pos)
  {
    t_beg_pos = begpos - pres_block_beg_pos * block_size;
    begpos-=t_beg_pos;
    if ( pres_block_beg_pos == pres_block_end_pos ) t_end_pos = endpos-pres_block_end_pos*block_size+1;
    else t_end_pos = block_size;
    for(; t_beg_pos < t_end_pos ; t_beg_pos++ )
    {
      if(v[pres_block_beg_pos].s[t_beg_pos]%3==0)
      {
        v[pres_block_beg_pos].co--;
      }
      v[pres_block_beg_pos].s[t_beg_pos]++;
      if(v[pres_block_beg_pos].s[t_beg_pos]%3==0)
      {
        v[pres_block_beg_pos].co++;
      }
    }
    begpos+=block_size;
    pres_block_beg_pos++;
  }
}

int fun1(int begpos,int endpos,vector<myvector> & v)
{
  int block_size = v[0].s.size() , no_of_blocks = v.size();
  int pres_block_beg_pos = begpos / block_size , pres_block_end_pos = endpos / block_size ;
  int t_beg_pos , t_end_pos ;
  int cou=0;
  while( pres_block_beg_pos <= pres_block_end_pos)
  {
    t_beg_pos = begpos - pres_block_beg_pos * block_size;
    begpos -= t_beg_pos ;
    if( pres_block_beg_pos == pres_block_end_pos ) t_end_pos = endpos - pres_block_beg_pos * block_size + 1;
    else t_end_pos = endpos;
    if( t_beg_pos == 0 && t_end_pos == endpos )
    {
      cou+=v[pres_block_beg_pos].co;
    }
    else
    {
      for(; t_beg_pos < t_end_pos ; t_beg_pos++ )
      {
        if(v[pres_block_beg_pos].s[t_beg_pos]%3==0) cou++;
      }
    }
    begpos += block_size ;
    pres_block_beg_pos++;
  }
  return cou;
}

int main(int argc, char const *argv[])
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t , n , op , i , j , cou , block_size , no_of_blocks ;
  cin>>n>>t;
  block_size = ceil(sqrt(n));
  no_of_blocks = ceil(float(n)/block_size);
  vector<myvector> v ( no_of_blocks , myvector ( block_size ) );
  v[no_of_blocks-1].co -= block_size * no_of_blocks - n;
  while(t--)
  {
    cin>>op>>i>>j;
    if(op)
    {
      cout<<fun1(i,j,v)<<'\n';
    }
    else fun(i,j,v);
  }
  return 0;
}
