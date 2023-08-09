#define PIN_MQ2 A1
#define LED     3
#define MOTOR   6
#define BUZZER  9

int value;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PIN_MQ2, INPUT);
}

void loop() {
   value = analogRead(PIN_MQ2);

   Serial.println("VALUE - " + String(value));
   Serial.println(" ");
  
   if (value > 90) {
     digitalWrite(LED, HIGH);
     digitalWrite(MOTOR, HIGH); // Allumer le moteur
     tone(BUZZER, 1000); // Faire sonner le buzzer
   } else {
     digitalWrite(LED, LOW);
     digitalWrite(MOTOR, LOW); // Éteindre le moteur
     noTone(BUZZER); // Arrêter le buzzer
   }

   delay(200);
}
