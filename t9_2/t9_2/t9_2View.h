
// t9_2View.h : Ct9_2View ��Ľӿ�
//

#pragma once


class Ct9_2View : public CView
{
protected: // �������л�����
	Ct9_2View();
	DECLARE_DYNCREATE(Ct9_2View)

// ����
public:
	Ct9_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ct9_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // t9_2View.cpp �еĵ��԰汾
inline Ct9_2Doc* Ct9_2View::GetDocument() const
   { return reinterpret_cast<Ct9_2Doc*>(m_pDocument); }
#endif

