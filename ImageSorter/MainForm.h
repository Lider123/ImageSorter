#pragma once

namespace ImageSorter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  orientationSortingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sizeFiltrationToolStripMenuItem;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;
	private: System::Windows::Forms::StatusStrip^  statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^  pathToolStripStatusLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^  countToolStripStatusLabel;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar;
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Panel^  buttonsPanel;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::Button^  buttonNext;
	private: System::Windows::Forms::Button^  buttonPrev;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->orientationSortingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sizeFiltrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->pathToolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->countToolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripProgressBar = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->buttonsPanel = (gcnew System::Windows::Forms::Panel());
			this->buttonNext = (gcnew System::Windows::Forms::Button());
			this->buttonPrev = (gcnew System::Windows::Forms::Button());
			this->menuStrip->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->buttonsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->toolsToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(800, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->closeToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->openToolStripMenuItem->Text = L"Open...";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::closeToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->orientationSortingToolStripMenuItem,
					this->sizeFiltrationToolStripMenuItem
			});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// orientationSortingToolStripMenuItem
			// 
			this->orientationSortingToolStripMenuItem->Name = L"orientationSortingToolStripMenuItem";
			this->orientationSortingToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->orientationSortingToolStripMenuItem->Text = L"Orientation sorting";
			this->orientationSortingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::orientationSortingToolStripMenuItem_Click);
			// 
			// sizeFiltrationToolStripMenuItem
			// 
			this->sizeFiltrationToolStripMenuItem->Name = L"sizeFiltrationToolStripMenuItem";
			this->sizeFiltrationToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->sizeFiltrationToolStripMenuItem->Text = L"Size filtration";
			this->sizeFiltrationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sizeFiltrationToolStripMenuItem_Click);
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->pathToolStripStatusLabel,
					this->countToolStripStatusLabel, this->toolStripProgressBar
			});
			this->statusStrip->Location = System::Drawing::Point(0, 578);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(800, 22);
			this->statusStrip->TabIndex = 1;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// pathToolStripStatusLabel
			// 
			this->pathToolStripStatusLabel->Name = L"pathToolStripStatusLabel";
			this->pathToolStripStatusLabel->Size = System::Drawing::Size(0, 17);
			// 
			// countToolStripStatusLabel
			// 
			this->countToolStripStatusLabel->Name = L"countToolStripStatusLabel";
			this->countToolStripStatusLabel->Size = System::Drawing::Size(0, 17);
			// 
			// toolStripProgressBar
			// 
			this->toolStripProgressBar->Name = L"toolStripProgressBar";
			this->toolStripProgressBar->Size = System::Drawing::Size(100, 16);
			// 
			// mainPanel
			// 
			this->mainPanel->Controls->Add(this->pictureBox);
			this->mainPanel->Controls->Add(this->buttonsPanel);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(0, 24);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(800, 554);
			this->mainPanel->TabIndex = 2;
			// 
			// pictureBox
			// 
			this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(800, 522);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// buttonsPanel
			// 
			this->buttonsPanel->Controls->Add(this->buttonNext);
			this->buttonsPanel->Controls->Add(this->buttonPrev);
			this->buttonsPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonsPanel->Location = System::Drawing::Point(0, 522);
			this->buttonsPanel->Name = L"buttonsPanel";
			this->buttonsPanel->Size = System::Drawing::Size(800, 32);
			this->buttonsPanel->TabIndex = 0;
			// 
			// buttonNext
			// 
			this->buttonNext->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->buttonNext->Location = System::Drawing::Point(413, 3);
			this->buttonNext->Name = L"buttonNext";
			this->buttonNext->Size = System::Drawing::Size(75, 23);
			this->buttonNext->TabIndex = 1;
			this->buttonNext->Text = L"next";
			this->buttonNext->UseVisualStyleBackColor = true;
			this->buttonNext->Click += gcnew System::EventHandler(this, &MainForm::buttonNext_Click);
			// 
			// buttonPrev
			// 
			this->buttonPrev->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->buttonPrev->Location = System::Drawing::Point(332, 3);
			this->buttonPrev->Name = L"buttonPrev";
			this->buttonPrev->Size = System::Drawing::Size(75, 23);
			this->buttonPrev->TabIndex = 0;
			this->buttonPrev->Text = L"prev";
			this->buttonPrev->UseVisualStyleBackColor = true;
			this->buttonPrev->Click += gcnew System::EventHandler(this, &MainForm::buttonPrev_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 600);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ImageSorter";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->mainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->buttonsPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	bool folderChosen;
	array<String^>^ formats;
	DirectoryInfo^ dirInfo;
	List<FileInfo^>^ fileInfos;
	int counter;
	
	System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		folderChosen = false;
		counter = -1;
		formats = gcnew array<String^> { L"*.jpg", L"*.jpeg", L"*.png" };
		toolStripProgressBar->Visible = false;
		UpdateMenu();
		UpdateContentVisibility();
	}

	void UpdateContentVisibility() {
		if (folderChosen && fileInfos != nullptr && fileInfos->Count > 0)
			mainPanel->Visible = true;
		else
			mainPanel->Visible = false;
	}

	System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

	System::Void orientationSortingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ SUFFIX_PORTRAIT = "_portrait";
		String^ SUFFIX_LANDSCAPE = "_landscape";
		String^ path = folderBrowserDialog->SelectedPath;

		toolStripProgressBar->Visible = true;
		try {
			String^ currDirName = dirInfo->Name;
			if (fileInfos->Count > 0) {
				toolStripProgressBar->Maximum = fileInfos->Count;
				toolStripProgressBar->Value = 0;
				dirInfo->CreateSubdirectory(currDirName + SUFFIX_PORTRAIT);
				dirInfo->CreateSubdirectory(currDirName + SUFFIX_LANDSCAPE);
				for (int i = 0; i < fileInfos->Count; i++) {
					FileInfo^ info = fileInfos[i];
					Bitmap^ image = gcnew Bitmap(path + "\\" + info->Name);
					if (image->Width > image->Height)
						writeToFile(path + "\\" + currDirName + SUFFIX_LANDSCAPE + "\\" + info->Name, image);
					if (image->Height > image->Width)
						writeToFile(path + "\\" + currDirName + SUFFIX_PORTRAIT + "\\" + info->Name, image);
					toolStripProgressBar->Increment(1);
				}
				MessageBox::Show("Sorting complete", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				Console::WriteLine("Sorting complete. Sorted " + fileInfos->Count + " files");
			}
			else
				MessageBox::Show("There are no files in current directory", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		catch (ArgumentException^ e) {
			MessageBox::Show("Error: Wrong path", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			Console::WriteLine("Error while sorting");
		}
		finally {
			toolStripProgressBar->Visible = false;
		}
	}
	
	System::Void sizeFiltrationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ SUFFIX = "_filtered";
		int MIN_HEIGHT = 610;
		String^ path = folderBrowserDialog->SelectedPath;

		toolStripProgressBar->Visible = true;
		try {
			String^ currDirName = dirInfo->Name;
			if (fileInfos->Count > 0) {
				toolStripProgressBar->Maximum = fileInfos->Count;
				toolStripProgressBar->Value = 0;
				dirInfo->CreateSubdirectory(currDirName + SUFFIX);
				for (int i = 0; i < fileInfos->Count; i++) {
					FileInfo^ info = fileInfos[i];
					Bitmap^ image = gcnew Bitmap(path + "\\" + info->Name);
					if (image->Height >= MIN_HEIGHT)
						writeToFile(path + "\\" + currDirName + SUFFIX + "\\" + info->Name, image);
					toolStripProgressBar->Increment(1);
				}

				MessageBox::Show("Sorting complete", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				Console::WriteLine("Sorting complete. Sorted " + fileInfos->Count + " files");
			}
			else
				MessageBox::Show("There are no files in current directory", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		catch (ArgumentException^ e) {
			MessageBox::Show("Error: Wrong path", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			Console::WriteLine("Error while sorting");
		}
		finally {
			toolStripProgressBar->Visible = false;
		}
	}
	
	System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult result = folderBrowserDialog->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK) {
			folderChosen = true;
			UpdateMenu();
			SetContent(folderBrowserDialog->SelectedPath);
			UpdateContentVisibility();
		}
	}

	void SetContent(String^ path) {
		dirInfo = gcnew DirectoryInfo(this->folderBrowserDialog->SelectedPath);
		fileInfos = gcnew List<FileInfo^>();
		for (int i = 0; i < formats->Length; i++)
			fileInfos->AddRange(dirInfo->GetFiles(formats[i]));
		if (fileInfos->Count > 0) {
			this->pictureBox->Image = Image::FromFile(fileInfos[0]->FullName);
			counter = 0;
		}
		else {
			MessageBox::Show("There are no images in selected folder", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			counter = -1;
		}

		this->pathToolStripStatusLabel->Text = this->folderBrowserDialog->SelectedPath;
		this->countToolStripStatusLabel->Text = String::Format("{0}/{1}", counter + 1, fileInfos->Count);
	}

	void RemoveContent() {
		UpdateContentVisibility();
		this->pathToolStripStatusLabel->Text = L"";
		this->countToolStripStatusLabel->Text = L"";
	}
	
	void UpdateMenu() {
		this->closeToolStripMenuItem->Enabled = this->folderChosen;
		this->orientationSortingToolStripMenuItem->Enabled = this->folderChosen;
		this->sizeFiltrationToolStripMenuItem->Enabled = this->folderChosen;
	}
	
	System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		folderChosen = false;
		counter = -1;
		fileInfos->Clear();
		this->folderBrowserDialog->Reset();
		UpdateMenu();
		RemoveContent();
	}

	System::Void writeToFile(String^ path, Bitmap^ image) {
		FileStream^ fstream = gcnew FileStream(path, FileMode::Create, FileAccess::Write);
		try {
			image->Save(fstream, System::Drawing::Imaging::ImageFormat::Jpeg);
		}
		catch (Exception^ e) {
			Console::WriteLine("Failed to create file with the following error: " + e->Message);
		}
		finally {
			fstream->Close();
		}
	}
	
	System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		formats->Clear;
		delete dirInfo;
		delete fileInfos;
	}
	
	System::Void buttonPrev_Click(System::Object^  sender, System::EventArgs^  e) {
		counter--;
		if (counter < 0)
			counter = fileInfos->Count - 1;
		this->pictureBox->Image = Image::FromFile(fileInfos[counter]->FullName);
		this->countToolStripStatusLabel->Text = String::Format("{0}/{1}", counter + 1, fileInfos->Count);
	}

	System::Void buttonNext_Click(System::Object^  sender, System::EventArgs^  e) {
		counter++;
		if (counter >= fileInfos->Count)
			counter = 0;
		this->pictureBox->Image = Image::FromFile(fileInfos[counter]->FullName);
		this->countToolStripStatusLabel->Text = String::Format("{0}/{1}", counter + 1, fileInfos->Count);
	}
};
}
