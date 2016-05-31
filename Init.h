//保存初始化启动显示，定时器初始化，以及延时函数
#ifndef _INIT_H_
#define _INIT_H_
#include"BaseValue.h"
 
 //==========================================================
//函 数 名: DelayMs()
//功能描述: 延时函数  产生1ms延时
//输入参数: 延迟时间 n(ms)
//==========================================================
void DelayMs(uint n)
{
 	uchar j;
	while(n--)
	{
		for(j=0;j<113;j++);			//11.0592MHz时延时常数为113		  	
	}	
}

 //==========================================================
//函 数 名: Init()/Init1()
//功能描述: 系统初始化函数/秒表初始化函数
//==========================================================
void Init(void)
{
	flag=0;							//初始化标志位
	TMOD=0x11;						//T0定时器工作方式1
	TH0=0x4C;						//50ms中断（产生一个计数单位）
	TL0=0x00;
	TH1=0x4C;						//50ms中断
	TL1=0x00;						
	EA=1;							//开总中断
	ET0=1;							//开定时器T0中断
	ET1=1;							//开定时器T1中断
	TR0=1;							//定时器T0启动
	TR1=0;							//定时器T0启动

}

//==========================================================
//函 数 名: InitDisp()
//功能描述: 初始化显示函数	启动时最先显示该内容
//输入参数: 无
//输出参数:	无
//==========================================================
void InitDisp(void)
{
	uchar i,m;
	for(m=0;m<150;m++)
		{
		for(i=0;i<4;i++)
		{
		ComPort=BitCode[i];
		DataPort=SegCode[27-i];		 //显示OPEN
		DelayMs(5);
		}
		}
}  

#endif