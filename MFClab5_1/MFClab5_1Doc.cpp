// MFClab5_1Doc.cpp : implementation of the CMFClab5_1Doc class
//

#include "stdafx.h"
#include "MFClab5_1.h"

#include "MFClab5_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1Doc

IMPLEMENT_DYNCREATE(CMFClab5_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFClab5_1Doc, CDocument)
	//{{AFX_MSG_MAP(CMFClab5_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1Doc construction/destruction

CMFClab5_1Doc::CMFClab5_1Doc()
{
	// TODO: add one-time construction code here
		

 m_startRect=false;   //绘制矩形框标志
 m_startPoint.x=0; //矩形框开始点
 m_startPoint.y=0;
 m_OldPoint.x=150;   //矩形框终点（但是它是上一次的点，所以这里用了Old标识）
 m_OldPoint.y=150;

}

CMFClab5_1Doc::~CMFClab5_1Doc()
{
}

BOOL CMFClab5_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1Doc serialization

void CMFClab5_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1Doc diagnostics

#ifdef _DEBUG
void CMFClab5_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFClab5_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1Doc commands
