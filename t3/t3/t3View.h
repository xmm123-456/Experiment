
// t3View.h : Ct3View 类的接口
//

#pragma once


class Ct3View : public CView
{
protected: // 仅从序列化创建
	Ct3View();
	DECLARE_DYNCREATE(Ct3View)

// 特性
public:
	Ct3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ct3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // t3View.cpp 中的调试版本
inline Ct3Doc* Ct3View::GetDocument() const
   { return reinterpret_cast<Ct3Doc*>(m_pDocument); }
#endif

