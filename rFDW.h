
// rFDW, a real fast way of saying realFastDigitalWrite

// One common feature of Arduino projects is that they use the digitalWrite()
// function. It's far from optimal, as Developer-X has shown here:
// 		http://developer-x.ru/2014/11/how-digitalwrite-works/
//
// He suggests that just writing to PORTD is faster and easier.
// By using rFDW you can have best of both worlds, as you're essentially just
// doing this--writing to PORTwhatever.
//
// Note that this won't work if a number of preconditions aren't met:
//    * pin shouldn't be actively working with PWM (no previous calls to
//      analogWrite)
//	  * pin should be set to output
//    * maybe something else

// There is really no code, honestly.
// All there is is just #defines.

// There is even no header guards. Define-redefine, who cares anyway.

// Thanks to Arduino pin mapping diagram there: 
//     http://academy.kaziunas.com/tutorials/images/embedded_programming/Atmega168Pinout_Arduino.png

// digitalWrite(myPin, LOW)
#define		rFDW( 0,0)		PORTD &= 0b11111110
#define		rFDW( 1,0)		PORTD &= 0b11111101
#define		rFDW( 2,0)		PORTD &= 0b11111011
#define		rFDW( 3,0)		PORTD &= 0b11110111
#define		rFDW( 4,0)		PORTD &= 0b11101111
#define		rFDW( 5,0)		PORTD &= 0b11011111
#define		rFDW( 6,0)		PORTD &= 0b10111111
#define		rFDW( 7,0)		PORTD &= 0b01111111

#define		rFDW( 8,0)		PORTB &= 0b11111110
#define		rFDW( 9,0)		PORTB &= 0b11111101
#define		rFDW(10,0)		PORTB &= 0b11111011
#define		rFDW(11,0)		PORTB &= 0b11110111
#define		rFDW(12,0)		PORTB &= 0b11101111
#define		rFDW(13,0)		PORTB &= 0b11011111

#define		rFDW(14,0)		PORTC &= 0b11111110
#define		rFDW(15,0)		PORTC &= 0b11111101
#define		rFDW(16,0)		PORTC &= 0b11111011
#define		rFDW(17,0)		PORTC &= 0b11110111
#define		rFDW(18,0)		PORTC &= 0b11101111
#define		rFDW(19,0)		PORTC &= 0b11011111

// digitalWrite(myPin, HIGH)
#define		rFDW( 0,1)		PORTD |= 0b00000001
#define		rFDW( 1,1)		PORTD |= 0b00000010
#define		rFDW( 2,1)		PORTD |= 0b00000100
#define		rFDW( 3,1)		PORTD |= 0b00001000
#define		rFDW( 4,1)		PORTD |= 0b00010000
#define		rFDW( 5,1)		PORTD |= 0b00100000
#define		rFDW( 6,1)		PORTD |= 0b01000000
#define		rFDW( 7,1)		PORTD |= 0b10000000

#define		rFDW( 8,1)		PORTB |= 0b00000001
#define		rFDW( 9,1)		PORTB |= 0b00000010
#define		rFDW(10,1)		PORTB |= 0b00000100
#define		rFDW(11,1)		PORTB |= 0b00001000
#define		rFDW(12,1)		PORTB |= 0b00010000
#define		rFDW(13,1)		PORTB |= 0b00100000

#define		rFDW(14,1)		PORTC |= 0b00000001
#define		rFDW(15,1)		PORTC |= 0b00000010
#define		rFDW(16,1)		PORTC |= 0b00000100
#define		rFDW(17,1)		PORTC |= 0b00001000
#define		rFDW(18,1)		PORTC |= 0b00010000
#define		rFDW(19,1)		PORTC |= 0b00100000

// Thanks for your attention.