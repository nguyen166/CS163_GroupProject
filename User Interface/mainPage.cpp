#include "dicType.h"
#include "mainPage.h"

mainPage::mainPage(wxWindow* parent) : wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColor("#38435A"));

	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->AddSpacer(24);

	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBitmap bmAddButton(wxT("D:/CS163/picture/addButton.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmOrigin(wxT("D:/CS163/picture/origin.png"), wxBITMAP_TYPE_PNG);

	wxBitmapButton* addButton = new wxBitmapButton(panel, wxID_ANY, bmAddButton, wxDefaultPosition, wxSize(90, 85), wxNO_BORDER);
	wxBitmapButton* origin = new wxBitmapButton(panel, wxID_ANY, bmOrigin, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);

	addButton->SetBackgroundColour("#38435A");
	origin->SetBackgroundColour("#38435A");

	topSizer->Add(addButton, 0, wxEXPAND | wxLEFT, 24);
	topSizer->AddSpacer(24);
	topSizer->Add(origin, 0, wxEXPAND | wxTOP, 10);



	dicType* list = new dicType(panel);

	// Tạo wxBitmap từ file ảnh
	wxBitmap bmHistory(wxT("D:/CS163/picture/search history.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmRandom(wxT("D:/CS163/picture/random word.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmFavWords(wxT("D:/CS163/picture/favorite words.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmWordGames(wxT("D:/CS163/picture/word games.png"), wxBITMAP_TYPE_PNG);



	// Tạo wxBitmapButton
	wxBitmapButton* history = new wxBitmapButton(panel, wxID_ANY, bmHistory, wxPoint(80, 490), wxSize(230, 326));
	wxBitmapButton* Random = new wxBitmapButton(panel, wxID_ANY, bmRandom, wxPoint(427, 490), wxSize(230, 326));
	wxBitmapButton* FavWords = new wxBitmapButton(panel, wxID_ANY, bmFavWords, wxPoint(774, 490), wxSize(230, 326));
	wxBitmapButton* WordGames = new wxBitmapButton(panel, wxID_ANY, bmWordGames, wxPoint(1121, 490), wxSize(230, 326));

	topSizer->Add(list->list, 0, wxEXPAND | wxLEFT, 968);

	mainSizer->Add(topSizer);

	wxBitmap tPDic(wxT("D:/CS163/picture/TPHANG DICTIONARY.png"), wxBITMAP_TYPE_PNG);
	wxBitmapButton* name = new wxBitmapButton(panel, wxID_ANY, tPDic, wxDefaultPosition, wxSize(884, 147), wxNO_BORDER);
	name->SetBackgroundColour("#38435A");

	mainSizer->AddSpacer(60);
	mainSizer->Add(name, 0, wxEXPAND | wxLEFT, 273);

	// Create a horizontal sizer for the search bar
	wxBoxSizer* searchSizer = new wxBoxSizer(wxHORIZONTAL);

	// Create the search input field
	wxTextCtrl* searchInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(867, 40));
	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Varela Round");
	searchInput->SetFont(font);
	searchInput->SetHint("Enter search text...");  // Placeholder text

	// Create the search button
	wxButton* searchButton = new wxButton(panel, wxID_ANY, "Search", wxDefaultPosition, wxSize(100, 40), wxNO_BORDER);
	searchButton->SetFont(font);
	searchButton->SetBackgroundColour("#FF4F70");
	searchButton->SetForegroundColour(wxColour("#FFFFFF"));

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


	panel->SetSizerAndFit(mainSizer);



}

void mainPage::OnButtonClicked(wxCommandEvent& event)
{
	wxCommandEvent evt(wxEVT_COMMAND_BUTTON_CLICKED, wxID_ANY);
	evt.SetEventObject(this);
	wxPostEvent(GetParent(), evt);
}
