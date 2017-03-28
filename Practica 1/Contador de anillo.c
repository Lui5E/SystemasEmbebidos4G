#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)

void main (void){
  unsigned int8 contador=0b10000000;
   setup_oscillator(OSC_32MHZ);
   
   set_tris_d(0x00); //0b00000000
   while(true){
      output_d(contador);
      contador >>=1;
      //delay_ms(500);
      if(contador==0)
      {
      contador=128; //0b10000000 o 0x80
      }
   }
}
