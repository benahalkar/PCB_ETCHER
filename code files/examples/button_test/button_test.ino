int BUTTON = A6;
int button_state;

void setup() {
  pinMode(A6, INPUT);
  Serial.begin(9600);
}

void loop() {
  button_state = analogRead(BUTTON);
  Serial.print("button state : ");
  Serial.println(button_state);
  delay(1000);   
}
