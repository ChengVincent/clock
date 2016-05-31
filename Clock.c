#include"BaseValue.h"
#include"Init.h"
#include"Interrupt.h"
#include"DisplayLED.h"
#include"TimeSet.h"


//==========================================================
//�� �� ��: StopWatch()
//��������: ����ܺ���
//�������: 
//�������:	
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
						TR1 = !TR1;			//������ʱ��T1	
						BEEP = !BEEP;			//�������죨��ʾ��ʱ��
						DelayMs(8);
						SecDisp();
						break;
					case RST:
						BEEP = !BEEP;			//�������죨��ʾ��ʱ��
						DelayMs(8);
						Minute1 = 0;			//���������ʾ������ȫ����0
						Second1 = 0;
						Counter1 = 0;
						SecDisp();		//ˢ����ʾ����
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
//�� �� ��: AlarmClock()
//��������: ���庯��   �����εε���
//�������: 
//�������:	
//==========================================================
void AlarmClock() 
{ 
	uchar m=0; 
	uchar i=0;   
   	if(Hour==HourB&&Minute==MinuteB&&Second<10)		//ʱ��������ʱ��� 
 	{ 								            	//������30��
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
	    	 while(m++<30); 			 				//��30�ν���           
	}        
} 
//==========================================================
//�� �� ��: TimeShow()
//��������: ʱ���л���ʾ   
//�������: 
//�������:	
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
					case 1:					//ģʽһ����һ�£�����ʾ����
						MinSecDisp();
						break;
					case 2:					//ģʽ���������£�����ʾ��
						YearDisp();
						break;
					case 3:					//ģʽ���������£�����ʾ����
						DateDisp();
						break;
					case 4:					//ģʽ�ģ������£�����ʾ����ʱ��
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
//�� �� ��: SetClock
//��������: ����ʱ�亯��   
//�������: 
//�������:	
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
//�� �� ��: ModeSelect
//��������: ģʽ�л�����   
//�������: 
//�������:	
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
//�� �� ��: CheckKey
//��������: �����水����⺯��   
//�������: 
//�������:	
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
//�� �� ��: main()
//��������: ������   
//�������: ��
//�������:	��
//==========================================================
void main(void)
{
	InitDisp();					//��ʾ��ʼ������
	Init();						//��ʼ��
	while(1)					
	{
			AlarmClock(); 			//���庯��
			CheckKey();
			HouMinDisp();
	}
}

