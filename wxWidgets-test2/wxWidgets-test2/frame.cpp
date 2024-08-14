#include "frame.h"
#include "mainPage.h"
#include "searchPage.h"
#include <wx/simplebook.h>

frame::frame() : wxFrame(NULL, wxID_ANY, "wxSimplebook Example")
{
	// Tạo wxSimplebook
	wxSimplebook* book = new wxSimplebook(this, wxID_ANY);

	int dicTypeInt = 0;
	int searchTypeInt = 0;
	wxString searchWord = "";
	mainPage* home = new mainPage(book, dicTypeInt, searchTypeInt, searchWord);
	searchPage* search = new searchPage(book, dicTypeInt, searchTypeInt, searchWord);



	// Thêm các trang vào wxSimplebook
	book->AddPage(home, "Home");
	book->AddPage(search, "Search");

	book->SetSelection(1);

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(book, 1, wxEXPAND);
	this->SetSizerAndFit(sizer);


	// Đặt wxSimplebook vào khung
	//wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	//sizer->Add(book, 1, wxEXPAND);
	// Lấy kích thước màn hình
	//wxSize screenSize = wxGetDisplaySize();
	//wxSize screenSize = wxSize(1458, 866);

	// Thiết lập kích thước của frame theo kích thước màn hình
	//SetSize(screenSize);
	//this->SetSizer(sizer);
	//SetMaxSize(screenSize);
	//SetMinSize(screenSize);

}
