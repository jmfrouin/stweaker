// Power.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "Power.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Power dialog


Power::Power(CWnd* pParent /*=NULL*/)
	: CDialog(Power::IDD, pParent)
{
	//{{AFX_DATA_INIT(Power)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Power::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Power)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Power, CDialog)
	//{{AFX_MSG_MAP(Power)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Power message handlers


BOOL Power::OnInitDialog() 
{
	SYSTEM_POWER_STATUS_EX batt;
	CString temp;
	CDialog::OnInitDialog();
	GetSystemPowerStatusEx(&batt,true);

	switch(batt.ACLineStatus){
	case 1:
		temp.Format(_T("Online"));
		break;
	case 0:
		temp.Format(_T("Offline"));
		break;
	default:
		temp.Format(_T("Unknow"));
	}
	this->SetDlgItemText(IDC_AC,temp);

	switch(batt.BatteryFlag){
	case 1:
		temp.Format(_T("High"));
		break;
	case 2:
		temp.Format(_T("Low"));
		break;
	case 4:
		temp.Format(_T("Critical"));
		break;
	case 8:
		temp.Format(_T("Charging"));
		break;
	case 128:
		temp.Format(_T("Not present !"));
		break;
	case 255:
	default:
		temp.Format(_T("Unknow"));
		break;
	}
	this->SetDlgItemText(IDC_BattStatus,temp);
	switch(batt.BackupBatteryFlag){
	case BATTERY_FLAG_HIGH:
		temp.Format(_T("High"));
		break;
	case BATTERY_FLAG_CRITICAL:
		temp.Format(_T("Critical"));
		break;
	case BATTERY_FLAG_CHARGING:
		temp.Format(_T("Charging ???"));
		break;
	case BATTERY_FLAG_NO_BATTERY:
		temp.Format(_T("Not present !"));
		break;
	case BATTERY_FLAG_LOW:
		temp.Format(_T("Low"));
		break;
	case BATTERY_FLAG_UNKNOWN:
	default:
		temp.Format(_T("Unknow"));
		break;
	}
	this->SetDlgItemText(IDC_BackupPower,temp);

	return TRUE;
}
