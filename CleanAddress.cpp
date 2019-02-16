// leanAddress.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "CleanAddress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CleanAddress dialog


CleanAddress::CleanAddress(CWnd* pParent /*=NULL*/)
	: CDialog(CleanAddress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CleanAddress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CleanAddress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CleanAddress)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CleanAddress, CDialog)
	//{{AFX_MSG_MAP(CleanAddress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CleanAddress message handlers

void CleanAddress::OnOK() 
{
	HKEY hkey;
	DWORD dwDisposition;
	DWORD val=0;
	LONG cond;
	int reponse;
	CString c;
	reponse=this->IsDlgButtonChecked(IDC_NoAdd);
	if(reponse==BST_CHECKED){
		RegDeleteKey(HKEY_LOCAL_MACHINE,TEXT("EXPLORER\\AddressHistory"));
	}else{
		RegCreateKeyExW(HKEY_LOCAL_MACHINE ,TEXT("EXPLORER\\AddressHistory"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
		RegCloseKey(hkey);
		
		reponse=this->IsDlgButtonChecked(IDC_CleanAdd);
		if(reponse==BST_CHECKED){
			do{
				c.Format(_T("%d"),val);
				RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("EXPLORER\\AddressHistory"),0,
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

BOOL CleanAddress::OnInitDialog() 
{	
	HKEY hkey;
	long rep;
	CDialog::OnInitDialog();
	rep=RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("EXPLORER\\AddressHistory"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegCloseKey(hkey);
	if(rep==ERROR_SUCCESS){
		this->CheckDlgButton(IDC_NoAdd,false);
	}
	else{
		this->CheckDlgButton(IDC_NoAdd,true);
	}
	return TRUE;
}
