// Startup.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "Startup.h"
#include <Atlbase.h>

TCHAR szFileName[MAX_PATH];

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Startup dialog
bool OpenFile(HWND hOwner)
{

    BOOL            bSuccess = FALSE;
	TCHAR			szPathName[MAX_PATH] = TEXT("\\"), szExtName[100] = {0};
    OPENFILENAME    of;
    TCHAR           szOpen[50] = TEXT("Select file");

    const LPTSTR pszOpenFilter = TEXT("Browser Files(*.exe)\0*.exe\0All Documents (*.*)\0*.*\0\0");

    memset((LPVOID)&of, 0, sizeof(OPENFILENAME));
    of.lStructSize	    = sizeof(OPENFILENAME);
    of.hwndOwner	    = hOwner;
    of.lpstrFile	    = szFileName;
    of.lpstrInitialDir  = NULL;
    of.nMaxFile		    = sizeof(szFileName)/sizeof(TCHAR);

    of.lpstrDefExt  = szExtName;
    of.Flags = OFN_HIDEREADONLY |  // Do not display the Read-Only check box.
               OFN_LONGNAMES;      // Display long filenames if possible.

    of.lpfnHook = NULL;
    of.Flags        |= OFN_FILEMUSTEXIST;
    of.lpstrTitle   = szOpen;
    of.lpstrFilter	= pszOpenFilter;
    bSuccess = GetOpenFileName(&of);

    if( bSuccess )
    {
      MessageBox(hOwner,szFileName, _T("Notice"),
							MB_OK | MB_ICONINFORMATION);
    }
    else
		MessageBox(hOwner, szFileName, _T("Notice3"),
							MB_OK | MB_ICONINFORMATION);
	return true;
}


Startup::Startup(CWnd* pParent /*=NULL*/)
	: CDialog(Startup::IDD, pParent)
{
	//{{AFX_DATA_INIT(Startup)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Startup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Startup)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Startup, CDialog)
	//{{AFX_MSG_MAP(Startup)
	ON_BN_CLICKED(IDC_Remove, OnRemove)
	ON_BN_CLICKED(IDC_Add, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Startup message handlers


BOOL Startup::OnInitDialog() 
{
	HANDLE hSearch;
	WIN32_FIND_DATA FileData;
	BOOL bFinished = FALSE;
	CListBox* Liste = (CListBox*) GetDlgItem(IDC_Reg);
	CString c;
	
	CDialog::OnInitDialog();

	Liste->ResetContent();
	hSearch = FindFirstFile (TEXT("\\Windows\\Startup\\*"), &FileData);
	if (hSearch == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	while (!bFinished)
	{
		Liste->AddString(FileData.cFileName);
		if (!FindNextFile (hSearch, &FileData))
		{
			bFinished = TRUE;
		}
	}
	return TRUE;
}

void Startup::OnRemove() 
{
	CListBox* Liste = (CListBox*) GetDlgItem(IDC_Reg);
	CString str,c;
	int nIndex=Liste->GetCurSel();
	Liste->GetText(nIndex,str);
	c.Format(_T("\\windows\\startup\\%s"),str);
	if(DeleteFile(c))
		MessageBox(_T("Deleted from \\Windows\\Startup"),_T("SStartup"),MB_OK);
	OnInitDialog();	
}

HRESULT CreateShortcut(/*in*/ LPCTSTR lpszFileName, 
                    /*in*/ LPCTSTR lpszDesc, 
                    /*in*/ LPCTSTR lpszShortcutPath)
{
    HRESULT hRes = E_FAIL;
    DWORD dwRet = 0;
    CComPtr<IShellLink> ipShellLink;
    TCHAR szPath[MAX_PATH];    
    LPTSTR lpszFilePart;    
    WCHAR wszTemp[MAX_PATH];
    dwRet = GetFullPathName(lpszFileName, 
                       sizeof(szPath) / sizeof(TCHAR), 
                       szPath, &lpszFilePart);
    if (!dwRet)                                        
        return hRes;
    hRes = CoCreateInstance(CLSID_ShellLink,
                            NULL, 
                            CLSCTX_INPROC_SERVER,
                            IID_IShellLink,
                            (void**)&ipShellLink);
    if (SUCCEEDED(hRes))
    {
        CComQIPtr<IPersistFile> ipPersistFile(ipShellLink);
        hRes = ipShellLink->SetPath(szPath);
        if (FAILED(hRes))
            return hRes;
        hRes = ipShellLink->SetDescription(lpszDesc);
        if (FAILED(hRes))
            return hRes;
        MultiByteToWideChar(CP_ACP, 0, 
                       lpszShortcutPath, -1, wszTemp, MAX_PATH);
        hRes = ipPersistFile->Save(wszTemp, TRUE);
    }
    return hRes;
}

void Startup::OnAdd() 
{
    LPCTSTR lpszShortcutDesc = _T("Add by SStartup");
    LPCTSTR lpszShortcutPath = _T("\\SStartup.lnk");
    CreateShortcut(szFileName, lpszShortcutDesc, lpszShortcutPath);
	OpenFile((HWND)NULL);	
}
