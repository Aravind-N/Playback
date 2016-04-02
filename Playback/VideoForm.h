#include"bass.h"
#include "RecordForm.h"
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
	/// Summary for VideoForm
	/// </summary>
	public ref class VideoForm : public System::Windows::Forms::Form
	{
	public:
		VideoForm(System::Windows::Forms::Form ^ first)
		{
			//otherform is a member of public ref class VideoForm and is used when the form is closed to call MusicForm's show function
			otherform = first;
			InitializeComponent();
		}
		VideoForm(System::Windows::Forms::Form ^ first, System::String^ s)
		{
			otherform = first;
			InitializeComponent();
			WindowsMediaPlayer1->URL = s;
		}

	private: System::Windows::Forms::ToolStripMenuItem^  recordModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  musicModeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  creditsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;

	public:
	private: System::Windows::Forms::Form ^ otherform;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VideoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: AxWMPLib::AxWindowsMediaPlayer^  WindowsMediaPlayer1;
	private: System::Windows::Forms::MenuStrip^  Menu2;
	protected:


	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VideoForm::typeid));
			this->WindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->Menu2 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->musicModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recordModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creditsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WindowsMediaPlayer1))->BeginInit();
			this->Menu2->SuspendLayout();
			this->SuspendLayout();
			// 
			// WindowsMediaPlayer1
			// 
			this->WindowsMediaPlayer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->WindowsMediaPlayer1->Enabled = true;
			this->WindowsMediaPlayer1->Location = System::Drawing::Point(0, 27);
			this->WindowsMediaPlayer1->Name = L"WindowsMediaPlayer1";
			this->WindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"WindowsMediaPlayer1.OcxState")));
			this->WindowsMediaPlayer1->Size = System::Drawing::Size(739, 449);
			this->WindowsMediaPlayer1->TabIndex = 0;
			// 
			// Menu2
			// 
			this->Menu2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->creditsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->Menu2->Location = System::Drawing::Point(0, 0);
			this->Menu2->Name = L"Menu2";
			this->Menu2->Size = System::Drawing::Size(739, 24);
			this->Menu2->TabIndex = 1;
			this->Menu2->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->musicModeToolStripMenuItem, this->recordModeToolStripMenuItem
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
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &VideoForm::openToolStripMenuItem_Click);
			// 
			// musicModeToolStripMenuItem
			// 
			this->musicModeToolStripMenuItem->Name = L"musicModeToolStripMenuItem";
			this->musicModeToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->musicModeToolStripMenuItem->Text = L"&Music mode";
			this->musicModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &VideoForm::musicModeToolStripMenuItem_Click);
			// 
			// recordModeToolStripMenuItem
			// 
			this->recordModeToolStripMenuItem->Name = L"recordModeToolStripMenuItem";
			this->recordModeToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->recordModeToolStripMenuItem->Text = L"&Record mode";
			this->recordModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &VideoForm::recordModeToolStripMenuItem_Click);
			// 
			// creditsToolStripMenuItem
			// 
			this->creditsToolStripMenuItem->Name = L"creditsToolStripMenuItem";
			this->creditsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->creditsToolStripMenuItem->Text = L"&Credits";
			this->creditsToolStripMenuItem->Click += gcnew System::EventHandler(this, &VideoForm::creditsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"&Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &VideoForm::helpToolStripMenuItem_Click);
			// 
			// VideoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 479);
			this->Controls->Add(this->WindowsMediaPlayer1);
			this->Controls->Add(this->Menu2);
			this->MainMenuStrip = this->Menu2;
			this->Name = L"VideoForm";
			this->Text = L"Media suite (Video mode)";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &VideoForm::VideoForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &VideoForm::VideoForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WindowsMediaPlayer1))->EndInit();
			this->Menu2->ResumeLayout(false);
			this->Menu2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::String ^ filename;
			bool returned_due_to_file = false;
	private:
		//libvlc_instance_t *inst;
		//libvlc_media_player_t *mp;
		//libvlc_media_t *m;
	private: System::Void VideoForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
	}
	public: System::Void Play_Video_From_Path(System::String^ filename)
	{
		WindowsMediaPlayer1->URL = filename;
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the tool strip is clicked, the FileName property of openFileDialog1 is assigned to the URL property of WindowsMediaPlayer.
		//The URL property is the path of the file to be played

		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "All supported files|*.mp3;*.mp2;*.mp1;*.m4a;*.wav;*.ogg;*.avi;*.mp4;*.asf;*.wma;*.wmv;*.wm;*.asx;*.wax;*.wvx;*.wpl;*.dvr-ms;*.mpg;*.mpeg;*.m1v;*.mpa;*.mpe;*.mpv2;*.m3u;*.mid;*.midi;*.rmi;*.ivf|Mp3 files|*.mp3|Mp2 files|*.mp2|Mp1 files|*.mp1|MPEG-4 (m4a) files|*.m4a|WAV files|*.wav|OGG files|*.ogg|Audio Visual Interleave (AVI)|*.avi|MPEG-4 (mp4)|*.mp4|Windows media formats|*.asf;*.wma;*.wmv;*.wm|Windows media metafiles|*.asx;*.wax;*.wvx;*.wpl|Microsoft digital video recording|*.dvr-ms|Moving Pictures Experts Group|*.mpg;*.mpeg;*.m1v;*.mpa;*.mpe;*.mpv2;*.m3u|MIDI|*.mid;*.midi;*.rmi|Indeo video technology|*.ivf";
		openFileDialog1->Title = "Select a File";
		openFileDialog1->FilterIndex = 1;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char ext[_MAX_EXT];
			char *file = (char*)(void*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName);

			//splits the path to get filename

			_splitpath(file, NULL, NULL, NULL, ext);
			System::String^ extention = gcnew String(ext);
			if ((extention == ".mp3") || (extention == ".mp2") || (extention == ".mp1") || (extention == ".m4a") || (extention == ".wav") || (extention == ".ogg"))
			{
				returned_due_to_file = true;
				filename = openFileDialog1->FileName;
				this->Hide();
				otherform->Show();
			}
			else
			{
				WindowsMediaPlayer1->URL = openFileDialog1->FileName;
			}
		}


	}
	private: System::Void VideoForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		Application::Exit();
	}
	private: System::Void musicModeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Hide();
		otherform->Show();
	}
	private: System::Void recordModeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the record mode item is clicked, the current form is closed and the record mode form is opened.

		RecordForm^ rf = gcnew RecordForm();
		rf->Show();
	}
	private: System::Void creditsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//When the credits menu item is clicked the credits box is shown

		MessageBox::Show("Created by Aravind-N");
	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MessageBox::Show("Click the Menu button to Open a new file or switch to the other modes");
	}
	};
}
