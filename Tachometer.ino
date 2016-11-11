#define GND 5
#define VCC 6
#define PIN 7

uint32_t count=0;
long start=0;
void setup() {
  pinMode(GND,OUTPUT);
  pinMode(VCC,OUTPUT);
  pinMode(PIN,INPUT);

  digitalWrite(GND,LOW);
  digitalWrite(VCC,HIGH);
  
  Serial.begin(9600);
}

void loop() {
  count=0;
  Serial.println("Starting measurement for 1 second...");
  start=millis();
  while(millis()-start<1000){
    while(digitalRead(PIN)==1);
    count++;
    while(digitalRead(PIN)==0);
  }
  Serial.print("Measurement complete... Count:");
  Serial.println(count);
  while(!Serial.available());
  Serial.read();
}
