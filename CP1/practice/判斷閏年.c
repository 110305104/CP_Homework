#include <stdio.h>

int main()
{
  int year;
  scanf("%d",&year);
  
  if(year <0)
  {
   printf("???"); 
  }
  else if(year ==2021)
  {
   printf("今年"); 
  }
  
  else if (year%4 !=0 ||(year%100==0 && year%400 !=0))
  {
    printf("平年");
  }
  else
  {
    printf("閏年");
  }
  return 0;
}