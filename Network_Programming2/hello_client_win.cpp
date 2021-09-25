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
	//SOCKETǰ��һЩ��飬���Э���İ汾��Ϊ�˱����İ汾��socket������ͨ��
	//WSAStartup������Ӧ�İ汾��WSAStartup�Ĳ���һ���ǰ汾��Ϣ��һ����һЩ��ϸ��ϸ�ڣ�ע��ߵ�λ
	//WSAStartup��WSACleanup��Ӧ
	int err;
	WORD versionRequired;
	WSADATA wsaData;
	versionRequired = MAKEWORD(1, 1);
	err = WSAStartup(versionRequired, &wsaData);//Э���İ汾��Ϣ

	//ͨ��WSACleanup�ķ���ֵ��ȷ��socketЭ���Ƿ�����
	if (!err)
	{
		printf("�ͻ���Ƕ�����Ѿ���!\n");
	}
	else
	{
		printf("�ͻ��˵�Ƕ���ִ�ʧ��!\n");
		return 0;//����
	}
	//����socket����ؼ��ʣ�������һ���Ǹ�ͼ���е�socket�����
	//ע��socket�������������������������socket��������ϵͳ��socket�����ͣ��Լ�һЩ������Ϣ
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	//socket����У���������һ���ṹ��SOCKADDR_IN����������һЩ��Ϣ����socket��ϵͳ��
	//�˿ںţ�ip��ַ����Ϣ������洢���Ƿ������˵ļ��������Ϣ
	SOCKADDR_IN clientsock_in;
	clientsock_in.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	clientsock_in.sin_family = AF_INET;
	clientsock_in.sin_port = htons(6000);

	//ǰ�ڶ������׽��֣������˷������˵ļ������һЩ��Ϣ�洢��clientsock_in�У�
	//׼��������ɺ�Ȼ��ʼ������׽������ӵ�Զ�̵ļ����
	//Ҳ���ǵ�һ������

	connect(clientSocket, (SOCKADDR*)&clientsock_in, sizeof(SOCKADDR));//��ʼ����


	char receiveBuf[100];

	//����socket���������
	recv(clientSocket, receiveBuf, 101, 0);
	printf("%s\n", receiveBuf);

	//����socket����
	send(clientSocket, "hello,this is client", strlen("hello,this is client") + 1, 0);

	//�ر��׽���
	closesocket(clientSocket);
	//�رշ���
	WSACleanup();
	return 0;
}
#endif
