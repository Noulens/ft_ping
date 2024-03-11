## ft_ping
Launch make test to run on a docker:
    make test
## Usage

Usage: ping [OPTION...] HOST ...

    Send ICMP ECHO_REQUEST packets to network hosts.
    Options:
    -c=NUMBER                   stop after sending NUMBER packets
    -i=NUMBER                   wait NUMBER seconds between sending each packet
    --ttl=N                specify N as time-to-live
    -v                          verbose output
    -W=N                        number of seconds to wait for response
    -q                          quiet output
    -?                          display this help

##  Usage

Run `make test` in the root of the projet:

    make test
Launch as follows:

    ./ft_ping [OPTION] HOST
