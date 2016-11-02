const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(analogOutPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  if (sensorValue < 700) sensorValue = 700;  
  if (sensorValue > 900) sensorValue = 900;
  outputValue = map(sensorValue, 700, 900, 255, 0);
  //if(sensorValue>900) digitalWrite (analogOutPin, LOW);
  //if(sensorValue<700) digitalWrite (analogOutPin, HIGH);
  analogWrite(analogOutPin, outputValue);
  

  // print the results to the serial monitor:
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  delay(2);
}
