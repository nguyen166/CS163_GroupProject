#pragma once

#include <wx/wx.h>

class searchPage : public wxWindow {
public:
	searchPage(wxWindow* parent);
	void OnButtonClicked(wxCommandEvent& event);
private:
	wxBitmap bgBitmap;
	void setBackgroundImage(wxPaintEvent& even);
	void OnEraseBackground(wxEraseEvent& event);
};


