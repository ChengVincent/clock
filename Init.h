//�����ʼ��������ʾ����ʱ����ʼ�����Լ���ʱ����
#ifndef _INIT_H_
#define _INIT_H_
#include"BaseValue.h"
 
 //==========================================================
//�� �� ��: DelayMs()
//��������: ��ʱ����  ����1ms��ʱ
//�������: �ӳ�ʱ�� n(ms)
//==========================================================
void DelayMs(uint n)
{
 	uchar j;
	while(n--)
	{
		for(j=0;j<113;j++);			//11.0592MHzʱ��ʱ����Ϊ113		  	
	}	
}

 //==========================================================
//�� �� ��: Init()/Init1()
//��������: ϵͳ��ʼ������/�����ʼ������
//==========================================================
void Init(void)
{
	flag=0;							//��ʼ����־λ
	TMOD=0x11;						//T0��ʱ��������ʽ1
	TH0=0x4C;						//50ms�жϣ�����һ��������λ��
	TL0=0x00;
	TH1=0x4C;						//50ms�ж�
	TL1=0x00;						
	EA=1;							//�����ж�
	ET0=1;							//����ʱ��T0�ж�
	ET1=1;							//����ʱ��T1�ж�
	TR0=1;							//��ʱ��T0����
	TR1=0;							//��ʱ��T0����

}

//==========================================================
//�� �� ��: InitDisp()
//��������: ��ʼ����ʾ����	����ʱ������ʾ������
//�������: ��
//�������:	��
//==========================================================
void InitDisp(void)
{
	uchar i,m;
	for(m=0;m<150;m++)
		{
		for(i=0;i<4;i++)
		{
		ComPort=BitCode[i];
		DataPort=SegCode[27-i];		 //��ʾOPEN
		DelayMs(5);
		}
		}
}  

#endif