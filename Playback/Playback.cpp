// Playback.cpp : main project file.

#include "stdafx.h"
#include "MusicForm.h"

using namespace Playback;

void ExitWhenLastWindowClosed(Object^ sender, FormClosedEventArgs^ e)
{
	//this function is created to ensure that the program closes only when no forms are active.
	if (Application::OpenForms->Count == 0)
	{

		Application::Exit();
	}
	else Application::OpenForms[0]->FormClosed += gcnew FormClosedEventHandler(ExitWhenLastWindowClosed);
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MusicForm^ first = gcnew MusicForm();

	//Creates a new instance of MusicForm class. the gcnew keyword is used to create objects of managed classes

	first->FormClosed += gcnew FormClosedEventHandler(ExitWhenLastWindowClosed);

	//When the first is closed, it creates a new instance of FormClosedEventHandler with the argument as ExitWhenLastWindowClosed.

	first->Show();

	//Shows the first form as by default it is hidden.

	Application::Run();
	//Runs the application and shifts control to MusicForm.h

	return 0;
}
