//
// VirtualWire implementation to transmit messages
//


#include <VirtualWire.h>

const int pin_led = 11;
const int pin_transmit = 12;
const int pin_receive = 2;
const int pin_transmit_en = 3;

void setup()
{
    // Initialise the IO and ISR
    vw_set_tx_pin(pin_transmit);
    vw_set_rx_pin(pin_receive);
    vw_set_ptt_pin(pin_transmit_en);
    vw_set_ptt_inverted(true); 			// Required for DR3100
    vw_setup(2000);       				// Bits per sec
    pinMode(pin_led, OUTPUT);
}

byte count = 1;

void loop()
{
  char msg[7] = {'m','e','s','s','a','g','e', ' '};

  msg[6] = count;
  
  digitalWrite(pin_led, HIGH); // Flash a light to show transmitting
  
  vw_send((uint8_t *)msg, 7);
  
  vw_wait_tx(); // Wait until the whole message is gone
  
  digitalWrite(pin_led, LOW);
  
  delay(1000);
  
  count = count + 1;
}