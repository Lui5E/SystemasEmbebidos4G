#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)
#define retardo 500

void error();

void main (void){
   set_tris_a(0b00000000);
   set_tris_b(0b11110000);
   SETUP_ADC_PORTS(NO_ANALOGS);// para conversion a todos los puertos analogos a digitales
   setup_oscillator(OSC_32MHZ);
   int16 resultado=0;
   int8 operando1=0,operando2=0,operacion=0; //Variables operandos operacion
   while(True){
   operando1=input_c();
   operando2=input_d();
   if(input(PIN_B4)==1) operacion=1; //suma
   else if(input(PIN_B5)==1) operacion=2;//resta
   else if(input(PIN_B6)==1) operacion=3;//multiplicacion
   else if(input(PIN_B7)==1) operacion=4;//divicion
   if(operacion==1) resultado = operando1 + operando2;
   else if(operacion == 2) resultado = operando1 - operando2;
   else if(operacion == 3) resultado = operando1 * operando2;
   else if(operacion == 4)
   {
   if(input_d()==0) error(); //funcion de error 
   else resultado = operando1 / operando2;
   }
   output_a(resultado);
   output_b(resultado>>6);
   output_e(resultado>>10);
   } 
}   
void error()
{
   output_a(0b00111111);
   output_b(0b00001111);
   output_e(0b00001111);
   delay_ms(retardo);
   output_a(0b00000000);
   output_b(0b00000000);
   output_e(0b00001000);
   delay_ms(retardo);
}
