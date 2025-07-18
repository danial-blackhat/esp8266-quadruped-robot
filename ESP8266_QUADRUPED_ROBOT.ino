#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

// WiFi credentials
const char* ssid = "Quadruped_Robot";         // CHANGE YOUR OWN SSID
const char* password = "Technology!62#";      // CHANGE YOUR OWN PASSWORD 

// Servo objects
Servo s1, s2, s3, s4;

// WiFi server
ESP8266WebServer server(80);

// Current command
String command = "";

void setup() {
  Serial.begin(115200);

  // Set up ESP8266 as Access Point
  WiFi.softAP(ssid, password);
  Serial.println("Access Point started!");
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Start server
  server.begin();

  // Attach servos to GPIO pins
  s1.attach(D1);  // Front Left
  s2.attach(D2);  // Front Right
  s3.attach(D5);  // Back Left
  s4.attach(D6);  // Back Right

  centerAll(); // Initial servo positions

  // Define server routes
  server.on("/", handleRoot);
  server.on("/action", handleAction);
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", buildWebPage());
}

void handleAction() {
  if (server.hasArg("cmd")) {
    command = server.arg("cmd");
    Serial.println("CMD: " + command);

    if (command == "forward") walkForward();
    else if (command == "backward") walkBackward();
    else if (command == "left") turnLeft();
    else if (command == "right") turnRight();
    else centerAll();

    server.send(200, "text/plain", "OK");
  }
}

// ---- SERVO CONTROL LOGIC ----
void walkForward() {
  s1.write(70); s3.write(110);
  delay(60);  // faster
  s1.write(90); s3.write(90);
  delay(60);
  s2.write(70); s4.write(110);
  delay(60);
  s2.write(90); s4.write(90);
}

void walkBackward() {
  s1.write(110); s3.write(70);
  delay(60);  // faster
  s1.write(90); s3.write(90);
  delay(60);
  s2.write(110); s4.write(70);
  delay(60);
  s2.write(90); s4.write(90);
}

void turnLeft() {
  s1.write(70); s4.write(110);
  delay(90);  // faster
  centerAll();
}

void turnRight() {
  s2.write(70); s3.write(110);
  delay(90);  // faster
  centerAll();
}

void centerAll() {
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
}

// ---- HTML & BUTTON WEB UI ----
String buildWebPage() {
  String html = R"====(
    <!DOCTYPE html>
    <html>
    <head>
      <title>Quadruped Robot Control</title>
      <meta name='viewport' content='width=device-width, initial-scale=1'>
      <style>
        body {
          font-family: sans-serif;
          text-align: center;
          background: #f4f4f4;
        }
        h1 {
          margin-top: 20px;
        }
        .button-grid {
          display: grid;
          grid-template-columns: 1fr 1fr 1fr;
          gap: 15px;
          max-width: 300px;
          margin: 40px auto;
        }
        button {
          padding: 20px;
          font-size: 18px;
          background: #007bff;
          color: white;
          border: none;
          border-radius: 10px;
          box-shadow: 0 4px 6px rgba(0,0,0,0.2);
        }
        button:active {
          background: #0056b3;
        }
      </style>
    </head>
    <body>
      <h1>Quadruped Robot Control</h1>
      <div class="button-grid">
        <div></div>
        <button onclick="sendCommand('forward')">Forward</button>
        <div></div>
        <button onclick="sendCommand('left')">Left</button>
        <button onclick="sendCommand('center')">Center</button>
        <button onclick="sendCommand('right')">Right</button>
        <div></div>
        <button onclick="sendCommand('backward')">Backward</button>
        <div></div>
      </div>

      <script>
        function sendCommand(cmd) {
          fetch('/action?cmd=' + cmd)
            .then(response => response.text())
            .then(data => console.log("Sent command: " + cmd));
        }
      </script>
    </body>
    </html>
  )====";
  return html;
}
