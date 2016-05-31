#ifndef _BASEVALUE_H_
#define	_BASEVALUE_H_


#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int

//===========================常量和端口定义===========================
#define	LedNum		4			//数码管个数4
#define	DataPort	P1		    //段口
#define	ComPort		P0			//位口(4 bit)
#define keyPort     P2

#define ONOFF 0xfe  					//秒表开始、停止键
#define	RST 0xfd    					//秒表复位键		 
#define	showTimeKey 0xfb				//查看时间键
#define	add 0xfe						//+键
#define	sub 0xfd						//-键
#define	changItem 0xfb					//调整键
#define	modeKey 0xf7					//模式切换键
//===========================变量===========================
uchar	data	DispBuff[LedNum];		//数点缓冲区
uchar   Counter=0;						//计时单位变量
uchar	Hour=12,Minute=1,Second=1;		//时钟变量
uchar	Month=3,Day=26;					//月和日
uint    Year=2016;						//年
uchar	HourB=12,MinuteB=2;				//闹铃变量
uchar   Counter1=0,Minute1=0,Second1=0;		//秒表变量
uchar   flag;							//标志位变量
sbit 	BEEP = P0 ^ 4;					//蜂鸣器（闹铃、整点报时）

//=============================数码管码表和月份表=============================
uchar	code SegCode[]={ 						//段码表
						0xc0,0xf9,0xa4,0xb0,  	//	0-0		1-1		2-2		3-3
						0x99,0x92,0x82,0xf8,	//	4-4		5-5		6-6		7-7
						0x80,0x90,0xff,0xa0,	//	8-8		9-9		10-空	11-a
						0x83,0xc6,0xa1,0x8b,	//	12-b	13-C	14-D	15-h
						0x8e,0xc2,0xc1,0x89,	//	16-F	17-G	18-U	19-H
						0xc7,0xbf,0x91,0x92,	//	20-L	21--	22-y	23-S
						0xc0,0x8c,0x86,0xc8		//	24-0	25-p	26-E	27-n
					    };	
uchar	code BitCode[]={0xf7,0xfb,0xfd,0xfe	};//4位数码管 //位码表											   
uchar   monthTable[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};  //月份哈希表 ，第一位放闰年2月天数

#endif