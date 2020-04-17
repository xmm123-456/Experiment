
// 课后练习8View.h : C课后练习8View 类的接口
//

#pragma once


class C课后练习8View : public CView
{
protected: // 仅从序列化创建
	C课后练习8View();
	DECLARE_DYNCREATE(C课后练习8View)

// 特性
public:
	C课后练习8Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C课后练习8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void Ontanchu();
};

#ifndef _DEBUG  // 课后练习8View.cpp 中的调试版本
inline C课后练习8Doc* C课后练习8View::GetDocument() const
   { return reinterpret_cast<C课后练习8Doc*>(m_pDocument); }
#endif

