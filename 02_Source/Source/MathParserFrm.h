///-----------------------------------------------------------------
///
/// @file      MathParserFrm.h
/// @author    ruett1
/// Created:   24.04.2012 12:17:13
/// @section   DESCRIPTION
///            MathParserFrm class declaration
///
///------------------------------------------------------------------

#ifndef __MATHPARSERFRM_H__
#define __MATHPARSERFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef MathParserFrm_STYLE
#define MathParserFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class MathParserFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		MathParserFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("MathParser"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = MathParserFrm_STYLE);
		virtual ~MathParserFrm();
		void WxButton1Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *wxValueStep;
		wxTextCtrl *wxMaxValue;
		wxTextCtrl *wxMinValue;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxTextCtrl *WxMemo1;
		wxTextCtrl *WxEdit1;
		wxButton *WxButton1;
		////GUI Control Declaration End
		wxClientDC *dc;
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXVALUESTEP = 1015,
			ID_WXMAXVALUE = 1014,
			ID_WXMINVALUE = 1013,
			ID_WXSTATICTEXT4 = 1012,
			ID_WXSTATICTEXT3 = 1011,
			ID_WXSTATICTEXT2 = 1010,
			ID_WXSTATICTEXT1 = 1009,
			ID_WXMEMO1 = 1004,
			ID_WXEDIT1 = 1002,
			ID_WXBUTTON1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
