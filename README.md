# DLogNet - Network extensions for DLog

Provide various network based writers for DLog

[![Build Status](https://travis-ci.org/liebman/DLogNet.svg?branch=master)](https://travis-ci.org/liebman/DLogNet)

### Implemnented Writers

 * `DLogTCPWriter` - sends log lines to remote systems.
 * `DLogSyslogWriter` - send log lines to remote syslog (Requires Syslog library)

### Future Writers

 * `DLogUDPWriter` - send log lines to remote systems via UDP
 * `DLogESWriter` - send log lines to Elastic Search
