#include "dictionary.h"
#include "frame.h"

bool dictionary::OnInit()
{
	wxInitAllImageHandlers();

	frame* frames = new frame();

	frames->Show(true);
	return true;
}

wxIMPLEMENT_APP(dictionary);
