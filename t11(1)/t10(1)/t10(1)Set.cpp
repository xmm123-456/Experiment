
// t10(1)Set.cpp : Ct101Set ���ʵ��
//

#include "stdafx.h"
#include "t10(1).h"
#include "t10(1)Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct101Set ʵ��

// ���������� 2020��5��11��, 13:58

IMPLEMENT_DYNAMIC(Ct101Set, CRecordset)

Ct101Set::Ct101Set(CDatabase* pdb)
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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Ct101Set::GetDefaultConnect()
{
	
	return _T("DSN=����Դ_ѧ����Ϣ1;DBQ=C:\\USERS\\ADMINISTRATOR\\Desktop\\data1.accdb;DriverId=25;FIL = MS Access; MaxBufferSize = 2048; PageTimeout = 5; UID = admin; ");
}

CString Ct101Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ]");
}

void Ct101Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Long(pFX, _T("[����]"), column3);
	RFX_Text(pFX, _T("[��Ƭ]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// Ct101Set ���

#ifdef _DEBUG
void Ct101Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ct101Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

