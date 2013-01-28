/**
\brief General OpenWSN definitions

\author Thomas Watteyne <watteyne@eecs.berkeley.edu>, August 2010
\author Ankur Mehta <mehtank@eecs.berkeley.edu>, September 2010
*/

#ifndef __OPENWSN_H
#define __OPENWSN_H

//general
#include <stdint.h>               // needed for uin8_t, uint16_t
#include "board_info.h"

//=========================== define ==========================================

static const uint8_t infoStackName[] = "OpenWSN ";
#define OPENWSN_VERSION_MAJOR 1
#define OPENWSN_VERSION_MINOR 2
#define OPENWSN_VERSION_PATCH 1

// enter the last byte of your mote's address if you want it to be an LBR
#define DEBUG_MOTEID_MASTER 0x41

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

enum {
   E_SUCCESS                           = 0,          
   E_FAIL                              = 1,
};

// types of addresses
enum {
   ADDR_NONE                           = 0,
   ADDR_16B                            = 1,
   ADDR_64B                            = 2,
   ADDR_128B                           = 3,
   ADDR_PANID                          = 4,
   ADDR_PREFIX                         = 5,
   ADDR_ANYCAST                        = 6,
};

enum {
   LITTLE_ENDIAN                       = TRUE,
   BIG_ENDIAN                          = FALSE,
};

// protocol numbers, as defined by the IANA
enum {
   IANA_UNDEFINED                      = 0x00,
   IANA_TCP                            = 0x06,
   IANA_UDP                            = 0x11,
   IANA_ICMPv6                         = 0x3a,
   IANA_ICMPv6_ECHO_REQUEST            =  128,
   IANA_ICMPv6_ECHO_REPLY              =  129,
   IANA_ICMPv6_RS                      =  133,
   IANA_ICMPv6_RA                      =  134,
   IANA_ICMPv6_RA_PREFIX_INFORMATION   =    3,
   IANA_ICMPv6_RPL                     =  155,
   IANA_ICMPv6_RPL_DIO                 = 0x01,
   IANA_ICMPv6_RPL_DAO                 = 0x04,
   IANA_RSVP                           =   46,
};

// well known ports (which we define)
enum {
   //TCP
   WKP_TCP_HTTP                        =    80,
   WKP_TCP_ECHO                        =     7,
   WKP_TCP_INJECT                      =  2188,
   WKP_TCP_DISCARD                     =     9,
   //UDP
   WKP_UDP_COAP                        =  5683,
   WKP_UDP_HELI                        =  2192,
   WKP_UDP_IMU                         =  2190,
   WKP_UDP_ECHO                        =     7,
   WKP_UDP_INJECT                      =  2188,
   WKP_UDP_DISCARD                     =     9,
   WKP_UDP_RAND                        = 61000,
   WKP_UDP_LATENCY                     = 61001,
};

//status elements
enum {
   STATUS_ISSYNC                       =  0,
   STATUS_ID                           =  1,
   STATUS_DAGRANK                      =  2,
   STATUS_OUTBUFFERINDEXES             =  3,
   STATUS_ASN                          =  4,
   STATUS_MACSTATS                     =  5,
   STATUS_SCHEDULE                     =  6,
   STATUS_BACKOFF                      =  7,
   STATUS_QUEUE                        =  8,
   STATUS_NEIGHBORS                    =  9,
   STATUS_MAX                          = 10,
};

//component identifiers
//the order is important because
enum {
   COMPONENT_NULL                      = 0x00,
   COMPONENT_OPENWSN                   = 0x01,
   //cross-layers
   COMPONENT_IDMANAGER                 = 0x02,
   COMPONENT_OPENQUEUE                 = 0x03,
   COMPONENT_OPENSERIAL                = 0x04,
   COMPONENT_PACKETFUNCTIONS           = 0x05,
   COMPONENT_RANDOM                    = 0x06,
   //PHY
   COMPONENT_RADIO                     = 0x07,
   //MAClow
   COMPONENT_IEEE802154                = 0x08,
   COMPONENT_IEEE802154E               = 0x09,
   
