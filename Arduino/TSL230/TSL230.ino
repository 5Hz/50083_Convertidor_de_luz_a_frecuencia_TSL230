
int TSL230_Pin = 4; //TSL230 output
int TSL230_s0 = 3; //TSL230 sensitivity setting 1
int TSL230_s1 = 2; //TSL230 sensitivity setting 2

int TSL230_samples = 6; //higher = slower but more stable and accurate

void setup(){
  Serial.begin(9600);
  setupTSL230();
}


void loop(){

  float lightLevel = readTSL230(TSL230_samples);
  Serial.println(lightLevel);


}

void setupTSL230(){
  pinMode(TSL230_s0, OUTPUT); 
  pinMode(TSL230_s1, OUTPUT); 

  //configure sensitivity - Can set to
  //S1 LOW  | S0 HIGH: low
  //S1 HIGH | S0 LOW:  med
  //S1 HIGH | S0 HIGH: high

  digitalWrite(TSL230_s1, LOW);
  digitalWrite(TSL230_s0, HIGH);
}



float readTSL230(int samples){
//sample light, return reading in frequency
//higher number means brighter

  float start = micros();  
  int readings = 0;

  while(readings < samples){
   pulseIn(TSL230_Pin, HIGH);
   readings ++;
  }

  float length = micros() - start;
  float freq = (1000000 / (length / samples)) * 10;

  return freq;
}
