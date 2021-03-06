/*
 *  Copyright (C) 2013-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

// needed for CNetworkInterfaceLinux::GetHostMacAddress and taken from osx sdk
// net/if_types.h net/route.h netinet/if_ether.h

/*
 * These numbers are used by reliable protocols for determining
 * retransmission behavior and are included in the routing structure.
 */
struct rt_metrics {
	u_int32_t	rmx_locks;	/* Kernel must leave these values alone */
	u_int32_t	rmx_mtu;	/* MTU for this path */
	u_int32_t	rmx_hopcount;	/* max hops expected */
	int32_t		rmx_expire;	/* lifetime for route, e.g. redirect */
	u_int32_t	rmx_recvpipe;	/* inbound delay-bandwidth product */
	u_int32_t	rmx_sendpipe;	/* outbound delay-bandwidth product */
	u_int32_t	rmx_ssthresh;	/* outbound gateway buffer limit */
	u_int32_t	rmx_rtt;	/* estimated round trip time */
	u_int32_t	rmx_rttvar;	/* estimated rtt variance */
	u_int32_t	rmx_pksent;	/* packets sent using this route */
	u_int32_t	rmx_filler[4];	/* will be used for T/TCP later */
};

/*
 * Structures for routing messages.
 */
struct rt_msghdr {
	u_short	rtm_msglen;		/* to skip over non-understood messages */
	u_char	rtm_version;		/* future binary compatibility */
	u_char	rtm_type;		/* message type */
	u_short	rtm_index;		/* index for associated ifp */
	int	rtm_flags;		/* flags, incl. kern & message, e.g. DONE */
	int	rtm_addrs;		/* bitmask identifying sockaddrs in msg */
	pid_t	rtm_pid;		/* identify sender */
	int	rtm_seq;		/* for sender to identify action */
	int	rtm_errno;		/* why failed */
	int	rtm_use;		/* from rtentry */
	u_int32_t rtm_inits;		/* which metrics we are initializing */
	struct rt_metrics rtm_rmx;	/* metrics themselves */
};
struct sockaddr_inarp {
	u_char	sin_len;
	u_char	sin_family;
	u_short sin_port;
	struct	in_addr sin_addr;
	struct	in_addr sin_srcaddr;
	u_short	sin_tos;
	u_short	sin_other;
#define SIN_PROXY 1
};
#define RTF_LLINFO	0x400		/* generated by link layer (e.g. ARP) */
// --- END
