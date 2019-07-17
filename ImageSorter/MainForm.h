#pragma once
#include <boost/log/trivial.hpp>

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
	private: System::Windows::Forms::FolderBrowserDialog^  imageFolderBrowserDialog;
	private: System::Windows::Forms::Button^  browseButton;
	private: System::Windows::Forms::ProgressBar^  progressBar;
	private: System::Windows::Forms::TextBox^  textBox;
	private: System::Windows::Forms::Button^  buttonSort;
	protected:

	protected:

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
			this->imageFolderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->browseButton = (gcnew System::Windows::Forms::Button());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->buttonSort = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// browseButton
			// 
			this->browseButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->browseButton->Location = System::Drawing::Point(106, 39);
			this->browseButton->Name = L"browseButton";
			this->browseButton->Size = System::Drawing::Size(75, 23);
			this->browseButton->TabIndex = 0;
			this->browseButton->Text = L"Browse";
			this->browseButton->UseVisualStyleBackColor = true;
			this->browseButton->Click += gcnew System::EventHandler(this, &MainForm::browseButton_Click);
			// 
			// progressBar
			// 
			this->progressBar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->progressBar->Location = System::Drawing::Point(0, 238);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(284, 23);
			this->progressBar->Step = 1;
			this->progressBar->TabIndex = 1;
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(12, 13);
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->Size = System::Drawing::Size(260, 20);
			this->textBox->TabIndex = 2;
			// 
			// buttonSort
			// 
			this->buttonSort->Location = System::Drawing::Point(106, 209);
			this->buttonSort->Name = L"buttonSort";
			this->buttonSort->Size = System::Drawing::Size(75, 23);
			this->buttonSort->TabIndex = 3;
			this->buttonSort->Text = L"Sort";
			this->buttonSort->UseVisualStyleBackColor = true;
			this->buttonSort->Click += gcnew System::EventHandler(this, &MainForm::buttonSort_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->buttonSort);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->browseButton);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void browseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = imageFolderBrowserDialog->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
			textBox->Text = imageFolderBrowserDialog->SelectedPath;
	}

	private: System::Void buttonSort_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ SUFFIX_PORTRAIT = "_portrait";
		String^ SUFFIX_LANDSCAPE = "_landscape";
		String^ path = textBox->Text;
		try {
			DirectoryInfo^ dirInfo = gcnew DirectoryInfo(path);
			String^ currDirName = dirInfo->Name;
			array<FileInfo^>^ fileInfos = dirInfo->GetFiles("*.jpg");
			if (fileInfos->Length > 0) {
				progressBar->Maximum = fileInfos->Length;
				progressBar->Value = 0;
				dirInfo->CreateSubdirectory(currDirName + SUFFIX_PORTRAIT);
				dirInfo->CreateSubdirectory(currDirName + SUFFIX_LANDSCAPE);
				for (int i = 0; i < fileInfos->Length; i++) {
					FileInfo^ info = fileInfos[i];
					Bitmap^ image = gcnew Bitmap(path + "\\" + info->Name);
					if (image->Width > image->Height)
						writeToFile(path + "\\" + currDirName + SUFFIX_LANDSCAPE + "\\" + info->Name, image);
					if (image->Height > image->Width)
						writeToFile(path + "\\" + currDirName + SUFFIX_PORTRAIT + "\\" + info->Name, image);
					progressBar->Increment(1);
				}
				MessageBox::Show("Sorting complete", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				BOOST_LOG_TRIVIAL(info) << "Sorting complete. Sorted " << fileInfos->Length << " files";
			}
			else {
				MessageBox::Show("There are no files in current directory", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
		}
		catch (ArgumentException^ e) {
			MessageBox::Show("Error: Wrong path", "ImageSorter", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			BOOST_LOG_TRIVIAL(error) << "Error while sorting";
		}
	}

	private: System::Void writeToFile(String^ path, Bitmap^ image) {
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
};
}
