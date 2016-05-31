
#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include"BaseValue.h"
//==========================================================
//函 数 名: T0_Isr()/T1_Isr()
//功能描述: T0/T1中断函数
//==========================================================
void T0_Isr(void) interrupt 1
{
	Counter++;						//计数单位加1
	if(Counter==20)					//20次计数为1秒
	{
		Counter=0;					//满1秒计数单位置0
		Second++;					//秒加1
		if(Second==60)				//60秒为一分钟
		{
			Second=0;				//满1分秒置0
			Minute++;				//分加1
			if(Minute==60)			//60分为一小时
			{
				Minute=0;			//满1小时分置0
				Hour++;				//时加1
				BEEP=!BEEP;			//蜂鸣器取反（整点报时）
				DelayMs(500);		//延时500ms
				if(Hour==24)		//24小时为一天
				{
					Hour=0;			//满1天时置0
					Day++;			//天加1
					if(Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)	//是闰年从哈希表中取月判断
					{
						if(Month==2)
						{
							 if(monthTable[0]==Day-1)
						 	{
						 	Day=1;
							 Month++;
						 	}
						}													
					}
					else
					{
						 if(monthTable[Month]==Day-1)
					 	 {
						 Day=1;
				  	   	Month++;
					 	 }
					}
																								//天置1
	 		   		if(Day==1)									//满足一个月条件
					{
	  					Month++;								//月加1
	  					if(Month==13)							//12个月为一年
	  					{
						   Year++;
						   if(Year>9999)
						   Year=9999;
						}
					}
				}
			}
		}
	}
	TH0=0x4C;													//重装50ms定时
	TL0=0x00;
	if(Counter%10==0)
		flag=!flag;												//500ms标志位取反
}	
void T1_Isr(void) interrupt 3
{
	Counter1++;
	if(Counter1==20)
	{
		Counter1=0;
		Second1++;
		if(Second1==60)
		{
			Second1=0;
			Minute1++;
			if(Minute1==10)
			{
				Minute1=0;
			}

		}
	}
	TH1=0x4C;
	TL1=0x00;
}

#endif