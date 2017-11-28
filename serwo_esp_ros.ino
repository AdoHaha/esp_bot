#include <ESP8266WiFi.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Bool.h>
#include <Servo.h>

//////////////////////
// WiFi Definitions //
//////////////////////

#define ROBOT_NAME "BOTcroc2"

#define SENSOR_TOPIC ROBOT_NAME "/sensor_value"
#define SENSOR_BINARY_TOPIC ROBOT_NAME "/sensor_binary_value"
#define SERVO_TOPIC ROBOT_NAME "/servo"

const char* ssid = "ipython_robotics";
const char* password = "&&ampersand";



//IPAddress server(192, 168, 111, 108); // ip of your ROS server

IPAddress server(192,168,111,108);

IPAddress ip_address;
int status = WL_IDLE_STATUS;

WiFiClient client;

class WiFiHardware {

  public:
  WiFiHardware() {};

  void init() {
    // do your initialization here. this probably includes TCP server/client setup
    client.connect(server, 11411);
  }

  // read a byte from the serial port. -1 = failure
  int read() {
    // implement this method so that it reads a byte from the TCP connection and returns it
    //  you may return -1 is there is an error; for example if the TCP connection is not open
    
    return client.read();         //will return -1 when it will works
   
    }
    
  

  // write data to the connection to ROS
  void write(uint8_t* data, int length) {
    // implement this so that it takes the arguments and writes or prints them to the TCP connection
    
    
    for(int i=0; i<length; i++){
      client.write(data[i]);
    }
    
    
  }

  // returns milliseconds since start of program
  unsigned long time() {
     return millis(); // easy; did this one for you
  }
};

Servo s;
int i;

void servoCallback(const std_msgs::Int16& msg) {
  i = msg.data;
  s.write(i);
}

ros::Subscriber<std_msgs::Int16> sub(SERVO_TOPIC, &servoCallback);
ros::NodeHandle_<WiFiHardware> nh;

std_msgs::Int16 czujnik_value;
std_msgs::Bool czujnik_2_value;

ros::Publisher czujniczek(SENSOR_TOPIC, &czujnik_value);
ros::Publisher czujniczek_binarny(SENSOR_BINARY_TOPIC, &czujnik_2_value);


void setupWiFi()
{
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 1000) delay(500);
  
  if(i == 1001){
    Serial.print("Could not connect to"); Serial.println(ssid);
  //  while(1) delay(500);
  }
  
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.print("Ready! Use ");
  Serial.print(WiFi.localIP());
  Serial.println(" to access client");

  }
}




void setup() {
  Serial.begin(115200);
  setupWiFi();
  delay(2000);
  s.attach(2);  // PWM pin
  Serial.println("initializing the node");
  nh.initNode();
  delay(1000);
  Serial.println("adveritsing and subscribing");
  nh.advertise(czujniczek);
  nh.advertise(czujniczek_binarny);
  nh.subscribe(sub);
  pinMode(5, INPUT);
}

unsigned long last_checked_connection_time;

int x=0;
void check_connection()
{

   if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connection to Wifi broken, setuping again");
    setupWiFi();
  }
  if(!client.connected())
  {
    Serial.println("client not connected, reconnecting");
    
     client.connect(server, 11411);
     int tries=1;
     while(!client.connected())
     {
      delay(100);
      tries++;

      if(WiFi.status() != WL_CONNECTED)
      {
        Serial.println("Connection to Wifi broken, setuping again");
        setupWiFi();
        delay(1000);
      }
      if(tries%10)
      {
        Serial.println("still trying to reconnect");
      }
      if(tries%500)
      {
        Serial.println("trying to re initialize the node");
        nh.initNode();
       delay(100);
       nh.advertise(czujniczek);
       delay(100);
       nh.advertise(czujniczek_binarny);
       delay(100);
       nh.subscribe(sub);
       delay(2000);
      }
     }
     
  }
}
void loop() {

  int sensorValue = 1024-analogRead(A0); // when dark 0
  bool sensor2Value= !digitalRead(5); // when dark False
  czujnik_value.data = sensorValue;
  czujnik_2_value.data=sensor2Value;

  check_connection();
  if(client.connected())
  {
  czujniczek.publish( &czujnik_value );
  czujniczek_binarny.publish(& czujnik_2_value);
  nh.spinOnce();
  }
/*
 if(millis()>last_checked_connection_time) // try every 10 seconds if connection
 {
  Serial.println("checking if everything ok");
  last_checked_connection_time=millis()+10000;
  check_connection();
 }
 
  */
  Serial.println(x);
  x++;
  
  delay(10);
}
