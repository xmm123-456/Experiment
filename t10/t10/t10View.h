
// t10View.h : Ct10View ��Ľӿ�
//

#pragma once


class Ct10View : public CView
{
protected: // �������л�����
	Ct10View();
	DECLARE_DYNCREATE(Ct10View)

// ����
public:
	Ct10Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ct10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // t10View.cpp �еĵ��԰汾
inline Ct10Doc* Ct10View::GetDocument() const
   { return reinterpret_cast<Ct10Doc*>(m_pDocument); }
#endif

