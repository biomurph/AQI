#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
// Replace with desired access point credentials

const char* ssid = "AQI-Sensor_01";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>AQI Sensor 01</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
<style>
html {
font-family: Arial;
text-align: center;
}
body {
max-width: 400px;
margin:0px auto;
}
</style>
</head>
<body>
<h1>AQI Sensor 01</h1>
<p>Congratulations!<br>You found an access point with an Air Quality Sensor!</p>
</body>
</html>
)rawliteral";

void initAP() {
WiFi.mode(WIFI_AP);
WiFi.softAP(ssid, password);
}


void setup() {
// Serial port for debugging purposes
Serial.begin(115200);
initAP();
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
request->send(200, "text/html", index_html);
});
// Start server
server.begin();
delay(1000);
Serial.println("Server is available at AQI-Sensor-01");

}
void loop() {
//
}






