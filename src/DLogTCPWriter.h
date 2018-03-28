/*
 * DLogTCPWriter.h
 *
 *  Created on: Mar 10, 2018
 *      Author: chris.l
 */

#ifndef DLOGTCPWRITER_H_
#define DLOGTCPWRITER_H_

#include "DLogWriter.h"
#include "WiFiClient.h"


class DLogTCPWriter: public DLogWriter
{
public:
    DLogTCPWriter(const char* host, uint16_t port);
    DLogTCPWriter(const char* host, uint16_t port, uint16_t max_attempts, unsigned int timeout);

    virtual ~DLogTCPWriter();

    virtual void write(const char* message);

private:
    WiFiClient  _client;
    String      _host;
    uint16_t    _port;
    uint16_t    _attempts_left;
};

#endif /* DLOGTCPWRITER_H_ */
