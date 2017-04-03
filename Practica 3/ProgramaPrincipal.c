#include <18F4620.h>
#USE delay(clock=16000000)        //Configurando el reloj a 32Mhz
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
int contadorDesvordamiento=0;
#int_TIMER0
void TIMER0_funcion(void)
{
   contadorDesvordamiento++;
}
   
   void main(void)
   {
      int contadorDesvordamiento=0;   //Variable para contabilizar en numero de veces que se ejecuta la interrupcion TIMER0
      int8 conAnilloA=0x10000000;            //Variable con el valor del valor para el contador de anillo del puerto A
      int8 conAnilloB=0x10000000;             //Variable con el valor del valor para el contador de anillo del puerto B
      int8 conAnilloC=0x10000000;             //Variable con el valor del valor para el contador de anillo del puerto C
      int8 conAnilloD=0x10000000;             //Variable con el valor del valor para el contador de anillo del puerto D
      setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);   //Configuracion de la fuente y divisor del TMR0
      enable_interrupts(int_TIMER0);  //Abilitamos la interrupcion TIMER0
      enable_interrupts(GLOBAL);      //Abilitamos las interrupciones globales
      while(1)                        //Ciclo infinito
      {
         if(contadorDesvordamiento%1)   //Cada que pase una interrupción en TMR0, se ejecuta contador de anillo del puerto A
         {
            output_a(conAnilloA);      //Imprimimos contador
            conAnilloA>>=1;            //Desplazamos el bit
            if(conAnilloA==0)          //Si el valor de conAnilloA sobrepaso el LSM, devuelbe el valor al MSB
            {
               conAnilloA=0x10000000; 
            }
         }
         if(contadorDesvordamiento%5)   //Cada cinco interrupciónes de TMR0, se ejecuta contador de anillo del puerto B
         {
            output_b(conAnilloB);      //Imprimimos contador
            conAnilloB>>=1;            //Desplazamos el bit
            if(conAnilloB==0)          //Si el valor de conAnilloB sobrepaso el LSM, devuelbe el valor al MSB
            {
               conAnilloB=0x10000000; 
            }
         }
         if(contadorDesvordamiento%10)   //Cada diez interrupciónes de TMR0, se ejecuta contador de anillo del puerto C
         {
            output_c(conAnilloC);      //Imprimimos contador
            conAnilloC>>=1;            //Desplazamos el bit
            if(conAnilloC==0)          //Si el valor de conAnilloC sobrepaso el LSM, devuelbe el valor al MSB
            {
               conAnilloC=0x10000000; 
            }
         }
         if(contadorDesvordamiento%15)   //Cada quince interrupciónes de TMR0, se ejecuta contador de anillo del puerto D
         {
            output_d(conAnilloD);      //Imprimimos contador
            conAnilloD>>=1;            //Desplazamos el bit
            if(conAnilloD==0)          //Si el valor de conAnilloD sobrepaso el LSM, devuelbe el valor al MSB
            {
               conAnilloD=0x10000000; 
            }
            contadorDesvordamiento=0;  //Devolvemos el valor del contador de desvordamientos del TMR0 a 0 para que solo cuente de 0 a 15
         }
         
      }
   }
