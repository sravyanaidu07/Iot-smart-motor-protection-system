#define BLYNK_TEMPLATE_ID "TMPL3wYROligZ"
#define BLYNK_TEMPLATE_NAME "IOT based Smart Motor Protection System"
#define BLYNK_AUTH_TOKEN "YOUR_NEW_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ZMPT101B.h>
#include <math.h>

// Replace these placeholders with your own credentials
// locally. Never commit real credentials to a public repository.
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Voltage sensor: ZMPT101B connected to ESP32 GPIO 34
ZMPT101B voltageSensor(34, 50.0);

// Current sensor: ACS712 30A connected to ESP32 GPIO 35
const int sensorPin = 35;
const float sensitivity = 0.066; // 66 mV/A model
const float Vref = 3.3;
const int ADC_RES = 4095;

float offset = 0;
BlynkTimer timer;

// Calibrate current sensor with no current flowing
void calibrateSensor() {
  long sum = 0;

  for (int i = 0; i < 1000; i++) {
    sum += analogRead(sensorPin);
    delay(2);
  }

  offset = sum / 1000.0;

  Serial.print("Current sensor offset: ");
  Serial.println(offset);
}

// Estimate current from sampled sensor readings.
// Validate RMS measurement against a suitable reference meter.
float readCurrent() {
  float sum = 0;
  const int samples = 500;

  for (int i = 0; i < samples; i++) {
    float adc = analogRead(sensorPin);
    float sensorVoltage = (adc - offset) * (Vref / ADC_RES);
    float current = sensorVoltage / sensitivity;

    sum += current * current;
  }

  float rms = sqrt(sum / samples);

  if (rms < 0.1) {
    rms = 0;
  }

  return rms;
}

void sendData() {
  float voltage = voltageSensor.getRmsVoltage();
  float current = readCurrent();

  // Blynk dashboard: V0 = voltage, V1 = current
  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  Serial.println("-------------------");
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);

  voltageSensor.setSensitivity(500.0f);

  // Calibrate before starting normal measurements.
  calibrateSensor();

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}
```
