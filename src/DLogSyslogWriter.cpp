/*
 * DLogSyslogWriter.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: chris.l
 */

#include <DLogSyslogWriter.h>

DLogSyslogWriter::DLogSyslogWriter(const char* host, uint16_t port, const char* devicename, const char* appname, uint16_t defpri) :
        _syslog(_udp, host, port, devicename, appname, defpri)
{
}

DLogSyslogWriter::~DLogSyslogWriter()
{
}

void DLogSyslogWriter::write(const char* message)
{
    _syslog.log(LOG_USER | LOG_INFO, message);
}
