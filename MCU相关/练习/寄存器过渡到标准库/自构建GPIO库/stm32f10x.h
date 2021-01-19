#ifndef __STM32F10X_H
#define __STM32F10X_H

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

/********************总线基址编号***********************/
#define PERIPHER_BASE           ((uint32_t)0x40000000)
#define PERIPHERAHB_BASE        (PERIPHER_BASE + 0x20000)
#define PERIPHERAPB2_BASE       (PERIPHER_BASE + 0x10000)

/*****************GPIO基址and时钟基址编号*********************/
#define GPIOB_BASE              (PERIPHERAPB2_BASE + 0x0C00 )
#define RCC_BASE                (PERIPHERAHB_BASE  + 0x1000 )

/***************编号转化为地址****************/
#define GPIOB                   ((GPIO_TypeDef*) GPIOB_BASE)     
#define RCC                     ((RCC_TypeDef* ) RCC_BASE)

/*****************************************
 * 
 *          volatile关键字笔记
 *      作用：
 *          编译器对访问该变量的代码就不再进行优化。
 * 
 *          当要求使用 volatile 声明的变量的值的时候，
 *          系统总是重新从它所在的内存读取数据，（即若赋值给其他变量后，调用读取i的数据可能不从i的原地址读取对应值。）
 *          即使它前面的指令刚刚从该处读取过数据。
 *          而且读取的数据立刻被保存
 * 
 *      小结：
 *          现阶段只能理解它的作用，
 *          实际用途位置
 * 
 *      实例：库函数的GPIO结构体定义方式
 *          typedef __IO volatile
            typedef struct
             {
             __IO uint32_t CRL; // 端口配置低寄存器， 地址偏移 0X00
             __IO uint32_t CRH; // 端口配置高寄存器， 地址偏移 0X04
             __IO uint32_t IDR; // 端口数据输入寄存器， 地址偏移 0X08
             __IO uint32_t ODR; // 端口数据输出寄存器， 地址偏移 0X0C
             __IO uint32_t BSRR; // 端口位设置/清除寄存器，地址偏移 0X10
             __IO uint32_t BRR; // 端口位清除寄存器， 地址偏移 0X14
             __IO uint32_t LCKR; // 端口配置锁定寄存器， 地址偏移 0X18
             } GPIO_TypeDef;
 * 
 * ***************************************/


/****************结构体设置*********************/
//GPIO
typedef struct 
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;   
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;

}GPIO_TypeDef;




//RCC
typedef struct
{
    uint32_t CRR_CR;
    uint32_t CRR_CFGR;
    uint32_t RCC_CIR;
    uint32_t RCC_APB2RSTR;
    uint32_t RCC_APB1RSTR;
    uint32_t RCC_AHBENR;
    uint32_t RCC_APB2ENR;
    uint32_t RCC_APB1ENR;
    uint32_t RCC_BDCR;
    uint32_t RCC_CSR;
}RCC_TypeDef;



void RCC_InitConfig(RCC_TypeDef*RCC_Def);



#endif
