// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "STweaker 2004.h"

#include "MainFrm.h"
#include "Rename.h"
#include "Animation.h"
#include "SpeedIE.h"
#include "Hide.h"
#include "CleanAddress.h"
#include "CleanRun.h"
#include "ShellSwaper.h"
#include "Startup.h"
#include "IEAmelioration.h"
#include "Infos.h"
#include "Power.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const DWORD dwAdornmentFlags = 0; // exit button

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_CP, OnCp)
	ON_COMMAND(ID_ANIMATION, OnAnimation)
	ON_COMMAND(ID_SpeedPIE, OnSpeedPIE)
	ON_COMMAND(ID_Hide, OnHide)
	ON_COMMAND(ID_CleanAdd, OnCleanAdd)
	ON_COMMAND(ID_CleanRun, OnCleanRun)
	ON_COMMAND(IDC_SHELL, OnShell)
	ON_COMMAND(ID_HELP, OnHelp)
	ON_COMMAND(IDC_Startup, OnStartup)
	ON_COMMAND(ID_Advanced, OnAdvanced)
	ON_COMMAND(ID_Infos, OnInfos)
	ON_WM_PAINT()
	ON_COMMAND(ID_POWER, OnPower)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	
#if defined(_WIN32_WCE_PSPC) // MFC for Palm-Size PC
	if(!m_wndCommandBar.Create(this) ||
	   !m_wndCommandBar.InsertMenuBar(IDR_MAINFRAME) ||
	   !m_wndCommandBar.AddAdornments(dwAdornmentFlags) ||
	   !m_wndCommandBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create CommandBar\n");
		return -1;      // fail to create
	}
#else // MFC for Windows CE 2.1 or later
	if(!m_wndCommandBar.Create(this) ||
	   !m_wndCommandBar.InsertMenuBar(IDR_MAINFRAME) ||
	   !m_wndCommandBar.InsertSeparator(6) ||
	   !m_wndCommandBar.LoadToolBar(IDR_MAINFRAME) ||
	   !m_wndCommandBar.AddAdornments(dwAdornmentFlags))
	{
		TRACE0("Failed to create CommandBar\n");
		return -1;      // fail to create
	}
#endif

	m_wndCommandBar.SetBarStyle(m_wndCommandBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_FIXED);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	//  the CREATESTRUCT cs

	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnCp() 
{
	
	Rename d;
	d.DoModal();
}


void CMainFrame::OnAnimation() 
{
	Animation d;
	d.DoModal();
}

void CMainFrame::OnSpeedPIE() 
{
	SpeedIE d;
	d.DoModal();
}

void CMainFrame::OnHide() 
{
	Hide d;
	d.DoModal();
}

void CMainFrame::OnCleanAdd() 
{
	CleanAddress d;
	d.DoModal();
}

void CMainFrame::OnCleanRun() 
{
	CleanRun d;
	d.DoModal();
	
}


void CMainFrame::OnShell() 
{
	ShellSwaper d;
	d.DoModal();
}

void CMainFrame::OnHelp() 
{

	MessageBox(_T("STweaker2004.htp"));	
}

void CMainFrame::OnStartup() 
{
	Startup d;
	d.DoModal();
}

void CMainFrame::OnAdvanced() 
{
	IEAmelioration d;
	d.DoModal();
}

void CMainFrame::OnInfos() 
{
	Infos d;
	d.DoModal();
}

void CMainFrame::OnPower() 
{
	Power d;
	d.DoModal();
}
