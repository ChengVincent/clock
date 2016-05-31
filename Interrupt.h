
#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include"BaseValue.h"
//==========================================================
//�� �� ��: T0_Isr()/T1_Isr()
//��������: T0/T1�жϺ���
//==========================================================
void T0_Isr(void) interrupt 1
{
	Counter++;						//������λ��1
	if(Counter==20)					//20�μ���Ϊ1��
	{
		Counter=0;					//��1�������λ��0
		Second++;					//���1
		if(Second==60)				//60��Ϊһ����
		{
			Second=0;				//��1������0
			Minute++;				//�ּ�1
			if(Minute==60)			//60��ΪһСʱ
			{
				Minute=0;			//��1Сʱ����0
				Hour++;				//ʱ��1
				BEEP=!BEEP;			//������ȡ�������㱨ʱ��
				DelayMs(500);		//��ʱ500ms
				if(Hour==24)		//24СʱΪһ��
				{
					Hour=0;			//��1��ʱ��0
					Day++;			//���1
					if(Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)	//������ӹ�ϣ����ȡ���ж�
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
																								//����1
	 		   		if(Day==1)									//����һ��������
					{
	  					Month++;								//�¼�1
	  					if(Month==13)							//12����Ϊһ��
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
	TH0=0x4C;													//��װ50ms��ʱ
	TL0=0x00;
	if(Counter%10==0)
		flag=!flag;												//500ms��־λȡ��
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