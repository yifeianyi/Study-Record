#include "control.h"

int error;
int Output1=7100;
int Output2=7100;
extern int sensor[9];
void TIM3_IRQHandler(void)   //TIM3中断服务函数
{
	if(TIM3->SR&0X0001)//定时器每10ms定时中断一次
	{   
		  TIM3->SR&=~(1<<0);//清除定时器三的计时标志，执行完TIM3中断服务函数里的操作后定时器会重新计时
			
		
				if( (sensor[0]==0)&&(sensor[1]&&sensor[2])&&(sensor[3]==0) ){//正中
					TIM_SetCompare2(TIM4,4500);
					TIM_SetCompare1(TIM4,4500);
					//error=0;
					//Base = 0;
				}
				//左正，右负
				else if((sensor[0]==0)&&(sensor[1]==0 && sensor[2])&&(sensor[3]==0)){
					//左小偏
					TIM_SetCompare2(TIM4,4500);//左
					TIM_SetCompare1(TIM4,5000);//右
					//error = 1;
					//Base = 0;
				}
				else if((sensor[0]==0)&&(sensor[1] && sensor[2]==0 )&&(sensor[3]==0)){
					//右小偏
					TIM_SetCompare2(TIM4,5000);//左
					TIM_SetCompare1(TIM4,4500);//右
					//error = -1;
					//Base = 0;
				}
				else if((sensor[0])&&(sensor[1]&&sensor[2]==0)&&(sensor[3]==0)){
					//左偏
					TIM_SetCompare2(TIM4,5000);//左
					TIM_SetCompare1(TIM4,6000);//右
					//error = 5;
					//a = 2;
				}
				else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2])&&(sensor[3])){
					//右偏
					TIM_SetCompare2(TIM4,6000);//左
					TIM_SetCompare1(TIM4,5000);//右
					//error = -5;
				}
				else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3])){
					//右大偏
					TIM_SetCompare2(TIM4,5000);//左
					TIM_SetCompare1(TIM4,3000);//右
					//error =  -7;
				}
				else if((sensor[0])&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3]==0)){
					//左大偏
					TIM_SetCompare2(TIM4,3000);//左
					TIM_SetCompare1(TIM4,5000);//右
				}
		
		
		
		
			
		
			//Calc();
		
			//PID值计算
//   		PID_value=Position_PD (error,0);
//		  PID_sd=Position_PID (error,0);
//		  PID_jc=Position_P (a,0);
//		
//		  Xianfu_PID();//限幅函数
//			Su();//PWM输出函数
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

