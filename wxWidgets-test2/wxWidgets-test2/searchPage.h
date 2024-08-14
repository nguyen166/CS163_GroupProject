#pragma once

#include "dicType.h"
#include "searchType.h"
#include <vector>
#include <wx/wx.h>

class searchPage : public wxWindow {
public:

	wxBitmapButton* home;
	dicType* lists;
	searchType* choice;
	wxBitmapButton* searchButton;
	wxBitmapButton* origin;
	wxBitmapButton* add;

	wxTextCtrl* searchInput;
	wxBitmapButton* like;
	wxBitmapButton* del;
	wxBitmapButton* fix;

	wxStaticText* word;
	wxTextCtrl* editWord;

	std::vector<wxStaticText*> def;
	std::vector<wxTextCtrl*> editDef;

	searchPage(wxWindow* parent, int& dicTypeInt, int& searchType, wxString& Word);
	void OnButtonClicked(wxCommandEvent& event);

private:
	void setTopControls(wxPanel* panel, int& dicTypeInt, int& searchTypeInt, wxString Word);
	void setControls(int& dicTypeInt, int& searchTypeInt, wxString Word);
};


