/*
 * DLogTCPWriter.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: chris.l
 */

#include "DLogTCPWriter.h"

//#define DLOG_TCP_DEBUG
#if defined(DLOG_TCP_DEBUG)
#define dbprintf(...)  Serial.printf(__VA_ARGS__)
#else
#define dbprintf(fmt, ...)
#endif


DLogTCPWriter::DLogTCPWriter(const char* host, uint16_t port) : _host(host), _port(port), _attempts_left(1)
{
}

DLogTCPWriter::DLogTCPWriter(const char* host, uint16_t port, uint16_t max_attempts, unsigned int timeout) :
        _host(host),
        _port(port),
        _attempts_left(max_attempts)
{
    _client.setTimeout(timeout);
}

DLogTCPWriter::~DLogTCPWriter()
{
    if (_client.connected())
    {
        dbprintf("closing connection!\n");
        _client.stop();
    }
}

void DLogTCPWriter::write(const char* message)
{
    if (!_client.connected())
    {
        if (_attempts_left == 0)
        {
            return;
        }

        --_attempts_left;

        dbprintf("connecting to: %s:%u\n", _host.c_str(), _port);

        if (!_client.connect(_host.c_str(), _port))
        {
            dbprintf("connection failed: %s:%u\n", _host.c_str(), _port);
            return;
        }
    }

    _client.write(message);
    _client.flush();
}

