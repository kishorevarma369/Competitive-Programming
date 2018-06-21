#include<stdio.h>

void fun()
{
  unsigned long long int no[2],price[2],ex_price,total;
  scanf("%llu %llu\n%llu %llu %llu",no,no+1,price,price+1,&ex_price);
  if(price[0]>price[1])//swapping
  {
    price[0]=price[0]+price[1]-(price[1]=price[0])
    no[0]=no[0]+no[1]-(no[1]=no[0]);
  }
  total=price[0]*no[0];
  if(price[1]>price[0]+ex_price) total+=(price[0]+ex_price)*no[1];
  else total+=price[1]*no[1];
  printf("%llu\n",total);
}

int main(int argc, char const *argv[])
{
  int n;
  scanf("%d",&n);
  while(n--) fun();
  return 0;
}
