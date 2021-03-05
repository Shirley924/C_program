#include<stdio.h>
   #include<stdlib.h>
  
   int main(int argc, char *argv[])
   {
       int num, denom, result_num, result_denom;
  
       result_num=atoi(argv[1])*atoi(argv[4])+atoi(argv[3])*atoi(argv[2]); /*分子通分後相加*/
      num=result_num;
      result_denom=atoi(argv[2])*atoi(argv[4]); /*分母通分*/
      denom=result_denom;
 
      do
      {
          int remainder;
          remainder=result_num%result_denom; /*利用輾轉相除法計算分子分母最大公因數*/
          result_num=result_denom;
          result_denom=remainder;
      }while(result_denom!=0);
 
      num=num/result_num; /*化為最簡分數*/
      denom=denom/result_num;
      printf("%d/%d\n", num, denom);
 
      return 0;
  }
