/*
 * File:   pic18f2431.c
 * Author: l2e0
 *
 * Created on May 16, 2016, 9:53 PM
 */


#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1H
#pragma config OSC = IRC         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = ON        // Internal External Oscillator Switchover bit (Internal External Switchover mode enabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bits (Brown-out Reset enabled)
// BORV = No Setting

// CONFIG2H
#pragma config WDTEN = ON       // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDPS = 32768     // Watchdog Timer Postscale Select bits (1:32768)
#pragma config WINEN = OFF      // Watchdog Timer Window Enable bit (WDT window disabled)

// CONFIG3L
#pragma config PWMPIN = OFF     // PWM output pins Reset state control (PWM outputs disabled upon Reset (default))
#pragma config LPOL = HIGH      // Low-Side Transistors Polarity (PWM0, 2, 4 and 6 are active-high)
#pragma config HPOL = HIGH      // High-Side Transistors Polarity (PWM1, 3, 5 and 7 are active-high)
#pragma config T1OSCMX = ON     // Timer1 Oscillator MUX (Low-power Timer1 operation when microcontroller is in Sleep mode)

// CONFIG3H
#pragma config MCLRE = ON       // MCLR Pin Enable bit (Enabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Low-Voltage ICSP Enable bit (Low-voltage ICSP enabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-000FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (001000-001FFF) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (002000-002FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (003000-003FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-000FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (001000-001FFF) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (002000-002FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (003000-003FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-000FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (001000-001FFF) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (002000-002FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (003000-003FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from table reads executed in other blocks)


void main(void) {
    
    
    TRISA=0x00;
    TRISB=0x00;
    TRISC=0x00;
    
    ANSEL0=0x00;

    ADCON0=0x01;
    ADCON1=0x00;            //ADCHS A/D Chanel Slect Register
    ADCON2=0x03;
    
    PORTA=0x00;
    PORTB=0x00;

    OSCCON=0x70;

    
    
    PTCON0=0x00;//1:1 Postscale 1:1 Prescale　Free-Running mode 1:1 Prescale　Free-Running mode
    PTCON1=0x80;//PWM有効 PWM time base counts up
    PWMCON0=0x30;// PWM0,PWM1,PWM2,PWM3有効　すべて相補モード
    PTPERH=0;       //PWM周期設定上位
    PTPERL=0xff;//PWM周期設定下位
    PTCON0=0x00;//1:1 Postscale 1:1 Prescale　Free-Running mode
}
