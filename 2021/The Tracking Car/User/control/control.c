#include "control.h"

int error;
int Output1=7100;
int Output2=7100;
extern int sensor[9];
void TIM3_IRQHandler(void)   //TIM3�жϷ�����
{
	if(TIM3->SR&0X0001)//��ʱ��ÿ10ms��ʱ�ж�һ��
	{   
		  TIM3->SR&=~(1<<0);//�����ʱ�����ļ�ʱ��־��ִ����TIM3�жϷ�������Ĳ�����ʱ�������¼�ʱ
			
		
				if( (sensor[0]==0)&&(sensor[1]&&sensor[2])&&(sensor[3]==0) ){//����
					TIM_SetCompare2(TIM4,4500);
					TIM_SetCompare1(TIM4,4500);
					//error=0;
					//Base = 0;
				}
				//�������Ҹ�
				else if((sensor[0]==0)&&(sensor[1]==0 && sensor[2])&&(sensor[3]==0)){
					//��Сƫ
					TIM_SetCompare2(TIM4,4500);//��
					TIM_SetCompare1(TIM4,5000);//��
					//error = 1;
					//Base = 0;
				}
				else if((sensor[0]==0)&&(sensor[1] && sensor[2]==0 )&&(sensor[3]==0)){
					//��Сƫ
					TIM_SetCompare2(TIM4,5000);//��
					TIM_SetCompare1(TIM4,4500);//��
					//error = -1;
					//Base = 0;
				}
				else if((sensor[0])&&(sensor[1]&&sensor[2]==0)&&(sensor[3]==0)){
					//��ƫ
					TIM_SetCompare2(TIM4,5000);//��
					TIM_SetCompare1(TIM4,6000);//��
					//error = 5;
					//a = 2;
				}
				else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2])&&(sensor[3])){
					//��ƫ
					TIM_SetCompare2(TIM4,6000);//��
					TIM_SetCompare1(TIM4,5000);//��
					//error = -5;
				}
				else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3])){
					//�Ҵ�ƫ
					TIM_SetCompare2(TIM4,5000);//��
					TIM_SetCompare1(TIM4,3000);//��
					//error =  -7;
				}
				else if((sensor[0])&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3]==0)){
					//���ƫ
					TIM_SetCompare2(TIM4,3000);//��
					TIM_SetCompare1(TIM4,5000);//��
				}
		
		
		
		
			
		
			//Calc();
		
			//PIDֵ����
//   		PID_value=Position_PD (error,0);
//		  PID_sd=Position_PID (error,0);
//		  PID_jc=Position_P (a,0);
//		
//		  Xianfu_PID();//�޷�����
//			Su();//PWM�������
		}
}

void check(void){
	if(Output1 < 5000 || Output2 <5000){
		Output1+=500;
		Output2+=500;
	}
}

void Calc(void){
		if(error>0){
			Output1-=error;
		}
		else{
			Output2-=error;
		}
		check();
		
		TIM_SetCompare2(TIM4,Output2);
		TIM_SetCompare1(TIM4,Output1);
}