   //All components with higher component id than COMPONENT_IEEE802154E
   //won't be able to get free packets from the queue 
   //when the mote is not synch
   
   //MAClow<->MAChigh ("virtual components")
   COMPONENT_RES_TO_IEEE802154E        = 0x0a,
   COMPONENT_IEEE802154E_TO_RES        = 0x0b,
   //MAChigh
   COMPONENT_RES                       = 0x0c,
   COMPONENT_NEIGHBORS                 = 0x0d,
   COMPONENT_SCHEDULE                  = 0x0e,
   //IPHC
   COMPONENT_OPENBRIDGE                = 0x0f,
   COMPONENT_IPHC                      = 0x10,
   //IPv6
   COMPONENT_FORWARDING                = 0x11,
   COMPONENT_ICMPv6                    = 0x12,
   COMPONENT_ICMPv6ECHO                = 0x13,
   COMPONENT_ICMPv6ROUTER              = 0x14,
   COMPONENT_ICMPv6RPL                 = 0x15,
   //TRAN
   COMPONENT_OPENTCP                   = 0x16,             
   COMPONENT_OPENUDP                   = 0x17,
   COMPONENT_OPENCOAP                  = 0x18,
   //App test
   COMPONENT_TCPECHO                   = 0x19,
   COMPONENT_TCPINJECT                 = 0x1a,
   COMPONENT_TCPPRINT                  = 0x1b,
   COMPONENT_UDPECHO                   = 0x1c,
   COMPONENT_UDPINJECT                 = 0x1d,
   COMPONENT_UDPPRINT                  = 0x1e,
   COMPONENT_RSVP                      = 0x1f,
   //App
   COMPONENT_OHLONE                    = 0x20,
   COMPONENT_HELI                      = 0x21,
   COMPONENT_IMU                       = 0x22,
   COMPONENT_RLEDS                     = 0x23,
   COMPONENT_RREG                      = 0x24,
   COMPONENT_RWELLKNOWN                = 0x25,
   COMPONENT_RT                        = 0x26,
   COMPONENT_REX                       = 0x27,
   COMPONENT_RXL1                      = 0x28,
   COMPONENT_RINFO                     = 0x29,
   COMPONENT_RHELI                     = 0x2a,
   COMPONENT_RRUBE                     = 0x2b,
   COMPONENT_LAYERDEBUG                = 0x2c,
   COMPONENT_UDPRAND                   = 0x2d,
   COMPONENT_UDPSTORM                  = 0x2e,
   COMPONENT_UDPLATENCY                = 0x2f,
   COMPONENT_TEST                      = 0x30,
};

