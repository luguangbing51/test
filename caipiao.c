#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#define sr srand((unsigned)time(0))
void qbjx(); //全部机选
void zixuan(); // 自选函数
void jixuan(); // 机选函数
void dh(); //登陆函数
void by(); //备用函数
void djsc(int n); //兑奖输出函数
void syjs(int a[],int n); //剩余接收函数
void px(int a[],int n); //排序函数
int dj(int a[],int n); //兑奖函数
int jsgq(); //自选接收关卡
int dj(int a[],int n) /*兑奖函数*/
{
 int o[7]={1,7,14,17,21,28,35};
 int x=0,i,j,k;
 for(i=0;i<7;i++)
 for(j=0;j<n;j++)
 if(o[i]==a[j] || o[i]==a[j]-48)
 x++;
 printf("本期的中奖号码为: ");
 for(k=0;k<7;k++)
 {
 Sleep(200);
 printf("%d ",o[k]);
 }
 printf("\n\n");
return x;
}
void px(int a[],int n) /*排序函数*/
{
 int i,j,temp;
 for(i=0;i<n-1;i++)
 for(j=0;j<n-i-1;j++)
 if(a[j]>a[j+1])
 {
 temp=a[j];
 a[j]=a[j+1];
 a[j+1]=temp;
 }
}
void syjs(int a[],int n) /*剩余接收函数-递归被调函数*/
{
 int h,i;
 for(h=n;h<7;h++) /*范围判断*/
 {
 printf("请输入第%d个号码：",h+1);
 a[h]=jsgq();
 if(a[h]<36 && a[h]>0)
 {
 for(i=0;i<h;i++) /*重复判断*/
 {
 if(a[h]==a[h-i-1])
 {
 printf("您输入的号码已经存在!\n");
 syjs(a,h);break;
 }
 }
 }
 else
 {
 printf("您输入的范围有误!\n");
 syjs(a,h);break;
 }
 if(a[6]!=0) /* 根据第七个数是否被接收判断，下同*/
 break;
 else
 continue;
 }
}
int jsgq() //自选接收关卡
{
 int x;
 char b[10]={'\0'}; //接收关卡
 scanf("%s",b);
 if(b[1]=='\0')
 x=(b[0]-48);
 else
 x=(b[0]-48)*10+b[1]-48;
 if(b[2]!='\0')
 x=100;
 return x;
}
void zixuan1()
{
 int a[7]={0}; /* 数组a初始化*/
 int x,y,i,h; //其中X为正式存放临时变量
 printf("请输入第1个号码:");
 x=jsgq();
 printf("\b");
 if(0<x && x<36)
 {
 a[0]=x;
 for(h=1;h<7;h++) /*范围判断*/
 {
 printf("请输入第%d个号码:",h+1);
 a[h]=jsgq();
 if(a[h]>35 || a[h]<1)
 {
 printf("您输入的范围有误!\n");
 syjs(a,h);break;
 }
 for(i=0;i<h;i++) /*重复判断*/
 {
 if(a[h]==a[h-i-1])
 {
 printf("输入的已经存在!\n");
 syjs(a,h);break;
 }
 }
 if(a[6]!=0)
 break;
 else
 continue;
 }
 }
 else /*若第一个数接收失败，重新开始*/
 {
 printf("输入的范围有误！\n");
 system("pause");
 zixuan1();
 }
 printf("\n开始兑奖！\n");
 system("pause");
 printf("\n\n");
 px(a,7);
 printf("\n\n ");
 printf("您的自选号码为: ");
 for(i=0;i<7;i++)
 {
 Sleep(200);
 printf("%d ",a[i]);
 }
 printf("\n\n ");
 y=dj(a,7);
 djsc(y);
}
 
