#ifndef _TIME_SET_
#define _TIME_SET_

#include"BaseValue.h"
#include"DisplayLED.h"

//==========================================================
//函 数 名: 
//功能描述: 各类事件调整函数，包括加减时间和时间显示  
//输入参数: 
//输出参数:	
//==========================================================
 void HourAddAjust()
{
	Hour++;
	if (Hour == 25)
	{
		Hour = 1;
	}
}
void HourSubAjust()
{
	if (Hour - 1 == 0)
	{
		Hour = 24;
	}
	else
	{
		Hour--;
	}
}
void HourDisplay()
{
	if (flag == 1)					  //标志位为1
	{
		DispBuff[3] = Hour / 10;	  //显示时
		DispBuff[2] = Hour % 10;
	}
	else
	{
		DispBuff[3] = 0xff;		  //数码管暗（不显示）
		DispBuff[2] = 0xff;
	}
	DispBuff[1] = Minute / 10;		  //显示分
	DispBuff[0] = Minute % 10;
	Buff_To_Seg0();
}


void MinuteAddAjust()
{
	Minute++;
	if (Minute == 60)
	{
		Minute = 0;
	}
}
void MinuteSubAjust()
{
	if (Minute== 0)
	{
		Minute = 59;
	}
	else
	{
		Minute--;
	}
}
void MinuteDisplay()
{
	DispBuff[3] = Hour / 10;		  //显示时
	DispBuff[2] = Hour % 10;
	if (flag == 1)					  //标志位为1
	{
		DispBuff[1] = Minute / 10;	  //显示分
		DispBuff[0] = Minute % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //数码管暗（不显示）
		DispBuff[0] = 0xff;
	}
	Buff_To_Seg0();
}


void SecondAddAjust()
{
	Second++;
	if (Second == 60)
	{
		Second = 0;
	}
}
void SecondSubAjust()
{
	if (Second == 0)
	{
		Second = 59;
	}
	else
	{
		Second--;
	}
}
void SecondDisplay()
{

	DispBuff[3] = 0;		  //显示分
	DispBuff[2] = 0;
	if (flag == 1)					  //标志位为1
	{
		DispBuff[1] = Second / 10;	  //显示秒
		DispBuff[0] = Second % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //数码管暗（不显示）
		DispBuff[0] = 0xff;
	}
	Buff_To_Seg1();
}

void YearAddAjust()
{
	Year++;
	if (Year == 10000)
	{
		Year=1;
	}
}
void YearSubAjust()
{
	if (Year - 1 == 0)
	{
		Year = 9999;
	}
	else
	{
		Year--;
	}
}
void YearDisplay()
{
	if (flag == 1)					  //标志位为1
	{
		DispBuff[3] = Year / 1000;			//年千位
		DispBuff[2] = Year / 100 % 10;		//年百位
		DispBuff[1] = Year / 10 % 10;			//年十位
		DispBuff[0] = Year % 10;			//年个位
	}
	else
	{
		DispBuff[3] = 0xff;		  //数码管暗（不显示）
		DispBuff[2] = 0xff;
		DispBuff[1] = 0xff;
		DispBuff[0] = 0xff;
	}
	Buff_To_Seg();
}

void MonthAddAjust()
{
	Month++;
	if (Month == 13)
	{
		Month = 1;
	}
}
void MonthSubAjust()
{
	if (Month - 1 == 0)
	{
		Month = 12;
	}
	else
	{
		Month--;
	}
}
void MonthDisplay()
{
	if (flag == 1)					  //标志位为1
	{
		DispBuff[3] = Month / 10;	  //显示月
		DispBuff[2] = Month % 10;
	}
	else
	{
		DispBuff[3] = 0xff;		  //数码管暗（不显示）
		DispBuff[2] = 0xff;
	}
	DispBuff[1] = Day / 10;			  //显示日
	DispBuff[0] = Day % 10;
	Buff_To_Seg();
}

void DayAddAjust()
{
	Day++;
	if (Month == 2&&(Year % 4 == 0 && Year % 100 != 0 )|| Year % 400 == 0)	//是闰年从哈希表中取月判断
	{
			if (monthTable[0] == Day - 1)
				Day = 1;
	}
	else
	{
		if (monthTable[Month] == Day - 1)
			Day = 1;
	}
}
void DaySubAjust()
{
if(Month == 2&&(Year % 4 == 0 && Year % 100 != 0 )|| Year % 400 == 0)
{
			if (0 == Day - 1)
				Day = monthTable[0];
}
else
{
 	if (0 == Day - 1)
	Day = monthTable[Month];
	else
	Day--;
}
}
void DayDisplay()
{
	DispBuff[3] = Month / 10;		  //显示月
	DispBuff[2] = Month % 10;
	if (flag == 1)					  //标志位为1
	{
		DispBuff[1] = Day / 10;		  //显示日
		DispBuff[0] = Day % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //显示日
		DispBuff[0] = 0xff;
	}
	Buff_To_Seg();
}

