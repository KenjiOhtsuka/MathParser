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
#include <sstream>
#include "MathParserFrm.h"
#include "MathParser.h"
#include "array.h"
#include "xy_T.h"
using namespace std;

#define GRAPH_X         200                             // graph distance to the left side of the frame
#define GRAPH_Y         40                              // graph distance to the top side of the frame
#define GRAPH_WIDTH     440                             // graph width
#define GRAPH_HEIGHT    320                             // graph height
#define TEXT_X_L        ( GRAPH_X - 10 )                // x-axis text
#define TEXT_X_R        ( GRAPH_X + GRAPH_WIDTH - 14 )
#define TEXT_X_Y        ( GRAPH_Y + GRAPH_HEIGHT + 4 )
#define TEXT_Y_T        ( GRAPH_Y - 5 )                 // y-axis text
#define TEXT_Y_B        ( GRAPH_Y + GRAPH_HEIGHT - 8 )
#define TEXT_Y_X        ( GRAPH_X - 40 )

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

	wxValueStep = new wxTextCtrl(this, ID_WXVALUESTEP, wxT("1.0"), wxPoint(104, 88), wxSize(54, 24), 0, wxDefaultValidator, wxT("wxValueStep"));

	wxMaxValue = new wxTextCtrl(this, ID_WXMAXVALUE, wxT("20.0"), wxPoint(104, 64), wxSize(54, 24), 0, wxDefaultValidator, wxT("wxMaxValue"));

	wxMinValue = new wxTextCtrl(this, ID_WXMINVALUE, wxT("0.0"), wxPoint(104, 40), wxSize(54, 24), 0, wxDefaultValidator, wxT("wxMinValue"));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("Formel"), wxPoint(8, 8), wxDefaultSize, 0, wxT("WxStaticText4"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("Value Step"), wxPoint(8, 88), wxDefaultSize, 0, wxT("WxStaticText3"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Maximum Value"), wxPoint(8, 64), wxDefaultSize, 0, wxT("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Minimum Value"), wxPoint(8, 40), wxDefaultSize, 0, wxT("WxStaticText1"));

	WxMemo1 = new wxTextCtrl(this, ID_WXMEMO1, wxEmptyString, wxPoint(8, 120), wxSize(150, 248), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo1"));
	WxMemo1->SetMaxLength(0);
	WxMemo1->SetFocus();
	WxMemo1->SetInsertionPointEnd();

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, wxT("1+log(cos(x),7)*2"), wxPoint(68, 8), wxSize(340, 24), 0, wxDefaultValidator, wxT("WxEdit1"));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Berechnen"), wxPoint(416, 8), wxSize(80, 24), 0, wxDefaultValidator, wxT("WxButton1"));

	SetTitle(wxT("MathParser"));
	SetIcon(wxNullIcon);
	SetSize(8,8,668,408);
	Center();
	
	////GUI Items Creation End
	
	WxMemo1->SetEditable(false);
    dc = new wxClientDC(this);
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
	WxMemo1->SetEditable(false);
	WxMemo1->SetValue("");
	dc->Clear();
	
	// read the WxEdit1 field
	char * formelPtr;
	wxString wstr = WxEdit1->GetValue();
	formelPtr = new char[wstr.Length()+1];
	strcpy(formelPtr, wstr.c_str());
	std::string formelStr(formelPtr);
	
	// get min, max and step values
	bool calc = true;
	char * valueStr;
	double minValue, maxValue, ValueStep;
	wstr = wxMinValue->GetValue();
	valueStr = new char[wstr.Length()+1];
	strcpy(valueStr, wstr.c_str());
	std::istringstream minValueC(valueStr);
	if (!(minValueC >> minValue)) {
        calc = false;
	    (*WxMemo1) << "Minimum value is no double number!\n";
    }
    delete[] valueStr;
	wstr = wxMaxValue->GetValue();
	valueStr = new char[wstr.Length()+1];
	strcpy(valueStr, wstr.c_str());
	std::istringstream maxValueC(valueStr);
	if (!(maxValueC >> maxValue)) {
        calc = false;
	    (*WxMemo1) << "Maximum value is no double number!\n";
    }
    delete[] valueStr;
	wstr = wxValueStep->GetValue();
	valueStr = new char[wstr.Length()+1];
	strcpy(valueStr, wstr.c_str());
	std::istringstream ValueStepC(valueStr);
	if (!(ValueStepC >> ValueStep)) {
        calc = false;
	    (*WxMemo1) << "Value step is no double number!\n";
    }
    delete[] valueStr;
	
	if (calc) { // only calc if no errors !!
	    // calc
	    MathParser *parser = new MathParser();
	    parser->parse(formelStr);
	   
	    // draw the rectangle around the graph panel
        dc->SetPen(wxPen(wxColor(0,0,0), 1)); // black line, 1 pixels thick
        dc->DrawRectangle(GRAPH_X, GRAPH_Y, GRAPH_WIDTH, GRAPH_HEIGHT);
	   
        // evaluate points
        int StepNbrs = (maxValue-minValue)/ValueStep + 1;
            PointArray points(StepNbrs);
        for(int i = 0; i < StepNbrs; i = i++) {
            points[i].x = minValue + i*ValueStep;
            points[i].y = parser->evaluate(points[i].x);
            (*WxMemo1) << "f(" << points[i].x << ")=" << points[i].y << "\n";
        }
        
        // draw min and max values
        char temp[100];
	    double min = points.min_y();
	    double max = points.max_y();
	    sprintf(temp, "%.3f", points.min_x());
	    dc->DrawText(temp, TEXT_X_L, TEXT_X_Y);
	    sprintf(temp, "%.3f", points.max_x());
	    dc->DrawText(temp, TEXT_X_R, TEXT_X_Y);
	    sprintf(temp, "%.3f", min);
	    dc->DrawText(temp, TEXT_Y_X, TEXT_Y_B);
	    sprintf(temp, "%.3f", max);
	    dc->DrawText(temp, TEXT_Y_X, TEXT_Y_T);
	    
        // draw graph
	    double StepWidth = (double)GRAPH_WIDTH / (double)(StepNbrs-1);
	    double StepHeight = (double)GRAPH_HEIGHT / (double)(max-min);
	    for(int i = 1; i < StepNbrs; i = i++) {
             dc->DrawLine(GRAPH_X+(i-1)*StepWidth, GRAPH_Y+GRAPH_HEIGHT-(points[i-1].y-min)*StepHeight,
                    GRAPH_X+i*StepWidth, GRAPH_Y+GRAPH_HEIGHT-(points[i].y-min)*StepHeight);
        }
    }
}
