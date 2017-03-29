#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#define retardo 500
//Faltan los fast_io
void error();

void main (void){
   setup_oscillator(OSC_16MHZ);//Generalmente este va primero
   set_tris_a(0b00000000); // output A0 A1 A2 A3 A4 A5 A6 A7
   set_tris_b(0b11110000); // output B0 B1 B2 B3 input B4 B5 B6 B7
   //Los tris de C y D?
   SETUP_ADC_PORTS(NO_ANALOGS);// para conversion a todos los puertos analogos a digitales
   
   int16 resultado=0;
   int8 operacion=0; //Variables operandos oper
   while(True){//No está identado todo el código
      if(input(PIN_B4)) operacion=1; //suma
   else if(input(PIN_B5)) operacion=2;//resta
   else if(input(PIN_B6)) operacion=3;//multiplicacion
   else if(input(PIN_B7)) operacion=4;//divicion
   if(operacion==1) resultado = (long)input_c() + (long)input_d();
   else if(operacion == 2) resultado = (long)input_c() - (long)input_d();
   else if(operacion == 3) resultado = (long)input_c() * (long)input_d();
   else if(operacion == 4)
   {
   if(input_d()==0) error() , delay_ms(2); //funcion de error 
   else resultado = (long)input_c() / (long)input_d();
   }
   output_a(resultado);
   output_b(resultado>>6);
   output_e(resultado>>10);
   } 
}   
void error()
{
   //Y si su función de error mejor solo cambia el contenido de la variable resultado? y el despliegue lo dejan igual?
   output_a(0b00111111);
   output_b(0b00001111);
   output_e(0b00001111);
   delay_ms(retardo);//Recuerden que el retardo de 500 ms es mucho, Partan el retardo a un valor mas pequeño como vimos en la clase
   output_a(0b00000000);
   output_b(0b00000000);
   output_e(0b00001000);
   delay_ms(retardo);
}
