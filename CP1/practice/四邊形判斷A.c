#include<stdio.h>
main()
{
    int n;
    scanf("%d",&n);
    int a[8 * n];
    int i,j;
    int temp1,temp2;
    for(i = 0;i < 8 * n;i ++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0;i < 8 * n;i += 8)
    {
        if(((a[i+2]-a[i]) * (a[i+5]-a[i+1]) - (a[i+3]-a[i+1]) * (a[i+4]-a[i])) > 0)
        {
            temp1 = a[i+2];
            temp2 = a[i+3];
            a[i+2] = a[i+4];
            a[i+3] = a[i+5];
            a[i+4] = temp1;
            a[i+5] = temp2;
        }
        if(((a[i+2]-a[i]) * (a[i+7]-a[i+1]) - (a[i+3]-a[i+1]) * (a[i+6]-a[i])) > 0)
        {
            temp1 = a[i+2];
            temp2 = a[i+3];
            a[i+2] = a[i+6];
            a[i+3] = a[i+7];
            a[i+6] = temp1;
            a[i+7] = temp2;
        }
        if(((a[i+4]-a[i]) * (a[i+7]-a[i+1]) - (a[i+5]-a[i+1]) * (a[i+6]-a[i])) > 0)
        {
            temp1 = a[i+4];
            temp2 = a[i+5];
            a[i+4] = a[i+6];
            a[i+5] = a[i+7];
            a[i+6] = temp1;
            a[i+7] = temp2;
        }  
    }
    for(i = 0;i < n*8;i += 8){
            int AB[2] = {(a[i+2]-a[i]),(a[i+3]-a[i+1])};
            int BC[2] = {(a[i+4]-a[i+2]),(a[i+5]-a[i+3])};
            int CD[2] = {(a[i+6]-a[i+4]),(a[i+7]-a[i+5])};
            int DA[2] = {(a[i]-a[i+6]),(a[i+1]-a[i+7])};
            int A = AB[0] * AB[0] + AB[1] * AB[1];
            int B = BC[0] * BC[0] + BC[1] * BC[1];
            int C = CD[0] * CD[0] + CD[1] * CD[1];
            int D = DA[0] * DA[0] + DA[1] * DA[1];
            if(A==B&&B==C&&C==D){
                if(AB[0] * BC[0] + AB[1] * BC[1] == 0 && CD[0] * BC[0] + CD[1] * BC[1] == 0 &&
                CD[0] * DA[0] + CD[1] * DA[1] == 0 && AB[0] * DA[0] + AB[1] * DA[1] == 0){
                    printf("square\n");
                }
                else{
                    printf("diamond\n");
                }
            }
            else{
                if(AB[0] * BC[0] + AB[1] * BC[1] == 0 && CD[0] * BC[0] + CD[1] * BC[1] == 0 &&
                CD[0] * DA[0] + CD[1] * DA[1] == 0 && AB[0] * DA[0] + AB[1] * DA[1] == 0){
                    printf("rectangle\n");
                }
                else{
                    printf("other\n");
                }
            }
 
        }
 
 
 
 
 
}