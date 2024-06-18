#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "secrets.h"

const char DEVICE_LOGIN_NAME[]  = "79196d36-d129-45da-9b69-ad27bfc1f5f6";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]         = SECRET_DEVICE_KEY;    // Secret device password

void onWindowMotorChange();
void onWindowTempChange();

CloudDimmedLight window_motor;
CloudTemperatureSensor window_temp;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(window_motor, READWRITE, ON_CHANGE, onWindowMotorChange);
  ArduinoCloud.addProperty(window_temp, READWRITE, ON_CHANGE, onWindowTempChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
