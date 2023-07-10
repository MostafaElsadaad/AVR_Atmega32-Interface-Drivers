# AVR_Atmega32-Interface-Drivers

I wrote this driver during the NTI Automotive Embedded Software program and i wanted to make it easy as using an arduino.

**Please notice that driver is still under development and not completed but i will update it frequently**

##  MCAL Functions
Here's a quick summary of the functions i wrote, for more details please check the Readme inside the MCAL Folder
### Digital I/O
*  digitalRead()                  -  Reads the value from a specified digital pin, either HIGH or LOW.
*  digitalWrite()                 -  Write a HIGH or a LOW value to a digital pin.
*  pinMode()                      -  Configures the specified pin to behave either as an input or an output.

###  External Interrupt 0
*  EXT0_voidInit()                -  Initiates and configures EXT0
*  EXT0_voidEnable()              -  Enables EXT0
*  EXT0_voidDisable()             -  Disables EXT0
*  EXT0_voidCallBack()            -  Interrupt CallBack function
*  EXT0_voidSetSignalch()         -  Change signal sensing during runtime

###  Analog/Digtal Converter
*  ADC_Init()                     -  Initiates and configures ADC
*  ADC_Read()                     -  Reads the Value from a specified analog pin
*  ADC_voidInterrputEnable()      -  Enables ADC interrupt
*  ADC_voidAutoTrigger()          -  Enables ADC Auto Trigger
*  ADC_INT_voidCallBack()         -  ADC Interrupt CallBack function

###  General Interrupt Enable (GIE)
*  GIE_voidEnable()               -  Enables global interrupt
*  GIE_voidDisable()              -  Disables global interrupt

###  Timer0
*  TIMER0_void_Init()             - Initiates and configures Timer0
*  TIMER0_void_SetTimerReg()      - Sets Timer register(TCNT0) with a certain value
*  TIMER0_void_SetCompareVal()    - Sets Output compare register(OC0) with a certain value
*  TIMER0_void_EnableOVInt()      - Enables Timer interrupt
*  TIMER0_void_DisableOVInt()     - Disables Timer interrupt
*  TIMER0_void_EnableCTCInt()     - Enables Clear on compare(CTC) mode
*  TIMER0_void_DisableCTCInt      - Disables Clear on compare(CTC) mode
*  TIMER0_void_SetOVCallBack()    - Timer0 Overflow interrupt CallBack function
*  TIMER0_void_SetCTCCallBack()   - Timer0 CTC interrupt CallBack function
