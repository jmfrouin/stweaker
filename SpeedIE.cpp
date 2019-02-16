// SpeedIE.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "SpeedIE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SpeedIE dialog


SpeedIE::SpeedIE(CWnd* pParent /*=NULL*/)
	: CDialog(SpeedIE::IDD, pParent)
{
	//{{AFX_DATA_INIT(SpeedIE)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SpeedIE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SpeedIE)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SpeedIE, CDialog)
	//{{AFX_MSG_MAP(SpeedIE)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SpeedIE message handlers

void SpeedIE::OnOK() 
{
	HKEY hkey;
	DWORD dwDisposition;
	DWORD val;
	int reponse;
	static const TCHAR szRegValue[] = TEXT("Limit");
	reponse=this->IsDlgButtonChecked(IDC_SpeedPIE);
	RegCreateKeyExW(HKEY_LOCAL_MACHINE ,TEXT("SYSTEM\\GDI\\GLYPHCACHE"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
	if(reponse==BST_CHECKED){
		val=64000;
	}else{
		val=32768;
	}
	RegSetValueExW(hkey,szRegValue, NULL, REG_DWORD,(PBYTE)&val,sizeof(val));
	RegCloseKey(hkey);
	CDialog::OnOK();
}

BOOL SpeedIE::OnInitDialog() 
{
	HKEY hkey;
	DWORD val;
	DWORD dwType;
	DWORD dwLength;
	CDialog::OnInitDialog();
	RegOpenKeyEx(HKEY_LOCAL_MACHINE ,TEXT("SYSTEM\\GDI\\GLYPHCACHE"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("Limit"), NULL, &dwType,(LPBYTE)&val, &dwLength);
	RegCloseKey(hkey);
	if(val==64000)
		this->CheckDlgButton(IDC_SpeedPIE,true);
	else
		this->CheckDlgButton(IDC_SpeedPIE,false);
	return TRUE;
}
