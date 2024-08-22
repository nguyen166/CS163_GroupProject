#include <wx/wx.h>

class QuizApp : public wxApp {
public:
    virtual bool OnInit();
};

class QuizFrame : public wxFrame {
public:
    QuizFrame(const wxString& title);

private:
    void OnButtonClicked(wxCommandEvent& event);
};

wxIMPLEMENT_APP(QuizApp);

bool QuizApp::OnInit() {
    QuizFrame* frame = new QuizFrame("Quiz Game");
    frame->Show(true);
    return true;
}

QuizFrame::QuizFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 500)) {
    wxPanel* panel = new wxPanel(this);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    wxStaticText* gameModeText = new wxStaticText(panel, wxID_ANY, "GAME MODE", wxDefaultPosition, wxSize(800, 50), wxALIGN_CENTER);
    gameModeText->SetFont(wxFont(28, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    vbox->Add(gameModeText, 0, wxEXPAND | wxTOP | wxBOTTOM, 10);


    wxStaticText* wordText = new wxStaticText(panel, wxID_ANY, "Word", wxDefaultPosition, wxSize(700, 50), wxALIGN_CENTER_HORIZONTAL);
    wordText->SetFont(wxFont(24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    vbox->Add(wordText, 0, wxEXPAND | wxALL, 20);

    wxGridSizer* gSizer = new wxGridSizer(2, 2, 20, 20);
    wxFont buttonFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxColour buttonColor(0, 128, 0);

    wxButton* buttons[4];
    wxString labels[4] = { "A.", "B.", "C.", "D." };
    for (int i = 0; i < 4; ++i) {
        buttons[i] = new wxButton(panel, 10001 + i, labels[i], wxDefaultPosition, wxSize(200, 50));
        buttons[i]->SetFont(buttonFont);
        buttons[i]->SetBackgroundColour(buttonColor);
        buttons[i]->SetForegroundColour(*wxWHITE);
        gSizer->Add(buttons[i], 0, wxEXPAND | wxALL, 10);
    }

    vbox->Add(gSizer, 1, wxEXPAND | wxALL, 20);
    panel->SetSizer(vbox);

    Bind(wxEVT_BUTTON, &QuizFrame::OnButtonClicked, this, 10001);
    Bind(wxEVT_BUTTON, &QuizFrame::OnButtonClicked, this, 10002);
    Bind(wxEVT_BUTTON, &QuizFrame::OnButtonClicked, this, 10003);
    Bind(wxEVT_BUTTON, &QuizFrame::OnButtonClicked, this, 10004);

    SetBackgroundColour(wxColour(240, 240, 240));
}

void QuizFrame::OnButtonClicked(wxCommandEvent& event) {
    int id = event.GetId();
    wxString msg;
    switch (id) {
    case 10001: msg = "Button A clicked!"; break;
    case 10002: msg = "Button B clicked!"; break;
    case 10003: msg = "Button C clicked!"; break;
    case 10004: msg = "Button D clicked!"; break;
    }
    wxMessageBox(msg, "Info", wxOK | wxICON_INFORMATION);
}