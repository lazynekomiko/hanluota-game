#include<stdio.h>
#include <stdlib.h>
#include<math.h>
int i=0,data[3][8]={0};//data数组用于储存座上每一个小节的信息 
char through=0;//用于在展示部分选择是否一次性显示全部步骤 
int main()
{char choose,number,origin,end;//choose用于选择展示步骤或开始游戏 ,origin和end分别用于在游戏中表示移动的起点和终点,number用于选择层数 
char minimum,n;//minimum用于提示玩家最少次数  
void hanoi(int number,char stick1,char stick2,char stick3);
void move(char x,char y);
void represent(); 
int check1(int x);
int check0(int x);
int turn(char x);
printf("古代有一个梵塔，塔内有3个座A,B,C,一个老和尚想把n个盘子从A座移到C座\n但规定每次只能移动一个，且移动过程中3个座上都始终保持大盘在下，小盘在上\n现由你来移动n个盘子\n接下来输入汉罗塔的层数（1-7）\n");
scanf("%d",&number);
for(n=7;n!=7-number;n--)
{data[0][n]=n; 

}
represent();//用于显示number层数的初始状态 
printf("输入r来展示步骤，输入p来开始游戏\n"); 
scanf(" %c",&choose);
if(choose=='r')
{printf("按下回车展示下一步,输入a可直接展示全部步骤\n");
getchar();
hanoi(number,'A','B','C');
}//用于展示步骤 
else {if(choose=='p')
{printf("游戏开始\n输入A,B,C来移动盘子\n例：输入A B为A=>B\n"); 
for(;data[2][8-number]!=8-number;)
{
scanf(" %c %c",&origin,&end);
if(data[turn(end)][check1(turn(end))]!=0)//当座上无盘子时，跳过规则的判断 
{
if(data[turn(origin)][check1(turn(origin))]<data[turn(end)][check1(turn(end))])//大盘在上小盘在下的判断 
{if(data[turn(origin)][check1(turn(origin))]!=0){i++;}//此处i用于计数 
move(origin,end);
system("cls");
represent();
printf("\n次数%d\n",i);//清屏后显示一次移动后的状态 
}
else{printf("\n较大的层不能放在较小层上面\n");}
}
else
{if(data[turn(origin)][check1(turn(origin))]!=0){i++;}
move(origin,end);
system("cls");
represent();
printf("\n次数%d\n",i);//无规则判断执行部分 
}
}
if(data[2][8-number]==8-number) //游戏胜利条件的判断 
{
printf("你赢了");
if(i!=pow(2,number)-1)
{
printf("，但可以次数可以更少\n%d层的最少步骤为%d",number,minimum=pow(2,number)-1);//判断是否是次数最少 
}
}
}
else
{
printf("请输入r来展示步骤，或p进行游戏") ; //开始时输入其它字符则显示此处 
}
}


printf("\n");
}
//------------------------------------------------------------------------------------------------
void hanoi(int number,char stick1,char stick2,char stick3)//汉诺塔基本函数 
{int check(int x);void move(char x,char y);void represent();
int k;
if(number==1)
{
if(through!='a')
{
scanf("%c",&through); 
system("cls");//清屏以达似动态效果 
}
printf("%c=>%c 次数=%d\n",stick1,stick3,++i);
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
printf("%c=>%c 次数=%d\n",stick1,stick3,++i);
move(stick1,stick3);
represent();
hanoi(number-1,stick2,stick1,stick3);
}
}
//------------------------------------------------------------------------------ 
void represent()//用于显示全部的小节 
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
void show(int x)//将数组中对应的数字转化为图像显示 
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
int check1(int x)//自上而下检测座上第一个不为零的数组元素 
{int k;
for(k=0;data[x][k]==0&&k!=7;k++);
return k;
}
//---------------------------------------------------------------------------------
int check0(int x)//自下而上检测座上第一个为零的数组元素 
{int k;
for(k=7;data[x][k]!=0;k--);
return k;
}
//---------------------------------------------------------------------------------
int turn(char x)//将A,B,C座分别转化为数组对应的行 
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
void move(char x,char y)//用于移动盘子 
{int check1(int x);int check0(int x);
int turn(char x);
data[turn(y)][check0(turn(y))]=data[turn(x)][check1(turn(x))];
data[turn(x)][check1(turn(x))]=0;
}
