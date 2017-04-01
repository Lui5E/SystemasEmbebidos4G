#include <18F4620.h>
#USE delay(clock=32000000)        //Configurando el reloj a 32Mhz
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#DEFINE Retardo  500              // Definimos 500 como "Retardo"
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void main()
  {
  int8 bit=128;                   // Declaramos bit como entero de 8 bits. Inicializamos bit a 128 (MSB)     
  set_tris_c(0);                  // Configuramos todo el PORTC como salida                                
  while(true)                     // Ciclo infinito| True = 1
    {
        output_c(bit);            //Mandamos todo el puerto C el valor de bit, lo que indicara cual pin estara activo 
        delay_ms(Retardo);        //Interrupción definitiva de 500ms 
        bit>>=1;                  //Recorremos un bit a la variable "bit" a la derecha
        if(bit==0)                //Comparación para saber si ya nos pasamos del bit LSM
        {
           bit=128;               //Regresamos al MSB
        }
    } // Fin del while(TRUE)
    
  } //Fin void m

