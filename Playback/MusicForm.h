#include "bass.h"
#include "VideoForm.h"
#include "RecordForm.h"
#include <stdlib.h>

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
	/// Summary for MusicForm
	/// </summary>
	public ref class MusicForm : public System::Windows::Forms::Form
	{
	public:
		MusicForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MusicForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^  btnStop;
	private: System::Windows::Forms::MenuStrip^  Menu;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::Label^  lblStatus;

	private: System::Windows::Forms::Label^  lblSongName;





	private: System::Windows::Forms::ToolStripMenuItem^  creditsToolStripMenuItem;
	private: System::Windows::Forms::Button^  btnPause;
	private: System::Windows::Forms::Timer^  SongStateChecker;
	private: System::Windows::Forms::TrackBar^  Trackbar;

	private: System::Windows::Forms::Timer^  SongPositionChecker;

	private: System::Windows::Forms::ToolStripMenuItem^  recordModeToolStripMenuItem1;
	private: System::Windows::Forms::Button^  btnRepeat;

	private: System::Windows::Forms::Timer^  Return_from_video_checker;
	private: System::Windows::Forms::ToolStripMenuItem^  videoModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;

	private: System::Windows::Forms::Button^  btnPlay;












	private: System::ComponentModel::IContainer^  components;







	protected:


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
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->Menu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->videoModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recordModeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creditsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->lblSongName = (gcnew System::Windows::Forms::Label());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->SongStateChecker = (gcnew System::Windows::Forms::Timer(this->components));
			this->Trackbar = (gcnew System::Windows::Forms::TrackBar());
			this->SongPositionChecker = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnRepeat = (gcnew System::Windows::Forms::Button());
			this->Return_from_video_checker = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->Menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Trackbar))->BeginInit();
			this->SuspendLayout();
			// 
			// btnStop
			// 
			this->btnStop->AutoSize = true;
			this->btnStop->Enabled = false;
			this->btnStop->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnStop->Location = System::Drawing::Point(181, 115);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(96, 31);
			this->btnStop->TabIndex = 3;
			this->btnStop->Text = L"&Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MusicForm::btnStop_Click);
			// 
			// Menu
			// 
			this->Menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->creditsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->Menu->Location = System::Drawing::Point(0, 0);
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(312, 24);
			this->Menu->TabIndex = 4;
			this->Menu->Text = L"menuStrip1";
			this->Menu->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MusicForm::Menu_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->videoModeToolStripMenuItem, this->recordModeToolStripMenuItem1
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->fileToolStripMenuItem->Text = L"&Menu";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->openToolStripMenuItem->Text = L"&Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MusicForm::openToolStripMenuItem_Click);
			// 
			// videoModeToolStripMenuItem
			// 
			this->videoModeToolStripMenuItem->Name = L"videoModeToolStripMenuItem";
			this->videoModeToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->videoModeToolStripMenuItem->Text = L"&Video mode";
			this->videoModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MusicForm::videoModeToolStripMenuItem_Click);
			// 
			// recordModeToolStripMenuItem1
			// 
			this->recordModeToolStripMenuItem1->Name = L"recordModeToolStripMenuItem1";
			this->recordModeToolStripMenuItem1->Size = System::Drawing::Size(145, 22);
			this->recordModeToolStripMenuItem1->Text = L"&Record mode";
			this->recordModeToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MusicForm::recordModeToolStripMenuItem1_Click);
			// 
			// creditsToolStripMenuItem
			// 
			this->creditsToolStripMenuItem->Name = L"creditsToolStripMenuItem";
			this->creditsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->creditsToolStripMenuItem->Text = L"&Credits";
			this->creditsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MusicForm::creditsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"&Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MusicForm::helpToolStripMenuItem_Click);
			// 
			// lblStatus
			// 
			this->lblStatus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->ForeColor = System::Drawing::Color::CadetBlue;
			this->lblStatus->Location = System::Drawing::Point(68, 44);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(164, 24);
			this->lblStatus->TabIndex = 5;
			this->lblStatus->Text = L"Please Load Song";
			this->lblStatus->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblStatus->Click += gcnew System::EventHandler(this, &MusicForm::lblStatus_Click);
			// 
			// lblSongName
			// 
			this->lblSongName->AutoSize = true;
			this->lblSongName->Location = System::Drawing::Point(12, 75);
			this->lblSongName->Name = L"lblSongName";
			this->lblSongName->Size = System::Drawing::Size(0, 13);
			this->lblSongName->TabIndex = 6;
			// 
			// btnPause
			// 
			this->btnPause->Enabled = false;
			this->btnPause->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnPause->Location = System::Drawing::Point(34, 115);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(94, 31);
			this->btnPause->TabIndex = 7;
			this->btnPause->Text = L"Pa&use";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Visible = false;
			this->btnPause->Click += gcnew System::EventHandler(this, &MusicForm::btnPause_Click);
			// 
			// SongStateChecker
			// 
			this->SongStateChecker->Enabled = true;
			this->SongStateChecker->Tick += gcnew System::EventHandler(this, &MusicForm::timer1_Tick);
			// 
			// Trackbar
			// 
			this->Trackbar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Trackbar->Enabled = false;
			this->Trackbar->Location = System::Drawing::Point(0, 175);
			this->Trackbar->Maximum = 1000;
			this->Trackbar->Name = L"Trackbar";
			this->Trackbar->Size = System::Drawing::Size(312, 45);
			this->Trackbar->TabIndex = 8;
			this->Trackbar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->Trackbar->Scroll += gcnew System::EventHandler(this, &MusicForm::Trackbar_Scroll);
			// 
			// SongPositionChecker
			// 
			this->SongPositionChecker->Enabled = true;
			this->SongPositionChecker->Interval = 50;
			this->SongPositionChecker->Tick += gcnew System::EventHandler(this, &MusicForm::SongPositionChecker_Tick);
			// 
			// btnRepeat
			// 
			this->btnRepeat->Location = System::Drawing::Point(181, 212);
			this->btnRepeat->Name = L"btnRepeat";
			this->btnRepeat->Size = System::Drawing::Size(96, 24);
			this->btnRepeat->TabIndex = 9;
			this->btnRepeat->Text = L"&Repeat Off";
			this->btnRepeat->UseVisualStyleBackColor = true;
			this->btnRepeat->Click += gcnew System::EventHandler(this, &MusicForm::btnRepeat_Click);
			// 
			// Return_from_video_checker
			// 
			this->Return_from_video_checker->Enabled = true;
			this->Return_from_video_checker->Tick += gcnew System::EventHandler(this, &MusicForm::Return_from_video_checker_Tick);
			// 
			// btnPlay
			// 
			this->btnPlay->AutoSize = true;
			this->btnPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnPlay->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnPlay->Location = System::Drawing::Point(34, 115);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(94, 31);
			this->btnPlay->TabIndex = 12;
			this->btnPlay->Text = L"&Play";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MusicForm::btnPlay_Click);
			// 
			// MusicForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(312, 261);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->btnRepeat);
			this->Controls->Add(this->Trackbar);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->lblSongName);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->Menu);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MainMenuStrip = this->Menu;
			this->MaximizeBox = false;
			this->Name = L"MusicForm";
			this->Text = L"Playback (Music mode)";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MusicForm::MusicForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MusicForm::MusicForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MusicForm::MusicForm_Load);
			this->Menu->ResumeLayout(false);
			this->Menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Trackbar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private:
		//This is the channel used to play music. DWORD is an #defined version of unsigned long;

		DWORD channel;

		//Boolean variables to check the state of the file.

		bool FileIsLoaded;
		bool FilePlayed;
		bool btnRepeatPressed;

		//Length of the song.

		QWORD Len;

		//Leastcount of the song.

		double leastcount;

		//Form2 definition

		VideoForm^ videoForm = gcnew VideoForm(this);
