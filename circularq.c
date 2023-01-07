#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int q[10];
int rear=0,front=0;
void insertq(int item)
{
int rl=rear;
rl=(rl+1)%10;
if(rl==front)
printf("Queue is full");
else
{
rear=rl;
q[rear]=item;
}
}
int deleteq1(int*status)
{
if(front==rear)
{
printf(" queue is empty");
*status=0;
}
else
{
front=(front+1)%10;
*status=1;
return q[front];
}
}
int searchq(int item)
{
int t;
t=front;
t=(t+1)%10;
while(t!=rear&&q[t]!=item)
t=(t+1)%10;
if(q[t]==item)
return t+1;
else
return 0;
}
void main ()
{
int item,opt,ans,status;
do
{
printf(" \n 1. insert \n ");
printf(" \n 2. delete \n ");
printf(" \n 3.search \n ");
printf(" \n 4.exit \n ");
printf("enter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("data:");
scanf("%d",&item);
insertq(item);
break;
case 2:item=deleteq1(&status);
if(status==1)
printf("deleted=%d",item);
break;
case 3:printf("enter the number to search:");
scanf("%d",&item);
ans=searchq(item);
if(ans==0)
printf("not found");
else
printf("item found at %d position \n",ans);
break;
case 4: exit(0);
}
}
while(1);
}

