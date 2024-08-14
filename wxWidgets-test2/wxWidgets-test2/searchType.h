#pragma once
#include <wx/bmpcbox.h>
#include <wx/wx.h>

class searchType : public wxBitmapComboBox
{
public:
	searchType(wxWindow* panel, int& seacrhTypeInt);
};

