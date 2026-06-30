#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const int currentSensorPin = A0;
const int relayPin = 7;
const int toggleSwitchPin = 2;
const int buzzerPin = 8;
const int threshold = 10; // Set a threshold for power theft detection
const int gpsTx = 4;
const int gpsRx = 3;
const int gsmTx = 6;
const int gsmRx = 5;

SoftwareSerial gpsSerial(gpsRx, gpsTx);
SoftwareSerial gsmSerial(gsmRx, gsmTx);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);
  lcd.begin(16, 2);
  pinMode(currentSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(toggleSwitchPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  int currentReading = analogRead(currentSensorPin);
  float current = (currentReading / 1024.0) * 5.0 / 0.185; // Convert analog reading to current

  if (digitalRead(toggleSwitchPin) == LOW) {
    if (current > threshold) {
      digitalWrite(relayPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Theft detected!");
      lcd.setCursor(0, 1);
      lcd.print("Sending SMS...");
      sendSMS(getGPSLocation());
    } else {
      digitalWrite(relayPin, LOW);
      digitalWrite(buzzerPin, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("No theft detected");
    }
  } else {
    digitalWrite(relayPin, LOW);
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System off");
  }
  delay(1000);
}

String getGPSLocation() {
  String location = "Loc: ";
  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    location += c;
  }
  return location;
}

void sendSMS(String message) {
  gsmSerial.println("AT+CMGF=1"); // Set SMS to text mode
  delay(100);
  gsmSerial.println("AT+CMGS=\"+1234567890\""); // Replace with your phone number
  delay(100);
  gsmSerial.print(message);
  delay(100);
  gsmSerial.write(26); // ASCII code of CTRL+Z
  delay(1000);
}