// Hide.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "Hide.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Hide dialog


Hide::Hide(CWnd* pParent /*=NULL*/)
	: CDialog(Hide::IDD, pParent)
{
	//{{AFX_DATA_INIT(Hide)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Hide::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Hide)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Hide, CDialog)
	//{{AFX_MSG_MAP(Hide)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Hide message handlers

void Hide::OnOK() 
{
	HKEY hkey;
	DWORD dwDisposition;
	DWORD val;
	int reponse;
	static const TCHAR szRegValue[] = TEXT("");
	reponse=this->IsDlgButtonChecked(IDC_Hide);
	RegCreateKeyExW(HKEY_LOCAL_MACHINE ,TEXT("Software\\Microsoft\\Shell\\AutoHide"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
	if(reponse==BST_CHECKED){
		val=1;
	}else{
		val=0;
	}
	RegSetValueExW(hkey,szRegValue, NULL, REG_DWORD,(PBYTE)&val,sizeof(val));
	RegCloseKey(hkey);
	AfxMessageBox(_T("This tweak need a soft reset"),MB_OK,0);
	CDialog::OnOK();
}

BOOL Hide::OnInitDialog() 
{
	HKEY hkey;
	DWORD val;
	DWORD dwType;
	DWORD dwLength;
	CDialog::OnInitDialog();
	RegOpenKeyEx(HKEY_LOCAL_MACHINE ,TEXT("Software\\Microsoft\\Shell\\AutoHide"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT(""), NULL, &dwType,(LPBYTE)&val, &dwLength);
	RegCloseKey(hkey);
	if(val==1)
		this->CheckDlgButton(IDC_Hide,true);
	if(val==0)
		this->CheckDlgButton(IDC_Hide,false);
	return TRUE;
}
