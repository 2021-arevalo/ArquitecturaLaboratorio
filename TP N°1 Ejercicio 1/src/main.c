/*Ejercicio 1
Diseñe e implemente un Firmware sobre la placa STM32F4 - Discovery que controle
de manera secuencial el encendido y apagado de 4 LEDs. El tiempo de encendido/apagado entre cada led
deberá ser 300ms.
Alumna: Arevalo Daiana Marisol   MU: 01502*/

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

#pragma GCC diagnostic push

void SysTick_Handler(void)                 //genera solicitudes de interrupcion de forma regular
   {
    HAL_IncTick();
   }

void Init_GPIO_LEDS(){                          //Inicializacion de Leds
    GPIO_InitTypeDef GPIO_InitStruct = {0};
        __HAL_RCC_GPIOD_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        //leds
        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

        HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);
}
void main()
{
        HAL_Init();
        Init_GPIO_LEDS();

      while (1)
        {
    	  //Cada led cambia su estado a medida que pasan los 300 ms

    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);	// Led 12-GREEN (verde)
    	  HAL_Delay(300);   //300 ms                //genera un tiempo en ms de interrupcion en el sistema
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);	// Led 13-ORANGE (anaranjado)
    	  HAL_Delay(300);  //300 ms
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);	// Led 14-RED (rojo)
    	  HAL_Delay(300);  //300 ms
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);	// Led 15-BLUE (azul)
    	  HAL_Delay(300);  //300 ms
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
        }
}



#pragma GCC diagnostic pop
