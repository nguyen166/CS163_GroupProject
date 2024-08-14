#include "frame.h"
#include "mainPage.h"
#include "searchPage.h"
#include <wx/simplebook.h>

frame::frame() : wxFrame(NULL, wxID_ANY, "wxSimplebook Example")
{
	// Tạo wxSimplebook
	wxSimplebook* book = new wxSimplebook(this, wxID_ANY);


	mainPage* home = new mainPage(book);
	searchPage* search = new searchPage(book);

	// Thêm các trang vào wxSimplebook
	book->AddPage(home, "Home");
	book->AddPage(search, "Search");

	book->SetSelection(1);

	// Đặt wxSimplebook vào khung
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(book, 1, wxEXPAND);
	// Lấy kích thước màn hình
	wxSize screenSize = wxGetDisplaySize();

	// Thiết lập kích thước của frame theo kích thước màn hình
	SetSize(screenSize);
	this->SetSizer(sizer);

}
