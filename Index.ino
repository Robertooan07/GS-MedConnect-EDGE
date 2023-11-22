#include <ArduinoJson.h>
#include <LiquidCrystal.h>
#include <WiFi.h>
#include <PubSubClient.h>

//informações necessárias para conectar o dispositivo à rede Wi-Fi e ao servidor MQTT da Tago.io.
const char* ssid = "Wokwi-GUEST"; 
const char* password = "";

const char* mqttServer = "mqtt.tago.io";
const int mqttPort = 1883;
const char* mqttUser = "Default";
const char* mqttPassword = "3ffcf440-c105-4b8b-ae95-6074c7550a57";

WiFiClient espClient;
PubSubClient client(espClient);

// Parte do código LCD
LiquidCrystal lcd(5, 17, 4, 0, 2, 15);

int redLed = 16;
int trava = 13;
int successButton = 18;
int failedButton = 19;

void setup()
{
  Serial.begin(9600);
  connectToWiFi();
  connectToMQTT();
  
  lcd.begin(20, 4); // Inicializa o LCD com 20 colunas por 4 linhas
  pinMode(successButton, INPUT);
  pinMode(failedButton, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(trava, OUTPUT);
  initialMessage(); //a função initialMessage, que exibe uma mensagem inicial no LCD.
}
//Lembrete: bloco abaixo usa as funções dos botões pra exibir informações no LCD e enviar dados para a Tago.io via MQTT.
void loop()
{
  client.loop();

  if (digitalRead(successButton) == HIGH)
  {
    lcd.clear();
    lcd.print("Nome: Roberto");
    lcd.setCursor(0, 1);
    lcd.print("Oliveira");
    lcd.setCursor(0, 2);
    lcd.print("CPF:12627603801");
    lcd.setCursor(0, 3);
    lcd.print("clique no amarelo ->");
    digitalWrite(trava, HIGH);
    delay(5000);
    enviarDadosParaTago("Roberto Oliveira", "12627603801");
    initialMessage();
    digitalWrite(trava, LOW);
  }
  else if (digitalRead(failedButton) == HIGH)
  {
    lcd.clear();
    digitalWrite(redLed, HIGH);
    lcd.print("Telefone: 999312123");
    lcd.setCursor(0, 1);
    lcd.print("Plano: NotreDame");
    lcd.setCursor(0, 2);
    lcd.print("Intermedica");
    lcd.setCursor(0, 3);
    lcd.print("Boa Consulta :)");
    delay(5000);
    enviarDadosParaTago("999312123", "NotreDame Intermedica");
    initialMessage();
    digitalWrite(redLed, LOW);
  }
}

void initialMessage()
{
  lcd.clear();
  lcd.print("Aguardando RFID"); //exibe uma mensagem inicial no LCD
  lcd.setCursor(0, 1);
}

void enviarDadosParaTago(String dado1, String dado2) //cria e envia uma mensagem JSON contendo os dados para o servidor MQTT da Tago.io.
{
  DynamicJsonDocument jsonDoc(1024);
  JsonObject root = jsonDoc.to<JsonObject>();

  root["dado1"] = dado1;
  root["dado2"] = dado2;

  String payload;
  serializeJson(root, payload);

  client.publish("tago/data", payload.c_str());
  Serial.println("Dados enviados para Tago.io: " + payload);
}

void connectToWiFi() //responsável por conectar o dispositivo à rede Wi-Fi
{
  Serial.println("Conectando WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi Conectado");
}

void connectToMQTT() //estabelece a conexão com o servidor MQTT da Tago.io.
{
  Serial.println("Conectando com Servidor MQTT");
  client.setServer(mqttServer, mqttPort);
  while (!client.connected())
  {
    if (client.connect("esp32", mqttUser, mqttPassword))
    {
      Serial.println("MQTT Conectado");
    }
    else
    {
      Serial.print("Falha na conexão com MQTT, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}
