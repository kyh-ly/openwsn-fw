if (NOT LOG_LEVEL)
    set(LOG_LEVEL "6" CACHE STRING "Select a logging level: 0 (no logs) - 6 (all logs)" FORCE)
    add_definitions(-DOPENWSN_LOG_LEVEL=${LOG_LEVEL})
else ()
    add_definitions(-DOPENWSN_LOG_LEVEL=${LOG_LEVEL})
endif ()

option(COAP "Enable the COAP protocol" OFF)
if (COAP)
    add_definitions(-DOPENWSN_COAP_C)
    set(OPENWSN_COAP_C "1")
else ()
    set(OPENWSN_COAP_C "0")
endif ()

option(UDP "Enable the UDP protocol" OFF)
if (UDP)
    add_definitions(-DOPENWSN_UDP_C)
    set(OPENWSN_UDP_C "1")
else ()
    set(OPENWSN_UDP_C "0")
endif ()

option(FRAG "Enable 6LoWPAN fragmentation" OFF)
if (FRAG)
    add_definitions(-DOPENWSN_6LO_FRAGMENTATION_C)
    set(OPENWSN_6LO_FRAGMENTATION_C "1")
else ()
    set(OPENWSN_6LO_FRAGMENTATION_C "0")
endif ()

option(PING "Enable the ping functionality (icmpv6_echo)" OFF)
if (PING)
    add_definitions(-DOPENWSN_ICMPV6ECHO_C)
    set(OPENWSN_ICMPV6ECHO_C "1")
else ()
    set(OPENWSN_ICMPV6ECHO_C "0")
endif ()

option(CJOIN "Enable the ping functionality" OFF)
if (CJOIN)
    add_definitions(-DOPENWSN_CJOIN_C)
    set(OPENWSN_CJOIN_C "1")
else ()
    set(OPENWSN_CJOIN_C "0")
endif ()

option(UECHO "Enable the ping functionality" OFF)
if (UECHO)
    add_definitions(-DOPENWSN_UECHO_C)
    set(OPENWSN_UECHO_C "1")
else ()
    set(OPENWSN_UECHO_C "0")
endif ()

option(ADAPTIVE_MSF "Enable the adaptive MSF functionality" OFF)
if (ADAPTIVE_MSF)
    add_definitions(-DADAPTIVE_MSF)
    set(ADAPTIVE_MSF "1")
else ()
    set(ADAPTIVE_MSF "0")
endif ()

option(DAGROOT "Configure the build as DAGroot" OFF)
if (DAGROOT)
    add_definitions(-DDAGROOT)
    set(DAGROOT "1")
else ()
    set(DAGROOT "0")
endif ()

option(PRINTF "Enable printf functionality" OFF)
if (PRINTF)
    add_definitions(-DBOARD_OPENSERIAL_PRINTF)
    set(BOARD_OPENSERIAL_PRINTF "1")
else ()
    set(BOARD_OPENSERIAL_PRINTF "0")
endif ()