#include "dicType.h"
#include "mainPage.h"

mainPage::mainPage(wxWindow* parent, int& dicTypeIt, int& searchTypeIt, wxString& searchWord) : wxWindow(parent, wxID_ANY)
{

	this->SetBackgroundColour(wxColor("#38435A"));

	setControls(dicTypeIt, searchTypeIt);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);

	topSizer->Add(addButton, 0, wxEXPAND | wxALL, 23);
	topSizer->Add(origin, 0, wxEXPAND | wxALL, 23);

	topSizer
		topSizer->Add(list, 0, wxEXPAND | wxLEFT, 968);

	mainSizer->Add(topSizer);


	mainSizer->AddSpacer(60);
	mainSizer->Add(name, 0, wxALIGN_CENTER);

	// Create a horizontal sizer for the search bar
	wxBoxSizer* searchSizer = new wxBoxSizer(wxHORIZONTAL);


	// Add search input and button to the search sizer
	searchSizer->Add(searchInput, 1, wxALIGN_CENTER_VERTICAL, 10);
	searchSizer->AddSpacer(10);
	searchSizer->Add(searchButton, 0, wxALIGN_CENTER_VERTICAL, 10);

	mainSizer->Add(searchSizer, 0, wxALIGN_CENTER | wxALL, 10);

	mainSizer->AddSpacer(100);

	wxBoxSizer* botSizer = new wxBoxSizer(wxHORIZONTAL);

	botSizer->Add(history, 0, wxEXPAND | wxLEFT, 80);
	botSizer->Add(Random, 0, wxEXPAND | wxLEFT, 117);
	botSizer->Add(FavWords, 0, wxEXPAND | wxLEFT, 117);
	botSizer->Add(WordGames, 0, wxEXPAND | wxLEFT, 117);

	// Add the searchSizer to the mainSizer

	mainSizer->Add(botSizer);


	this->SetSizerAndFit(mainSizer);



}

void mainPage::OnButtonClicked(wxCommandEvent& event)
{
	wxCommandEvent evt(wxEVT_COMMAND_BUTTON_CLICKED, wxID_ANY);
	evt.SetEventObject(this);
	wxPostEvent(GetParent(), evt);
}

void mainPage::setControls(int& dicTypeIt, int& searchTypeIt)
{
	// Create the search input field
		// Create the search button
	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Varela Round");


	searchInput = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(867, 40));
	searchInput->SetFont(font);
	searchInput->SetHint("Enter search text...");  // Placeholder text

	searchButton = new wxButton(this, wxID_ANY, "Search", wxDefaultPosition, wxSize(100, 40), wxNO_BORDER);
	searchButton->SetFont(font);
	searchButton->SetBackgroundColour("#FF4F70");
	searchButton->SetForegroundColour(wxColour("#FFFFFF"));

	// Tạo wxBitmap từ file ảnh
	wxBitmap bmHistory(wxT("D:/CS163/picture/search history.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmRandom(wxT("D:/CS163/picture/random word.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmFavWords(wxT("D:/CS163/picture/favorite words.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmWordGames(wxT("D:/CS163/picture/word games.png"), wxBITMAP_TYPE_PNG);



	// Tạo wxBitmapButton
	history = new wxBitmapButton(this, wxID_ANY, bmHistory, wxPoint(80, 490), wxSize(230, 326));
	Random = new wxBitmapButton(this, wxID_ANY, bmRandom, wxPoint(427, 490), wxSize(230, 326));
	FavWords = new wxBitmapButton(this, wxID_ANY, bmFavWords, wxPoint(774, 490), wxSize(230, 326));
	WordGames = new wxBitmapButton(this, wxID_ANY, bmWordGames, wxPoint(1121, 490), wxSize(230, 326));

	list = new dicType(this, dicTypeIt);

	wxBitmap bmAddButton(wxT("D:/CS163/picture/addButton.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmOrigin(wxT("D:/CS163/picture/origin.png"), wxBITMAP_TYPE_PNG);

	addButton = new wxBitmapButton(this, wxID_ANY, bmAddButton, wxDefaultPosition, wxSize(90, 85), wxNO_BORDER);
	origin = new wxBitmapButton(this, wxID_ANY, bmOrigin, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);

	addButton->SetBackgroundColour("#38435A");
	origin->SetBackgroundColour("#38435A");

	wxBitmap tPDic(wxT("D:/CS163/picture/TPHANG DICTIONARY.png"), wxBITMAP_TYPE_PNG);
	name = new wxBitmapButton(this, wxID_ANY, tPDic, wxDefaultPosition, wxSize(884, 147), wxNO_BORDER);
	name->SetBackgroundColour("#38435A");
}
