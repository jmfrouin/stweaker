// Animation.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "Animation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Animation dialog


Animation::Animation(CWnd* pParent /*=NULL*/)
	: CDialog(Animation::IDD, pParent)
{
	//{{AFX_DATA_INIT(Animation)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Animation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Animation)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Animation, CDialog)
	//{{AFX_MSG_MAP(Animation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Animation message handlers

void Animation::OnOK() 
{
	HKEY hkey;
	DWORD dwDisposition;
	DWORD val;
	int reponse;
	static const TCHAR szRegValue[] = TEXT("Animate");
	reponse=this->IsDlgButtonChecked(IDC_Animation);
	RegCreateKeyExW(HKEY_LOCAL_MACHINE ,TEXT("SYSTEM\\GWE"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
	if(reponse==BST_CHECKED){
		val=1;
	}else{
		val=0;
	}
	RegSetValueExW(hkey,szRegValue, NULL, REG_DWORD,(PBYTE)&val,sizeof(val));
	RegCloseKey(hkey);
	CDialog::OnOK();
}

BOOL Animation::OnInitDialog() 
{
	HKEY hkey;
	DWORD val;
	DWORD dwType;
	DWORD dwLength;

	CDialog::OnInitDialog();
	RegOpenKeyEx(HKEY_LOCAL_MACHINE ,TEXT("SYSTEM\\GWE"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("Animate"), NULL, &dwType,(LPBYTE)&val, &dwLength);
	RegCloseKey(hkey);
	if(val==1)
		this->CheckDlgButton(IDC_Animation,true);
	if(val==0)
		this->CheckDlgButton(IDC_Animation,false);
	return TRUE; 
}
