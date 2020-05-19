// lib2.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "lib2.h"


// 这是导出变量的一个示例
LIB2_API int nlib2=0;

// 这是导出函数的一个示例。
LIB2_API int fnlib2(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 lib2.h
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