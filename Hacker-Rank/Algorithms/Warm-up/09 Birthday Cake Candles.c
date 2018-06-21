/*

      Question :-

          https://www.hackerrank.com/challenges/birthday-cake-candles

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

int main()
{
  int n,val,max,count=1;
  scanf("%d",&n);
  scanf("%d",&val);
  max=val;
  for(i=1;i<n;i++)
  {
    scanf("%d",&val);
    if(val>max)
    {
      max=val;
      count=1;
    }
    else if(val==max) count++;
  }
  printf("%d",count);
  return 0;
}
