#ifndef _DISPLAY_LED_
#define _DISPLAY_LED_

#include"BaseValue.h"
//==========================================================
//函 数 名: Buff_To_Seg()/Buff_To_Seg0()/Buff_To_Seg1()/Buff_To_Seg2()
//功能描述: 把四种不同的字符类型显示在led上#ifndef _DISPLAY_LED_
//输入参数: 无
//输出参数:	无
//==========================================================
void Buff_To_Seg(void)
{
	uchar i;
	for(i=0;i<4;i++)
	{
		DataPort=SegCode[DispBuff[i]];			 	//只显示数字
		ComPort=BitCode[i];
		DelayMs(1);
	}
}

void Buff_To_Seg0(void)
{
	uchar i;
	for(i=0;i<4;i++)
	{
		if(i==2)
		{	
			if(flag==1)
				DataPort=SegCode[DispBuff[i]];	
			else
	   			DataPort=SegCode[DispBuff[i]]&0x7f;	//第二个数码管同时显示小数点并闪烁（500ms亮500ms灭）
		}
		else   
			DataPort=SegCode[DispBuff[i]];
		ComPort=BitCode[i];
		DelayMs(1);
	}
}
void Buff_To_Seg1(void)
{
	uchar i;
	for(i=0;i<4;i++)
	{
		if(i==2)
		{	
	   		DataPort=SegCode[DispBuff[i]]&0x7f;		//第二个数码管同时显示小数点
		}
		else 
			DataPort=SegCode[DispBuff[i]];
		ComPort=BitCode[i];
		DelayMs(1);
	}
} 
void Buff_To_Seg2(void)
{
	uchar i;
	for(i=0;i<4;i++)
	{
		if(i==1)
			DataPort=SegCode[DispBuff[i]]&0x7f;		//第一个数码管同时显示小数点（代表分）
		else if(i==3)
			DataPort=SegCode[DispBuff[i]]&0x7f;		//第三个数码管同时显示小数点（2、3两个数码管代表秒）
		else
			DataPort=SegCode[DispBuff[i]];
		ComPort=BitCode[i];
		DelayMs(1);
	}
}

//==========================================================
//函 数 名: HouMinDiap()
//功能描述: 时分显示函数
//输入参数: 
//输出参数:	
//==========================================================
void HouMinDisp()
{
 	DispBuff[3]=Hour/10;			//时十位
	DispBuff[2]=Hour%10;			//时个位
	DispBuff[1]=Minute/10;			//分十位
  	DispBuff[0]=Minute%10;			//分个位
	Buff_To_Seg0();
}
//==========================================================
//函 数 名: YearDiap()
//功能描述: 年显示函数
//输入参数: 
//输出参数:	
//==========================================================
void YearDisp()
{
	DispBuff[3]=Year/1000;			//年千位
	DispBuff[2]=Year/100%10;		//年百位
	DispBuff[1]=Year/10%10;			//年十位
  	DispBuff[0]=Year%10;			//年个位
	Buff_To_Seg();
}
//==========================================================
//函 数 名: DataDiap()
//功能描述: 日期显示函数
//输入参数: 
//输出参数:	
//==========================================================
void DateDisp()
{
	DispBuff[3]=Month/10;			//月十位
	DispBuff[2]=Month%10;			//月个位
	DispBuff[1]=Day/10;				//日十位
	DispBuff[0]=Day%10;				//日个位
	Buff_To_Seg();
}
//==========================================================
//函 数 名: MinSecDiap()
//功能描述: 秒显示函数
//输入参数: 
//输出参数:	
//==========================================================
void MinSecDisp()
{
 	DispBuff[3]=0;			//分十位
 	DispBuff[2]=0;			//分个位
	DispBuff[1]=Second/10;			//秒十位
	DispBuff[0]=Second%10;			//秒个位
	Buff_To_Seg1();
}
//==========================================================
//函 数 名: Timekeeping()
//功能描述: 闹铃显示函数
//输入参数: 
//输出参数:	
//==========================================================
void Timekeeping()
{
 	DispBuff[3]=HourB/10;			//闹铃时十位
	DispBuff[2]=HourB%10;			//闹铃时个位
	DispBuff[1]=MinuteB/10;			//闹铃分十位
 	DispBuff[0]=MinuteB%10;			//闹铃分个位
	Buff_To_Seg1();
}
//==========================================================
//函 数 名: SecDiap()
//功能描述: 秒表显示函数
//输入参数: 
//输出参数:	
//==========================================================
void SecDisp()
{
  	DispBuff[3]=Minute1%10;			//分个位（该秒表最大计时为9分59秒9）
	DispBuff[2]=Second1/10;			//秒十位
	DispBuff[1]=Second1%10;			//秒个位
	DispBuff[0]=Counter1%10;		//计数单位
	Buff_To_Seg2();
}

void BlackDisp()
{
 	DispBuff[3]=10;			//时十位
	DispBuff[2]=10;			//时个位
	DispBuff[1]=10;			//分十位
  	DispBuff[0]=10;			//分个位
	Buff_To_Seg();
}

#endif