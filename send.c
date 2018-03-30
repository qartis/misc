#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <netpacket/packet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

int main()
{
  int fd=socket(AF_PACKET,SOCK_DGRAM,htons(ETH_P_ARP));
  if (fd==-1) {
        die("%s",strerror(errno));
  }
  struct ifreq ifr;
  size_t if_name_len=strlen(if_name);
  if (if_name_len<sizeof(ifr.ifr_name)) {
        memcpy(ifr.ifr_name,if_name,if_name_len);
            ifr.ifr_name[if_name_len]=0;
  } else {
        die("interface name is too long");
  }
  if (ioctl(fd,SIOCGIFINDEX,&ifr)==-1) {
        die("%s",strerror(errno));
  }
  int ifindex=ifr.ifr_ifindex;
  const unsigned char ether_broadcast_addr[]=
        {0xff,0xff,0xff,0xff,0xff,0xff};

  struct sockaddr_ll addr={0};
  addr.sll_family=AF_PACKET;
  addr.sll_ifindex=ifindex;
  addr.sll_halen=ETHER_ADDR_LEN;
  addr.sll_protocol=htons(ETH_P_ARP);
  memcpy(addr.sll_addr,ether_broadcast_addr,ETHER_ADDR_LEN);
}
