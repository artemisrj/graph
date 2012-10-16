// MFClab5_1View.cpp : implementation of the CMFClab5_1View class
//

#include "stdafx.h"
#include "MFClab5_1.h"

#include "MFClab5_1Doc.h"
#include "MFClab5_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1View

IMPLEMENT_DYNCREATE(CMFClab5_1View, CView)

BEGIN_MESSAGE_MAP(CMFClab5_1View, CView)
	//{{AFX_MSG_MAP(CMFClab5_1View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1View construction/destruction

CMFClab5_1View::CMFClab5_1View()
{
	// TODO: add construction code here

}

CMFClab5_1View::~CMFClab5_1View()
{
}

BOOL CMFClab5_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1View drawing

void CMFClab5_1View::OnDraw(CDC* pDC)
{
	CMFClab5_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->MoveTo(pDoc->m_startPoint.x,pDoc->m_startPoint.y);
	pDC->LineTo(pDoc->m_OldPoint.x,pDoc->m_OldPoint.y);
}

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1View printing

BOOL CMFClab5_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFClab5_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFClab5_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1View diagnostics

#ifdef _DEBUG
void CMFClab5_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFClab5_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFClab5_1Doc* CMFClab5_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFClab5_1Doc)));
	return (CMFClab5_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFClab5_1View message handlers

void CMFClab5_1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMFClab5_1Doc* pDoc = GetDocument();  
	ASSERT_VALID(pDoc);    //check it 
	pDoc->m_startPoint.x = point.x;  
	pDoc->m_startPoint.y = point.y;  
	pDoc->m_startRect = TRUE;
	
	CView::OnLButtonDown(nFlags, point);
}

void CMFClab5_1View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMFClab5_1Doc* pDoc = GetDocument();  
	ASSERT_VALID(pDoc);    
	pDoc->m_OldPoint.x = point.x;  
	pDoc->m_OldPoint.y = point.y;   
	pDoc->m_startRect = FALSE;  
	//Invalidate( );

	CView::OnLButtonUp(nFlags, point);
}

void CMFClab5_1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMFClab5_1Doc* pDoc = GetDocument();  
	CView::OnMouseMove(nFlags, point);
	if(pDoc->m_startRect == TRUE)  
	{   
		pDoc->m_startPoint.x = point.x;   
		pDoc->m_startPoint.y = point.y;    
		Invalidate();    
	}
}
