#define DDRB   (*(volatile unsigned char*)  0x24)
#define TCCR1A (*(volatile unsigned char*)  0x80)
#define TCCR1B (*(volatile unsigned char*)  0x81)
#define OCR1A  (*(volatile unsigned short*) 0x88)

void setup() {
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1A |= 0b01000000; // Toggles PB1 on compare match
  TCCR1B |= 0b00000101; // Sets the prescaler to 1024
  TCCR1B |= 0b00001000; // Enables CTC
  OCR1A = 15625;        // Sets the compare value  
  DDRB |= 0b00000010;   // Sets PB1 (pin 9) as an output
}

void loop() {}
