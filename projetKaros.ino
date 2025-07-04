#include <Servo.h>
#include <SoftwareSerial.h>
#include <Ultrasonic.h>
#include <TinyGPS++.h>

Ultrasonic ultrasonic1(3, 4); // Proximité
Ultrasonic ultrasonic2(5, 6); // Niveau de saleté

String numero = "+23560579896"; 

int ServoPin = 9;
Servo monServo;

#define RX_PIN 11
#define TX_PIN 10
SoftwareSerial gsmSerial(RX_PIN, TX_PIN);

// LED Pins
int ledVerte = 7;  // Connectez la LED verte à la broche 
int ledJaune = 2; // Connectez la LED jaune à la broche 8
int ledRouge = 12; // Connectez la LED rouge à la broche 12



void setup() {
  monServo.attach(ServoPin);

  pinMode(ledVerte, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledRouge, OUTPUT);

  gsmSerial.begin(9600);
  Serial.begin(9600);

  gsmSerial.println("AT");
  gsmSerial.println("AT+CMGF=1");
  delay(1000);
  gsmSerial.println("AT+CNMI=1,2,0,0,0\r");
  delay(100);
}

void loop() {
  // Proximité de la poubelle :
  int distance = ultrasonic1.read();
  Serial.print("Proximite :");
  Serial.println(distance);
  delay(1000);

  if (distance < 20) {
    monServo.write(0);
  } else {
    monServo.write(180); // Correction: 180 au lieu de 360 pour un servo standard
  }
  delay(1000);


  // Niveau de saleté et gestion des LEDs
  int distanceSalete = ultrasonic2.read();
  Serial.print("Niveau de dechet :");
  Serial.println(distanceSalete);
  delay(1000);

  // Logique des LEDs
  if (distanceSalete >= 30) {  // Plus grand ou égal à 30cm (ou valeur seuil)
    digitalWrite(ledVerte, HIGH);
    digitalWrite(ledJaune, LOW);
    digitalWrite(ledRouge, LOW);


    Serial.println("Poubelle est a 25 SUR 100 pleine !");
    
    // Envoi du SMS (seulement si la poubelle est pleine)
    gsmSerial.println("AT+CMGS=\"60579896\"\r");
    
    delay(3000);
    
    gsmSerial.println("Poubelle pleine ! Localisation : ENASTIC"); // + localisation
    
    gsmSerial.write((char)26);
    
    delay(1000);
  }
  
   
  else if (distanceSalete >= 24)
  
  { // Entre 24cm et 30cm
    digitalWrite(ledVerte, LOW);
    
    digitalWrite(ledJaune, HIGH);
    
    digitalWrite(ledRouge, LOW);

    
    Serial.println("Poubelle presque pleine!");
    
    // Envoi du SMS (seulement si la poubelle est pleine)
    gsmSerial.println("AT+CMGS=\"60579896\"\r");
    
    delay(3000);
    
    gsmSerial.println("Poubelle presque pleine ! Localisation : ENASTIC"); // + localisation
    
    gsmSerial.write((char)26);
    
    delay(1000);
  } 
  else 
  {                               // Moins de 24cm
    digitalWrite(ledVerte, LOW);
    
    digitalWrite(ledJaune, LOW);
    
    digitalWrite(ledRouge, HIGH);
    
    Serial.println("Poubelle pleine !");
    
    // Envoi du SMS (seulement si la poubelle est pleine)
    gsmSerial.println("AT+CMGS=\"60579896\"\r");
    
    delay(3000);
    
    gsmSerial.println("Poubelle pleine ! Localisation : ENASTIC"); // + localisation
    
    gsmSerial.write((char)26);
    
    delay(1000);
  }

  
}