#pragma endregion
	private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the play button is clicked,the current channel is played and now playing is shown

		BASS_ChannelPlay(channel, false);
		Trackbar->Enabled = true;
		FilePlayed = true;
		lblStatus->Left = 98;
		lblStatus->Text = "Now Playing";
		lblStatus->Visible = true;
		if (BASS_ChannelIsActive(channel) == BASS_ACTIVE_PLAYING)
		{
			//while a song is playing, play button is deactivated and stop button is activated

			btnPlay->Enabled = false;
			btnPlay->Visible = false;
			btnPause->Enabled = true;
			btnPause->Visible = true;
			btnStop->Enabled = true;
			btnRepeat->Enabled = true;
		}

	}
	private: System::Void MusicForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		//When the form is closed,the memory allocated to BASS is freed

		BASS_Free();
	}
	private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the stop button is clicked,it is disabled and the channel is stopped.
		//The position of the channel is set to 0 bytes so that the song's playback, if resumed, resumes from the beginning

		BASS_ChannelStop(channel);
		BASS_ChannelSetPosition(channel, 0, NULL);
		Trackbar->Value = 0;
		Trackbar->Enabled = false;
		btnStop->Enabled = false;
		btnPause->Enabled = false;
		btnPause->Visible = false;
		btnRepeat->Enabled = false;
		btnRepeatPressed = false;
		btnRepeat->Text = L"&Repeat Off";
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the open button in the tool strip is clicked, Windows Explorer is called and a file can be selected

		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		//applies filters for choosing files

		openFileDialog1->Filter = "All supported files|*.mp3;*.mp2;*.mp1;*.m4a;*.wav;*.ogg;*.avi;*.mp4;*.asf;*.wma;*.wmv;*.wm;*.asx;*.wax;*.wvx;*.wpl;*.dvr-ms;*.mpg;*.mpeg;*.m1v;*.mpa;*.mpe;*.mpv2;*.m3u;*.mid;*.midi;*.rmi;*.ivf|Mp3 files|*.mp3|Mp2 files|*.mp2|Mp1 files|*.mp1|MPEG-4 (m4a) files|*.m4a|WAV files|*.wav|OGG files|*.ogg|Audio Visual Interleave (AVI)|*.avi|MPEG-4 (mp4)|*.mp4|Windows media formats|*.asf;*.wma;*.wmv;*.wm|Windows media metafiles|*.asx;*.wax;*.wvx;*.wpl|Microsoft digital video recording|*.dvr-ms|Moving Pictures Experts Group|*.mpg;*.mpeg;*.m1v;*.mpa;*.mpe;*.mpv2;*.m3u|MIDI|*.mid;*.midi;*.rmi|Indeo video technology|*.ivf";
		//sets the title for the window

		openFileDialog1->Title = "Select a File";
		openFileDialog1->FilterIndex = 1;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)

		{
			FileIsLoaded = true;
			FilePlayed = false;
			BASS_ChannelStop(channel);
			char fname[_MAX_FNAME];
			char ext[_MAX_EXT];

			//converts openFileDialog1->FileName from System::String to char* and assigns to file

			char *file = (char*)(void*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName);

			//splits the path to get filename

			_splitpath(file, NULL, NULL, fname, ext);

			//converts fname from char* to System::String

			System::String^ s = gcnew String(fname);
			System::String^ extention = gcnew String(ext);
			lblSongName->Text = s;
			if ((extention == ".mp3") || (extention == ".mp2") || (extention == ".mp1") || (extention == ".m4a") || (extention == ".wav") || (extention == ".ogg"))
			{
				channel = BASS_StreamCreateFile(false, file, 0, 0, 0);
				btnPause->Enabled = false;
				btnPause->Visible = false;
				btnPlay->Enabled = true;
				btnPlay->Visible = true;
				btnStop->Enabled = false;
				btnRepeat->Enabled = true;
				lblStatus->Left = 90;
				lblStatus->Text = "Song Loaded";
				lblStatus->Visible = true;

				//Gets the length of the song.

				Len = BASS_ChannelGetLength(channel, BASS_POS_BYTE);

				//Sets the least count of the trackbar.

				leastcount = Len / 1000.0;

				//Sets the value of the trackbar to 0.

				Trackbar->Value = 0;
			}

			else
			{
				FileIsLoaded = false;
				FilePlayed = false;
				BASS_ChannelStop(channel);
				Trackbar->Value = 0;
				Trackbar->Enabled = false;
				BASS_StreamFree(channel);
				lblStatus->Text = "Please load song";
				lblStatus->Left = 68;
				btnStop->Enabled = false;
				btnPlay->Enabled = false;
				btnPlay->Visible = true;
				btnPause->Enabled = false;
				btnPause->Visible = false;
				lblSongName->Text = "";
				btnRepeat->Text = L"&Repeat Off";
				btnRepeat->Enabled = false;
				btnRepeatPressed = false;

				//The other file is sent to form2 using the Play() function

				this->Hide();
				videoForm->Show();
				videoForm->Play_Video_From_Path(openFileDialog1->FileName);
			}
		}
	}
	private: System::Void lblStatus_Click(System::Object^  sender, System::EventArgs^  e)
	{
	}
	private: System::Void MusicForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		//When the form loads, the introductory message box is shown

		btnPlay->Enabled = false;
		btnRepeat->Enabled = false;
		//Initialises BASS
		BASS_Init(-1, 44100, 0, 0, NULL);
		FilePlayed = false;
		Len = 0;
		leastcount = 0;
		btnRepeatPressed = false;
	}
	private: System::Void Menu_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e)
	{
	}
	private: System::Void MusicForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		//When the form is closed, the ending message is shown.
		videoForm->Close();
	}
	private: System::Void creditsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{

		//When the credits menu item is clicked the credits box is shown

		MessageBox::Show("Created by Aravind-N");
	}

	private: System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the Pause button is clicked, the current channel is paused, the Pause button is disabled, its visibility is set to false and the Play button is shown.
		BASS_ChannelPause(channel);
		lblStatus->Left = 91;
		lblStatus->Text = "Song Paused";
		btnPause->Enabled = false;
		btnPause->Visible = false;
		btnPlay->Enabled = true;
		btnPlay->Visible = true;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		//Every 100 milliseconds the control checks if the channel is active and if it is stopped...
		if (BASS_ChannelIsActive(channel) == BASS_ACTIVE_STOPPED)
		{
			//Checks if song state is true and does the following.
			if (FileIsLoaded == true)
			{
				if (FilePlayed == true)
				{
					btnPause->Enabled = false;
					btnPause->Visible = false;
					btnPlay->Visible = true;
					btnPlay->Enabled = true;
					btnStop->Enabled = false;
					lblStatus->Text = "Song Stopped";
					lblStatus->Left = 91;
				}
				else
				{
					btnPause->Enabled = false;
					btnPause->Visible = false;
					btnPlay->Visible = true;
					btnPlay->Enabled = true;
				}
			}
			//Otherwise it retains default controls
			else
			{
				btnPause->Enabled = false;
				btnPause->Visible = false;
				btnPlay->Visible = true;
				btnPlay->Enabled = false;
				btnStop->Enabled = false;
				lblStatus->Left = 68;
				lblStatus->Text = "Please Load Song";
			}
		}
	}
	private: System::Void Trackbar_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		//When the position of the trackbar is changed, the position of the song is accordingly set.

		SongPositionChecker->Enabled = false;
		BASS_ChannelSetPosition(channel, (Trackbar->Value * leastcount), BASS_POS_BYTE);
		SongPositionChecker->Enabled = true;
	}
	private: System::Void SongPositionChecker_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		//If the song is loaded, the trackbar is auto updated and is set to sync with the position of the song.

		if (FileIsLoaded == true)
		{
			if (FilePlayed == true)
			{
				Trackbar->Value = BASS_ChannelGetPosition(channel, BASS_POS_BYTE) / leastcount;
			}
			else
			{
				Trackbar->Value = 0;
			}
		}
		if ((BASS_ChannelIsActive(channel) == BASS_ACTIVE_STOPPED) && (BASS_ChannelGetPosition(channel, BASS_POS_BYTE) == BASS_ChannelGetLength(channel, BASS_POS_BYTE)))
		{
			Trackbar->Value = 0;
			Trackbar->Enabled = false;
			btnStop->Enabled = false;
			if (btnRepeatPressed == true)
			{
				BASS_ChannelPlay(channel, false);
				Trackbar->Enabled = true;
				FilePlayed = true;
				lblStatus->Left = 98;
				lblStatus->Text = "Now Playing";
				lblStatus->Visible = true;
				if (BASS_ChannelIsActive(channel) == BASS_ACTIVE_PLAYING)
				{
					//while a song is playing, play button is deactivated and stop button is activated

					btnPlay->Enabled = false;
					btnPlay->Visible = false;
					btnPause->Enabled = true;
					btnPause->Visible = true;
					btnStop->Enabled = true;
				}
			}
		}

	}
	private: System::Void recordModeToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the record mode item is clicked, the current form is closed and the record mode form is opened.

		RecordForm^ rf = gcnew RecordForm();
		rf->Show();
	}
	private: System::Void videoModeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the Video mode tab under the switch toolbar is clicked, the song being played, if any , is stopped and the status label is changed

		FileIsLoaded = false;
		FilePlayed = false;
		BASS_ChannelStop(channel);
		Trackbar->Value = 0;
		Trackbar->Enabled = false;
		BASS_StreamFree(channel);
		lblStatus->Text = "Please load song";
		lblStatus->Left = 68;
		btnStop->Enabled = false;
		btnPlay->Enabled = false;
		btnPlay->Visible = true;
		btnPause->Enabled = false;
		btnPause->Visible = false;
		lblSongName->Text = "";
		btnRepeat->Text = L"&Repeat Off";
		btnRepeat->Enabled = false;
		btnRepeatPressed = false;

		//A new instance of Form2 is created. this is then shown and the current form is hidden using the Hide() function

		// Form2^ form2 = gcnew Form2 (this);
		videoForm->Show();
		this->Hide();
	}
	private: System::Void btnRepeat_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (btnRepeatPressed == false)
		{
			btnRepeatPressed = true;
			btnRepeat->Text = L"&Repeat On";
		}
		else
		{
			btnRepeatPressed = false;
			btnRepeat->Text = L"&Repeat Off";
		}
	}
	private: System::Void lblRepeat_Click(System::Object^  sender, System::EventArgs^  e)
	{
	}
	private: System::Void Return_from_video_checker_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (videoForm->returned_due_to_file == true)
		{
			videoForm->returned_due_to_file = false;
			FileIsLoaded = true;
			FilePlayed = false;
			BASS_ChannelStop(channel);
			char fname[_MAX_FNAME];
			char ext[_MAX_EXT];

			//converts openFileDialog1->FileName from System::String to char* and assigns to file

			char *file = (char*)(void*)Marshal::StringToHGlobalAnsi(videoForm->filename);

			//splits the path to get filename

			_splitpath(file, NULL, NULL, fname, ext);

			//converts fname from char* to System::String

			System::String^ s = gcnew String(fname);
			System::String^ extention = gcnew String(ext);
			lblSongName->Text = s;
			channel = BASS_StreamCreateFile(false, file, 0, 0, 0);
			btnPause->Enabled = false;
			btnPause->Visible = false;
			btnPlay->Enabled = true;
			btnPlay->Visible = true;
			btnStop->Enabled = false;
			btnRepeat->Enabled = true;
			lblStatus->Left = 90;
			lblStatus->Text = "Song Loaded";
			lblStatus->Visible = true;

			//Gets the length of the song.

			Len = BASS_ChannelGetLength(channel, BASS_POS_BYTE);

			//Sets the least count of the trackbar.

			leastcount = Len / 1000.0;

			//Sets the value of the trackbar to 0.

			Trackbar->Value = 0;
		}
	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MessageBox::Show("Click the Menu button to Open a new file or switch to the other modes");
	}
	};
}
