#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT 
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#define retardo 50
#define contadorN 10
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)

 int16 error(int &contadorError);
 
 void main (void){
    setup_oscillator(OSC_16MHZ);//16mhz
    set_tris_a(0b00000000); // output A0 A1 A2 A3 A4 A5 A6 A7
    set_tris_b(0b11110000); // output B0 B1 B2 B3 input B4 B5 B6 B7
    set_tris_c(0b11111111); // input C0 C1 C2 C3 C4 C5 C6 C7 C8 
    set_tris_d(0b11111111); // input D0 D1 D2 D3 D4 D5 D6 D7 D8 
    SETUP_ADC_PORTS(NO_ANALOGS);// para conversion a todos los puertos analogos a digitales
    int8 contadorError=1; // contador
    int16 resultado=0; // variable resultado 16 bits
    int8 operacion=0; //variable operacion
    while(True){
    if(input(PIN_B4)) operacion=1; //suma
    else if(input(PIN_B5)) operacion=2;//resta
    else if(input(PIN_B6)) operacion=3;//multiplicacion
    else if(input(PIN_B7)) operacion=4;//divicion
    if(operacion==1) resultado = (long)input_c() + (long)input_d();
    else if(operacion == 2) resultado = (long)input_c() - (long)input_d();
    else if(operacion == 3) resultado = (long)input_c() * (long)input_d();
    else if(operacion == 4)
    {
    if(input_d()==0) 
    {
       resultado=error(contadorError);  //funcion de error 
    }
    else resultado = (long)input_c() / (long)input_d();
    }
    output_a(resultado);
    output_b(resultado>>6);
    output_e(resultado>>10);
    } 
 }   
 int16 error(int &contadorError)
 {
   int16 leds=0;
   if(contadorError<contadorN)
   {
      leds=8191;
   }
   else
   {
      leds=0;
   }
   if(contador==20)
   {
      contador=0;
   }
   contadorError++;
   delay_ms(retardo);
   return leds;
}
