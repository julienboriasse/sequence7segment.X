/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F25K80
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

// Déclaration des segments de l'afficheur 7 segments (de B0 à B6)
// Segments: a, b, c, d, e, f, g (dans l'ordre correspondant)
const unsigned char hex_digits[] = {
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000, // 9
    0b10001000, // A
    0b10000011, // B
    0b11000110, // C
    0b10100001, // D
    0b10000110, // E
    0b10001110  // F
};

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    // Initialisation des ports
    TRISB = 0x01;  // Configure B0 comme entrée et B1 à B7 comme sortie  // Configure le port B comme sortie
    LATB = 0x00;   // Initialise le port B à 0

    uint8_t etape = 1;
    printf("\r\n\r\nEtape 1 : Chiffres de 0 a 9\r\n");
    
    while (1) {
        
        if (etape == 1) {
            const unsigned char sequence1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            for (int i = 0; i < 10; i++) {
                // Obtenir le chiffre de la séquence
                unsigned char digit = sequence1[i];

                // Envoyer le chiffre à l'afficheur 7 segments
                LATB = ~(hex_digits[digit] << 1);  // Décalage pour utiliser B1 à B7

                // Attendre 1 seconde
                __delay_ms(1000);
            }
            etape = 0;
        }
        
        if (etape == 2) {
            const unsigned char sequence2[] = {3, 7, 9, 1, 2 ,4};
            for (int i = 0; i < 6; i++) {
                // Obtenir le chiffre de la séquence
                unsigned char digit = sequence2[i];

                // Envoyer le chiffre à l'afficheur 7 segments
                LATB = ~(hex_digits[digit] << 1);  // Décalage pour utiliser B1 à B7

                // Attendre 1 seconde
                __delay_ms(333);
            }
            etape = 0;
        }
        
        
        if (etape == 3) {
            const unsigned char sequence3[] = {1, 2, 3, 4, 5 ,6};
            for (int i = 0; i < 6; i++) {
                // Obtenir le chiffre de la séquence
                unsigned char digit = sequence3[i];

                // Envoyer le chiffre à l'afficheur 7 segments
                LATB = ~(hex_digits[digit] << 2);  // Décalage pour utiliser B1 à B7

                // Attendre 1 seconde
                __delay_ms(333);
            }
            etape = 0;
        }
        
        
        // Lecture de l'UART.
        if (EUSART1_is_rx_ready()) {
            
            char rxData = getch();

            switch (rxData) {
                case '1':
                    etape = 1;
                    printf("\r\n\r\nEtape 1 : Chiffres de 0 a 9\r\n");
                    break;
                case '2':
                    etape = 2;
                    printf("\r\n\r\nEtape 2 : Sequence de 6 chiffres\r\n");
                    break;
                case '3':
                    etape = 3;
                    printf("\r\n\r\nEtape 3 : Sequence de 1 a 6\r\n");
                    break;

            }
        }
    }

   
}
/**
 End of File
*/