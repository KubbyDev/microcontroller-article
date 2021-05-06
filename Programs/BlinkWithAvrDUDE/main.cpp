#define DDRD   (*(volatile unsigned char*)  0x2A)
#define PORTD  (*(volatile unsigned char*)  0x2B)
#define TCCR1A (*(volatile unsigned char*)  0x80)
#define TCCR1B (*(volatile unsigned char*)  0x81)
#define TIMSK1 (*(volatile unsigned char*)  0x6F)
#define OCR1A  (*(volatile unsigned short*) 0x88)
#define SREG   (*(volatile unsigned char*)  0x5F)

int main() {
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= 0b00000101; // Sets the prescaler to 1024
  TCCR1B |= 0b00001000; // Enables CTC
  OCR1A = 15625;        // Sets the compare value
  TIMSK1 |= 0b00000010; // Enables the interruption on compare match A
  DDRD |= 0b00000100;   // Sets PD2 (pin 2) as an output
  SREG |= 0b10000000;   // Enable global interruptions
  while(true);
}

// This function will be called when the interruption is triggered
extern "C" void __vector_11() __attribute__((signal,used,externally_visible)); void __vector_11() {
  PORTD ^= 0b00000100;  // Toggles PD2 (pin 2)
}