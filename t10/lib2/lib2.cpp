// lib2.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "lib2.h"


// ���ǵ���������һ��ʾ��
LIB2_API int nlib2=0;

// ���ǵ���������һ��ʾ����
LIB2_API int fnlib2(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� lib2.h
Clib2::Clib2()
{
    return;
}
LIB2_API int factorial2(int n) {
	if (n == 0)
		return 1;
	return n*factorial2(n - 1);

}
LIB2_API float FAC2::convert(int a) {
	float d = (1.0*a / 180)*3.1415926;
	return d;
}