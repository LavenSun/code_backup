#pragma once
#include <cstddef>
class CopyString
{
public:
	CopyString(const char* p = NULL); //Ĭ�ϲ���ֻ����������
	~CopyString();
	CopyString(const CopyString& another); //������������ǳ�����������Ҫ�Լ�ʵ��
	//ϵͳ��Ĭ�Ͽ�����������һ���Լ�д��Ĭ�ϵ�ʧЧ
	CopyString& operator=(const CopyString& another);
	CopyString operator+(const CopyString& another);
	bool operator>(const CopyString& another);
	bool operator<(const CopyString& another);
	bool operator==(const CopyString& another);
	char& operator[](int index);
	char at(int index);
	//Ĭ�����������Ҳ��һ�ֵ�λ��ֵ��ǳ��ֵ(���ܵ����ڴ�й©���ظ��������Ը�ֵ��
	char* c_str();
private:
	char* _str;
};

