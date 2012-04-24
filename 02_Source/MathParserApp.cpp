//---------------------------------------------------------------------------
//
// Name:        MathParserApp.cpp
// Author:      ruett1
// Created:     24.04.2012 12:17:13
// Description: 
//
//---------------------------------------------------------------------------

#include "MathParserApp.h"
#include "Source\MathParserFrm.h"

IMPLEMENT_APP(MathParserFrmApp)

bool MathParserFrmApp::OnInit()
{
    MathParserFrm* frame = new MathParserFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int MathParserFrmApp::OnExit()
{
	return 0;
}
