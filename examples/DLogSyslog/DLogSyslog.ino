
#include "Arduino.h"
#ifdef ESP8266
#include "ESP8266WiFi.h"
#else
#include "WiFi.h"
#endif
#include "DLog.h"
#include "DLogPrintWriter.h"
#include "DLogSyslogWriter.h"

#define WIFI_SSID "Your_WiFi_SSID_Here"
#define WIFI_PASS "Your_WiFi_Password_Here"

DLog& dlog = DLog::getLog();

static const char* sTAG = "setup";
static const char* lTAG = "loop";

void pre_log(DLogBuffer& buffer, DLogLevel level)
{
    (void)level; // we know its not used
    buffer.printf(F("%010u: "), millis());
}

void setup()
{
    delay(2000);
    Serial.begin(115200);
    dlog.setLevel(lTAG, DLOG_LEVEL_DEBUG);
    dlog.setPreFunc(pre_log);
    dlog.begin(new DLogPrintWriter(Serial));
    dlog.info(sTAG, "Startup!");
    dlog.debug(sTAG, "this wont show because 'setup' level not set to at least DEBUG");

    dlog.info(sTAG, "starting WiFi");
#if defined(ESP8266) || defined(ESP_PLATFORM)
    WiFi.mode(WIFI_STA);
#endif
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      dlog.debug(sTAG, "waiting for wifi status...");
    }

    dlog.info(sTAG, "WiFi connected");
    IPAddress ip = WiFi.localIP();
    dlog.info(sTAG, "IP address: %u.%u.%u.%u", ip[0], ip[1], ip[2], ip[3]);
    dlog.info(sTAG, F("starting TCP writer"));
    dlog.begin(new DLogSyslogWriter("192.168.0.42", 514, "DLlog"));
    dlog.info(sTAG, F("Done"));
}

void loop()
{
    dlog.debug(lTAG, "this will show because 'loop' level includes DEBUG");
    dlog.trace(lTAG, "this won't show because level does not include TRACE!");
    delay(60000); // one minute
}
