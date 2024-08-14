#include "searchType.h"

searchType::searchType(wxWindow* panel, int& searchTypeInt) : wxBitmapComboBox(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0, nullptr, wxCB_READONLY | wxNO_BORDER)
{

	wxBitmap bitmap1(wxT("D:/CS163/picture/Group 7 (1).png"), wxBITMAP_TYPE_PNG);
	wxBitmap bitmap2(wxT("D:/CS163/picture/Group 7 (2).png"), wxBITMAP_TYPE_PNG);

	this->Append("", bitmap1);
	this->Append("", bitmap2);

	this->SetSelection(searchTypeInt);
}
