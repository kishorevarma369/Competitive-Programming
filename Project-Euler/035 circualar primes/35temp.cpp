#include<iostream>
#define million 1000000
using namespace std;
bool prime[million];

void primegen()
{
  int i=0,j,k;
  for (i=2; i<million; i++) prime[i]=1;
  for(i=2;i<million;i++)
  {
    if(prime[i])
    {
      for (j=2; (k=i*j) < million; j++) prime[k]=0;
    }
  }
}

int main(int argc, char const *argv[])
{
  primegen();
  int i,j,k,dig=1,divi=1,ndivi=10,mat[6],l,m,flag,count=0;
  for(i=0;i<10;i++) if(prime[i]) count++;
  for(;i<1000000;i++)
  {
    if(i==ndivi)
    {
      dig++;
      divi=ndivi;
      ndivi*=10;
    }
    if(prime[i])
    {
      j=k=i;
      l=flag=0;
      while(j>9)
      {
        k=((k%divi)*10+k/divi);
        if(k==i) goto a;
        if(prime[k]) mat[l++]=k;
        else mat[l++]=0;
        j/=10;
      }
      prime[i]=0;
      for(m=0;m<l;m++)
      {
        prime[mat[m]]=0;
        if(!mat[m]) flag=1;
      }
      if(flag==0) count+=dig;
      continue;
      a:
      count+=1;
    }
  }
  cout<<count;
  return 0;
}
