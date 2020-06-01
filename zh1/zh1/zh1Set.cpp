
// zh1Set.cpp : Czh1Set ���ʵ��
//

#include "stdafx.h"
#include "zh1.h"
#include "zh1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Czh1Set ʵ��

// ���������� 2020��5��25��, 11:37

IMPLEMENT_DYNAMIC(Czh1Set, CRecordset)

Czh1Set::Czh1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = 0.0;
	column6 = L"";
	column7 = L"";
	column8 = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Czh1Set::GetDefaultConnect()
{
	return _T("DSN=����Դ_ѧ����Ϣ3;DBQ=C:\\Users\\Administrator\\Desktop\\data2.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Czh1Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ]");
}

void Czh1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[רҵ]"), column3);
	RFX_Text(pFX, _T("[�Ա�]"), column4);
	RFX_Double(pFX, _T("[��������]"), column5);
	RFX_Text(pFX, _T("[�ֻ�����]"), column6);
	RFX_Text(pFX, _T("[��ͥסַ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// Czh1Set ���

#ifdef _DEBUG
void Czh1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void Czh1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

