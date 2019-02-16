// Rename.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "Rename.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Rename dialog


Rename::Rename(CWnd* pParent /*=NULL*/)
	: CDialog(Rename::IDD, pParent)
{
	//{{AFX_DATA_INIT(Rename)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Rename::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Rename)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Rename, CDialog)
	//{{AFX_MSG_MAP(Rename)
	ON_BN_CLICKED(IDC_CP, OnCp)
	ON_BN_CLICKED(IDC_MyHPC, OnMyHPC)
	ON_BN_CLICKED(IDC_Databases, OnDatabases)
	ON_BN_CLICKED(IDC_Recycle, OnRecycle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Rename message handlers

void Rename::OnOK() 
{
	HKEY hkey;
	DWORD dwDisposition;
	static const TCHAR szRegValue[] = TEXT("DisplayName");
	char Titre[100];
	int reponse;
	this->GetDlgItemText(IDC_Name,LPTSTR(Titre),100);
	if(strlen(Titre)==0){
		reponse=AfxMessageBox(_T("Empty title can be instable !!\nAre you sure ?"),MB_YESNO,0);
	}
	if(reponse==IDNO){
		AfxMessageBox(_T("Not applied !!"),MB_OK,0);
	}
	else{
		reponse=this->IsDlgButtonChecked(IDC_Recycle);
		if(reponse==BST_CHECKED){
			RegCreateKeyExW(HKEY_CLASSES_ROOT,TEXT("{000214A1-0000-0000-C000-000000000046}"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
			RegSetValueExW(hkey,szRegValue, NULL, REG_SZ, (PBYTE)&Titre, sizeof(Titre));
			RegCloseKey(hkey);
		}
		reponse=this->IsDlgButtonChecked(IDC_CP);
		if(reponse==BST_CHECKED){
			RegCreateKeyExW(HKEY_CLASSES_ROOT,TEXT("{000314fe-0000-0000-C000-000000000046}"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
			RegSetValueExW(hkey,szRegValue, NULL, REG_SZ, (PBYTE)&Titre, sizeof(Titre));
			RegCloseKey(hkey);
		}
		reponse=this->IsDlgButtonChecked(IDC_MyHPC);
		if(reponse==BST_CHECKED){
			RegCreateKeyExW(HKEY_CLASSES_ROOT,TEXT("{000214A0-0000-0000-C000-000000000046}"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
			RegSetValueExW(hkey,szRegValue, NULL, REG_SZ, (PBYTE)&Titre, sizeof(Titre));
			RegCloseKey(hkey);
		}
		reponse=this->IsDlgButtonChecked(IDC_Databases);
		if(reponse==BST_CHECKED){
			RegCreateKeyExW(HKEY_CLASSES_ROOT,TEXT("{000214A4-0000-0000-C000-000000000046}"), \
			0, NULL, 0, KEY_ALL_ACCESS, NULL, &hkey, &dwDisposition);
			RegSetValueExW(hkey,szRegValue, NULL, REG_SZ, (PBYTE)&Titre, sizeof(Titre));
			RegCloseKey(hkey);
		}
	}
	CDialog::OnOK();
}

BOOL Rename::OnInitDialog() 
{
	CDialog::OnInitDialog();
	return TRUE;
}

void Rename::OnCp() 
{
	HKEY hkey;
	char name[255];
	DWORD dwType;
	DWORD dwLength;	
	RegOpenKeyEx(HKEY_CLASSES_ROOT,TEXT("{000314fe-0000-0000-C000-000000000046}"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("DisplayName"), NULL, &dwType,(LPBYTE)&name, &dwLength);
	RegCloseKey(hkey);
	this->SetDlgItemText(IDC_Name,LPCTSTR(name));
}

void Rename::OnMyHPC() 
{
	HKEY hkey;
	char name[255];
	DWORD dwType;
	DWORD dwLength;	
	RegOpenKeyEx(HKEY_CLASSES_ROOT,TEXT("{000214A0-0000-0000-C000-000000000046}"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("DisplayName"), NULL, &dwType,(LPBYTE)&name, &dwLength);
	RegCloseKey(hkey);
	this->SetDlgItemText(IDC_Name,LPCTSTR(name));
}

void Rename::OnDatabases() 
{
	HKEY hkey;
	char name[255];
	DWORD dwType;
	DWORD dwLength;	
	RegOpenKeyEx(HKEY_CLASSES_ROOT,TEXT("{000214A4-0000-0000-C000-000000000046}"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("DisplayName"), NULL, &dwType,(LPBYTE)&name, &dwLength);
	RegCloseKey(hkey);
	this->SetDlgItemText(IDC_Name,LPCTSTR(name));
}

void Rename::OnRecycle() 
{
	HKEY hkey;
	char name[255];
	DWORD dwType;
	DWORD dwLength;	
	RegOpenKeyEx(HKEY_CLASSES_ROOT,TEXT("{000214A1-0000-0000-C000-000000000046}"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("DisplayName"), NULL, &dwType,(LPBYTE)&name, &dwLength);
	RegCloseKey(hkey);
	this->SetDlgItemText(IDC_Name,LPCTSTR(name));
}
