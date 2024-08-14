#pragma once
#include <wx/bmpcbox.h>
#include <wx/wx.h>

class dicType : public wxComboBox
{
public:
	dicType(wxWindow* panel, int& dicTypeInt);
};

