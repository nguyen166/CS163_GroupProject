#include "dicType.h"
#include "searchPage.h"

searchPage::searchPage(wxWindow* parent) : wxWindow(parent, wxID_ANY)
{
	bgBitmap = wxBitmap(wxT("D:/CS163/picture/Search background.png"), wxBITMAP_TYPE_PNG);

	// Ensure bitmap is loaded
	if (!bgBitmap.IsOk()) {
		wxLogError("Failed to load background image.");
	}



	// Bind events
	Bind(wxEVT_PAINT, &searchPage::setBackgroundImage, this);

	// Create panel and sizers
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

	topSizer->Add(addButton, 0, wxLEFT, 24);
	topSizer->AddSpacer(24);
	topSizer->Add(origin, 0, wxTOP, 10);

	dicType* list = new dicType(panel);

	wxBitmap bmHistory(wxT("D:/CS163/picture/search history.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmRandom(wxT("D:/CS163/picture/random word.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmFavWords(wxT("D:/CS163/picture/favorite words.png"), wxBITMAP_TYPE_PNG);
	wxBitmap bmWordGames(wxT("D:/CS163/picture/word games.png"), wxBITMAP_TYPE_PNG);

	wxBitmapButton* history = new wxBitmapButton(panel, wxID_ANY, bmHistory, wxDefaultPosition, wxSize(230, 326));
	wxBitmapButton* Random = new wxBitmapButton(panel, wxID_ANY, bmRandom, wxDefaultPosition, wxSize(230, 326));
	wxBitmapButton* FavWords = new wxBitmapButton(panel, wxID_ANY, bmFavWords, wxDefaultPosition, wxSize(230, 326));
	wxBitmapButton* WordGames = new wxBitmapButton(panel, wxID_ANY, bmWordGames, wxDefaultPosition, wxSize(230, 326));

	topSizer->Add(list->list, 0, wxLEFT, 968);

	mainSizer->Add(topSizer);

	wxBitmap tPDic(wxT("D:/CS163/picture/TPHANG DICTIONARY.png"), wxBITMAP_TYPE_PNG);
	wxBitmapButton* name = new wxBitmapButton(panel, wxID_ANY, tPDic, wxDefaultPosition, wxSize(884, 147), wxNO_BORDER);
	name->SetBackgroundColour("#38435A");

	mainSizer->AddSpacer(60);
	mainSizer->Add(name, 0, wxLEFT, 273);

	wxBoxSizer* searchSizer = new wxBoxSizer(wxHORIZONTAL);

	wxTextCtrl* searchInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(867, 40));
	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Varela Round");
	searchInput->SetFont(font);
	searchInput->SetHint("Enter search text...");

	wxButton* searchButton = new wxButton(panel, wxID_ANY, "Search", wxDefaultPosition, wxSize(100, 40), wxNO_BORDER);
	searchButton->SetFont(font);
	searchButton->SetBackgroundColour("#FF4F70");
	searchButton->SetForegroundColour(wxColour("#FFFFFF"));

	searchSizer->Add(searchInput, 1, wxALIGN_CENTER_VERTICAL, 10);
	searchSizer->AddSpacer(10);
	searchSizer->Add(searchButton, 0, wxALIGN_CENTER_VERTICAL, 10);

	mainSizer->Add(searchSizer, 0, wxALIGN_CENTER | wxALL, 10);

	mainSizer->AddSpacer(100);

	wxBoxSizer* botSizer = new wxBoxSizer(wxHORIZONTAL);

	botSizer->Add(history, 0, wxLEFT, 80);
	botSizer->Add(Random, 0, wxLEFT, 117);
	botSizer->Add(FavWords, 0, wxLEFT, 117);
	botSizer->Add(WordGames, 0, wxLEFT, 117);

	mainSizer->Add(botSizer);

	panel->SetSizerAndFit(mainSizer);
}

void searchPage::setBackgroundImage(wxPaintEvent& event)
{
	wxPaintDC dc(this);

	if (bgBitmap.IsOk()) {
		wxSize size = GetClientSize();
		wxBitmap resizedBitmap = wxBitmap(bgBitmap.ConvertToImage().Scale(size.GetWidth(), size.GetHeight()));
		dc.DrawBitmap(resizedBitmap, 0, 0, true);
	}

	event.Skip(); // Ensure other event handlers are processed
}

void searchPage::OnEraseBackground(wxEraseEvent& event)
{
	// Prevent background from being erased
}
