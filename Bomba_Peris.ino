
#define PWM_P 4
#define EN1_P 6
#define EN2_P 8
#define PUMP_SPEED 200

void setup() {
  Serial.begin(9600);
  
  while(!Serial);

  while(Serial.available()){
    Serial.read();
  }
  
  pinMode(PWM_P, OUTPUT);
  pinMode(EN1_P, OUTPUT);
  pinMode(EN2_P, OUTPUT);
  
  Serial.print("\nEnter time (ms): ");  
}

void loop() {
  int dir;
  long tnow, t;
  static bool flag = false;
  
  if(Serial.available()){

    t = Serial.parseInt();

    digitalWrite(EN1_P, 1);
    
    analogWrite(PWM_P, PUMP_SPEED);

    tnow = millis();

    Serial.print("\nEnter time (ms): ");  

    while(Serial.available()){
      Serial.read();
    }

    flag = true;
  }

  if(tnow + t < millis() && flag){
    flag = false;
    digitalWrite(EN1_P, 0);
    digitalWrite(EN2_P, 0);
    analogWrite(PWM_P, 0);
  }
  
}
