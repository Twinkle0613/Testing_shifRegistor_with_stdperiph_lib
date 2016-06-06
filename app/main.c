
#include "GPIO_setting.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"


#define LOW 0
#define HIGH 1
void sendOnebit(FunctionalState NewState){
   if( NewState == ENABLE)    
      GPIO_SetBits(GPIOA, GPIO_Pin_7);   // send High
   else 
      GPIO_ResetBits(GPIOA, GPIO_Pin_7); // send Low
      
      GPIO_ResetBits(GPIOA, GPIO_Pin_5); // Clock Low
      GPIO_SetBits(GPIOA, GPIO_Pin_5);   // Clock High
     // GPIO_ResetBits(GPIOA, GPIO_Pin_5); // Clock Low
}

void delay(int counter)
{
    int i;
    for (i = 0; i < counter * 10000; i++) {}
}


void outData(){
      GPIO_ResetBits(GPIOA, GPIO_Pin_4); // Clock Low
      GPIO_SetBits(GPIOA, GPIO_Pin_4);   // Clock High
    //  GPIO_ResetBits(GPIOA, GPIO_Pin_4); // Clock Low
}
void GPIO_conf1(GPIO_TypeDef* GPIOx, uint16_t Pin, int Speed, int Mode){
    GPIO_InitTypeDef  gpio;
    gpio.GPIO_Pin = Pin;
    gpio.GPIO_Speed = Speed;
    gpio.GPIO_Mode = Mode;
    GPIO_Init(GPIOx,&gpio);
}
int main(void)
{
  
    //******GPIOA*******//
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOA,DISABLE);
    GPIO_conf1(GPIOA,GPIO_Pin_4,GPIO_Speed_10MHz,GPIO_Mode_Out_PP);   //SPI1_NSS
     GPIO_conf1(GPIOA,GPIO_Pin_5,GPIO_Speed_10MHz,GPIO_Mode_Out_PP);   //SPI1_SCK
     GPIO_conf1(GPIOA,GPIO_Pin_7,GPIO_Speed_10MHz,GPIO_Mode_Out_PP);   //SPI1_MOSI
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOC,DISABLE);
    GPIO_conf1(GPIOC,GPIO_Pin_13,GPIO_Speed_10MHz,GPIO_Mode_Out_PP);   //SPI1_NSS
     while(1){

      sendOnebit(HIGH);
      outData();
      sendOnebit(LOW);
      outData();
      sendOnebit(LOW);
      outData();
      sendOnebit(LOW);
      outData();
      sendOnebit(LOW);
      outData();
      sendOnebit(LOW);
      outData();
      sendOnebit(LOW);
      outData();
      sendOnebit(LOW);
       outData();

     }
}


      // GPIO_SetBits(GPIOA, GPIO_Pin_7); 
      // GPIO_SetBits(GPIOA, GPIO_Pin_4); 
      // GPIO_SetBits(GPIOA, GPIO_Pin_5); 
      // GPIO_ResetBits(GPIOA, GPIO_Pin_7); 
      // GPIO_ResetBits(GPIOA, GPIO_Pin_4); 
      // GPIO_ResetBits(GPIOA, GPIO_Pin_5); 

      //GPIO_ResetBits(GPIOC, GPIO_Pin_13); 
      //delay(100);
      //GPIO_SetBits(GPIOC, GPIO_Pin_13);
      //delay(100);

    //******GPIOc*******//

    // GPIO_InitTypeDef gpio;         //The GPIO_InitTypeDef structure can be referred by stm32f10x_gpio.h.
    
    // gpio.GPIO_Pin = GPIO_Pin_13;
    // gpio.GPIO_Speed = GPIO_Speed_50MHz;
    // gpio.GPIO_Mode = GPIO_Mode_Out_OD;
    
    
    // GPIO_Init(GPIOC,&gpio);
