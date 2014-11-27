
// rFDW, a real fast way of saying realFastDigitalWrite

// One common feature of Arduino projects is that they use the digitalWrite()
// function. It's far from optimal, as Developer-X has shown here:
// 		http://developer-x.ru/2014/11/how-digitalwrite-works/
//
// He suggests that just writing to PORTx is faster and easier.
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
#define		rFDW_0_0		PORTD &= 0b11111110
#define		rFDW_1_0		PORTD &= 0b11111101
#define		rFDW_2_0		PORTD &= 0b11111011
#define		rFDW_3_0		PORTD &= 0b11110111
#define		rFDW_4_0		PORTD &= 0b11101111
#define		rFDW_5_0		PORTD &= 0b11011111
#define		rFDW_6_0		PORTD &= 0b10111111
#define		rFDW_7_0		PORTD &= 0b01111111

#define		rFDW_8_0		PORTB &= 0b11111110
#define		rFDW_9_0		PORTB &= 0b11111101
#define		rFDW_10_0		PORTB &= 0b11111011
#define		rFDW_11_0		PORTB &= 0b11110111
#define		rFDW_12_0		PORTB &= 0b11101111
#define		rFDW_13_0		PORTB &= 0b11011111

#define		rFDW_14_0		PORTC &= 0b11111110
#define		rFDW_15_0		PORTC &= 0b11111101
#define		rFDW_16_0		PORTC &= 0b11111011
#define		rFDW_17_0		PORTC &= 0b11110111
#define		rFDW_18_0		PORTC &= 0b11101111
#define		rFDW_19_0		PORTC &= 0b11011111

// digitalWrite(myPin, HIGH)
#define		rFDW_0_1		PORTD |= 0b00000001
#define		rFDW_1_1		PORTD |= 0b00000010
#define		rFDW_2_1		PORTD |= 0b00000100
#define		rFDW_3_1		PORTD |= 0b00001000
#define		rFDW_4_1		PORTD |= 0b00010000
#define		rFDW_5_1		PORTD |= 0b00100000
#define		rFDW_6_1		PORTD |= 0b01000000
#define		rFDW_7_1		PORTD |= 0b10000000

#define		rFDW_8_1		PORTB |= 0b00000001
#define		rFDW_9_1		PORTB |= 0b00000010
#define		rFDW_10_1		PORTB |= 0b00000100
#define		rFDW_11_1		PORTB |= 0b00001000
#define		rFDW_12_1		PORTB |= 0b00010000
#define		rFDW_13_1		PORTB |= 0b00100000

#define		rFDW_14_1		PORTC |= 0b00000001
#define		rFDW_15_1		PORTC |= 0b00000010
#define		rFDW_16_1		PORTC |= 0b00000100
#define		rFDW_17_1		PORTC |= 0b00001000
#define		rFDW_18_1		PORTC |= 0b00010000
#define		rFDW_19_1		PORTC |= 0b00100000

// Thanks for your attention.
