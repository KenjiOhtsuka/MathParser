///-----------------------------------------------------------------
///
/// @file      MathParserFrm.cpp
/// @author    ruett1
/// Created:   24.04.2012 12:17:13
/// @section   DESCRIPTION
///            MathParserFrm class implementation
///
///------------------------------------------------------------------

#include <iostream>
#include <string>
#include "MathParserFrm.h"
#include "MathParser.h"
using namespace std;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// MathParserFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(MathParserFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(MathParserFrm::OnClose)
	EVT_BUTTON(ID_WXBUTTON1,MathParserFrm::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

MathParserFrm::MathParserFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

MathParserFrm::~MathParserFrm()
{
}

void MathParserFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, wxT("1+log(cos(x),7)*2"), wxPoint(12, 10), wxSize(400, 24), 0, wxDefaultValidator, wxT("WxEdit1"));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Berechnen"), wxPoint(416, 8), wxSize(80, 24), 0, wxDefaultValidator, wxT("WxButton1"));

	SetTitle(wxT("MathParser"));
	SetIcon(wxNullIcon);
	SetSize(8,8,514,336);
	Center();
	
	////GUI Items Creation End
}

void MathParserFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void MathParserFrm::WxButton1Click(wxCommandEvent& event)
{
	char * formelPtr;
	
	// read the WxEdit1 field
	wxString wstr = WxEdit1->GetValue();
	formelPtr = new char[wstr.Length()+1];
	strcpy(formelPtr, wstr.c_str());
	std::string formelStr(formelPtr);
	
	// calc
	MathParser *parser = new MathParser();
	parser->parse(formelStr);
	double res;
	
	res = parser->evaluate(2.0);
	res = parser->evaluate(3.0);
	res = parser->evaluate(4.0);
	res = parser->evaluate(100.0);
}
