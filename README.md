# STM32F429-BareMetal
Bare metal coding in STM32 with using Keil u-vision5.
  
  
# Setting-up Keil for STM32f429:
1. Open Keil uvision-5, go to Project->New uvision project, give a suitable name to the project.
2. It will now as you to select the device for the project, in my case, i have used STM32F429ZITx, you can choose any controller you want which is available to you.
3. It will now open a "Manage Run-Time enviornment" tab wherein, you only need to select 2 things,
   a)Board support Variant from STM32F469IDISCOVERY to STM32F429I-Discovery.
   b)CMSIS->CORE->tick
   c)Device->Startup->tick
   As we are not using any HAL drivers, we will not select any HAL apis from the Device section.
5. Now click "+" on Target 1 and right click the Source Group to add a "new item to the group" & then select .c file and name      it as main.
6. Now the first thing we need to do is open "main.c" file and write #include "stm32f429xx.h".
7. Now we can write our code by defining functions, Peripherals and pins in int main() etc.


*code for Button controlled LED.txt* contains a code where the on-board User Button has been used to toggle the on-board Green LED. you can paste the code in your project and run directly.
