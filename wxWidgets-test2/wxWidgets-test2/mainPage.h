#pragma once

#include"dicType.h"
#include <wx/wx.h>

class mainPage : public wxWindow {
public:

	wxBitmapButton* origin;
	wxBitmapButton* addButton;
	wxBitmapButton* history;
	wxBitmapButton* Random;
	wxBitmapButton* FavWords;
	wxBitmapButton* WordGames;

	wxTextCtrl* searchInput;
	wxBitmapButton* name;

	wxButton* searchButton;

	dicType* list;


	mainPage(wxWindow* parent, int& dicTypeInt, int& searchType, wxString& searchWord);
	void OnButtonClicked(wxCommandEvent& event);
private:
	void setControls(int& dicTypeIt, int& searchTypeIt);
};


