#include<stdio.h>
int main(int argc ,char* argv[])
{
   int N=atoi(argv[1]) ,P=atoi(argv[2]);
   printf("You set N=%d ,P=%d\n",N ,P);   /*print:N= P= */

   int p[P],g[P],i=0,j=0;

   do
   {
       printf("ans:");
       for(i=0;i<P;i++)
       {
          scanf("%d",&p[i]);  /*輸入答案*/
       }
          for(i=0;i<P;i++)       /*檢查輸入的數字是否符合條件*/
         {
            if(p[i]<N+1&&p[i]>0)
            j=1;            /*符合條件離開do-while loop*/
            else
            {
            printf("The answer is illegal,please reset the answer.\n");
            j=0;            /*不符合條件則重新輸入答案*/
            break;
            }
          }
       }while(j==0);

       while(j==1)
       {
          int H=0 ,X=0;
          printf("guess:");
          for(i=0;i<P;i++)
          {
             scanf("%d",&g[i]);  /*輸入猜測數字*/
          }
          for(i=0;i<P;i++)
          {
             if(g[i]==p[i])     /*數有幾個數字對且位置對的猜測*/
             H++;
          }
             int count_ans=0,count_guess=0,k=0;
             for(k=0;k<N+1;k++)
             {
                int sum;
                for(i=0;i<P;i++)   /*數有幾個數字對的猜測(不論位置對與否)*/
                {
                   if(p[i]==k)    /*統計答案有幾個1,2,...,N*/
                   count_ans++;
                   if(g[i]==k)    /*統計猜測有幾個1,2,...,N*/
                   count_guess++;
                 }
                            sum=count_ans<=count_guess?count_ans:count_guess;   /*找兩者間較小的統計結果*/
 count_ans=0;      /*歸零繼續下一次統計*/
 count_guess=0;
 X=X+sum;
 }
X=X-H;    /*數有幾個數字對但位置不對的猜測*/

printf("%dH %dX\n",H ,X);   /*print: ?H ?X*/
if(H==P&&X==0)
j=3;     /*跳出while loop*/
}
return 0;
}