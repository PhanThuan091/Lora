#define M0_PIN 4
#define M1_PIN 5
#define AUX_PIN 18

// UART2: TXD2 = GPIO 17, RXD2 = GPIO 16
HardwareSerial LoRaSerial(2);

void setup() {
  // Thiết lập chân điều khiển
  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);
  pinMode(AUX_PIN, INPUT);

  // Đặt module vào Normal Mode (M0 = 0, M1 = 0)
  digitalWrite(M0_PIN, LOW);
  digitalWrite(M1_PIN, LOW);

  // Khởi tạo Serial Monitor để debug
  Serial.begin(115200);
  // Khởi tạo UART2 cho LoRa
  LoRaSerial.begin(9600, SERIAL_8N1, 16, 17);

  delay(1000);
  Serial.println("Sender ready");
}

void loop() {
  // Dữ liệu cần gửi: "HloCEra"
  char message[] = "HloCEra";

  // Tiền tố Fixed Transmission: [ADDH] [ADDL] [CHAN]
  byte prefix[] = {0xFF, 0xFF, 0x17}; // Địa chỉ 195 (0x00C3), kênh 9 (0x09)

  // Gửi tiền tố
  LoRaSerial.write(prefix, 3);
  // Gửi dữ liệu
  LoRaSerial.write((byte*)message, strlen(message));

  Serial.println("Sent: HloCEra to address 100, channel 8");
  delay(2000); // Gửi mỗi 2 giây
}