#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

int ledPin = 15;                // Deklarasi variabel input pin LED
int inputPin = 14;               // Deklarasi variabel input pin Sensor PIR
int pirState = LOW;             // Pada saat memulai, Sensor PIR dimulai dari LOW
int val = 0;                    // Deklarasi variabel untuk membaca status pin

void setup() {
  pinMode(ledPin, OUTPUT);      // Deklarasi LED sebagai Output
  pinMode(inputPin, INPUT);     // Deklarasi Sensor PIR sebagai Input

  // Program Awal LCD
  LCD.init();
  LCD.backlight();
  LCD.setCursor(1,0);
  LCD.print(" Final Project  ");
  LCD.setCursor(1,1);
  LCD.print("    UAS   ");
  delay (500);

  LCD.clear();
  LCD.setCursor(1,0);
  LCD.print("SISTEM PEMANTAU KEAMANAN");
  LCD.setCursor(1,1);
  LCD.print("KEAMANAN RUMAH");
  delay (500);

  LCD.clear();
  LCD.setCursor(1,0);
  LCD.print("     MULAI     ");
  delay(700);
  LCD.clear();
}

void loop() {
  val = digitalRead(inputPin);  // Membaca nilai input
  if (val == LOW) {            // Jika Input LOW, maka :
    digitalWrite(ledPin, LOW);  // LED tidak menyala
    if (pirState == LOW) {
      // Jika, input LOW maka akan LCD akan mengeluarkan output "TIDAK TERDETEKSI GERAKAN"
      LCD.init();
      LCD.backlight();
      LCD.setCursor(0,0);
      LCD.print("TIDAK TERDETEKSI");
      LCD.setCursor(0,1);
      LCD.print("    GERAKAN    ");
      // Output program akan terganti, jika input bernilai HIGH
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, HIGH); // Menuliskan nilai LED/output bernilai HIGH
    if (pirState == HIGH) {  // Jika Input HIGH, maka :
       // Jika, input HIGH maka akan LCD akan mengeluarkan output "TERDETEKSI GERAKAN"
      LCD.init();
      LCD.init();
      LCD.backlight();
      LCD.setCursor(0,0);
      LCD.print("   TERDETEKSI   ");
      LCD.setCursor(0,1);
      LCD.print("    GERAKAN    ");
      // Output program akan terganti, jika input bernilai LOW
      pirState = LOW;
    }
  }
}