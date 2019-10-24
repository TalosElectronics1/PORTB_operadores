/*
 * Rafael Lozano Rolon
 * soporte@taloselectronis.com
 * Manejo del puerto B y operaciones con bits
 * Puertos ATMEGA328
 * B (pines digitales del 8 al 13)
 * C (entradas analógicas)
 * D (pines digitales del 0 al 7) PD0 y PD1 son para TX y RX 
 */

void setup() {
  // put your setup code here, to run once:
  DDRB = 0b111111; // 13,12,11,10, 9, 8 como salidas
  PORTB= 0b101010; //  1, 0, 1, 0, 1, 0 //Enciende los pines 13,11,9
  _delay_ms(2000);//Espera 2 segundos
  PORTB=~PORTB;//Complemento a 1 (inversion de bits) de 101010=010101
  _delay_ms(2000);//Espera 2 segundos
}

void loop() {
  // put your main code here, to run repeatedly:
  int Tiempo=100;//100ms de espera
  PORTB = 0b000001;
  _delay_ms(Tiempo);
  for (int i = 0; i < 5; i++) //Repetir 5 veces desplazamiento
  {
    PORTB = PORTB << 1;//Desplazamiento a la izquierda
    _delay_ms(Tiempo);//Espera un tiempo
  }
  _delay_ms(Tiempo);
  for (int i = 0; i < 5; i++)//Repetir 5 veces desplazamiento
  {
    PORTB = PORTB >> 1;//Dsplzamiento a la derecha
    _delay_ms(Tiempo);//Espera un tiempo
  }
}