/**
\brief error codes used throughout the OpenWSN stack

\note The comments are used in the Python parsing tool:
   - {0} refers to the value of the first argument,
   - {1} refers to the value of the second argument,
*/
enum {
   // l7
   ERR_RCVD_ECHO_REQUEST               = 0x01, // received an echo request
   ERR_RCVD_ECHO_REPLY                 = 0x02, // received an echo reply
   ERR_GETDATA_ASKS_TOO_FEW_BYTES      = 0x03, // getData asks for too few bytes, maxNumBytes={0}, fill level={1}
   ERR_INPUT_BUFFER_OVERFLOW           = 0x04, // the input buffer has overflown
   // l4
   ERR_WRONG_TRAN_PROTOCOL             = 0x05, // unknown transport protocol {0} (code location {1})
   ERR_WRONG_TCP_STATE                 = 0x06, // wrong TCP state {0} (code location {1})
   ERR_TCP_RESET                       = 0x07, // TCP reset while in state {0} (code location {1})
   ERR_UNSUPPORTED_PORT_NUMBER         = 0x08, // unsupported port number {0} (code location {1})
   // l3
   ERR_UNEXPECTED_DAO                  = 0x09, // unexpected DAO (code location {0})
   ERR_UNSUPPORTED_ICMPV6_TYPE         = 0x0a, // unsupported ICMPv6 type {0} (code location {1})
   ERR_6LOWPAN_UNSUPPORTED             = 0x0b, // unsupported 6LoWPAN parameter {1} at location {0}
   ERR_NO_NEXTHOP                      = 0x0c, // no next hop
   ERR_INVALID_PARAM                   = 0x0d, // invalid parameter
   ERR_INVALID_FWDMODE                 = 0x0e, // invalid forward mode
   ERR_LARGE_DAGRANK                   = 0x0f, // large DAGrank {0}, set to {1}
   // l2b
   ERR_NEIGHBORS_FULL                  = 0x10, // neighbors table is full (max number of neighbor is {0})
   ERR_NO_SENT_PACKET                  = 0x11, // there is no sent packet in queue
   ERR_NO_RECEIVED_PACKET              = 0x12, // there is no received packet in queue
   ERR_SCHEDULE_OVERFLOWN              = 0x13, // schedule overflown
   // l2a
   ERR_WRONG_CELLTYPE                  = 0x14, // wrong celltype {0} at slotOffset {1}
   ERR_IEEE154_UNSUPPORTED             = 0x15, // unsupported IEEE802.15.4 parameter {1} at location {0}
   ERR_DESYNCHRONIZED                  = 0x16, // got desynchronized at slotOffset {0}
   ERR_SYNCHRONIZED                    = 0x17, // synchronized at slotOffset {0}
   ERR_LARGE_TIMECORRECTION            = 0x18, // large timeCorr.: {0} ticks (code loc. {1})
   ERR_WRONG_STATE_IN_ENDFRAME_SYNC    = 0x19, // wrong state {0} in end of frame+sync
   ERR_WRONG_STATE_IN_STARTSLOT        = 0x1a, // wrong state {0} in startSlot, at slotOffset {1}
   ERR_WRONG_STATE_IN_TIMERFIRES       = 0x1b, // wrong state {0} in timer fires, at slotOffset {1}
   ERR_WRONG_STATE_IN_NEWSLOT          = 0x1c, // wrong state {0} in start of frame, at slotOffset {1}
   ERR_WRONG_STATE_IN_ENDOFFRAME       = 0x1d, // wrong state {0} in end of frame, at slotOffset {1}
   ERR_MAXTXDATAPREPARE_OVERFLOW       = 0x1e, // maxTxDataPrepare overflows while at state {0} in slotOffset {1}
   ERR_MAXRXACKPREPARE_OVERFLOWS       = 0x1f, // maxRxAckPrepapare overflows while at state {0} in slotOffset {1}
   ERR_MAXRXDATAPREPARE_OVERFLOWS      = 0x20, // maxRxDataPrepapre overflows while at state {0} in slotOffset {1}
   ERR_MAXTXACKPREPARE_OVERFLOWS       = 0x21, // maxTxAckPrepapre overflows while at state {0} in slotOffset {1}
   ERR_WDDATADURATION_OVERFLOWS        = 0x22, // wdDataDuration overflows while at state {0} in slotOffset {1}
   ERR_WDRADIO_OVERFLOWS               = 0x23, // wdRadio overflows while at state {0} in slotOffset {1}
   ERR_WDRADIOTX_OVERFLOWS             = 0x24, // wdRadioTx overflows while at state {0} in slotOffset {1}
   ERR_WDACKDURATION_OVERFLOWS         = 0x25, // wdAckDuration overflows while at state {0} in slotOffset {1}
   // general
   ERR_BUSY_SENDING                    = 0x26, // busy sending
   ERR_UNEXPECTED_SENDDONE             = 0x27, // sendDone for packet I didn't send
   ERR_NO_FREE_PACKET_BUFFER           = 0x28, // no free packet buffer (code location {0})
   ERR_FREEING_UNUSED                  = 0x29, // freeing unused memory
   ERR_FREEING_ERROR                   = 0x2a, // freeing memory unsupported memory
   ERR_UNSUPPORTED_COMMAND             = 0x2b, // unsupported command {0}
   ERR_MSG_UNKNOWN_TYPE                = 0x2c, // unknown message type {0}
   ERR_WRONG_ADDR_TYPE                 = 0x2d, // wrong address type {0} (code location {1})
   ERR_BRIDGE_MISMATCH                 = 0x2e, // isBridge mismatch (code location {0})
   ERR_HEADER_TOO_LONG                 = 0x2f, // header too long, length {1} (code location {0})
   ERR_INPUTBUFFER_LENGTH              = 0x30, // input length problem, length={0}
   ERR_BOOTED                          = 0x31, // booted
   ERR_INPUTBUFFER_BAD_CRC             = 0x32, // serial packet had bad CRC
};

