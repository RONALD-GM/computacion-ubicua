int SENSOR;
float TEMPERATURA;
float SUMA;

void setup() {
  Serial.begin(9600);
}

void loop() {
  SUMA = 0;

  for (int i = 0; i < 5; i++) {
    SENSOR = analogRead(A0);
    // LM35: voltaje en mV = (lectura * 5000) / 1023
    // Temperatura °C = voltaje / 10
    TEMPERATURA = (SENSOR * 4.88); // 5000 / 1023 ≈ 4.88 mV por unidad
    SUMA = SUMA + TEMPERATURA;
    delay(500);
  }

  float promedio = SUMA / 5.0;
  Serial.print("Temperatura: ");
  Serial.print(promedio / 10.0, 1); // Dividir entre 10 para °C
  Serial.println(" °C");
}