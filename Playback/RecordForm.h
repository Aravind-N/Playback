#include <Windows.h>
#include <mmsystem.h>
#include <vcclr.h>
#pragma once

namespace Playback {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for RecordForm
	/// </summary>
	public ref class RecordForm : public System::Windows::Forms::Form
	{
	public:
		RecordForm()
		{
			//Based on the constructor, The other form is the original form who calls the record form.

			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RecordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  lblTime;
	private: System::Windows::Forms::Timer^  RecordTimer;
	private: System::Windows::Forms::MenuStrip^  MenuStrip;


	private: System::Windows::Forms::ToolStripMenuItem^  creditsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;











	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->RecordTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->MenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->creditsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(117, 104);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"&Record";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RecordForm::button1_Click);
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTime->Location = System::Drawing::Point(113, 173);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(87, 21);
			this->lblTime->TabIndex = 1;
			this->lblTime->Text = L"0:0:0:0";
			// 
			// RecordTimer
			// 
			this->RecordTimer->Enabled = true;
			this->RecordTimer->Interval = 10;
			this->RecordTimer->Tick += gcnew System::EventHandler(this, &RecordForm::RecordTimer_Tick);
			// 
			// MenuStrip
			// 
			this->MenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->creditsToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->MenuStrip->Location = System::Drawing::Point(0, 0);
			this->MenuStrip->Name = L"MenuStrip";
			this->MenuStrip->Size = System::Drawing::Size(323, 24);
			this->MenuStrip->TabIndex = 2;
			this->MenuStrip->Text = L"menuStrip1";
			// 
			// creditsToolStripMenuItem
			// 
			this->creditsToolStripMenuItem->Name = L"creditsToolStripMenuItem";
			this->creditsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->creditsToolStripMenuItem->Text = L"&Credits";
			this->creditsToolStripMenuItem->Click += gcnew System::EventHandler(this, &RecordForm::creditsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"&Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &RecordForm::helpToolStripMenuItem_Click);
			// 
			// RecordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(323, 261);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->MenuStrip);
			this->MainMenuStrip = this->MenuStrip;
			this->Name = L"RecordForm";
			this->Text = L"Playback (Record Mode)";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RecordForm::RecordForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RecordForm::RecordForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &RecordForm::RecordForm_Load);
			this->MenuStrip->ResumeLayout(false);
			this->MenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		//Boolean variable to check if the record button was pressed.

		bool btnRecordpressed;

		//Structure used by MCI to perform recording tasks.

		WORD wDeviceID;

		//The variables used to display the time elapsed.

		static int centiseconds = 0;
		static int seconds = 0;
		static int minutes = 0;
		static int hours = 0;
		String^ cent;
		String^ sec;
		String^ minute;
		String^ hrs;
	private: System::Void RecordForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//When the form is loaded, The btnRecordpressed is set to false and the MCI device is opened.

		btnRecordpressed = false;
		MCI_OPEN_PARMS parmOpen;
		parmOpen.dwCallback = 0;
		parmOpen.wDeviceID = 0;	// the default device
		parmOpen.lpstrDeviceType = TEXT("waveaudio");
		parmOpen.lpstrElementName = TEXT("");
		parmOpen.lpstrAlias = 0;

		mciSendCommand(0, MCI_OPEN, MCI_WAIT | MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&parmOpen);

		wDeviceID = parmOpen.wDeviceID;

	}
	private: System::Void RecordForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		//When the form is closed, Form 1 is shown and MCI is closed and deallocated.
		MCI_GENERIC_PARMS parmsGen;
		parmsGen.dwCallback = 0;
		mciSendCommand(wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD)&parmsGen);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the record button is pressed...

		if (btnRecordpressed == false)
		{
			//The btnRecordpressed variable is set to true, The MCI device is started and recording begins.

			btnRecordpressed = true;
			MCI_RECORD_PARMS parmRec;
			parmRec.dwCallback = 0;
			parmRec.dwFrom = 0;
			parmRec.dwTo = 0;
			mciSendCommand(wDeviceID, MCI_RECORD, 0, (DWORD)&parmRec);
		}
		else
		{
			//The btnRecordpressed variable is set to false, The MCI device is stopped and a Save file dialog is created.
			btnRecordpressed = false;
			MCI_GENERIC_PARMS parmGen;
			parmGen.dwCallback = 0;
			mciSendCommand(wDeviceID, MCI_STOP, MCI_WAIT, (DWORD)&parmGen);
			SaveFileDialog^ savefiledialog1 = gcnew SaveFileDialog();
			savefiledialog1->Title = "Save recording";
			//savefiledialog1->ShowDialog();
			savefiledialog1->DefaultExt = ".wav";
			savefiledialog1->Filter = ".WAV|*.wav";
			savefiledialog1->FilterIndex = 1;
			if (savefiledialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && savefiledialog1->FileName->Length > 0)
			{
				//If a File name has been typed,The recording stored in buffer is saved to disk.

				MCI_SAVE_PARMS parmSave;
				parmSave.dwCallback = 0;
				pin_ptr<const wchar_t> wname = PtrToStringChars(savefiledialog1->FileName);
				parmSave.lpfilename = wname;
				mciSendCommand(wDeviceID, MCI_SAVE, MCI_WAIT | MCI_SAVE_FILE, (DWORD)&parmSave);
			}
		}

	}

	private: System::Void RecordForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		//When the RecordForm is closing, The MCI device is closed. Any memory allocated to the MCI device is deallocated.

		MCI_GENERIC_PARMS parmsGen;
		parmsGen.dwCallback = 0;
		mciSendCommand(wDeviceID, MCI_CLOSE, MCI_WAIT, (DWORD)&parmsGen);
	}
	private: System::Void RecordTimer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		//If the record button was pressed...
		if (btnRecordpressed == true)
		{
			//The timer at the bottom of the screen is updated showing the current time.

			centiseconds++;
			if (centiseconds == 100)
			{
				centiseconds = 0;
				seconds++;
				if (seconds == 60)
				{
					seconds = 0;
					minutes++;
					if (minutes == 60)
					{
						minutes = 0;
						hours++;
					}
				}
			}
			cent = Convert::ToString(centiseconds);
			sec = Convert::ToString(seconds);
			minute = Convert::ToString(minutes);
			hrs = Convert::ToString(hours);
			lblTime->Text = hrs + ":" + minute + ":" + sec + ":" + cent;
		}
		else
		{
			//The time parameters are set to zero.

			centiseconds = 0;
			seconds = 0;
			minutes = 0;
			hours = 0;
			lblTime->Text = "0:0:0:0";
		}

	}
	private: System::Void videoModeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Hide();
	}
	private: System::Void creditsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the credits menu item is clicked the credits box is shown

		MessageBox::Show("Created by Aravind-N");
	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MessageBox::Show("Click the Record button to record audio");
	}
	private: System::Void videoModeToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	};
}
