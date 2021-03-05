#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
//IPV4 的STRUCT
struct IPV4{
int length;
unsigned char pro[1];
unsigned char SRC_IP[4];
unsigned char DST_IP[4];
}I;

//TCP的STRUCT
struct TCP{
int SRC_Port;
int DST_Port;
}T;

//UDP的STRUCT
struct UDP{
int SRC_Port;
int DST_Port;
}U;

//MAC的STRUCT
struct MAC{
unsigned char DST_MAC[6];
unsigned char SRC_MAC[6];
}M;

int main(int argc,char* argv[]){
FILE *fp;
fp=fopen(argv[1],"rb");
if(!fp){
printf("Can't open the file\n");
return -1;
}

unsigned char SRC_Port[2]="";
unsigned char DST_Port[2]="";
unsigned char length[2]="";
unsigned char dont_need[65535]=""; //資料最長的長度(不包括Ethernet)
int Pcount=0,Tcount=0,Ucount=0,Icount=0,i=0,num=1;

while(1){
num++;
//計算DST MAC
fread(M.DST_MAC,sizeof(char),6,fp);
if(feof(fp)) break;
printf("#%d\n",num);
printf("DST MAC:");
for(i=0;i<5;i++)
 printf("%02x:",M.DST_MAC[i]);
printf("%02x\n",M.DST_MAC[5]);
//計算SRC MAC
fread(M.SRC_MAC,sizeof(char),6,fp);
printf("SRC MAC:");
for(i=0;i<5;i++)
 printf("%02x:",M.SRC_MAC[i]);
printf("%02x\n",M.SRC_MAC[5]);
//把不要的去掉
fread(dont_need,sizeof(char),4,fp);
//計算長度
fread(length,sizeof(char),2,fp);
I.length=256*length[0]+length[1]+14;
//把不要的去掉
fread(dont_need,sizeof(char),5,fp);
//計算總共有幾個Packet
fread(I.pro,sizeof(char),1,fp);
Pcount++;
printf("Protocal:");
//為TCP時,計算該SRC IP,DST IP,SRC Port,DST Port
if(I.pro[0]==6){
 printf("TCP\n");
 Tcount++;
fread(dont_need,sizeof(char),2,fp);
fread(I.SRC_IP,sizeof(char),4,fp);
printf("SRC IP:");
for(i=0;i<3;i++)
 printf("%d.",I.SRC_IP[i]);
printf("%d\n",I.SRC_IP[3]);
fread(I.DST_IP,sizeof(char),4,fp);
printf("DST IP:");
for(i=0;i<3;i++)
 printf("%d.",I.DST_IP[i]);
printf("%d\n",I.DST_IP[3]);

fread(SRC_Port,sizeof(char),2,fp);
T.SRC_Port=SRC_Port[0]*256+SRC_Port[1];
fread(DST_Port,sizeof(char),2,fp);
T.DST_Port=DST_Port[0]*256+DST_Port[1];

printf("SRC_Port:%d\n",T.SRC_Port);
printf("DST_Port:%d\n",T.DST_Port);

fread(dont_need, sizeof(char), length[0]*256+length[1]-24,fp);
printf("Length:%d\n",I.length);}

//為UDP時,計算該SRC IP,DST IP,SRC Port,DST Port
if(I.pro[0]==17){
 printf("UDP\n");
 Ucount++;
fread(dont_need,sizeof(char),2,fp);
fread(I.SRC_IP,sizeof(char),4,fp);
printf("SRC IP:");
for(i=0;i<3;i++)
 printf("%d.",I.SRC_IP[i]);
printf("%d\n",I.SRC_IP[3]);
fread(I.DST_IP,sizeof(char),4,fp);
printf("DST IP:");
for(i=0;i<3;i++)
 printf("%d.",I.DST_IP[i]);
printf("%d\n",I.DST_IP[3]);

fread(SRC_Port,sizeof(char),2,fp);
U.SRC_Port=SRC_Port[0]*256+SRC_Port[1];
fread(DST_Port,sizeof(char),2,fp);
U.DST_Port=DST_Port[0]*256+DST_Port[1];

printf("SRC_Port:%d\n",U.SRC_Port);
printf("DST_Port:%d\n",U.DST_Port);

fread(dont_need, sizeof(char), length[0]*256+length[1]-24,fp);
printf("Length:%d\n",I.length);}
//為ICMP時,計算該SRC IP,DST IP
if(I.pro[0]==1){
 printf("ICMP\n");
 Icount++;
fread(dont_need,sizeof(char),2,fp);
fread(I.SRC_IP,sizeof(char),4,fp);
printf("SRC IP:");
for(i=0;i<3;i++)
 printf("%d.",I.SRC_IP[i]);
printf("%d\n",I.SRC_IP[3]);
fread(I.DST_IP,sizeof(char),4,fp);
printf("DST IP:");
for(i=0;i<3;i++)
 printf("%d.",I.DST_IP[i]);
printf("%d\n",I.DST_IP[3]);

fread(dont_need, sizeof(char), length[0]*256+length[1]-20,fp);
printf("Length:%d\n",I.length);}

}
num--;
printf("Packet:%d\n",Pcount);
printf("TCP:%d\n",Tcount);
printf("UDP:%d\n",Ucount);
printf("ICMP:%d\n",Icount);
fclose(fp);
return 0;
}