//=========================== typedef =========================================

typedef uint16_t  errorparameter_t;
typedef uint16_t  dagrank_t;
typedef uint8_t   error_t;
#define bool uint8_t

PRAGMA(pack(1));
typedef struct {
   uint8_t  byte4;
   uint16_t bytes2and3;
   uint16_t bytes0and1;
} asn_t;
PRAGMA(pack());

PRAGMA(pack(1));
typedef struct {                                 // always written big endian, i.e. MSB in addr[0]
   uint8_t type;
   union {
      uint8_t addr_16b[2];
      uint8_t addr_64b[8];
      uint8_t addr_128b[16];
      uint8_t panid[2];
      uint8_t prefix[8];
   };
} open_addr_t;
PRAGMA(pack());

typedef struct {
   //admin
   uint8_t       creator;                        // the component which called getFreePacketBuffer()
   uint8_t       owner;                          // the component which currently owns the entry
   uint8_t*      payload;                        // pointer to the start of the payload within 'packet'
   uint8_t       length;                         // length in bytes of the payload
   //l4
   uint8_t       l4_protocol;                    // l4 protocol to be used
   bool          l4_protocol_compressed;         // is the l4 protocol header compressed?
   uint16_t      l4_sourcePortORicmpv6Type;      // l4 source port
   uint16_t      l4_destination_port;            // l4 destination port
   uint8_t*      l4_payload;                     // pointer to the start of the payload of l4 (used for retransmits)
   uint8_t       l4_length;                      // length of the payload of l4 (used for retransmits)
   //l3
   open_addr_t   l3_destinationAdd;              // 128b IPv6 destination (down stack) 
   open_addr_t   l3_sourceAdd;                   // 128b IPv6 source address 
   //l2
   error_t       l2_sendDoneError;               // outcome of trying to send this packet
   open_addr_t   l2_nextORpreviousHop;           // 64b IEEE802.15.4 next (down stack) or previous (up) hop address
   uint8_t       l2_frameType;                   // beacon, data, ack, cmd
   uint8_t       l2_dsn;                         // sequence number of the received frame
   uint8_t       l2_retriesLeft;                 // number Tx retries left before packet dropped (dropped when hits 0)
   uint8_t       l2_numTxAttempts;               // number Tx attempts
   asn_t         l2_asn;                         // at what ASN the packet was Tx'ed or Rx'ed
   uint8_t*      l2_payload;                     // pointer to the start of the payload of l2 (used for MAC to fill in ASN in ADV)
   //l1 (drivers)
   uint8_t       l1_txPower;                     // power for packet to Tx at
   int8_t        l1_rssi;                        // RSSI of received packet
   uint8_t       l1_lqi;                         // LQI of received packet
   bool          l1_crc;                         // did received packet pass CRC check?
   //the packet
   uint8_t       packet[1+1+125+2+1];            // 1B spi address, 1B length, 125B data, 2B CRC, 1B LQI
} OpenQueueEntry_t;

//=========================== variables =======================================

//=========================== prototypes ======================================

void openwsn_init();

#endif
