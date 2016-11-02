const int analogInPin = A0;
int greenPin = 6;
int redPin = 9;
int bluePin = 5;

int sensorValue = 0;
int outputValue = 0;



void setup() {
  Serial.begin(9600);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  if (sensorValue < 700) sensorValue = 700;  
  if (sensorValue > 900) sensorValue = 900;
  outputValue = map(sensorValue, 700, 900, 255, 0);
  if(outputValue <= 85){//點亮綠色
    analogWrite(greenPin,255);
    analogWrite(redPin,0);
    analogWrite(bluePin,0);
  }
  else if(outputValue < 160 && outputValue > 85){//點亮紅色
    analogWrite(greenPin,0);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
  }
  else if(outputValue >= 160){//點亮藍色
    analogWrite(greenPin,0);
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
  } 
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  delay(2);
  }