void CHourAddAjust()
{
	HourB++;
	if (HourB == 25)
	{
		HourB = 1;
	}
}
void CHourSubAjust()
{
	if (HourB - 1 == 0)
	{
		HourB = 24;
	}
	else
	{
		HourB--;
	}
}
void CHourDisplay()
{
	if (flag == 1)					  //标志位为1
	{
		DispBuff[3] = HourB / 10;	  //显示时
		DispBuff[2] = HourB % 10;
	}
	else
	{
		DispBuff[3] = 0xff;		  //数码管暗（不显示）
		DispBuff[2] = 0xff;
	}
	DispBuff[1] = MinuteB / 10;		  //显示分
	DispBuff[0] = MinuteB % 10;
	Buff_To_Seg1();
}


void CMinuteAddAjust()
{
	MinuteB++;
	if (MinuteB == 60)
	{
		MinuteB = 0;
	}
}
void CMinuteSubAjust()
{
	if (MinuteB == 0)
	{
		MinuteB = 59;
	}
	else
	{
		MinuteB--;
	}
}
void CMinuteDisplay()
{
	DispBuff[3] = HourB / 10;		  //显示时
	DispBuff[2] = HourB % 10;
	if (flag == 1)					  //标志位为1
	{
		DispBuff[1] = MinuteB / 10;	  //显示分
		DispBuff[0] = MinuteB % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //数码管暗（不显示）
		DispBuff[0] = 0xff;
	}
	Buff_To_Seg1();
}

//==========================================================
//函 数 名: SetDate()
//功能描述: 修改时间按键响应函数  
//输入参数: 
//输出参数:	
//==========================================================
void SetDate()
{
	uchar count = 0;
	uchar nowKey = 0xff;
	uchar addFlag = 0;
	uchar subFlag = 0;
	uchar oldKey= 0xff;
	while (1)
	{
		if (keyPort != nowKey)
		{
			DelayMs(4);
			if (keyPort != nowKey)
			{
				nowKey = keyPort;
				if(nowKey!=oldKey)
				{
					switch (nowKey)
					{
					case modeKey:
						while(nowKey==keyPort)
						{HourDisplay();}
						return;
						break;
					case add:
						addFlag = 1;
						break;
					case sub:
						subFlag = 1;
						break;
					case changItem:
						count++	;
						break;
					default:break;
					}
				}
			}
		}
		switch (count)
		{
		case 0:					//模式一：调时（时闪烁（500ms亮500ms灭））
		{
			if (addFlag)
			{
				HourAddAjust();
				addFlag = 0;
			}
			if (subFlag)
			{
				HourSubAjust();
				subFlag = 0;
			}
			HourDisplay();
										
		}
			break;
		case 1:					//模式二（按一下）：调分（分闪烁（500ms亮500ms灭））
		{
									if (addFlag)
									{
										MinuteAddAjust();
										addFlag = 0;
									}
									if (subFlag)
									{
										MinuteSubAjust();
										subFlag = 0;
									}
									MinuteDisplay();
		}
			break;
		case 2:						  //模式三（按二下）：调秒（秒闪烁（500ms亮500ms灭））
		{

										  if (addFlag)
										  {
											  SecondAddAjust();
											  addFlag = 0;
										  }
										  if (subFlag)
										  {
											  SecondSubAjust();
											  subFlag = 0;
										  }
										  SecondDisplay();
		}
			break;
		case 3:					//模式四（按三下）：调年（年闪烁（500ms亮500ms灭））
		{
									if (addFlag)
									{
										YearAddAjust();
										addFlag = 0;
									}
									if (subFlag)
									{
										YearSubAjust();
										subFlag = 0;
									}
									YearDisplay();
		}
			break;
		case 4:					//模式五（按四下）：调月（月闪烁（500ms亮500ms灭））
		{		
		if (addFlag)
		{
			MonthAddAjust();
			addFlag = 0;
		}
		if (subFlag)
		{
			MonthSubAjust();
			subFlag = 0;
		}
		MonthDisplay();
		}
			break;
		case 5:				//模式六（按五下）：调日（日闪烁（500ms亮500ms灭））
		{
								if (addFlag)
								{
									DayAddAjust();
									addFlag = 0;
								}
								if (subFlag)
								{
									DaySubAjust();
									subFlag = 0;
								}
								DayDisplay();
		}
			break;
		default:
			count=0;
			break;
		}
		oldKey=nowKey;
		nowKey = 0xff;
	}
}

 #endif
