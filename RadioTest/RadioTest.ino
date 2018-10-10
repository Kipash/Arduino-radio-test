#include <RCSwitch.h>

RCSwitch switchTrans = RCSwitch();
RCSwitch switchRecei = RCSwitch();

void setup() {
  switchTrans.enableTransmit(10);  // Using Pin #10
  Serial.begin(9600);
  switchRecei.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}


int cycle = 0;
void loop() {
  cycle++;

  if(cycle == 500)
  {
    cycle = 0;
    switchTrans.send("10000100011000000000010100");
  }


  if (switchRecei.available()) 
  { 
    int value = switchRecei.getReceivedValue();
    
    if (value == 0) 
    {
      Serial.print("Unknown encoding");
    } 
    else 
    {
      Serial.print("Received ");
      Serial.print( switchRecei.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( switchRecei.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( switchRecei.getReceivedProtocol() );
    }

    switchRecei.resetAvailable();
  }
}
