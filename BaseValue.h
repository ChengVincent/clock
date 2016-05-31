#ifndef _BASEVALUE_H_
#define	_BASEVALUE_H_


#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int

//===========================�����Ͷ˿ڶ���===========================
#define	LedNum		4			//����ܸ���4
#define	DataPort	P1		    //�ο�
#define	ComPort		P0			//λ��(4 bit)
#define keyPort     P2

#define ONOFF 0xfe  					//���ʼ��ֹͣ��
#define	RST 0xfd    					//���λ��		 
#define	showTimeKey 0xfb				//�鿴ʱ���
#define	add 0xfe						//+��
#define	sub 0xfd						//-��
#define	changItem 0xfb					//������
#define	modeKey 0xf7					//ģʽ�л���
//===========================����===========================
uchar	data	DispBuff[LedNum];		//���㻺����
uchar   Counter=0;						//��ʱ��λ����
uchar	Hour=12,Minute=1,Second=1;		//ʱ�ӱ���
uchar	Month=3,Day=26;					//�º���
uint    Year=2016;						//��
uchar	HourB=12,MinuteB=2;				//�������
uchar   Counter1=0,Minute1=0,Second1=0;		//������
uchar   flag;							//��־λ����
sbit 	BEEP = P0 ^ 4;					//�����������塢���㱨ʱ��

//=============================����������·ݱ�=============================
uchar	code SegCode[]={ 						//�����
						0xc0,0xf9,0xa4,0xb0,  	//	0-0		1-1		2-2		3-3
						0x99,0x92,0x82,0xf8,	//	4-4		5-5		6-6		7-7
						0x80,0x90,0xff,0xa0,	//	8-8		9-9		10-��	11-a
						0x83,0xc6,0xa1,0x8b,	//	12-b	13-C	14-D	15-h
						0x8e,0xc2,0xc1,0x89,	//	16-F	17-G	18-U	19-H
						0xc7,0xbf,0x91,0x92,	//	20-L	21--	22-y	23-S
						0xc0,0x8c,0x86,0xc8		//	24-0	25-p	26-E	27-n
					    };	
uchar	code BitCode[]={0xf7,0xfb,0xfd,0xfe	};//4λ����� //λ���											   
uchar   monthTable[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};  //�·ݹ�ϣ�� ����һλ������2������

#endif