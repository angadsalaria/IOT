// This #include statement was automatically added by the Particle IDE.
#include "ThingSpeak/ThingSpeak.h"


/* Thingspeak */
TCPClient client;
unsigned long myChannelNumber = 161078;
const char * myWriteAPIKey = "****";

void setup() {
    
    Serial.println("Beginning communication");
    
    // Connect to ThingSpeak
    ThingSpeak.begin(client);

    // Input
    double inField1 = 111;
    double inField2 = 222;

    // Set Thinkgspeak fields
    ThingSpeak.setField(1, (float) inField1);
    ThingSpeak.setField(2, (float) inField2);

    // Write fields
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    Serial.println("Ending communication");
    
}

void loop() {
    
}