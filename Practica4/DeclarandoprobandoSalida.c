#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT 
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(UART1,BAUD=9600,BITS=8,PARITY=N,XMIT=PIN_B0,RCV=PIN_B1,STOP=1)  
#use standard_io(b)

void main(void)
{
   //Configuraciones
   setup_oscillator(OSC_16MHZ);
   //Variables
   int8 primerOperando, segundoOperando, operacion;
   float resultado;
   char opcion;
   printf("Practica No. 4\r");
   printf("Calculadora Aritmetica \r\r");
   printf("Ingresa el primer operando \r");
   primerOperando=getch();
   printf("Ingresa el segundo operando \r");
   segundoOperando=getch();
   printf("Seleccione una operacion: \r 1)Suma  2)Resta  3)Multiplicacion  4)Division \r");
   operacion=getch();
   while(true)
   {
      getch();
      printf("Comprobando que los datos fueron ingresados %d, %d, %d ",primerOperando,segundoOperando,operacion);
   }
}
 