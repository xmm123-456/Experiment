
// t11_3Set.cpp : Ct11_3Set 类的实现
//

#include "stdafx.h"
#include "t11_3.h"
#include "t11_3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct11_3Set 实现

// 代码生成在 2020年5月19日, 9:55

IMPLEMENT_DYNAMIC(Ct11_3Set, CRecordset)

Ct11_3Set::Ct11_3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = 0;
	column4 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Ct11_3Set::GetDefaultConnect()
{
	return _T("DSN=数据源_学生信息1;DBQ=C:\\USERS\\ADMINISTRATOR\\Desktop\\data1.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Ct11_3Set::GetDefaultSQL()
{
	return _T("[学生信息]");
}

void Ct11_3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Text(pFX, _T("[学号]"), column2);
	RFX_Long(pFX, _T("[年龄]"), column3);
	RFX_Text(pFX, _T("[相片]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// Ct11_3Set 诊断

#ifdef _DEBUG
void Ct11_3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ct11_3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

