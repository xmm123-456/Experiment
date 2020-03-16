
// t2Doc.h : Ct2Doc 类的接口
//


#pragma once


class Ct2Doc : public CDocument
{
protected: // 仅从序列化创建
	Ct2Doc();
	DECLARE_DYNCREATE(Ct2Doc)

// 特性g
public:

// 操作
public:
	int count;
	CString z,x,m,v;
	
	int A, B;
	int a, b;
	CRect c1, c2, c3,c4;

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Ct2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
