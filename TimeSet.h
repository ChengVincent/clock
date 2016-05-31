#ifndef _TIME_SET_
#define _TIME_SET_

#include"BaseValue.h"
#include"DisplayLED.h"

//==========================================================
//�� �� ��: 
//��������: �����¼����������������Ӽ�ʱ���ʱ����ʾ  
//�������: 
//�������:	
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
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[3] = Hour / 10;	  //��ʾʱ
		DispBuff[2] = Hour % 10;
	}
	else
	{
		DispBuff[3] = 0xff;		  //����ܰ�������ʾ��
		DispBuff[2] = 0xff;
	}
	DispBuff[1] = Minute / 10;		  //��ʾ��
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
	DispBuff[3] = Hour / 10;		  //��ʾʱ
	DispBuff[2] = Hour % 10;
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[1] = Minute / 10;	  //��ʾ��
		DispBuff[0] = Minute % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //����ܰ�������ʾ��
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

	DispBuff[3] = 0;		  //��ʾ��
	DispBuff[2] = 0;
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[1] = Second / 10;	  //��ʾ��
		DispBuff[0] = Second % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //����ܰ�������ʾ��
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
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[3] = Year / 1000;			//��ǧλ
		DispBuff[2] = Year / 100 % 10;		//���λ
		DispBuff[1] = Year / 10 % 10;			//��ʮλ
		DispBuff[0] = Year % 10;			//���λ
	}
	else
	{
		DispBuff[3] = 0xff;		  //����ܰ�������ʾ��
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
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[3] = Month / 10;	  //��ʾ��
		DispBuff[2] = Month % 10;
	}
	else
	{
		DispBuff[3] = 0xff;		  //����ܰ�������ʾ��
		DispBuff[2] = 0xff;
	}
	DispBuff[1] = Day / 10;			  //��ʾ��
	DispBuff[0] = Day % 10;
	Buff_To_Seg();
}

void DayAddAjust()
{
	Day++;
	if (Month == 2&&(Year % 4 == 0 && Year % 100 != 0 )|| Year % 400 == 0)	//������ӹ�ϣ����ȡ���ж�
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
	DispBuff[3] = Month / 10;		  //��ʾ��
	DispBuff[2] = Month % 10;
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[1] = Day / 10;		  //��ʾ��
		DispBuff[0] = Day % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //��ʾ��
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
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[3] = HourB / 10;	  //��ʾʱ
		DispBuff[2] = HourB % 10;
	}
	else
	{
		DispBuff[3] = 0xff;		  //����ܰ�������ʾ��
		DispBuff[2] = 0xff;
	}
	DispBuff[1] = MinuteB / 10;		  //��ʾ��
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
	DispBuff[3] = HourB / 10;		  //��ʾʱ
	DispBuff[2] = HourB % 10;
	if (flag == 1)					  //��־λΪ1
	{
		DispBuff[1] = MinuteB / 10;	  //��ʾ��
		DispBuff[0] = MinuteB % 10;
	}
	else
	{
		DispBuff[1] = 0xff;		  //����ܰ�������ʾ��
		DispBuff[0] = 0xff;
	}
	Buff_To_Seg1();
}

//==========================================================
//�� �� ��: SetDate()
//��������: �޸�ʱ�䰴����Ӧ����  
//�������: 
//�������:	
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
		case 0:					//ģʽһ����ʱ��ʱ��˸��500ms��500ms�𣩣�
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
		case 1:					//ģʽ������һ�£������֣�����˸��500ms��500ms�𣩣�
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
		case 2:						  //ģʽ���������£������루����˸��500ms��500ms�𣩣�
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
		case 3:					//ģʽ�ģ������£������꣨����˸��500ms��500ms�𣩣�
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
		case 4:					//ģʽ�壨�����£������£�����˸��500ms��500ms�𣩣�
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
		case 5:				//ģʽ���������£������գ�����˸��500ms��500ms�𣩣�
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
