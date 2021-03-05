#include<stdio.h>
#include<stdlib.h>
struct node{
 int value;
 struct node *next;
};
struct node *reverse(struct node*); //把原list倒過來
struct node *print(struct node*);  //列印list
struct node* q_sort(struct node*, struct node*);

int main(int argc,char *argv[]){
 int n=atoi(argv[1]),m=atoi(argv[2]),s=atoi(argv[3]),num,i=0;
 /*n為有幾個元素 , m為數字範圍 , s為隨機變數依據*/
 srand(s);
 struct node *head=NULL, *pivot=NULL;
 //先建立link list開頭
 for(i=0;i<n;i++){
  num=rand()%m;
  struct node *new_node=malloc(sizeof(struct node));
  //開新空間 其size為已宣告的struct大小
  new_node->value=num;
  //存隨機變數}
  new_node->next=head;
  head=new_node;
}
printf("Oringinal SLL:");
head = reverse(head);
print(head);
head=q_sort(head,NULL);
printf("Sorted SLL:");
while(1){
 if(head==NULL)  break;
 else{
  printf("%4d",head->value);
  head=head->next;
 }
}
printf("\n");
return 0;
}

struct node* reverse(struct node* head){
 if(head==NULL||head->next==NULL)
  return head;

 struct node *previous=NULL, *now=head, *preceding=head->next;
 while(preceding!=NULL){
  now->next=previous; //把now->next轉向
  previous=now; //previous往後挪
  now=preceding; //now往後挪
  preceding=preceding->next; //preceding往後挪
 }
 now->next=previous; //此時current位於最後一個node
 head=now; //更新head為now
  return head;
}

struct node * print(struct node* head){
struct node *current=head;
 while(1){
  if(current==NULL)   break;
  printf("%4d",current->value);
  current=current->next; }
 printf("\n");
}

struct node* q_sort(struct node *head,struct node  *tail)
{
 if(head == tail || head->next == tail)
  return head;
 struct node *pivot = head, *current=NULL, *previous, *pre_pivot = NULL;
 for(previous = NULL, current = head; current != tail; previous = current, current = current->next)
 {
  if(current->value < pivot->value){
   if(pivot == head) {
    previous->next = current->next;
    current->next = pivot;
    head = pre_pivot = current;
    current = previous;
   }
   else
   {
    previous->next = current->next;
    current->next = pivot;
    pre_pivot->next = current;
    pre_pivot = pre_pivot->next;
    current = previous;
   }
  }
 }
 head = q_sort(head, pivot);
 pivot->next = q_sort(pivot->next, tail);
 return head;
}
