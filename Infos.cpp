// Infos.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "Infos.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Infos dialog


Infos::Infos(CWnd* pParent /*=NULL*/)
	: CDialog(Infos::IDD, pParent)
{
	//{{AFX_DATA_INIT(Infos)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Infos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Infos)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Infos, CDialog)
	//{{AFX_MSG_MAP(Infos)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Infos message handlers

BOOL Infos::OnInitDialog() 
{
	MEMORYSTATUS mem;
	SYSTEM_INFO sys;
	CString temp,t;
	HKEY hkey;
	DWORD val;
	DWORD dwType;
	DWORD dwLength;
	CDialog::OnInitDialog();
	int tem;
	mem.dwLength=sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&mem);

	temp.Format(_T("%d %%"),mem.dwMemoryLoad);
	this->SetDlgItemText(IDC_MemoryLoad,temp);

	if(mem.dwTotalPhys>1024){
		tem=(mem.dwTotalPhys/1024);
		temp.Format(_T("%d Kb"),tem);
	}else{
		tem=mem.dwTotalPhys;
		temp.Format(_T("%d bytes"),tem);
	}
	this->SetDlgItemText(IDC_TotalPhys,temp);

	if(mem.dwAvailPhys>1024){
		tem=(mem.dwAvailPhys/1024);
		temp.Format(_T("%d Kb"),tem);
	}else{
		tem=mem.dwAvailPhys;
		temp.Format(_T("%d bytes"),tem);
	}
	this->SetDlgItemText(IDC_AvailPhys,temp);

	if((mem.dwTotalPhys-mem.dwAvailPhys)>1024){
		tem=((mem.dwTotalPhys-mem.dwAvailPhys)/1024);
		temp.Format(_T("%d Kb"),tem);
	}else{
		temp.Format(_T("%d bytes"),(mem.dwTotalPhys-mem.dwAvailPhys));
	}
	this->SetDlgItemText(IDC_UsedPhys,temp);

	if(mem.dwTotalVirtual>1024){
		tem=(mem.dwTotalVirtual/1024);
		temp.Format(_T("%d Kb"),tem);
	}else{
		tem=mem.dwTotalVirtual;
		temp.Format(_T("%d bytes"),tem);
	}
	this->SetDlgItemText(IDC_TotalVirtual,temp);

	if(mem.dwAvailVirtual>1024){
		tem=(mem.dwAvailVirtual/1024);
		temp.Format(_T("%d Kb"),tem);
	}else{
		tem=mem.dwAvailVirtual;
		temp.Format(_T("%d bytes"),tem);
	}
	this->SetDlgItemText(IDC_AvailVirtual,temp);
	if((mem.dwTotalVirtual-mem.dwAvailVirtual)>1024){
		tem=((mem.dwTotalVirtual-mem.dwAvailVirtual)/1024);
		temp.Format(_T("%d Kb"),tem);
	}else{
		temp.Format(_T("%d bytes"),(mem.dwTotalVirtual-mem.dwAvailVirtual));
	}
	this->SetDlgItemText(IDC_UsedVirtual,temp);
	//System
	GetSystemInfo(&sys); 
	switch(sys.dwProcessorType){
		case PROCESSOR_INTEL_386:
			temp.Format(_T("Intel 386 (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_INTEL_486:
			temp.Format(_T("Intel 486 (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_INTEL_PENTIUM:
			temp.Format(_T("Intel Pentium (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_MIPS_R3000:
			temp.Format(_T("Mips R3000 (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_MIPS_R4000:
			temp.Format(_T("Mips R4000 (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_HITACHI_SH3:
			temp.Format(_T("SH3 (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_HITACHI_SH4:
			temp.Format(_T("SH4 (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_PPC_821:
			temp.Format(_T("PPC 821(%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_STRONGARM:
			temp.Format(_T("Strong ARM (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		case PROCESSOR_ARM720:
			temp.Format(_T("ARM 720 (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
		default:
			temp.Format(_T("Unknow Proc (%d Processor(s))"),sys.dwNumberOfProcessors);
			break;
	}
	this->SetDlgItemText(IDC_Proc,temp);

	RegOpenKeyEx(HKEY_LOCAL_MACHINE,TEXT("Comm"),0,
		KEY_ALL_ACCESS,&hkey); 
	RegQueryValueEx(hkey, TEXT("BootCount"), NULL, &dwType,(LPBYTE)&val, &dwLength);
	RegCloseKey(hkey);
	//t.Format(_T("%s"),count);
	temp.Format(_T("You have press 0x%x\n(%d)  times Soft Reset Button"),val,val);
	this->SetDlgItemText(IDC_BootCount,temp);

	return TRUE;
}
