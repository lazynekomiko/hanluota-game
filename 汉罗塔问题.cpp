#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int i=0,data[3][8]={0};//data�������ڴ�������ÿһ��С�ڵ���Ϣ 
char through=0;//������չʾ����ѡ���Ƿ�һ������ʾȫ������ 
int main()
{char choose,number,origin,end;//choose����ѡ��չʾ�����ʼ��Ϸ ,origin��end�ֱ���������Ϸ�б�ʾ�ƶ��������յ�,number����ѡ����� 
char minimum,n;//minimum������ʾ������ٴ���  
void hanoi(int number,char stick1,char stick2,char stick3);
void move(char x,char y);
void represent(); 
int check1(int x);
int check0(int x);
int turn(char x);
printf("�Ŵ���һ��������������3����A,B,C,һ���Ϻ������n�����Ӵ�A���Ƶ�C��\n���涨ÿ��ֻ���ƶ�һ�������ƶ�������3�����϶�ʼ�ձ��ִ������£�С������\n���������ƶ�n������\n���������뺺�����Ĳ�����1-7��\n");
scanf("%d",&number);
for(n=7;n!=7-number;n--)
{data[0][n]=n; 

}
represent();//������ʾnumber�����ĳ�ʼ״̬ 
printf("����r��չʾ���裬����p����ʼ��Ϸ\n"); 
scanf(" %c",&choose);
if(choose=='r')
{printf("���»س�չʾ��һ��,����a��ֱ��չʾȫ������\n");
getchar();
hanoi(number,'A','B','C');
}//����չʾ���� 
else {if(choose=='p')
{printf("��Ϸ��ʼ\n����A,B,C���ƶ�����\n��������A BΪA=>B\n"); 
for(;data[2][8-number]!=8-number;)
{
scanf(" %c %c",&origin,&end);
if(data[turn(end)][check1(turn(end))]!=0)//������������ʱ������������ж� 
{
if(data[turn(origin)][check1(turn(origin))]<data[turn(end)][check1(turn(end))])//��������С�����µ��ж� 
{if(data[turn(origin)][check1(turn(origin))]!=0){i++;}//�˴�i���ڼ��� 
move(origin,end);
system("cls");
represent();
printf("\n����%d\n",i);//��������ʾһ���ƶ����״̬ 
}
else{printf("\n�ϴ�Ĳ㲻�ܷ��ڽ�С������\n");}
}
else
{if(data[turn(origin)][check1(turn(origin))]!=0){i++;}
move(origin,end);
system("cls");
represent();
printf("\n����%d\n",i);//�޹����ж�ִ�в��� 
}
}
if(data[2][8-number]==8-number) //��Ϸʤ���������ж� 
{
printf("��Ӯ��");
if(i!=pow(2,number)-1)
{
printf("�������Դ������Ը���\n%d������ٲ���Ϊ%d",number,minimum=pow(2,number)-1);//�ж��Ƿ��Ǵ������� 
}
}
}
else
{
printf("������r��չʾ���裬��p������Ϸ") ; //��ʼʱ���������ַ�����ʾ�˴� 
}
}


printf("\n");
}
//------------------------------------------------------------------------------------------------
void hanoi(int number,char stick1,char stick2,char stick3)//��ŵ���������� 
{int check(int x);void move(char x,char y);void represent();
int k;
if(number==1)
{
if(through!='a')
{
scanf("%c",&through); 
system("cls");//�����Դ��ƶ�̬Ч�� 
}
printf("%c=>%c ����=%d\n",stick1,stick3,++i);
move(stick1,stick3);
represent();
}
else
{
hanoi(number-1,stick1,stick3,stick2);
if(through!='a')
{
scanf("%c",&through); 
system("cls");
}
printf("%c=>%c ����=%d\n",stick1,stick3,++i);
move(stick1,stick3);
represent();
hanoi(number-1,stick2,stick1,stick3);
}
}
//------------------------------------------------------------------------------ 
void represent()//������ʾȫ����С�� 
{void show(int x); 
int k,n;
printf("\n\n\n\n\n\n\n\n\n\n\n") ;
for(k=0;k!=8;k++)
{for(n=0;n!=3;n++)
{show(data[n][k]); 
if(n==2){printf("\n");}
}
}
printf("\n                        A                                 B                                 C         \n");
}
//--------------------------------------------------------------------------------
void show(int x)//�������ж�Ӧ������ת��Ϊͼ����ʾ 
{
switch(x)	          
{case 7:printf("                |***************| ");break;
 case 6:printf("                 |*************|  ");break;
 case 5:printf("                  |***********|   ");break;
 case 4:printf("                   |*********|    ");break;
 case 3:printf("                    |*******|     ");break;
 case 2:printf("                     |*****|      ");break;
 case 1:printf("                      |***|       ");break;
 case 0:printf("                        |         ");break;
}                     	
} 
//---------------------------------------------------------------------------------
int check1(int x)//���϶��¼�����ϵ�һ����Ϊ�������Ԫ�� 
{int k;
for(k=0;data[x][k]==0&&k!=7;k++);
return k;
}
//---------------------------------------------------------------------------------
int check0(int x)//���¶��ϼ�����ϵ�һ��Ϊ�������Ԫ�� 
{int k;
for(k=7;data[x][k]!=0;k--);
return k;
}
//---------------------------------------------------------------------------------
int turn(char x)//��A,B,C���ֱ�ת��Ϊ�����Ӧ���� 
{
if(x=='A')
{return 0;
}
if(x=='B')
{return 1;
}
if(x=='C')
{return 2;
}
}
//---------------------------------------------------------------------------------
void move(char x,char y)//�����ƶ����� 
{int check1(int x);int check0(int x);
int turn(char x);
data[turn(y)][check0(turn(y))]=data[turn(x)][check1(turn(x))];
data[turn(x)][check1(turn(x))]=0;
}
