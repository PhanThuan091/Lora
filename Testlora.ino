

#define RX_PIN 17  // RX pin for Serial2 (can be changed)
#define TX_PIN 16  // TX pin for Serial2 (can be changed)

// Use HardwareSerial object for better ESP32 compatibility
HardwareSerial MySerial(2);  // Serial2 on ESP32

void setup() {
    // Initialize Serial (USB) for debugging
    Serial.begin(115200);  // Higher baud rate typical for ESP32
    while (!Serial) {
        ; // Wait for serial port to connect
    }
    
    // Initialize Serial2 with custom pins
    MySerial.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
    Serial.println("ESP32 Serial Communication Started");
}

void loop() {
    if (MySerial.available() > 0) {
        String str = MySerial.readString();
        Serial.print("Received on Serial2: ");
        Serial.println(str);
        MySerial.print("Echo: ");  // Echo back to sender
        MySerial.println(str);
    }
}
