#include "CalApp.h"


wxIMPLEMENT_APP(CalApp);


CalApp::CalApp()
{

}

CalApp::~CalApp()
{
	//delete[] m_frame1;
}

bool CalApp::OnInit()
{
	m_frame1 = new ButtonFactory();
	m_frame1->Show();
	return true;
}