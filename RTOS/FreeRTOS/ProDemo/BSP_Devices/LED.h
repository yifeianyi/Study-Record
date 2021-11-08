#ifndef __LED_H
#define __LED_H
    #include"stm32f10x.h"


    #define LED_PORT    GPIOB
    #define LED_CLK     RCC_APB2Periph_GPIOB
    #define LED_R       GPIO_Pin_5 
    #define LED_G       GPIO_Pin_0
    #define LED_B       GPIO_Pin_1

    #define ON  1
    #define OFF 0

    #define LED_Red(a) if(a)\
                        GPIO_ResetBits(LED_PORT,LED_R);\
                    else GPIO_SetBits(GPIOB,LED_R);

    #define LED_Blue(a) if(a)\
                        GPIO_ResetBits(LED_PORT,LED_B);\
                    else GPIO_SetBits(GPIOB,LED_B);
    

    #define LED_Green(a) if(a)\
                        GPIO_ResetBits(LED_PORT,LED_G);\
                    else GPIO_SetBits(GPIOB,LED_G);
    


    void LED_Color_Conf(uint16_t Pin);
                    
    

    

#endif 
