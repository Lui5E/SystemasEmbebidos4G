#include <18F4620.h>
#include <stdlib.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT 
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(BAUD=9600,BITS=8,PARITY=N,XMIT=PIN_B0,RCV=PIN_B1,STOP=1)  
#use standard_io(b)

//Variables globales
int tamanoBufer;
char Bufer[10];
int banderaError=0;
#int_rda
void rda_isr()
{

   int posicion=-1;
   printf("Si entro\r ");
   do{
      posicion++;
      Bufer[posicion]=getc();
      //Abilitar interrupción TMR0       
      //enable_interrupts(int_TMR0);
      //Resetear TMR0 "Desde donde va a correr" 
      //set_timer0(0);
      if(((Bufer[posicion]<'0' && Bufer[posicion]>'9') && Bufer[posicion]!='-' && Bufer[posicion]!='.'))     //Si no ingreso un numero, un - o un .   El dato es incorrecto 
      {
         printf("Dato incorrecto");
         banderaError=1;
      }
   }while(Bufer[posicion]!=13 && posicion<tamanoBufer);
   //Desabiitar interrupción TMR0
   if(Bufer[posicion]==13)    Bufer[posicion]=0;
   //disable_interrupts(int_rda);
}

void main(void)
{
   //Configuraciones
   setup_oscillator(OSC_16MHZ);
   enable_interrupts(global);
   enable_interrupts(int_rda);
   SETUP_ADC_PORTS(NO_ANALOGS);
   //Variables
   inicio:   //Punto de retorno
   float primerOperando=0, segundoOperando=0, operacion=0, resultado=0;
   ////
   while(true)
   {   
      //enable_interrupts(int_rda);
      printf("Practica No. 4\r");
      printf("Calculadora Aritmetica \r\r");
      printf("Ingresa el primer operando \r");    //Indica al usuario que ingrese el primer operando
      tamanoBufer=10;                             //Asigna tananoBufer a 10 
      getc();                                    //Toque de tecla
      if(banderaError)    goto inicio;
      primerOperando=atof(Bufer);                 //Asigna la cifra casteandola a un flotante, a primer operando en "primerOperando"
      //enable_interrupts(int_rda);
      printf("%f\r",primerOperando);              //Muestra el operando ingresado
      printf("Ingresa el segundo operando \r");   //Indica al usuario que ingrese el segundo operando
      tamanoBufer=10;                             //Asigna tananoBufer a 10 
      getc();                                     //Toque de tecla           
      segundoOperando=atof(Bufer);                //Asigna la cifra casteandola a un flotante, a segundo operando en "segundoOperando"
      printf("%f\r",segundoOperando);             //Muestra el operando ingresado
      //enable_interrupts(int_rda);
      printf("Seleccione una operacion: \r 1)Suma  2)Resta  3)Multiplicacion  4)Division \r");    //Indica al usuario que selecione segun su número, una operación
      tamanoBufer=1;                              //Asigna tananoBufer a 1 
      getc();                                     //Toque de tecla
      operacion=atof(Bufer);                      //Asigna la operación casteandola a un flotante, a operacion
  
      //Saca resultado con los dos operadores ingresados y deacuerdo a la operación seleccionada
      if(operacion==1)   resultado=primerOperando+segundoOperando;          //suma
      else if(operacion==2)   resultado=primerOperando-segundoOperando;     //resta
      else if(operacion==3)   resultado=primerOperando*segundoOperando;     //multiplicacion
      else if(operacion==4)   resultado=primerOperando/segundoOperando;     //divicion
      //Muestra resultado
      printf("El resultado de la operacion es: %f\r\r",resultado);
   } 
}

