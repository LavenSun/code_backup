#if 0
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma warning(disable : 4996)
void ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen;
	//if (argc != 3)
	//{
	//	printf("Usage : %s\n", argv[0]);
	//	exit(1);
	//}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);;
	if (hSocket == INVALID_SOCKET)
		ErrorHandling("socket() error!");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(6000);

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");

	strLen = recv(hSocket, message, sizeof(message) - 1, 0);
	if (strLen == -1)
		ErrorHandling("read() error!");
	printf("Message from server: %s \n", message);

	closesocket(hSocket);
	WSACleanup();
	return 0;
}
#endif

#if 0
#include<WinSock2.h>            
#include<stdio.h>
#pragma warning(disable : 4996)
int main()
{
	//SOCKET前的一些检查，检查协议库的版本，为了避免别的版本的socket，并且通过
	//WSAStartup启动对应的版本，WSAStartup的参数一个是版本信息，一个是一些详细的细节，注意高低位
	//WSAStartup与WSACleanup对应
	int err;
	WORD versionRequired;
	WSADATA wsaData;
	versionRequired = MAKEWORD(1, 1);
	err = WSAStartup(versionRequired, &wsaData);//协议库的版本信息

	//通过WSACleanup的返回值来确定socket协议是否启动
	if (!err)
	{
		printf("客户端嵌套字已经打开!\n");
	}
	else
	{
		printf("客户端的嵌套字打开失败!\n");
		return 0;//结束
	}
	//创建socket这个关键词，这里想一下那个图形中的socket抽象层
	//注意socket这个函数，他三个参数定义了socket的所处的系统，socket的类型，以及一些其他信息
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	//socket编程中，它定义了一个结构体SOCKADDR_IN来存计算机的一些信息，像socket的系统，
	//端口号，ip地址等信息，这里存储的是服务器端的计算机的信息
	SOCKADDR_IN clientsock_in;
	clientsock_in.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	clientsock_in.sin_family = AF_INET;
	clientsock_in.sin_port = htons(6000);

	//前期定义了套接字，定义了服务器端的计算机的一些信息存储在clientsock_in中，
	//准备工作完成后，然后开始将这个套接字链接到远程的计算机
	//也就是第一次握手

	connect(clientSocket, (SOCKADDR*)&clientsock_in, sizeof(SOCKADDR));//开始连接


	char receiveBuf[100];

	//解释socket里面的内容
	recv(clientSocket, receiveBuf, 101, 0);
	printf("%s\n", receiveBuf);

	//发送socket数据
	send(clientSocket, "hello,this is client", strlen("hello,this is client") + 1, 0);

	//关闭套接字
	closesocket(clientSocket);
	//关闭服务
	WSACleanup();
	return 0;
}
#endif
