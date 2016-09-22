//
// VirtualWire implementation to receive messages
//


#include <VirtualWire.h>

const int pin_led = 13;
const int pin_transmit = 12;
const int pin_replace = 11;
const int pin_transmit_en = 3;

void setup()
{
    Serial.println("Initialization");
	
	delay(1000);
    Serial.begin(9600);	
    
    // Initialise the IO and ISR
    vw_set_tx_pin(pin_transmit);
    vw_set_rx_pin(pin_replace);
    vw_set_ptt_pin(pin_transmit_en);
    vw_set_ptt_inverted(true); 			// Required for DR3100
    vw_setup(2000);	 					// Bits per sec

    vw_rx_start();       				// Start the receiver PLL running

    pinMode(pin_led, OUTPUT);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
		int i;

        digitalWrite(pin_led, HIGH); // Flash indicator upon message receipt

		Serial.print("Received: ");
	
		for (i = 0; i < buflen; i++)
		{
			Serial.print(char(buf[i]));
			Serial.print(' ');
		}
		
		Serial.println();
        digitalWrite(pin_led, LOW);
    }
}