/* util.h

Headers for reusable functions associated with Allen Downey's trout function.

*/
#ifndef util_h
#define util_h

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <sys/types.h>
#include <stdarg.h>
#include <syslog.h>
#include <unistd.h>

#define MAXLINE 4096

typedef void Sigfunc(int);                                                      

char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);               
void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);             
int sock_cmp_addr(const struct sockaddr *sa1,                                   
          const struct sockaddr *sa2, socklen_t salen);                         
void tv_sub (struct timeval *out, struct timeval *in);                          
char *icmpcode_v4(int code);                                                    
Sigfunc *Signal(int signo, Sigfunc *func);                                      
void *Calloc(size_t n, size_t size);                                            
void Gettimeofday(struct timeval *tv, void *foo);                               
void Pipe(int *fds);                                                            
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);                  
void Setsockopt(int fd, int level, int optname, const void *optval,             
        socklen_t optlen);  

#endif
