int ADC1 = A0;
int ADC2 = A1;
int ADC3 = A2;
int adcval1, adcval2, adcval3 ;

void setup() {
  pinMode(ADC1, INPUT);
  pinMode(ADC2, INPUT);
  pinMode(ADC3, INPUT);
  Serial.begin(9600);
}

void loop() {
  adcval1 = analogRead(ADC1);  
  adcval2 = analogRead(ADC2);  
  adcval3 = analogRead(ADC3);  
  
  Serial.print("ADC channel raw value: ");
  Serial.print(adcval1);
  Serial.print(" | ADC channe2 raw value: ");
  Serial.print(adcval2);
  Serial.print(" | ADC channe3 raw value: ");
  Serial.println(adcval3);
  delay(1000);
}
