// IEAmelioration.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "IEAmelioration.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IEAmelioration dialog


IEAmelioration::IEAmelioration(CWnd* pParent /*=NULL*/)
	: CDialog(IEAmelioration::IDD, pParent)
{
	//{{AFX_DATA_INIT(IEAmelioration)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void IEAmelioration::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(IEAmelioration)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(IEAmelioration, CDialog)
	//{{AFX_MSG_MAP(IEAmelioration)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// IEAmelioration message handlers

BOOL IEAmelioration::OnInitDialog() 
{
	HKEY hKey = 0;
	DWORD dwDisposition;
	CDialog::OnInitDialog();
	// JavaScript
	if (RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{F414C260-6AC0-11CF-B6D1-00AA00BBBB58}\\InprocServer32"), 0, _T(""), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS)
	{
		wchar_t szBuff[256];
		DWORD dwDataSize = 512;

		if (RegQueryValueEx(hKey, _T("Default"), 0, 0, (LPBYTE)&szBuff, &dwDataSize) == ERROR_SUCCESS) {
			if (! wcsicmp(szBuff, _T("\\windows\\jscript.dll"))){
				this->CheckDlgButton(IDC_Java,true);
			} else {
				this->CheckDlgButton(IDC_Java,false);
			}
		}
		RegCloseKey(hKey);
	}

	// VBScript
	if (RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{B54F3741-5B07-11CF-A4B0-00AA004A55E8}\\InprocServer32"), 0, _T(""), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS)
	{
		wchar_t szBuff[256];
		DWORD dwDataSize = 512;

		if (RegQueryValueEx(hKey, _T("Default"), 0, 0, (LPBYTE)&szBuff, &dwDataSize) == ERROR_SUCCESS) {
			if (! wcsicmp(szBuff, _T("\\windows\\vbscript.dll"))){
				this->CheckDlgButton(IDC_VB,true);
			} else {
				this->CheckDlgButton(IDC_VB,false);
			}
		}
		RegCloseKey(hKey);
	}
	
	return TRUE;
}

void IEAmelioration::OnOK() 
{
	HKEY hKey = 0;
	DWORD dwDisposition;

	// JavaScript
	if (RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{F414C260-6AC0-11CF-B6D1-00AA00BBBB58}\\InprocServer32"), 0, _T(""), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS)
	{
		wchar_t* szScript = _T("\\windows\\jscript.dll");

		if (this->IsDlgButtonChecked(IDC_Java)){
			RegSetValueEx(hKey, _T("Default"), 0, REG_SZ, (LPBYTE)szScript, wcslen(szScript)*2+2);
		} else {
			RegSetValueEx(hKey, _T("Default"), 0, REG_SZ, (LPBYTE)_T(""), 2);
		}
		RegCloseKey(hKey);
	}

	// VBScript
	if (RegCreateKeyEx(HKEY_CLASSES_ROOT, _T("CLSID\\{B54F3741-5B07-11CF-A4B0-00AA004A55E8}\\InprocServer32"), 0, _T(""), REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS)
	{
		wchar_t* szScript = _T("\\windows\\vbscript.dll");

		if (this->IsDlgButtonChecked(IDC_VB)){
			RegSetValueEx(hKey, _T("Default"), 0, REG_SZ, (LPBYTE)szScript, wcslen(szScript)*2+2);
		} else {
			RegSetValueEx(hKey, _T("Default"), 0, REG_SZ, (LPBYTE)_T(""), 2);
		}
		RegCloseKey(hKey);
	}	
	CDialog::OnOK();
}
