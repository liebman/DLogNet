/*
 * DLogSyslogWriter.h
 *
 *  Created on: Jun 3, 2018
 *      Author: chris.l
 */

#ifndef LIBRARIES_DLOGNET_SRC_DLOGSYSLOGWRITER_H_
#define LIBRARIES_DLOGNET_SRC_DLOGSYSLOGWRITER_H_

#include <DLogWriter.h>
#include <WiFiUdp.h>
#include <Syslog.h>

class DLogSyslogWriter: public DLogWriter
{
public:
    DLogSyslogWriter(const char* host, uint16_t port, const char* devicename = nullptr, const char* appname = nullptr, uint16_t defpri = LOG_USER);
    virtual ~DLogSyslogWriter();

    virtual void write(const char* message);

private:
    WiFiUDP _udp;
    Syslog _syslog;
};

#endif /* LIBRARIES_DLOGNET_SRC_DLOGSYSLOGWRITER_H_ */
