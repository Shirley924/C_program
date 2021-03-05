#include<stdio.h>
 int function_1(int a,int n)
 {
     int l;
     if(a<n+1&&a>0)
       { l=1; }           /*符合條件離開do-while loop*/
     else
     {
          printf("The answer is illegal,please reset the answer.\n");
          l=0;            /*不符合條件則重新輸入答案*/
     }
     return l;
 }

int function_2(int H,int guess,int ans)  /*數有幾個位置對且數字對的猜測*/
{
        if(guess==ans)
         H++;
        return H;
}

int function_3(int k,int ans,int c)  /*統計答案/猜測值各有幾個1~N的數*/
{
        if(ans==k)
        c++;
        return c;
}

int function_4(int a,int b)  /*找兩者間較小的統計結果*/
{
        if(a<b)
         return a;
        else
         return b;
}
 int main(int argc ,char* argv[])
 {
    int N=atoi(argv[1]) ,P=atoi(argv[2]);
    printf("You set N=%d ,P=%d\n",N ,P);   /*print:N= P= */

    int p[P],g[P],i=0,j=0;

    while(j==0)
    {
        printf("ans:");
        for(i=0;i<P;i++)
        {
           scanf("%d",&p[i]);  /*輸入答案*/
        }
           for(i=0;i<P;i++)       /*檢查輸入的數字是否符合條件*/
          {
                        j=function_1(p[i],N); /*呼叫函式*/
                        if(j==0)
                                break;
          }

        }

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
             H=function_2(H,g[i],p[i]); /*呼叫函式*/
           }
 int count_ans=0,count_guess=0,k=0;
             for(k=1;k<N+1;k++)
             {
                int sum;
                for(i=0;i<P;i++)   /*數有幾個數字對的猜測(不論位置對與否)*/
                {
                   count_ans=function_3(k,p[i],count_ans);  /*呼叫函式*/
                   count_guess=function_3(k,g[i],count_guess);  /*呼叫函式*/
                 }
               sum=function_4(count_ans,count_guess);  /*呼叫函式*/
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
