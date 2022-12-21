const int fan_pin = 11;
float fan_speed = 0;
float store_serial = 0;
void setup() {
 pinMode(fan_pin, OUTPUT);
 Serial.begin(9600);//open communication with fan
}

void loop() {
 check();
}


void check() {
 if (Serial.available() > 1){
  store_serial = Serial.parseFloat();//grab the input
  fan_speed = 2.55 * store_serial; //scale conversion
  
 
  if ((fan_speed < 147.9) && !(fan_speed==0)){//fan speed low fix(~58%)
    fan_speed = 150.0;
  }
  if (fan_speed > 255 ){//fan speed high fix
  
   fan_speed = 255;
  }
  
 }
analogWrite(fan_pin,fan_speed);//set fan speed
}




