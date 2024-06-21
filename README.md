# STM32F429-BareMetal
Bare metal coding in STM32 with using Keil u-vision5.
  
  
# Setting-up Keil for STM32f429:
1. Open Keil uvision-5, go to Project->New uvision project, give a suitable name to the project.
2. It will now as you to select the device for the project, in my case, i have used STM32F429ZITx, you can choose any controller you want which is available to you.
3. It will now open a "Manage Run-Time enviornment" tab wherein, you only need to select 2 things,
   a)Board support Variant from STM32F469IDISCOVERY to STM32F429I-Discovery.
   b)CMSIS->CORE->tick
   c)Device->Startup->tick
   As we are not using any HAL drivers, we will not select any HAL(Hardware Abstraction Layer) apis from the Device section.
5. Now click "+" on Target 1 and right click the Source Group to add a "new item to the group" & then select .c file and name it as main.
6. Now the first thing we need to do is open "main.c" file and write #include "stm32f429xx.h".
7. Now we can write our code by defining functions, Peripherals and pins in int main() etc.
8. After doing so, we need to configure the Target. "Options for Target" button which has a magic wand like icon is available just above main.c.
9. In the target we can select the ARM compiler, as well as the Freq(CLK) we want to run our system at.(Selecting XTAL/Freq is not available in Keil uvision 5 and higher),      we can also "simulate" the code(run the code without ACTUAL hardware) if we want, but that has its own limitations.
10. After this to upload the code to the STM32 Board, connect the controller with a USB-mini B to USB-A to the computer and select the Download option, which has LOAD           written over it, its shortcut is F8.

*code for Button controlled LED.txt* contains a code where the on-board User Button has been used to toggle the on-board Green LED. you can paste the code in your project and run directly.

*code_LEDblink_usingTimer.txt* contains a code where the internal timer-7, Auto-reload, Prescalers are used to generate a delay of 1 sec and toggle the on-board LED. 

*code_generating_PWM_usingTimers.txt* contains a code where the internal GenPurpose timer-2 has been used to generate a PWM signal of 500ms with also the on-board Red LED toggling at 1 sec intervals.

*UART_usingSTM.txt* contains a code where STM32 and FTDI-FT232 UBS-serial connector is used for performing Serial communication. The code, hardware connections & other information is in the UART folder.
