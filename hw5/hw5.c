#include<stdio.h>
#include<stdlib.h>
int or_array[100][101]={0},new_array[100][101]={0};
int num_array[101][100]={0},x[101][102]={0};
void fprint_result(int or_array[][101],int new_array[][101],int n,int lone)
{
        int i,j;
        FILE*fout;
        fout=fopen("hw5.out","w+t");
        if(fout==NULL)
        {
                printf("fail to open file hw5.out.");
                return;
        }
        for(i=0;i<n;i++)  //隨機存取original array
        {
                fprintf(fout,"%d/",i);
                for(j=1;j<or_array[i][0]+1;j++)
                    fprintf(fout,"%d",or_array[i][j]);
                fprintf(fout,"\n");
        }
        for(i=0;i<lone;i++)
        {
                fprintf(fout,"%d/",i);
                for(j=1;j<=new_array[i][0];j++)
                        fprintf(fout,"%d",new_array[i][j]);
                fprintf(fout,"\n");
        }
        fclose(fout);
}
int lon(int new_array[][101])  //計算new_array存到第lon個bucket
{       int i=0,lone=0;
        while(new_array[i][1]!=-1)
        {     i++;
              lone++;
        }
        return lone;
}
int most(int x[][102],int w)  //找最多match的陣列
{       int i,j,temp[1][102]={0};
        for(i=1;i<w+2;i++)
        {
                if(w==0)
                        return 0;  //如果w為0則跳出函式
                if(x[i][0]<x[i+1][0])  //將較大的數放置左側
                {
                        for(j=0;j<x[i][0]+2;j++)
                                temp[0][j]=x[i][j];
                        for(j=0;j<x[i+1][0]+2;j++)
                                x[i][j]=x[i+1][j];
                        for(j=0;j<temp[0][0]+2;j++)
                                x[i+1][j]=temp[0][j];
                }
        }
        most( x,w-1);
}
int con(int new_array[][101],int lone)  //計算new_array共有幾個數
{
        int i=0,sum_m=0;
        for(i=0;i<lone;i++)
        	 sum_m=sum_m+new_array[i][0];
        return sum_m;
}

int store(int new_array[][101],int or_array[][101],int x[][102],int a,int lone,int p,int m)
{
        int i=1,j=1;
        if(a>lone)
         return 0;  //代表已經與所有的new_array比完,可以開啟新壓縮bucket
        int disc=new_array[(x[a][1])][0]-(or_array[p][0]-x[a][0]);
        if(disc<=m-new_array[(x[a][0])][0])  //當new_array還存的下時
        {
                for(i=1;i<or_array[p][0]+1;i++)  //取出沒有重複的數字並加以儲存
                {
                        for(j=1;j<new_array[(x[a][1])][0]+1;j++)
                        {
                                if(or_array[p][i]==new_array[(x[a][1])][j])
                                 break;
                                new_array[(x[a][1])][(new_array[(x[a][1])][0]+1)]=or_array[p][i];
                                new_array[(x[a][1])][0]+=1;  //統計new_array該bucket已存了多少數
                        }
                        return 0;
                }
        }else if(disc>m-new_array[(x[a][0])][0])  //當new_array存不下時
                {
                store(new_array,or_array,x,a+1,lone,p,m);  //將match數第二大的拿來計算
                }
}
int main(int argc,char* argv[])
{
        int n=atoi(argv[1]);  //n為bucket的數量
        int m=atoi(argv[2]);  //m為一個bucket內可存的最大數字量
        int d=atoi(argv[3]);  //數字的範圍為0~(d-1)
        int s=atoi(argv[4]);  //seed of rand
        srand(s);
        int i,j,e=1,w=0,r=2,sum=0,lone=0,a=1,p=1,sum_n=0;
               for(i=0;i<=100;i++)
                {
                        for(j=0;j<=101;j++)
                                new_array[i][j]=-1;
                }
                for(i=0;i<n;i++)  //隨機存取original array
        {
                printf("%d/",i);
                or_array[i][0]=(rand()%m)+1;  //將該bucket中有幾個數字存到第一格
                for(j=1;j<or_array[i][0]+1;j++)
                {
                        or_array[i][j]=(rand()%d);
                        printf("%d",or_array[i][j]);
                                }
                printf("\n");
                }
        for(i=0;i<=or_array[0][0];i++)  //將or_array[0][0]複製到new_array[0][0]
               new_array[0][i]=or_array[0][i];
        for(p=1;p<n;p++)  //從第p個or_array壓縮
        {
                lone=lon(new_array);  //取目前已知的壓縮bucket數
                                  sum_n=con(new_array,lone);  //計算目前已壓縮的數量
  for(e=1;e<or_array[p][0]+1;e++)  //計算該or_array有甚麼數字,且有幾個
                {
                        for(i=0;i<d;i++)
                        {
                                if(or_array[p][e]==i)
                                num_array[0][i]++;
                        }
                }
                for(j=0;j<lone;j++)  //計算所有new_array有甚麼數字,且有幾個
                {
                        for(e=1;e<new_array[j][0]+1;e++)
                        {
                                for(i=0;i<d;i++)
                                {
                                        if(new_array[j][e]==i)
                                        num_array[j+1][i]++;
                                }
                        }
                }
                for(w=0;w<lone;w++)
                {
                        x[w+1][1]=w;  //存此為第w個new_array的值
                        for(i=0;i<d;i++)
                        {
                                if(num_array[0][i]!=0&&num_array[w+1][i]!=0)
                                {
                                        sum=num_array[0][i]<=num_array[w+1][i]?num_array[0][i]:num_array[w+1][i];
                                        x[w+1][0]=x[w+1][0]+sum;  //計算match總數量
                                        for(j=1;j<=sum;j++)
                                          x[w+1][r]=i;  //存重複那些數
                                        r++;  //跳下一個空間
                                }
                        }
                }
                most(x,w);
                store(new_array,or_array,x,a,lone,p,m);
                int sum_m=con(new_array,lone);
                if(sum_n==sum_m)  //如果不夠存放新的數字的話
                {
                        for(i=0;i<=or_array[p][0];i++)  //開新陣列
                        {
                                new_array[lone][i]=or_array[p][i];
                        }
                }
        }
        for(i=0;i<lone;i++)
        {
                printf("%d/",i);
                for(j=1;j<=new_array[i][0];j++)
                {
                        printf("%d",new_array[i][j]);
                }
                printf("\n");
        }
        fprint_result( or_array, new_array, n, lone);
return 0;
}
