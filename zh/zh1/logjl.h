#pragma once
#include "afxwin.h"


// logjl �Ի���

class logjl : public CDialogEx
{
	DECLARE_DYNAMIC(logjl)

public:
	logjl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~logjl();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox jl;
	CStringArray s;
	virtual BOOL OnInitDialog();
};
