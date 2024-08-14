#include "dicType.h"
#include "searchPage.h"

searchPage::searchPage(wxWindow* parent, int& dicTypeInt, int& searchTypeInt, wxString& Word) : wxWindow(parent, wxID_ANY)
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	// Create panel and sizers
	wxPanel* topPanel = new wxPanel(this, wxID_ANY);

	topPanel->SetBackgroundColour("#38435A");

	//wxBoxSizer* topMainSizer = new wxBoxSizer(wxVERTICAL);

	//topMainSizer->AddSpacer(24);

	setTopControls(topPanel, dicTypeInt, searchTypeInt, Word);

	wxBoxSizer* topMidSizer = new wxBoxSizer(wxHORIZONTAL);

	topMidSizer->Add(home, 0, wxEXPAND | wxALL, 30);

	topMidSizer->Add(choice, 0, wxEXPAND | wxALL, 30);

	topMidSizer->Add(searchInput, 0, wxEXPAND | wxALL, 30);

	topMidSizer->Add(searchButton, 0, wxEXPAND | wxALL, 30);

	topMidSizer->Add(lists, 0, wxALL, 30);

	topMidSizer->Add(origin, 0, wxEXPAND | wxALL, 30);

	topMidSizer->Add(add, 0, wxEXPAND | wxALL, 30);


	topPanel->SetSizer(topMidSizer);

	mainSizer->Add(topPanel);

	this->SetSizer(mainSizer);
}

void searchPage::setTopControls(wxPanel* panel, int& dicTypeInt, int& searchTypeInt, wxString Word)
{
	wxBitmap bmHome(wxT("D:/CS163/picture/home.png"), wxBITMAP_TYPE_PNG);
	home = new wxBitmapButton(panel, wxID_ANY, bmHome, wxDefaultPosition, wxSize(50, 54), wxNO_BORDER);
	home->SetBackgroundColour("#38435A");

	choice = new searchType(panel, searchTypeInt);
	choice->SetSize(87, 35);

	lists = new dicType(panel, dicTypeInt);
	lists->SetSize(wxSize(100, 20));

	wxBitmap bmSearchButton(wxT("D:/CS163/picture/searchButton.png"), wxBITMAP_TYPE_PNG);
	searchButton = new wxBitmapButton(panel, wxID_ANY, bmSearchButton, wxDefaultPosition, wxSize(54, 54), wxNO_BORDER);
	searchButton->SetBackgroundColour("#38435A");

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Varela Round");


	searchInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(663, 54));
	searchInput->SetFont(font);
	searchInput->SetHint("Enter search text...");  // Placeholder text

	wxBitmap bmOrigin(wxT("D:/CS163/picture/origin.png"), wxBITMAP_TYPE_PNG);
	origin = new wxBitmapButton(panel, wxID_ANY, bmOrigin, wxDefaultPosition, wxSize(73, 74), wxNO_BORDER);
	origin->SetBackgroundColour("#38435A");

	wxBitmap bmAddButton(wxT("D:/CS163/picture/addButton.png"), wxBITMAP_TYPE_PNG);
	add = new wxBitmapButton(panel, wxID_ANY, bmAddButton, wxDefaultPosition, wxSize(90, 85), wxNO_BORDER);
	add->SetBackgroundColour("#38435A");
}

void searchPage::setControls(int& dicTypeInt, int& searchTypeInt, wxString Word)
{

	wxBitmap bmLike(wxT("D:/CS163/picture/heart.png"), wxBITMAP_TYPE_PNG);
	like = new wxBitmapButton(this, wxID_ANY, bmLike, wxDefaultPosition, wxSize(45, 45), wxNO_BORDER);
	like->SetBackgroundColour("#F8D65B");

	wxBitmap bmDel(wxT("D:/CS163/picture/bin.png"), wxBITMAP_TYPE_PNG);
	del = new wxBitmapButton(this, wxID_ANY, bmDel, wxDefaultPosition, wxSize(45, 45), wxNO_BORDER);
	del->SetBackgroundColour("#F8D65B");

	wxBitmap bmFix(wxT("D:/CS163/picture/publishing.png"), wxBITMAP_TYPE_PNG);
	fix = new wxBitmapButton(this, wxID_ANY, bmFix, wxDefaultPosition, wxSize(45, 45), wxNO_BORDER);
	fix->SetBackgroundColour("#F8D65B");

	word = new wxStaticText(this, wxID_ANY, Word, wxDefaultPosition, wxSize(300, 30));
	editWord = new wxTextCtrl(this, wxID_ANY, word->GetLabel(), wxDefaultPosition, wxSize(300, 30));
	editWord->Hide();

	std::vector<wxString> defContent;

	// Set definition?

	for (int i = 0; i < def.size(); i++)
	{
		def[i] = new wxStaticText(this, wxID_ANY, Word, wxDefaultPosition, wxSize(300, 30));
		editDef[i] = new wxTextCtrl(this, wxID_ANY, word->GetLabel(), wxDefaultPosition, wxSize(300, 30));
		editDef[i]->Hide();
	}
}

