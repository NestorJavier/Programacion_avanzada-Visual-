// Calendario.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_ActiveX.h"
#include "Calendario.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalendario dialog


CCalendario::CCalendario(CWnd* pParent /*=NULL*/)
	: CDialog(CCalendario::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalendario)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCalendario::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalendario)
	DDX_Control(pDX, IDC_MONTHVIEW1, m_Cal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCalendario, CDialog)
	//{{AFX_MSG_MAP(CCalendario)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalendario message handlers

BEGIN_EVENTSINK_MAP(CCalendario, CDialog)
    //{{AFX_EVENTSINK_MAP(CCalendario)
	ON_EVENT(CCalendario, IDC_MONTHVIEW1, 1 /* DateClick */, OnDateClickMonthview1, VTS_DATE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CCalendario::OnDateClickMonthview1(DATE DateClicked) 
{
	// TODO: Add your control notification handler code here
	int d, m, a;
	CString cad;
	d = m_Cal.GetDay();
	m = m_Cal.GetMonth();
	a = m_Cal.GetYear();
	
	fecha.Format("%d", d);
	switch(m)
	{
		case 1:
			fecha += "-Enero-";
		break;
		case 2:
			fecha += "-Febrero-";
		break;
		case 3:
			fecha += "-Marzo-";
		break;
		case 4:
			fecha += "-Abril-";
		break;
		case 5:
			fecha += "-Mayo-";
		break;
		case 6:
			fecha += "-Junio-";
		break;
		case 7:
			fecha += "-Julio-";
		break;
		case 8:
			fecha += "-Agosto-";
		break;
		case 9:
			fecha += "-Septiembre-";
		break;
		case 10:
			fecha += "-Octubre-";
		break;
		case 11:
			fecha += "-Noviembre-";
		break;
		case 12:
			fecha += "-Diciembre-";
		break;
	}
	cad.Format("%d", a);

	fecha += cad;
	
	/*elejir un mes y un año dar click en cualquier dia obtener con GetDay, GetMonth, GetDay e imprimir en area cliente*/

}
