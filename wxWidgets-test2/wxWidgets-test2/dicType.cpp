#include "dicType.h"
#include <vector>

dicType::dicType(wxWindow* panel, int& dicTypeInt) : wxComboBox(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(150, 54), 0, nullptr, wxCB_READONLY | wxNO_BORDER)
{
	this->Append(wxT("Eng-Eng"));
	this->Append(wxT("Eng-Vie"));
	this->Append(wxT("Vie-Eng"));
	this->Append(wxT("Slang"));
	this->Append(wxT("Emoji"));

	this->SetSelection(dicTypeInt);

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Varela Round");
	this->SetFont(font);
}
