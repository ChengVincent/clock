#include"BaseValue.h"
#include"Init.h"
#include"Interrupt.h"
#include"DisplayLED.h"
#include"TimeSet.h"


//==========================================================
//函 数 名: StopWatch()
//功能描述: 秒表功能函数
//输入参数: 
//输出参数:	
//==========================================================
void StopWatch()
{
	uchar oldKey = 0xff;
	uchar nowKey = 0xff;
	while(1)
	{
		if (keyPort != nowKey)
		{
			DelayMs(4);
			if (keyPort != nowKey)
			{
				nowKey = keyPort;
			}
		}		   if(nowKey!=oldKey)
					{
				 	switch (nowKey)
					{
					case ONOFF:
						TR1 = !TR1;			//启动定时器T1	
						BEEP = !BEEP;			//蜂鸣器响（提示计时）
						DelayMs(8);
						SecDisp();
						break;
					case RST:
						BEEP = !BEEP;			//蜂鸣器响（提示计时）
						DelayMs(8);
						Minute1 = 0;			//将数码管显示的内容全部置0
						Second1 = 0;
						Counter1 = 0;
						SecDisp();		//刷新显示内容
						break;
					case modeKey:
						return;
						break;
						default:break;
					}
					}
					else
					{SecDisp(); }
		oldKey=nowKey;
		nowKey = 0xff;
	}
}
//==========================================================
//函 数 名: AlarmClock()
//功能描述: 闹铃函数   发出滴滴的声
//输入参数: 
//输出参数:	
//==========================================================
void AlarmClock() 
{ 
	uchar m=0; 
	uchar i=0;   
   	if(Hour==HourB&&Minute==MinuteB&&Second<10)		//时到了闹铃时间点 
 	{ 								            	//闹铃响30秒
			do
			{
					BEEP=!BEEP;
					for(i=0;i<30;i++)
					HouMinDisp();
					BlackDisp();
					BEEP=!BEEP;
					DelayMs(100);
					BEEP=!BEEP;
					for(i=0;i<30;i++)
					HouMinDisp();
					BlackDisp();
					BEEP=!BEEP;
					DelayMs(400);

			 }
	    	 while(m++<30); 			 				//闹30次结束           
	}        
} 
//==========================================================
//函 数 名: TimeShow()
//功能描述: 时间切换显示   
//输入参数: 
//输出参数:	
//==========================================================
void TimeShow()
{
	uchar count = 0;
	uchar oldKey= 0xff;
	uchar nowKey = 0xff;
	while (1)
	{
		if (keyPort != nowKey)
		{
			DelayMs(4);
			if (keyPort != nowKey)
			{
				nowKey = keyPort;
				if(nowKey!=oldKey&&nowKey == showTimeKey)
				{
					count++;
				}
			}
		}
				switch (count)
				{
					case 1:					//模式一（按一下）：显示分秒
						MinSecDisp();
						break;
					case 2:					//模式二（按两下）：显示年
						YearDisp();
						break;
					case 3:					//模式三（按三下）：显示日期
						DateDisp();
						break;
					case 4:					//模式四（按四下）：显示闹铃时间
						Timekeeping();
						break;
					default:
						while(nowKey==keyPort)
						{HouMinDisp();}
						return;
						break;
				}
		oldKey=nowKey;
		nowKey = 0xff;
	}
}

//==========================================================
//函 数 名: SetClock
//功能描述: 调整时间函数   
//输入参数: 
//输出参数:	
//==========================================================
void SetClock()
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
						{SecDisp();}	
						return;
						break;
					case add:
						addFlag = 1;
						break;
					case sub:
						subFlag = 1;
						break;
					case changItem:
						count++;
						break;
					default:break;
					}
				}
				
			}
		}
		switch (count)
		{
		case 0:
			if (addFlag)
			{
				CHourAddAjust();
				addFlag = 0;
			}
			if (subFlag)
			{
				CHourSubAjust();
				subFlag = 0;
			}
			CHourDisplay();
			break;
		case 1:
			if (addFlag)
			{
				CMinuteAddAjust();
				addFlag = 0;
			}
			if (subFlag)
			{
				CMinuteSubAjust();
				subFlag = 0;
			}
			CMinuteDisplay();
			break;
		default:
			count=0;
			break;
		}
		oldKey=nowKey;
		nowKey = 0xff;
	}
}

 //==========================================================
//函 数 名: ModeSelect
//功能描述: 模式切换函数   
//输入参数: 
//输出参数:	
//==========================================================
void ModeSelect()
{
	uchar count = 0;
	uchar oldKey= 0xff;
	uchar nowKey = 0xff;
	while (1)
	{
		if (keyPort != nowKey)
		{
			DelayMs(4);
			if (keyPort != nowKey)
			{
				nowKey = keyPort;
				if(nowKey!=oldKey&&nowKey == modeKey)
				{
					count++;
				}
			}
		}
					switch (count)
					{
					case 1:
						while(nowKey==keyPort)
							{HourDisplay();}
						SetDate();
						count++;
						break;
					case 2:
						SetClock();
						count++;
						break;
					case 3:
						while(nowKey==keyPort)
						{SecDisp();}						         
						StopWatch();
						count++;
						break;
					default:
					while(nowKey==keyPort)
						{HouMinDisp();}
						return;
					break;
					}
		oldKey=nowKey;
		nowKey = 0xff;
	}
}
 //==========================================================
//函 数 名: CheckKey
//功能描述: 主界面按键检测函数   
//输入参数: 
//输出参数:	
//==========================================================
void CheckKey()
{
	uchar nowKey = 0xff;
	if (keyPort != nowKey)
	{
		DelayMs(4);
		if (keyPort != nowKey)
		{
			nowKey = keyPort;
			//while (nowKey == keyPort);
			switch (nowKey)
			{
			case modeKey:
				ModeSelect();
				break;
			case showTimeKey:
				TimeShow();
				break;
			default:
				HouMinDisp();
			break;
			}
		}
	}
	nowKey = 0xff;
}
//==========================================================
//函 数 名: main()
//功能描述: 主函数   
//输入参数: 无
//输出参数:	无
//==========================================================
void main(void)
{
	InitDisp();					//显示初始化函数
	Init();						//初始化
	while(1)					
	{
			AlarmClock(); 			//闹铃函数
			CheckKey();
			HouMinDisp();
	}
}

