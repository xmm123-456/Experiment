
// 课后练习9View.h : C课后练习9View 类的接口
//

#pragma once


class C课后练习9View : public CView
{
protected: // 仅从序列化创建
	C课后练习9View();
	DECLARE_DYNCREATE(C课后练习9View)

// 特性
public:
	C课后练习9Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C课后练习9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onlujing();
	afx_msg void Onxianshi();

	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 课后练习9View.cpp 中的调试版本
inline C课后练习9Doc* C课后练习9View::GetDocument() const
   { return reinterpret_cast<C课后练习9Doc*>(m_pDocument); }
#endif

