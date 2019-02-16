// STweaker 2004.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "STweaker 2004.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int Choix=0;
/////////////////////////////////////////////////////////////////////////////
// CSTweaker2004App

BEGIN_MESSAGE_MAP(CSTweaker2004App, CWinApp)
	//{{AFX_MSG_MAP(CSTweaker2004App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSTweaker2004App construction

CSTweaker2004App::CSTweaker2004App()
	: CWinApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSTweaker2004App object

CSTweaker2004App theApp;

/////////////////////////////////////////////////////////////////////////////
// CSTweaker2004App initialization

BOOL CSTweaker2004App::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object.

	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	// create and load the frame with its resources

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);



	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSTweaker2004App message handlers





/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();		// Added for WCE apps
	afx_msg void OnLienHTTP();
	afx_msg void OnLien();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_Lien, OnLien)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CSTweaker2004App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CSTweaker2004App commands
// Added for WCE apps

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CenterWindow();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CAboutDlg::OnLien() 
{
	SHELLEXECUTEINFO blob;
	blob.cbSize=sizeof(SHELLEXECUTEINFO);
	blob.fMask=SEE_MASK_FLAG_NO_UI;
	blob.hwnd=NULL;
	blob.lpVerb=_T("open");
	blob.lpFile=_T("http://snoogie.free.fr");
	blob.lpParameters=NULL;
	blob.lpDirectory=NULL;
	blob.nShow=SW_SHOW;
	ShellExecuteEx(&blob);	
}
