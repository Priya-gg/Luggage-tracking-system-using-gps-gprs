 
 #include <SoftwareSerial.h>
SoftwareSerial gps(10,11); // RX, TX
//String str="";
char str[70];
String gpsString="";
char *test="$GPGGA";
String latitude="No Range      ";
String longitude="No Range     ";
int temp=0,i;
boolean gps_status=0;
void setup() 
{
   Serial.begin(9600);
  gps.begin(9600);
  delay(2000);
  gsm_init();
  get_gps();
  delay(2000);
}
void loop()
{
  serialEvent();
  if(temp)
  {
    get_gps();
    tracking();
  }
}
        i=0;
        gpsString="";
      }
     }
    if(inChar=='\r')
  {
     if(i>65)
     {
       gps_status=1;
       break;
     }
     else
     {
       i=0;
     }
    }
  }
   if(gps_status)
    break;
  }
}
void gsm_init()
  {
    Serial.println("AT");
    while(Serial.available()>0)
 
    delay(1000);
  }
  gpsEvent();
    int str_lenth=i;
    latitude="";
    longitude="";
    int comma=0;
    while(x<str_lenth)
    {
      if(gpsString[x]==',')
      comma++;
      if(comma==2)        //extract latitude from string
      latitude+=gpsString[x+1];     
      else if(comma==4)        //extract longitude from string
      longitude+=gpsString[x+1];
      x++;
}
    int l1=latitude.length();
    latitude[l1-1]=' ';
    l1=longitude.length();
    longitude[l1-1]=' ';
    delay(2000)
  send_data("Vehicle Tracking Alert:");
    send_data("Your Vehicle Current Location is:");
     send_data(latitude);
     send_data(longitude);
 
 
void serialEvent()
{
  while(Serial.available())
  {
    if(Serial.find("Track Vehicle"))
    {
      temp=1;
      break;
    }
    else
    temp=0;
  }
}
void gpsEvent()
{
  gpsString="";
  while(1)
  {
   while (gps.available()>0)            
   {
    char inChar = (char)gps.read();
     gpsString+= inChar;              
     i++;
     if (i < 7)                      
     {
      if(gpsString[i-1] != test[i-1])        
      {
 {
    Serial.println("ATE0");
    while(Serial.available()>0)
    {
      if(Serial.find("OK"))
echo_flag=0;
    }
    delay(1000);
  }
    {
      if(Serial.find("OK"))
      }
}
void init_sms()
 
  Serial.println("AT+CMGF=1");
  delay(400);
  Serial.println("AT+CMGS=\"+91**********\"");   // use your 10 digit cell no. here
   at_flag=0;
    }
  {
    Serial.println("AT+CPIN?");
    while(Serial.available()>0)
    {
      if(Serial.find("+CPIN: READY"))
      net_flag=0;
    }
    delay(1000);
  }
void get_gps()
{
   gps_status=0;
   int x=0;
   while(gps_status==0)
   {
 delay(400);
}
void send_data(String message)
{
  Serial.println(message);
  delay(200);
}
void send_sms()
{
  Serial.write(26);
}
void tracking()
{
    init_sms();
    send_data("Please take some action soon..\nThankyou");
    send_sms();
    delay(2000);
}
