#pragma once


// logzj �Ի���

class logzj : public CDialogEx
{
	DECLARE_DYNAMIC(logzj)

public:
	logzj(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~logzj();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit8();
	CString xm;
	CString xh;
	CString zy;
	CString xb;

	CString hm;
	double csny;
	CString zz;
	CString lj;
};
