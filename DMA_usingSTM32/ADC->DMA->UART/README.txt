In this program 2 DMAs and 2 different DMA Streams are used.
"DMA2_Stream0" is used to transfer data from the ADC to DMA [Periph to memory] and, the second "DMA1_Stream6" is used to transfer data
from the same memory where the ADC values have been stored to the USART2 to transmit the data. the transmitted data can be viewed in 
the Real-Term Application.
Circular DMA mode has been used to display the recieved data continously. 

There are problems with this code ATM wherein, only the 1st instance of the ADC value is stored and given to the DMA[i.e, the ADC is not running in continous mode because the feature is not available], which the DMA is transmitting. 
Though using ADC->DMA and then to USART is unneccessary, the sole purpose of the code is to understand and interface 2 peripherals using 2 DMA streams simaltenously.
