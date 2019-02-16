// leanRun.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "CleanRun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CleanRun dialog


CleanRun::CleanRun(CWnd* pParent /*=NULL*/)
	: CDialog(CleanRun::IDD, pParent)
{
	//{{AFX_DATA_INIT(CleanRun)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CleanRun::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CleanRun)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CleanRun, CDialog)
	//{{AFX_MSG_MAP(CleanRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CleanRun message handlers

BOOL CleanRun::OnInitDialog() 
{
	HKEY hkey;
	long rep;
	CDialog::OnInitDialog();
	rep=RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("EXPLORER\\RunHistory"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegCloseKey(hkey);
	if(rep==ERROR_SUCCESS){
		this->CheckDlgButton(IDC_NoRun,false);
	}
	else{
		this->CheckDlgButton(IDC_NoRun,true);
	}
	return TRUE;	
}

void CleanRun::OnOK() 
{
	HKEY hkey;
	DWORD dwDisposition;
	DWORD val=0;
	LONG cond;
	int reponse;
	CString c;
	reponse=this->IsDlgButtonChecked(IDC_NoRun);
	if(reponse==BST_CHECKED){
		RegDeleteKey(HKEY_LOCAL_MACHINE,TEXT("EXPLORER\\RunHistory"));
	}else{
		RegCreateKeyExW(HKEY_LOCAL_MACHINE ,TEXT("EXPLORER\\RunHistory"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
		RegCloseKey(hkey);

		reponse=this->IsDlgButtonChecked(IDC_CleanRun);
		if(reponse==BST_CHECKED){
			do{
				c.Format(_T("%d"),val);
				RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("EXPLORER\\RunHistory"),0,
				KEY_SET_VALUE,&hkey); 
				cond=RegDeleteValue(hkey,c);
				RegCloseKey(hkey);
				val++;
			}while(cond==ERROR_SUCCESS);
			AfxMessageBox(_T("Cleaned !"),MB_OK,1);
		}else{
			AfxMessageBox(_T("Not cleaned !"),MB_OK,2);
		}
	}
	CDialog::OnOK();
}
