#include"stm32f10x.h"
#include"LED.h"
void Delay(){
		int i=1000;
		int j;
		while(i--){
			j=5000;
			while(j--);
		}
}
int main(void){
	
	//LED_Color_Conf(LED_R|LED_B|LED_G);
    LED_Color_Conf(LED_R);
	
	
	while(1){
		//red
	// 	LED_Red(ON)
	// 	Delay();
	// 	LED_Red(OFF)
	// 	 Delay();
		
	// 	//blue
	// 	LED_Blue(ON)
	// 	Delay();
	// 	LED_Blue(OFF)
	// 	Delay();
		
	// 	//green
	// 	LED_Green(ON)
	// 	Delay();
	// 	LED_Green(OFF)
	// 	Delay();
	 }
}
