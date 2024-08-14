#pragma once

#include <wx/wx.h>

class mainPage : public wxWindow {
public:
	mainPage(wxWindow* parent);
	void OnButtonClicked(wxCommandEvent& event);
};


