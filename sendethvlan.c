#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/ether.h>

#define BCAST_VLAN 8

int main(int argc, char *argv[])
{
  int rc;
	int sockfd;
	struct ifreq if_idx;
	int tx_len = 0;
	char sendbuf[256];
	char dest[6];
	char src[6];
	struct sockaddr_ll socket_address;
	char *dev;
	int vlan;

	if (argc < 2) {
	  fprintf(stderr, "usage: %s dev [vlan] [dest_mac] [src_mac]\n", argv[0]);
	  exit(1);
  }

  dev = argv[1];

	vlan = BCAST_VLAN;
	if (argc > 2)
	  vlan = strtoul(argv[2], NULL, 0);

  if (argc > 3) {
    sscanf(argv[3], "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
        &dest[0], &dest[1], &dest[2], &dest[3], &dest[4], &dest[5]);
  } else if (vlan == BCAST_VLAN) {
    memcpy(dest, "\xff\xff\xff\xff\xff\xff", 6);
  } else {
    memcpy(dest, "\xaa\xbb\xcc\xdd\xee\xff", 6);
  }

  if (argc > 4) {
    sscanf(argv[4], "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
        &src[0], &src[1], &src[2], &src[3], &src[4], &src[5]);
  } else {
    memcpy(src, "\x00\x00\x00\x11\x11\x11", 6);
  }


	sockfd = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW);
	if (sockfd < 0)
    perror("socket");

	memset(&if_idx, 0, sizeof(struct ifreq));
	strncpy(if_idx.ifr_name, dev, IFNAMSIZ-1);
	rc = ioctl(sockfd, SIOCGIFINDEX, &if_idx);
	if (rc != 0)
    perror("SIOCGIFINDEX");

  sendbuf[tx_len++] = dest[0];
  sendbuf[tx_len++] = dest[1];
  sendbuf[tx_len++] = dest[2];
  sendbuf[tx_len++] = dest[3];
  sendbuf[tx_len++] = dest[4];
  sendbuf[tx_len++] = dest[5];
  sendbuf[tx_len++] = src[0];
  sendbuf[tx_len++] = src[1];
  sendbuf[tx_len++] = src[2];
  sendbuf[tx_len++] = src[3];
  sendbuf[tx_len++] = src[4];
  sendbuf[tx_len++] = src[5];
  sendbuf[tx_len++] = 0x81;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = vlan;
  sendbuf[tx_len++] = 0x08;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x45;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x54;
  sendbuf[tx_len++] = 0x94;
  sendbuf[tx_len++] = 0x6d;
  sendbuf[tx_len++] = 0x40;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x40;
  sendbuf[tx_len++] = 0x01;
  sendbuf[tx_len++] = 0x9f;
  sendbuf[tx_len++] = 0xc1;
  sendbuf[tx_len++] = 0xac;
  sendbuf[tx_len++] = 0x1b;
  sendbuf[tx_len++] = 0x58;
  sendbuf[tx_len++] = 0x56;
  sendbuf[tx_len++] = 0x01;
  sendbuf[tx_len++] = 0x01;
  sendbuf[tx_len++] = 0x01;
  sendbuf[tx_len++] = 0x08;
  sendbuf[tx_len++] = 0x08;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0xfa;
  sendbuf[tx_len++] = 0x84;
  sendbuf[tx_len++] = 0x22;
  sendbuf[tx_len++] = 0x4d;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x03;
  sendbuf[tx_len++] = 0x70;
  sendbuf[tx_len++] = 0x9b;
  sendbuf[tx_len++] = 0x6a;
  sendbuf[tx_len++] = 0x56;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x36;
  sendbuf[tx_len++] = 0x66;
  sendbuf[tx_len++] = 0x0b;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x00;
  sendbuf[tx_len++] = 0x10;
  sendbuf[tx_len++] = 0x11;
  sendbuf[tx_len++] = 0x12;
  sendbuf[tx_len++] = 0x13;
  sendbuf[tx_len++] = 0x14;
  sendbuf[tx_len++] = 0x15;
  sendbuf[tx_len++] = 0x16;
  sendbuf[tx_len++] = 0x17;
  sendbuf[tx_len++] = 0x18;
  sendbuf[tx_len++] = 0x19;
  sendbuf[tx_len++] = 0x1a;
  sendbuf[tx_len++] = 0x1b;
  sendbuf[tx_len++] = 0x1c;
  sendbuf[tx_len++] = 0x1d;
  sendbuf[tx_len++] = 0x1e;
  sendbuf[tx_len++] = 0x1f;
  sendbuf[tx_len++] = 0x20;
  sendbuf[tx_len++] = 0x21;
  sendbuf[tx_len++] = 0x22;
  sendbuf[tx_len++] = 0x23;
  sendbuf[tx_len++] = 0x24;
  sendbuf[tx_len++] = 0x25;
  sendbuf[tx_len++] = 0x26;
  sendbuf[tx_len++] = 0x27;
  sendbuf[tx_len++] = 0x28;
  sendbuf[tx_len++] = 0x29;
  sendbuf[tx_len++] = 0x2a;
  sendbuf[tx_len++] = 0x2b;
  sendbuf[tx_len++] = 0x2c;
  sendbuf[tx_len++] = 0x2d;
  sendbuf[tx_len++] = 0x2e;
  sendbuf[tx_len++] = 0x2f;
  sendbuf[tx_len++] = 0x30;
  sendbuf[tx_len++] = 0x31;
  sendbuf[tx_len++] = 0x32;
  sendbuf[tx_len++] = 0x33;
  sendbuf[tx_len++] = 0x34;
  sendbuf[tx_len++] = 0x35;
  sendbuf[tx_len++] = 0x36;
  sendbuf[tx_len++] = 0x37;

	socket_address.sll_ifindex = if_idx.ifr_ifindex;
	socket_address.sll_halen = ETH_ALEN;

	if (sendto(sockfd, sendbuf, tx_len, 0, (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll)) < 0)
	    printf("Send failed\n");

	return 0;
}
