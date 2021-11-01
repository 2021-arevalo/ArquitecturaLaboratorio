/*Ejercicio 2
Diseñe e implemente un Firmware sobre la placa STM32F4 que haga parpadear un led con un
periodo de 100 ms. El sistema debe permitir seleccionar uno de entre 4 de los leds disponibles
empleando un pulsador.
Pulsador: Selecciona LED BLUE
Alumna: Arevalo Daiana Marisol  M.U: 01502*/

#include <stdio.h>                       //librerias:
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

#pragma GCC diagnostic push

void main()
{
        HAL_Init();
        Init_GPIO_LEDS();

      while (1)
        {
   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);     // Led 14-RED (rojo)
   HAL_Delay(100);  //100 ms                               //genera un tiempo en ms de interrupcion en el sistema
   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
   HAL_Delay(100);


   if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1){

   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);    // Led 15-BLUE (azul)
   }
   else{
   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

   }
        }
}

void SysTick_Handler(void)                //genera solicitudes de interrupcion de forma regular
{
    HAL_IncTick();
}

void Init_GPIO_LEDS(){                         //inicializa los leds y el pulsador
    GPIO_InitTypeDef GPIO_InitStruct = {0};
        __HAL_RCC_GPIOD_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        // Inicializamos los Leds
        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

        HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);

        // Inicializamos el Pulsador
        GPIO_InitStruct.Pin = GPIO_PIN_0;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;

        HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}

#pragma GCC diagnostic pop