void zixuan() /*自选函数*/
{
 system("color 8c");
 system("title 自选模式 --c语言(www.dotcpp.com)研究中心");
 printf("您已进入自选模式\n");
 printf("请输入七个自选号码：\n");
 zixuan1();
}
void jixuan() /*机选函数*/
{
 char x;
 system("color 2f");
 system("title 机选模式 --c语言(www.dotcpp.com)研究中心");
 system("cls");
 printf("\n\n\n\n");
 printf(" ***************************************************\n");
 printf(" * *\n");
 printf(" * 选择机选模式: *\n");
 printf(" * 全部机选--请键入1 *\n");
 printf(" * *\n");
 printf(" * *\n");
 printf(" * 退出--请键入2 *\n");
 printf(" ***************************************************\n\n");
 for(;;)
 {
 x=getch();
 if(x=='1') {qbjx();break;}
 else if(x=='2'){by();break;}
 }
 system("pause");
 by();
}
void qbjx()
{
 int j,k;
 char i;
 int y,m;
 char x;
 int a[9][7];
 printf("请输入要打印的组数(1-9)：\n");
 printf("\n");
 for(;;)
 {
 i=getch();
 if(i>'0' && i<='9')
 {
 for(k=0;k<i-48;k++)
 {
 printf("<%3d >",k+1);
 for(j=0;j<7;j++)
 {
 a[k][j]=rand()%35+1;
 for(m=1;m<j+1;m++)
 {
 if(a[k][j]==a[k][j-m])
 {j--;break;}
 }
 }
 px(a[k],7); /*调用排序函数*/
 for(j=0;j<7;j++)
 printf(" %2d ",a[k][j]);
 printf("\n\n");
 }
 printf("您想要第几组号码兑奖？");
 printf("\n");
 for(;;)
 {
 x=getch();
 if(x>'0' && x<=i)
 {
 printf("\n\n ");
 Sleep(50);
 printf("您选择了第%d组号码:",x-48);
 for(j=0;j<7;j++)
 {
 Sleep(200);
 printf("%d ",a[x-48-1][j]);
 }
 printf("\n\n ");
 y=dj(a[x-48-1],7);
 djsc(y);break;
 }
 }break;
 } // if的
 } // for的
}
void dl() /*登陆界面*/
{
 int i,j,m;
 char a[100],mm[7];
 printf("\n\n\n\n");
 printf(" ************************************************************************\n");
 printf(" * *\n");
 printf(" * 欢迎使用本系统，本系统分自选和机选两种选号方式供彩民使用，登陆后可选 *\n");
 printf(" * *\n");
 printf(" ************************************************************************\n");
 printf("\n\n");
 printf(" 请输入帐号: ");
 scanf("%s",a);
 printf(" 请输入六位密码:");
 for(j=0;j<6;j++)
 {
 mm[j]=getch();
 printf("*");
 }
 printf("\n");
 printf("正在验证，请稍候...\n");
 printf(">>>>>>>>");
 for(i=0;i<70;i++) /* 控制打印<*/
 {
 Sleep(50);
 printf(">");
 }
 printf("\n");
 if(strcmp(a,"clang")==0)
 {
 printf("---------------------------------登陆成功!----------------------------------\n");
 system("pause");
 system("cls");
 }
 else
 {
 for(m=3;m>0;m--)
 {
 system("cls");
 printf("\n\n\n\n");
 printf(" ************************************************************************\n");
 printf(" * *\n");
 printf(" * 欢迎使用本系统，本系统分自选和机选两种选号方式供彩民使用，登陆后可选 *\n");
 printf(" * *\n");
 printf(" ************************************************************************\n");
 printf("\n\n");
 printf("帐号或密码错误，%d秒后重新输入！",m);
 Sleep(1000);
 }
 system("cls");
 dl();
 }
}
void hy() /*欢迎界面函数*/
{
 printf("\n\n\n\n\n\n\n");
 printf(" ============================================\n");
 printf(" ============================================\n");
 printf(" \n");
 printf(" *******欢迎使用本系统，请按任意键继续*******\n");
 printf(" \n");
 printf(" ============================================\n");
 printf(" ============================================\n");
 getch();
 system("cls");
}
void dh() /*导航界面*/
{
 char x[10];
 system("color 5f");
 system("title 选择方式 --c语言(www.dotcpp.com)研究中心");
 printf("\n\n\n\n\n\n");
 printf("\n");;
 printf(" ============================================\n");
 printf(" 请选择选号方式: \n");
 printf(" \n");
 printf(" 自选----------请输入1 \n");
 printf(" 机选----------请输入2 \n");
 printf(" 退出----------请输入3 \n");
 printf(" ============================================\n\n");
 printf("请选择要进行的操作（1或2或3），然后回车：");
 scanf("%s",x);
 if(x[0]=='1') zixuan();
 else if(x[0]=='2')
 {
 printf("您已进入机选模式\n");
 jixuan();
 }
 else if(x[0]=='3') exit(0);
 else
 {
 system("cls");
 dh();
 }
}
void djsc(int n)
{
 switch(n)
 {
 case 0: printf(" 很遗憾!您没能中奖!再接再厉! \n");break;
 case 1: printf(" 恭喜!有一个号码正确!\n");break;
 case 2: printf(" 恭喜!有两个号码正确!\n");break;
 case 3: printf(" 恭喜!您中了三个号码!\n");break;
 case 4: printf(" 恭喜恭喜!您中了四个号!\n");break;
 case 5: printf(" 恭喜恭喜!三等奖!\n");break;
 case 6: printf(" 恭喜恭喜! 二等奖!\n");break;
 default: printf(" 恭喜!恭喜!\n您的运气太好了! 恭喜您中大奖!\n");break;
 }
 printf("\n");
 printf("当前时间：");
 system("time /t"); system("date /t");
}
void by() /*备用函数*/
{
 char x;
 printf("\n\n\n");
 printf(" -------------------------------------------　\n");
 printf(" | 您希望？ | \n");
 printf(" | | \n");
 printf(" | 返回--------->请输入 q | \n");
 printf(" | | \n");
 printf(" | 退出--------->请按其他键 | \n");
 printf(" ------------------------------------------- \n");
 x=getch();
 if(x=='q')
 {
 system("cls");
 dh();
 }
 else exit(0);
}
int main() /*主函数*/
{
 sr;
 system("title 彩票35选7系统 --c语言(www.dotcpp.com)研究中心");
 system("color 1f");
 hy();
 dl();
 dh();
 printf("\n\n\n");
 system("pause");
 by();
 return 0;
}