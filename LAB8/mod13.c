#include <avr/io.h>

int main(void) {

	unsigned char inc,dec, counter, done;

	/**
	* set up inputs and outputs
	*/	
	DDRA = 0; //set A Ports as input
	DDRB = 0; //set B Ports as inputs
	
	DDRC = 0xff; //set C as output	

	//other varibles
	done = 0; 
	counter = 0;

	while (1) {

		//if increment is hit
		if( (inc = (PINA ^ 0xff)&0x01) && (done == 0)) {

			if (counter < 13) {
				counter += 1; //incremenet counter by one
			} else {
				counter = 0; //set back once counter is past 13 
			}
			done = 1; 
			
		}else if( (dec = (PINB ^ 0xff)&0x01) && (done == 0)) {

			if (counter > 0) {
				counter -= 1; //incremenet counter by one
			} else {
				counter = 13; //set back once counter is past 13 
			} 
			done = 1;	
		}
		
		//make sure clock doesnt mess up output 
		if(inc == 0 | dec == 0 ){
			done = 0;

		}
		
		//output to the LED
		PORTC = counter ^ 0xff;

	}
	
	return 0;
	

}
