#include "stm32f10x.h"
#ifndef __STM32F10X_GPIO_H
#define __STM32F10X_GPIO_H
    /***********************GPIO引脚*************************/
    /*
        以下宏定义一般用于IDR or ODR的配置，所以一般16位即可
    */
    #define GPIO_PIN_0              ((uint16_t)0x0001)
    #define GPIO_PIN_1              ((uint16_t)0x0002)
    #define GPIO_PIN_2              ((uint16_t)0x0004)
    #define GPIO_PIN_3              ((uint16_t)0x0008)
    #define GPIO_PIN_4              ((uint16_t)0x0010)
    #define GPIO_PIN_5              ((uint16_t)0x0020)
    #define GPIO_PIN_6              ((uint16_t)0x0040)
    #define GPIO_PIN_7              ((uint16_t)0x0080)

    #define GPIO_PIN_8              ((uint16_t)0x0100)
    #define GPIO_PIN_9              ((uint16_t)0x0200)
    #define GPIO_PIN_10             ((uint16_t)0x0400)
    #define GPIO_PIN_11             ((uint16_t)0x0800)
    #define GPIO_PIN_12             ((uint16_t)0x1000)
    #define GPIO_PIN_13             ((uint16_t)0x2000)
    #define GPIO_PIN_14             ((uint16_t)0x4000)
    #define GPIO_PIN_15             ((uint16_t)0x8000)
    #define GPIO_PIN_ALL            ((uint16_t)0xffff)
     

    /*******************相关结构体***********************/

    typedef enum{
        GPIO_SPEED_10MHz = 1,
        GPIO_SPEED_20MHz ,
        GPIO_SPEED_50MHz ,
    }GPIOSPEED_TypeDef;

    typedef enum{
        GPIO_MODE_AIN = 0x0,
        GPIO_MODE_AIN = 0x4,
        GPIO_MODE_AIN = 0X28,
        GPIO_MODE_AIN = 0x48,

        GPIO_MODE_AIN = 0x14,
        GPIO_MODE_AIN = 0x10,
        GPIO_MODE_AIN = 0x1C,
        GPIO_MODE_AIN = 0x18
    }GPIOMODE_TypeDef;



    /************************************
     * 
     *      初始化定义结构体笔记：
     *          初始化结构体为了方便操作，
     *          把对纯寄存器操作的流畅抽象成了三个步骤
     *          1、选择Pin
     *          2、选择输出速度
     *          3、选择配置模式
     *          
     *          以上配置方式是固件库源码的定义方式，
     *          根据配置原理，完全可以分成四个步骤or三个步骤。
     *          因为该结构的作用不是对寄存器直接修改操作，
     *          而是方便人为理解、操作。后续的初始化函数
     *          只不过根据以上原理映射回CRL、CRH的配置中而已。
     * 
     ************************************/
    typedef struct 
    {
        uint16_t Pin;
        GPIOSPEED_TypeDef Speed;
        GPIOMODE_TypeDef Mode;
    }GPIO_InitTypeDef;
    

    /***********************相关库函数**************************/
     void GPIOx_Setbit(GPIO_TypeDef*GPIOx,uint16_t Pin);
     void GPIOx_Retbit(GPIO_TypeDef*GPIOx,uint16_t Pin);
     void GPIOx_Cofig(GPIO_TypeDef*GPIOx,GPIO_InitTypeDef* GPIO_Init);
#endif