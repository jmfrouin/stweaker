// ShellSwaper.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "ShellSwaper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ShellSwaper dialog


ShellSwaper::ShellSwaper(CWnd* pParent /*=NULL*/)
	: CDialog(ShellSwaper::IDD, pParent)
{
	//{{AFX_DATA_INIT(ShellSwaper)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ShellSwaper::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ShellSwaper)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ShellSwaper, CDialog)
	//{{AFX_MSG_MAP(ShellSwaper)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ShellSwaper message handlers

BOOL ShellSwaper::OnInitDialog() 
{
	HKEY hkey;
	char name[255];
	DWORD dwType;
	DWORD dwLength;	
	CDialog::OnInitDialog();

	RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("init"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("Launch10"), NULL, &dwType,(LPBYTE)&name, &dwLength);
	RegCloseKey(hkey);
	this->SetDlgItemText(IDC_Shellname,LPCTSTR(name));
	
	return TRUE;
}
