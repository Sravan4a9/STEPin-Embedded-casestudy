#include "project_config.h"

#include "delay.h"
#include "led.h"

#include "activity_1.h"
#include "activity_2.h"
#include "activity_3.h"


int main(void)
{
    uint16_t temp;
    activity_1();       // Calling activity_1 function 
    activity_2();       // Calling activity_2 function
    activity_3();       // Calling activity_3 function
    

    while(1)
    {
        if((SW_PIN&(1<<SW2_PORT))==0)
        {
            if((SW_PIN&(1<<SW1_PORT))==0)
            {
                change_led_state(LED_ON);
				//delay_ms(LED_ON_TIME);
                temp=ReadADC(0);
                Output_Compare_Register_1_A = temp;
                if(temp<=200)
                {
                    unsigned char str1[]="20 degree Celsius\n";
                    int i=0;
                    /* Transmitting data to controller */
                    while(str1[i])
                    {
                         /* USART Control and Status Register  and USART I/O Data Register */
                        while(!(UCSR0A&(1<<UDRE0)));
                        UDR0 = str1[i];
                        i++;
                    }
                }
                else if(temp>=210 && temp<=500)
                {
                    unsigned char str2[]="25 degree Celsius\n";
                    int i=0;
                    /* Transmitting data to controller */
                    while(str2[i])
                    {
                        /* USART Control and Status Register  and USART I/O Data Register */
                        while(!(UCSR0A&(1<<UDRE0)));
                        UDR0 = str2[i];
                        i++;
                    }
                }
                else if(temp>=510 && temp<=700)
                {
                    unsigned char str3[]="29 degree Celsius\n";
                    int i=0;
                    /* Transmitting data to controller */
                    while(str3[i])
                    {
                        /* USART Control and Status Register  and USART I/O Data Register */
                        while(!(UCSR0A&(1<<UDRE0)));
                        UDR0 = str3[i];
                        i++;
                    }
                }
                else if(temp>=710 && temp<=1024)
                {
                    unsigned char str4[]="33 degree Celsius\n";
                    int i=0;
                    /* Transmitting data to controller */
                    while(str4[i])
                    {
                        /* USART Control and Status Register  and USART I/O Data Register */
                        while(!(UCSR0A&(1<<UDRE0)));
                        UDR0 = str4[i];
                        i++;
                    }
                }
            }
            else
            {
                change_led_state(LED_OFF);
				delay_ms(LED_OFF_TIME);
            }
        }
        else
        {
            change_led_state(LED_OFF);
			delay_ms(LED_OFF_TIME);
        }
    }
    return 0;
}