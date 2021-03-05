#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char* argv[])
{
    int i=0, n=0;
    switch(atoi(argv[1]))
    {
case 1:
      {
        float f=0.0;  //將float值初始化
        int *k=(int*)&f;  //f轉為整數指標,並把其位址存於k
        int a[32];
        for(i=0;i<32;i++)
        {
           if(argv[2][i]=='1')  //把字元argv[2][i]轉為整數陣列
            a[i]=1;
           else
            a[i]=0;
        }
        for(i=0;i<32;i++)
        {
            n|=a[i]<<(31-i);  //a[i]從n(為0)的最左位元比對,若a[i]為1其位元由0轉為1
         (*k)|=a[i]<<(31-i);  //同上,但從float位址更改其bit值
        }
        printf("integer:%d\n",n);  //print n
        printf("float:%f\n",f);  //print f
        	break;
        }
        case 2:
        {
          int num=atoi(argv[2]);  //用atoi將字串轉為整數
          printf("32-bit:");
          for(i=31;i>-1;i--)
         {
             n=num&(1<<i); //1從num最左的bit比對,若同為1,n的該bit存1,反之存0
             n>>=i; //將該bit值右移至底,使n值變為該bit值,利用迴圈印出
             printf("%d",abs(n));  //print n的絕對值
        }
        printf("\n");
                break;
        }
        case 3:
        {
            float a=atof(argv[2]);  //用atof將字串轉為float
            int *x=(int*)&a;  //將a轉整數指標並存取其位址

            printf("32-bit:");
            for(i=31;i>=0;i--)
	{
             n=(*x)&(1<<i);  //用int來表示其位元的*x中每個位元依序跟1做&運算
             n>>=i;  //將該bit值右移至底,使n值變為該bit值,利用迴圈印出
             printf("%d",abs(n));  //print n的絕對值
         }
        printf("\n");
        	break;
        }
        case 4:
        {
           long long b[64];//為避免溢位使用long long宣告，底下有long long皆同此理
           for(i=0;i<64;i++)
           {
              if (argv[2][i]=='1') //若字元為1則將數值1存入陣列，若為0則存入0
               b[i]=1;
              else
               b[i]=0;
           }
                long long  x=0;

            for(i=63;i>=0;i--)
            {
               x|=(long long)b[i]<<(63-i);  //x從最左bit開始比對,若b[i]為1則其位元轉為1
            }
               double *d=(double*)&x;  //將long long x轉double
               printf("integer:%lld\n",x);
               printf("double:%f\n",*d);
        	break;
        } 
        case 5:
        {
             long int num=atol(argv[2]);  //用atol將字串argv[2]轉為long int
              printf("64-bit:");
              for(i=63;i>=0;i--)
              {
                  n=num&((long int)1<<i);  //1以long型別存取,從最左開始比對,若同為1則該bit存1,反之存0
                  n>>=i;  //將該bit值右移至底,使n值變為該bit值,利用迴圈印出
                  printf("%d",abs(n));  //print n的絕對值
              }
              printf("\n");
                break;
        }
        case 6:
        {
           double d=strtod(argv[2],NULL);  //將字串轉換為double
          long long *y=(long long*)&d;  //運用指標將double位元以long long表示
          printf("64-bit:");
          for(i=63;i>=0;i--)
         {
            long long bit=(*y)&((long long)1<<i);  //用long long來表示其位元組成的*y，將其每個位元依序跟1做&運算
              bit>>=i;  //將該bit值右移至底,使其值變為該bit值,利用迴圈印出
              printf("%lld",bit);
          }
          printf("\n");
        }
    }
        return 0;
}
