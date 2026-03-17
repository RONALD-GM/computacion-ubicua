int TRIG = 10;
int ECO = 9;
int LED = 3;
long DURACION;
float DISTANCIA;

void setup(){
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(TRIG, LOW);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Leer eco con timeout
  DURACION = pulseIn(ECO, HIGH, 30000);

  // Calcular distancia en cm
  DISTANCIA = DURACION / 58.2;

  Serial.print("Distancia: ");
  Serial.print(DISTANCIA);
  Serial.println(" cm");

  // Parpadear LED si objeto está cerca
  if(DISTANCIA <= 20 && DISTANCIA > 0){
    digitalWrite(LED, HIGH);
    delay(300);              
    digitalWrite(LED, LOW);
    delay(300);              
  } else {
    digitalWrite(LED, LOW); 
    delay(200);
  }
}