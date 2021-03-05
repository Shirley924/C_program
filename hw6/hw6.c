#include<stdio.h>
#include<string.h>
int main(int argc[],char* argv[])
{
    int i=0,total=0;
    int F1=0,F2=0,F3=0,F4=0,F5=0;
    int f1=0,f2=0,f3=0,f4=0,f5=0;
    int count=0;
    char F1_str[10000][30],F2_str[10000][30],F3_str[10000][30],F4_str[10000][30],F5_str[10000][30];
    char f1_str[]="@0.0.0.0/0";
    char f2_str[]="0.0.0.0/0";
    char f3_str[]="0:65535";
    char f4_str[]="0:65535";
    char f5_str[]="0x00/0x00";
    char last[10000][30];
    char s1[30],s2[30],s3[30],s4[30],s5[30],s6[30],s7[30],s8[30],s9[30];
    FILE *input;
    input=fopen(argv[1],"r");
    while(EOF!=     fscanf(input,"%s%s%s%s%s%s%s%s%s",s1,s2,s3,s4,s5,s6,s7,s8,s9)){
                strcat(s3,s4);strcat(s3,s5);strcat(s6,s7);strcat(s6,s8);

        strcpy(F1_str[F1],s1);  //先存該字串於第F1個
        for(i=0;i<F1;i++)  //檢驗跟第0個到第(F1-1)個是否有重複
        { if(strcmp(s1,F1_str[i])==0)                  { memset(F1_str[F1],0,29);  //如果重複則刪除該字串
                   F1--;  //恢復先前的計數
                   break;  //跳出迴圈        }
                }
         F1++;
         strcpy(F2_str[F2],s2);  //先存該字串於第F2個
         for(i=0;i<F2;i++)  //檢驗跟第0個到第(F2-1)個是否有重複
                {
                        if(strcmp(s2,F2_str[i])==0)
                        {
                                memset(F2_str[F2],0,29);  //如果重複則刪除該字串
                                F2--;  //恢復先前的計數
                                break;  //跳出迴圈
                        }
                }
                F2++;

                strcpy(F3_str[F3],s3);  //先存該字串於第F1個
                for(i=0;i<F3;i++)  //檢驗跟第0個到第(F1-1)個是否有重複
                {
                        if(strcmp(s3,F3_str[i])==0)
                 {
                     memset(F3_str[F1],0,29);  //如果重複則刪除該字串
                                F3--;  //恢復先前的計數
                                break;  //跳出迴圈
                        }
                }
                F3++;
                strcpy(F4_str[F4],s6);  //先存該字串於第F1個
                for(i=0;i<F4;i++)  //檢驗跟第0個到第(F1-1)個是否有重複
                {
                        if(strcmp(s6,F4_str[i])==0)
                        {
                                memset(F4_str[F4],0,29);  //如果重複則刪除該字串
                                F4--;  //恢復先前的計數
                                break;  //跳出迴圈
                        }
                }
                F4++;
                strcpy(F5_str[F5],s9);  //先存該字串於第F1個
                for(i=0;i<F5;i++)  //檢驗跟第0個到第(F1-1)個是否有重複
                {
                        if(strcmp(s9,F5_str[i])==0)
                        {
                                memset(F5_str[F5],0,29);  //如果重複則刪除該字串
                                F5--;  //恢復先前的計數
                                break;  //跳出迴圈
                        }
                }
                F5++;

                if(strcmp(s1,f1_str)==0)
                        f1++;
                if(strcmp(s2,f2_str)==0)
                        f2++;
                if(strcmp(s3,f3_str)==0)
                        f3++;
                if(strcmp(s6,f4_str)==0)
                        f4++;
                if(strcmp(s9,f5_str)==0)
                        f5++;

        total++;

        strcat(s3,s6);strcat(s3,s9);
        strcpy(last[count],s3);  //先存該字串於第F1個
        for(i=0;i<count;i++)  //檢驗跟第0個到第(F1-1)個是否有重複
        {
                if(strcmp(s3,last[i])==0)
                {
                        memset(last[count],0,29);  //如果重複則刪除該字串
                        count--;  //恢復先前的計數
                        break;  //跳出迴圈
                }
        }
        count++;

        }
        fclose(input);

        printf("#of distinct field value:\n");
        printf("F1:%d\nF2:%d\nF3:%d\nF4:%d\nF5:%d\n",F1,F2,F3,F4,F5);
        printf("#of*\n");
        printf("F1:%d\nF2:%d\nF3:%d\nF4:%d\nF5:%d\n",f1,f2,f3,f4,f5);

        printf("total:\n%d\n",total);
        printf("the distinct subrules consisting only the last three fields:\n%d\n",count);

        return 0;
}
