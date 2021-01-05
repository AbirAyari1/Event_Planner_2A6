
/*
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 * -----------------------------------------------------------------------------------------
 * Project link: https://www.electronique-mixte.fr/microcontrolleurs/rfid-controle-dacces-par-badge-avec-arduino/
 */
#include <SPI.h> // SPI
#include <MFRC522.h> // RFID

#define SS_PIN 10
#define RST_PIN 9
int ledrouge=5;
int ledverte=7;
int data;
int alert=0;
// Déclaration 
MFRC522 rfid(SS_PIN, RST_PIN); 

// Tableau contentent l'ID
byte nuidPICC[4];

void setup() 
{ 
  // Init RS232
  Serial.begin(9600); // communication entre la carte et le port (frequence de 9600)
  pinMode(ledrouge,OUTPUT);// to set the output mode of the led
  pinMode(ledverte,OUTPUT);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522  
}
 
void loop() 
{

    if (Serial.available()>0) // if i'm sending something to Arduino 
 {
    data=Serial.read(); // to read the data from QT
    //Serial.println(data);
    if (data==48){ // Code ASCII DE 0
      digitalWrite(ledrouge,HIGH); // allumer la led rouge 
      delay(2000); // pendant deux secondes 
      digitalWrite(ledrouge,LOW); // eteindre la led rouge
    }
    if (data==49){ // Code ASCII DE 1
      digitalWrite(ledverte,HIGH); // allumer la led verte 
      delay(2000); //pendant deux sec
      digitalWrite(ledverte,LOW); // eteindre la led verte
    }
    if (data==50){ // CODE ASCII DE 2
      alert=1; // ALERTE 
     
    }
    if (data==51){ // CODE ASCII DE 3
      alert=0; // ALERTE 
     digitalWrite(ledrouge,LOW);
    }
  } 
  if (alert==0){ //
    if ( !rfid.PICC_IsNewCardPresent()) 
    return;

  // Vérifier la présence d'un nouveau badge 
  if ( !rfid.PICC_ReadCardSerial())
    return;

  // Enregistrer l'ID du badge (4 octets) 
  for (byte i = 0; i < 4; i++) 
  {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }

  
  // Affichage de l'ID 

  for (byte i = 0; i < 4; i++) 
  {
    Serial.print(nuidPICC[i], HEX);
  }

  
   
 //Serial.print(".");
  // Re-Init RFID
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD

  }
  else {
    delay(500);
     digitalWrite(ledrouge,HIGH);
      delay(500);
     digitalWrite(ledrouge,LOW);
  }
  // Initialisé la boucle si aucun badge n'est présent 
  

}
