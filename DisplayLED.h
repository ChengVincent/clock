#ifndef _DISPLAY_LED_
#define _DISPLAY_LED_

#include"BaseValue.h"
//==========================================================
//�� �� ��: Buff_To_Seg()/Buff_To_Seg0()/Buff_To_Seg1()/Buff_To_Seg2()
//��������: �����ֲ�ͬ���ַ�������ʾ��led��#ifndef _DISPLAY_LED_
//�������: ��
//�������:	��
//==========================================================
void Buff_To_Seg(void)
{
	uchar i;
	for(i=0;i<4;i++)
	{
		DataPort=SegCode[DispBuff[i]];			 	//ֻ��ʾ����
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
	   			DataPort=SegCode[DispBuff[i]]&0x7f;	//�ڶ��������ͬʱ��ʾС���㲢��˸��500ms��500ms��
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
	   		DataPort=SegCode[DispBuff[i]]&0x7f;		//�ڶ��������ͬʱ��ʾС����
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
			DataPort=SegCode[DispBuff[i]]&0x7f;		//��һ�������ͬʱ��ʾС���㣨����֣�
		else if(i==3)
			DataPort=SegCode[DispBuff[i]]&0x7f;		//�����������ͬʱ��ʾС���㣨2��3��������ܴ����룩
		else
			DataPort=SegCode[DispBuff[i]];
		ComPort=BitCode[i];
		DelayMs(1);
	}
}

//==========================================================
//�� �� ��: HouMinDiap()
//��������: ʱ����ʾ����
//�������: 
//�������:	
//==========================================================
void HouMinDisp()
{
 	DispBuff[3]=Hour/10;			//ʱʮλ
	DispBuff[2]=Hour%10;			//ʱ��λ
	DispBuff[1]=Minute/10;			//��ʮλ
  	DispBuff[0]=Minute%10;			//�ָ�λ
	Buff_To_Seg0();
}
//==========================================================
//�� �� ��: YearDiap()
//��������: ����ʾ����
//�������: 
//�������:	
//==========================================================
void YearDisp()
{
	DispBuff[3]=Year/1000;			//��ǧλ
	DispBuff[2]=Year/100%10;		//���λ
	DispBuff[1]=Year/10%10;			//��ʮλ
  	DispBuff[0]=Year%10;			//���λ
	Buff_To_Seg();
}
//==========================================================
//�� �� ��: DataDiap()
//��������: ������ʾ����
//�������: 
//�������:	
//==========================================================
void DateDisp()
{
	DispBuff[3]=Month/10;			//��ʮλ
	DispBuff[2]=Month%10;			//�¸�λ
	DispBuff[1]=Day/10;				//��ʮλ
	DispBuff[0]=Day%10;				//�ո�λ
	Buff_To_Seg();
}
//==========================================================
//�� �� ��: MinSecDiap()
//��������: ����ʾ����
//�������: 
//�������:	
//==========================================================
void MinSecDisp()
{
 	DispBuff[3]=0;			//��ʮλ
 	DispBuff[2]=0;			//�ָ�λ
	DispBuff[1]=Second/10;			//��ʮλ
	DispBuff[0]=Second%10;			//���λ
	Buff_To_Seg1();
}
//==========================================================
//�� �� ��: Timekeeping()
//��������: ������ʾ����
//�������: 
//�������:	
//==========================================================
void Timekeeping()
{
 	DispBuff[3]=HourB/10;			//����ʱʮλ
	DispBuff[2]=HourB%10;			//����ʱ��λ
	DispBuff[1]=MinuteB/10;			//�����ʮλ
 	DispBuff[0]=MinuteB%10;			//����ָ�λ
	Buff_To_Seg1();
}
//==========================================================
//�� �� ��: SecDiap()
//��������: �����ʾ����
//�������: 
//�������:	
//==========================================================
void SecDisp()
{
  	DispBuff[3]=Minute1%10;			//�ָ�λ�����������ʱΪ9��59��9��
	DispBuff[2]=Second1/10;			//��ʮλ
	DispBuff[1]=Second1%10;			//���λ
	DispBuff[0]=Counter1%10;		//������λ
	Buff_To_Seg2();
}

void BlackDisp()
{
 	DispBuff[3]=10;			//ʱʮλ
	DispBuff[2]=10;			//ʱ��λ
	DispBuff[1]=10;			//��ʮλ
  	DispBuff[0]=10;			//�ָ�λ
	Buff_To_Seg();
}

#endif