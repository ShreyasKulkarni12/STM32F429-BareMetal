Steps to initialize any interrupt : 

1.	Disable global interrupts (__disable_irq());
2.	Enable clock access for concerned GPIO.
3.	Select the GPIO pin as INPUT for an incoming interrupt.
4.	Enable SYSCFG(system config) clock in RCC register.
5.	Select SYSCFG->EXTICR[] acc. to your concerned pin.
6.	Unmask(enable) the particular pin from EXTI->IMR
7.	Select Falling/Rising edge trigger EXTI->FTSR
8.	Enable EXTI in NVIC (NVIC_EnableIRQ(service routine acc to NVIC vector table))
9.	Enable global interrupts
10.	Define the interrupt handler and check the EXTI->PR pin to check if interrupt has occurred or not.
11.	Define EXTI_callback if interrupt has occurred, toggle LED, send/receive UART in this callback function.
