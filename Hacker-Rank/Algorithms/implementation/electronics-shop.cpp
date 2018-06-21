#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int maxprice,no_keyb,no_usb,i,j,total=-1;
  scanf("%d %d %d",&maxprice,&no_keyb,&no_usb);
  int key[no_keyb],usb[no_usb];
  for(i=0;i<no_keyb;i++) scanf("%d",key+i);
  for(i=0;i<no_usb;i++) scanf("%d",usb+i);
  for(i=0;i<no_keyb;i++)
  {
    for(j=0;j<no_usb;j++)
    {
      if(key[i]+usb[j]>total&&key[i]+usb[j]<=maxprice) total=key[i]+usb[j];
    }
  }
  cout<<total;
  return 0;
}
