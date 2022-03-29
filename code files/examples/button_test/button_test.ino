int BUTTON = A6;
int button_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(A6, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = analogRead(BUTTON);
  Serial.print("button detected : ");
  Serial.println(button_state);
  delay(1000);   
}
