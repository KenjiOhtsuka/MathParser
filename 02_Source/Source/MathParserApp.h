//---------------------------------------------------------------------------
//
// Name:        MathParserApp.h
// Author:      ruett1
// Created:     24.04.2012 12:17:13
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __MATHPARSERFRMApp_h__
#define __MATHPARSERFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class MathParserFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
