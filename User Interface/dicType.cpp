#include "dicType.h"
#include <vector>

dicType::dicType(wxPanel* panel)
{
	list = new wxBitmapComboBox(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0, nullptr, wxCB_READONLY | wxNO_BORDER);

	wxBitmap bitmap1(wxT("D:/CS163/picture/Rectangle 39 (1).png"), wxBITMAP_TYPE_PNG);
	wxBitmap bitmap2(wxT("D:/CS163/picture/Rectangle 39 (2).png"), wxBITMAP_TYPE_PNG);
	wxBitmap bitmap3(wxT("D:/CS163/picture/Rectangle 39 (3).png"), wxBITMAP_TYPE_PNG);
	wxBitmap bitmap4(wxT("D:/CS163/picture/Rectangle 39 (4).png"), wxBITMAP_TYPE_PNG);
	wxBitmap bitmap5(wxT("D:/CS163/picture/Rectangle 39 (5).png"), wxBITMAP_TYPE_PNG);



	list->Append("", bitmap1);
	list->Append("", bitmap2);
	list->Append("", bitmap3);
	list->Append("", bitmap4);
	list->Append("", bitmap5);

	list->SetSelection(0);
}
