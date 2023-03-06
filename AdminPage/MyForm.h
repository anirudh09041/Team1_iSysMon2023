#include<Windows.h>
#include<winuser.h>
#pragma once 
#using <System.dll>

#pragma comment(lib, "user32.lib")


namespace AdminPage {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Timer^ ProcessTimer;
	private: System::Windows::Forms::PictureBox^ RefreshStopClient;

		   Timer^ StopClientTimer;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->StopButton->Hide();
			this->hide->Hide();
			this->OrderByCombo->Hide();
			this->ClientComboBox->Hide();
			this->SearchClientText->Hide();
			this->OrderByText->Hide();
			this->RefreshStopClient->Hide();
			this->StopClientComboBox->Hide();
			this->StopClient->Hide();
			ActiveClient->Hide();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ ClientName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	private: System::Windows::Forms::Label^ StartText;
	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::Button^ LogoutButton;
	private: System::Windows::Forms::Button^ StopButton;
	private: System::Windows::Forms::Label^ DisplayText;
	private: System::Windows::Forms::Button^ DIsplayButton;
	private: System::Windows::Forms::DataGridView^ ClientDataTable;
	private: System::Windows::Forms::DataGridView^ SystemInformationGrid;
	private: System::Windows::Forms::Button^ hide;
	private: System::Windows::Forms::ComboBox^ ClientComboBox;
	private: System::Windows::Forms::Label^ SearchClientText;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ parameters;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ systemInformation;
	private: System::Windows::Forms::Label^ activeConnectionLabel;
	private: System::Windows::Forms::Label^ ActiveClient;
	private: System::Windows::Forms::Label^ OrderByText;
	private: System::Windows::Forms::ComboBox^ OrderByCombo;
	private: System::Windows::Forms::Button^ StopClient;
	private: System::Windows::Forms::ComboBox^ StopClientComboBox;

















	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->ClientName = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->StartText = (gcnew System::Windows::Forms::Label());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->LogoutButton = (gcnew System::Windows::Forms::Button());
			this->StopButton = (gcnew System::Windows::Forms::Button());
			this->DisplayText = (gcnew System::Windows::Forms::Label());
			this->DIsplayButton = (gcnew System::Windows::Forms::Button());
			this->ClientDataTable = (gcnew System::Windows::Forms::DataGridView());
			this->SystemInformationGrid = (gcnew System::Windows::Forms::DataGridView());
			this->parameters = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->systemInformation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->hide = (gcnew System::Windows::Forms::Button());
			this->ClientComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SearchClientText = (gcnew System::Windows::Forms::Label());
			this->activeConnectionLabel = (gcnew System::Windows::Forms::Label());
			this->ActiveClient = (gcnew System::Windows::Forms::Label());
			this->OrderByText = (gcnew System::Windows::Forms::Label());
			this->OrderByCombo = (gcnew System::Windows::Forms::ComboBox());
			this->StopClient = (gcnew System::Windows::Forms::Button());
			this->StopClientComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->RefreshStopClient = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientDataTable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SystemInformationGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RefreshStopClient))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->ErrorImage = nullptr;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(15, 16);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(48, 48);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// ClientName
			// 
			this->ClientName->AutoSize = true;
			this->ClientName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClientName->Location = System::Drawing::Point(64, 19);
			this->ClientName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ClientName->Name = L"ClientName";
			this->ClientName->Size = System::Drawing::Size(116, 21);
			this->ClientName->TabIndex = 1;
			this->ClientName->Text = L"Lovekesh Jain";
			this->ClientName->Click += gcnew System::EventHandler(this, &MyForm::ClientName_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(67, 44);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"5678910";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->ErrorImage = nullptr;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1403, 19);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(32, 32);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// StartText
			// 
			this->StartText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartText->Location = System::Drawing::Point(12, 95);
			this->StartText->Name = L"StartText";
			this->StartText->Size = System::Drawing::Size(361, 96);
			this->StartText->TabIndex = 5;
			this->StartText->Text = L"The server is currently not running and clients will not be able to connect to th"
				L"e server.\n\nClick START button to start the server.";
			// 
			// StartButton
			// 
			this->StartButton->AutoSize = true;
			this->StartButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->StartButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->StartButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StartButton->FlatAppearance->BorderSize = 0;
			this->StartButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StartButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartButton->ForeColor = System::Drawing::Color::White;
			this->StartButton->Location = System::Drawing::Point(12, 194);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			this->StartButton->Size = System::Drawing::Size(87, 41);
			this->StartButton->TabIndex = 6;
			this->StartButton->Text = L"START";
			this->StartButton->UseVisualStyleBackColor = false;
			this->StartButton->Click += gcnew System::EventHandler(this, &MyForm::StartButton_Click);
			this->StartButton->MouseHover += gcnew System::EventHandler(this, &MyForm::StartButton_MouseHover);
			// 
			// LogoutButton
			// 
			this->LogoutButton->BackColor = System::Drawing::SystemColors::Control;
			this->LogoutButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LogoutButton->FlatAppearance->BorderSize = 0;
			this->LogoutButton->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->LogoutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LogoutButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogoutButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->LogoutButton->Location = System::Drawing::Point(1435, 16);
			this->LogoutButton->Name = L"LogoutButton";
			this->LogoutButton->Size = System::Drawing::Size(75, 36);
			this->LogoutButton->TabIndex = 7;
			this->LogoutButton->Text = L"Logout";
			this->LogoutButton->UseVisualStyleBackColor = false;
			this->LogoutButton->Click += gcnew System::EventHandler(this, &MyForm::LogoutButton_Click);
			// 
			// StopButton
			// 
			this->StopButton->AutoSize = true;
			this->StopButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->StopButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->StopButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StopButton->FlatAppearance->BorderSize = 0;
			this->StopButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StopButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StopButton->ForeColor = System::Drawing::Color::White;
			this->StopButton->Location = System::Drawing::Point(12, 194);
			this->StopButton->Name = L"StopButton";
			this->StopButton->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			this->StopButton->Size = System::Drawing::Size(79, 41);
			this->StopButton->TabIndex = 8;
			this->StopButton->Text = L"STOP";
			this->StopButton->UseVisualStyleBackColor = false;
			this->StopButton->Click += gcnew System::EventHandler(this, &MyForm::StopButton_Click);
			// 
			// DisplayText
			// 
			this->DisplayText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DisplayText->Location = System::Drawing::Point(413, 95);
			this->DisplayText->Name = L"DisplayText";
			this->DisplayText->Size = System::Drawing::Size(666, 27);
			this->DisplayText->TabIndex = 9;
			this->DisplayText->Text = L"Click the DISPLAY button to display all the information sent by multiple clients "
				L"accross the globe.";
			// 
			// DIsplayButton
			// 
			this->DIsplayButton->AutoSize = true;
			this->DIsplayButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->DIsplayButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->DIsplayButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DIsplayButton->FlatAppearance->BorderSize = 0;
			this->DIsplayButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DIsplayButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DIsplayButton->ForeColor = System::Drawing::Color::White;
			this->DIsplayButton->Location = System::Drawing::Point(417, 136);
			this->DIsplayButton->Name = L"DIsplayButton";
			this->DIsplayButton->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			this->DIsplayButton->Size = System::Drawing::Size(104, 41);
			this->DIsplayButton->TabIndex = 10;
			this->DIsplayButton->Text = L"DISPLAY";
			this->DIsplayButton->UseVisualStyleBackColor = false;
			this->DIsplayButton->Click += gcnew System::EventHandler(this, &MyForm::DIsplayButton_Click);
			// 
			// ClientDataTable
			// 
			this->ClientDataTable->AllowUserToDeleteRows = false;
			this->ClientDataTable->AllowUserToOrderColumns = true;
			dataGridViewCellStyle11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle11->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle11->NullValue = L"-";
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::Color::White;
			this->ClientDataTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle11;
			this->ClientDataTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->ClientDataTable->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->ClientDataTable->BackgroundColor = System::Drawing::SystemColors::Control;
			this->ClientDataTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClientDataTable->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->ClientDataTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle12->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle12->NullValue = L"-";
			dataGridViewCellStyle12->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle12->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ClientDataTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle12;
			this->ClientDataTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle13->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle13->NullValue = L"-";
			dataGridViewCellStyle13->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			dataGridViewCellStyle13->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle13->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle13->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ClientDataTable->DefaultCellStyle = dataGridViewCellStyle13;
			this->ClientDataTable->EnableHeadersVisualStyles = false;
			this->ClientDataTable->GridColor = System::Drawing::Color::White;
			this->ClientDataTable->Location = System::Drawing::Point(402, 212);
			this->ClientDataTable->Name = L"ClientDataTable";
			this->ClientDataTable->ReadOnly = true;
			this->ClientDataTable->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle14->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle14->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle14->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle14->NullValue = L"-";
			dataGridViewCellStyle14->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle14->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle14->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ClientDataTable->RowHeadersDefaultCellStyle = dataGridViewCellStyle14;
			this->ClientDataTable->RowHeadersVisible = false;
			this->ClientDataTable->RowHeadersWidth = 51;
			dataGridViewCellStyle15->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle15->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle15->NullValue = L"-";
			dataGridViewCellStyle15->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle15->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle15->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle15->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ClientDataTable->RowsDefaultCellStyle = dataGridViewCellStyle15;
			this->ClientDataTable->ShowEditingIcon = false;
			this->ClientDataTable->Size = System::Drawing::Size(1069, 586);
			this->ClientDataTable->TabIndex = 11;
			this->ClientDataTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::ClientDataTable_CellClick);
			this->ClientDataTable->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &MyForm::ClientDataTable_CellFormatting);
			// 
			// SystemInformationGrid
			// 
			this->SystemInformationGrid->AllowUserToDeleteRows = false;
			this->SystemInformationGrid->AllowUserToOrderColumns = true;
			dataGridViewCellStyle16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle16->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle16->NullValue = L"-";
			dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle16->SelectionForeColor = System::Drawing::Color::White;
			this->SystemInformationGrid->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle16;
			this->SystemInformationGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SystemInformationGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->SystemInformationGrid->BackgroundColor = System::Drawing::SystemColors::Control;
			this->SystemInformationGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SystemInformationGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->SystemInformationGrid->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle17->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle17->NullValue = L"-";
			dataGridViewCellStyle17->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle17->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SystemInformationGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle17;
			this->SystemInformationGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SystemInformationGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->parameters,
					this->systemInformation
			});
			dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle18->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle18->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle18->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle18->NullValue = L"-";
			dataGridViewCellStyle18->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle18->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SystemInformationGrid->DefaultCellStyle = dataGridViewCellStyle18;
			this->SystemInformationGrid->EnableHeadersVisualStyles = false;
			this->SystemInformationGrid->GridColor = System::Drawing::Color::White;
			this->SystemInformationGrid->Location = System::Drawing::Point(12, 261);
			this->SystemInformationGrid->Name = L"SystemInformationGrid";
			this->SystemInformationGrid->ReadOnly = true;
			this->SystemInformationGrid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle19->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle19->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle19->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle19->NullValue = L"-";
			dataGridViewCellStyle19->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle19->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle19->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SystemInformationGrid->RowHeadersDefaultCellStyle = dataGridViewCellStyle19;
			this->SystemInformationGrid->RowHeadersVisible = false;
			this->SystemInformationGrid->RowHeadersWidth = 51;
			dataGridViewCellStyle20->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle20->NullValue = L"-";
			dataGridViewCellStyle20->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SystemInformationGrid->RowsDefaultCellStyle = dataGridViewCellStyle20;
			this->SystemInformationGrid->ShowEditingIcon = false;
			this->SystemInformationGrid->Size = System::Drawing::Size(361, 534);
			this->SystemInformationGrid->TabIndex = 13;
			// 
			// parameters
			// 
			this->parameters->HeaderText = L"SYSTEM PARAMETERS";
			this->parameters->MinimumWidth = 6;
			this->parameters->Name = L"parameters";
			this->parameters->ReadOnly = true;
			// 
			// systemInformation
			// 
			this->systemInformation->HeaderText = L"SYSTEM INFORMATION";
			this->systemInformation->MinimumWidth = 6;
			this->systemInformation->Name = L"systemInformation";
			this->systemInformation->ReadOnly = true;
			// 
			// hide
			// 
			this->hide->AutoSize = true;
			this->hide->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->hide->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->hide->Cursor = System::Windows::Forms::Cursors::Hand;
			this->hide->FlatAppearance->BorderSize = 0;
			this->hide->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->hide->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hide->ForeColor = System::Drawing::Color::White;
			this->hide->Location = System::Drawing::Point(417, 136);
			this->hide->Name = L"hide";
			this->hide->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			this->hide->Size = System::Drawing::Size(78, 41);
			this->hide->TabIndex = 14;
			this->hide->Text = L"HIDE";
			this->hide->UseVisualStyleBackColor = false;
			this->hide->Click += gcnew System::EventHandler(this, &MyForm::hide_Click);
			// 
			// ClientComboBox
			// 
			this->ClientComboBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ClientComboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->ClientComboBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->ClientComboBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawVariable;
			this->ClientComboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ClientComboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->ClientComboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ClientComboBox->FormattingEnabled = true;
			this->ClientComboBox->IntegralHeight = false;
			this->ClientComboBox->ItemHeight = 24;
			this->ClientComboBox->Location = System::Drawing::Point(1256, 139);
			this->ClientComboBox->Name = L"ClientComboBox";
			this->ClientComboBox->Size = System::Drawing::Size(230, 30);
			this->ClientComboBox->Sorted = true;
			this->ClientComboBox->TabIndex = 16;
			this->ClientComboBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MyForm::ClientComboBox_DrawItem);
			this->ClientComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ClientComboBox_SelectedIndexChanged);
			this->ClientComboBox->TextUpdate += gcnew System::EventHandler(this, &MyForm::ClientComboBox_TextUpdate);
			// 
			// SearchClientText
			// 
			this->SearchClientText->AutoSize = true;
			this->SearchClientText->Location = System::Drawing::Point(1133, 142);
			this->SearchClientText->Name = L"SearchClientText";
			this->SearchClientText->Size = System::Drawing::Size(117, 21);
			this->SearchClientText->TabIndex = 17;
			this->SearchClientText->Text = L"Search Client : ";
			// 
			// activeConnectionLabel
			// 
			this->activeConnectionLabel->AutoSize = true;
			this->activeConnectionLabel->Location = System::Drawing::Point(199, 204);
			this->activeConnectionLabel->Name = L"activeConnectionLabel";
			this->activeConnectionLabel->Size = System::Drawing::Size(0, 21);
			this->activeConnectionLabel->TabIndex = 18;
			// 
			// ActiveClient
			// 
			this->ActiveClient->AutoSize = true;
			this->ActiveClient->Location = System::Drawing::Point(118, 204);
			this->ActiveClient->Name = L"ActiveClient";
			this->ActiveClient->Size = System::Drawing::Size(109, 21);
			this->ActiveClient->TabIndex = 19;
			this->ActiveClient->Text = L"Active Clients";
			this->ActiveClient->Visible = false;
			// 
			// OrderByText
			// 
			this->OrderByText->AutoSize = true;
			this->OrderByText->Location = System::Drawing::Point(1167, 95);
			this->OrderByText->Name = L"OrderByText";
			this->OrderByText->Size = System::Drawing::Size(83, 21);
			this->OrderByText->TabIndex = 21;
			this->OrderByText->Text = L"Order By :";
			// 
			// OrderByCombo
			// 
			this->OrderByCombo->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->OrderByCombo->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->OrderByCombo->Cursor = System::Windows::Forms::Cursors::Default;
			this->OrderByCombo->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawVariable;
			this->OrderByCombo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->OrderByCombo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->OrderByCombo->ForeColor = System::Drawing::SystemColors::ControlText;
			this->OrderByCombo->FormattingEnabled = true;
			this->OrderByCombo->IntegralHeight = false;
			this->OrderByCombo->ItemHeight = 24;
			this->OrderByCombo->Items->AddRange(gcnew cli::array< System::Object^  >(19) {
				L"availableRam", L"clientName", L"cpuUtilization",
					L"currentTime", L"dSpeeed", L"hddUtilization", L"IP", L"osName", L"osVersion", L"productID", L"systemBootTime", L"systemIdleWindow",
					L"systemName", L"systemType", L"systemType", L"systemUpTime", L"totalRam", L"userName", L"uSpeed"
			});
			this->OrderByCombo->Location = System::Drawing::Point(1256, 92);
			this->OrderByCombo->Name = L"OrderByCombo";
			this->OrderByCombo->Size = System::Drawing::Size(230, 30);
			this->OrderByCombo->Sorted = true;
			this->OrderByCombo->TabIndex = 20;
			this->OrderByCombo->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MyForm::OrderByCombo_DrawItem);
			this->OrderByCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::OrderByCombo_SelectedIndexChanged);
			// 
			// StopClient
			// 
			this->StopClient->AutoSize = true;
			this->StopClient->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->StopClient->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->StopClient->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StopClient->FlatAppearance->BorderSize = 0;
			this->StopClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StopClient->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StopClient->ForeColor = System::Drawing::Color::White;
			this->StopClient->Location = System::Drawing::Point(879, 138);
			this->StopClient->Name = L"StopClient";
			this->StopClient->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			this->StopClient->Size = System::Drawing::Size(104, 33);
			this->StopClient->TabIndex = 22;
			this->StopClient->Text = L"STOP CLIENT";
			this->StopClient->UseVisualStyleBackColor = false;
			this->StopClient->Click += gcnew System::EventHandler(this, &MyForm::StopClient_Click);
			// 
			// StopClientComboBox
			// 
			this->StopClientComboBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->StopClientComboBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->StopClientComboBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->StopClientComboBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawVariable;
			this->StopClientComboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StopClientComboBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->StopClientComboBox->ForeColor = System::Drawing::SystemColors::ControlText;
			this->StopClientComboBox->FormattingEnabled = true;
			this->StopClientComboBox->IntegralHeight = false;
			this->StopClientComboBox->ItemHeight = 24;
			this->StopClientComboBox->Location = System::Drawing::Point(627, 139);
			this->StopClientComboBox->Name = L"StopClientComboBox";
			this->StopClientComboBox->Size = System::Drawing::Size(230, 30);
			this->StopClientComboBox->Sorted = true;
			this->StopClientComboBox->TabIndex = 23;
			this->StopClientComboBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MyForm::StopClientComboBox_DrawItem);
			this->StopClientComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::OrderByCombo_SelectedIndexChanged);
			// 
			// RefreshStopClient
			// 
			this->RefreshStopClient->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshStopClient.Image")));
			this->RefreshStopClient->Location = System::Drawing::Point(600, 144);
			this->RefreshStopClient->Name = L"RefreshStopClient";
			this->RefreshStopClient->Size = System::Drawing::Size(20, 20);
			this->RefreshStopClient->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->RefreshStopClient->TabIndex = 24;
			this->RefreshStopClient->TabStop = false;
			this->RefreshStopClient->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1536, 864);
			this->Controls->Add(this->RefreshStopClient);
			this->Controls->Add(this->StopClientComboBox);
			this->Controls->Add(this->StopClient);
			this->Controls->Add(this->OrderByText);
			this->Controls->Add(this->OrderByCombo);
			this->Controls->Add(this->ActiveClient);
			this->Controls->Add(this->activeConnectionLabel);
			this->Controls->Add(this->SearchClientText);
			this->Controls->Add(this->ClientComboBox);
			this->Controls->Add(this->hide);
			this->Controls->Add(this->SystemInformationGrid);
			this->Controls->Add(this->ClientDataTable);
			this->Controls->Add(this->DIsplayButton);
			this->Controls->Add(this->DisplayText);
			this->Controls->Add(this->StopButton);
			this->Controls->Add(this->LogoutButton);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->StartText);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ClientName);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Admin Page";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientDataTable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SystemInformationGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RefreshStopClient))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}




		   static String^ clientName;
		   static String^ date;
		   static Process^ myProcess;



	public: System::Void empty_table() {
		String^ constring = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDatabase1 = gcnew MySqlCommand("use sysmon; select clientName AS \"CLIENT NAME\", hddUtilization AS \"FREE SPACE (GB)\", availableRam AS \"FREE RAM (GB)\", cpuUtilization AS \"CPU UTILIZATION (%)\",currentTime AS \"DATE\", \"All Information >>\" AS \"-\" FROM sysinfo LIMIT 0;", conDataBase);
		MySqlDataReader^ myReader;
		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDatabase1;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();

			bSource->DataSource = dbdataset;
			this->ClientDataTable->DataSource = bSource;
			sda->Update(dbdataset);

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}


		  // fills the search box
	private: void FillCombo(void) {

		// Connect to database
		String^ connectionString = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		connection->Open();

		// Prepare SQL query
		String^ sqlQuery = "USE sysmon ; SELECT distinct clientName FROM sysinfo";
		MySqlCommand^ command = gcnew MySqlCommand(sqlQuery, connection);

		// Load data into DataTable
		DataTable^ dataTable = gcnew DataTable();
		MySqlDataAdapter^ dataAdapter = gcnew MySqlDataAdapter(command);
		dataAdapter->Fill(dataTable);

		// Bind data to ComboBox
		ClientComboBox->DataSource = dataTable;
		ClientComboBox->DisplayMember = "clientName";
		ClientComboBox->ValueMember = "clientName";

		// Close connection
		connection->Close();

	}

		   //fills the search box for Stop Client          
	private:void fillComboStop() {

		// Connect to database               
		String^ connectionString = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		connection->Open();

		// Prepare SQL query               
		String^ sqlQuery = "USE sysmon ; SELECT distinct clientName FROM threadinfo";
		MySqlCommand^ command = gcnew MySqlCommand(sqlQuery, connection);

		// Load data into DataTable               
		DataTable^ dataTable = gcnew DataTable();
		MySqlDataAdapter^ dataAdapter = gcnew MySqlDataAdapter(command);
		dataAdapter->Fill(dataTable);

		// Bind data to ComboBox               
		StopClientComboBox->DataSource = dataTable;
		StopClientComboBox->DisplayMember = "clientName";
		StopClientComboBox->ValueMember = "clientName";

		// Close connection               
		connection->Close();
	}

	private: void EmptyThreadTable() {
		// Connect to database
		String^ connectionString = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		connection->Open();

		// Prepare SQL query
		String^ sql = "USE sysmon;" +
			"TRUNCATE TABLE threadinfo;";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, connection);

		// Execute the query
		cmd->ExecuteNonQuery();

		// Close connection
		connection->Close();
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		empty_table();
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Are you sure you want to logout ?", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			// kill the server
			try {
				if (myProcess->HasExited)
				{
					// Process has exited normally
				}
				else
				{
					myProcess->Kill();
					EmptyThreadTable();
				}
			}
			catch (Exception^ ex) {
				//MessageBox::Show(ex->Message);
			}
			this->Close();
		}
	}

	private: void CheckProcessStatus(Object^ sender, EventArgs^ e) {
		try {
			if (myProcess->HasExited)
			{
				ProcessTimer->Stop();
				MessageBox::Show("Server Shutdown!!!");
				this->StartText->Text = L"The server is not running and clients will not be able to connect to the server.\n\nClick START"
					L" button to start the server.";
				this->StopButton->Hide();
				this->StartButton->Show();
				this->RefreshStopClient->Hide();
				this->StopClientComboBox->Hide();
				this->StopClient->Hide();
			}
		}
		catch (Exception^ ex) {
			//MessageBox::Show(ex->Message);
		}
	}
	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->StartButton->Hide();
		this->StopButton->Show();
		this->StartText->Text = L"The Server is running, waiting for clients to connect\n\nClick STOP"
			L" button to terminate the server.";
		this->RefreshStopClient->Show();
		this->StopClientComboBox->Show();
		this->StopClient->Show();
		try {
			myProcess = Process::Start("C:\\Users\\anirudh.kaushal\\Downloads\\SocketConnect Latest (1)\\SocketConnect Latest (1)\\SocketConnect Latest\\SocketConnect\\x64\\Debug\\SocketConnect.exe");
			ProcessTimer = gcnew Timer();
			ProcessTimer->Interval = 1000; // checks process status every second
			ProcessTimer->Tick += gcnew EventHandler(this, &MyForm::CheckProcessStatus);
			ProcessTimer->Start();
			fillComboStop();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ClientName_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void StartButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void StopButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->StopButton->Hide();
		this->StartButton->Show();
		this->RefreshStopClient->Hide();
		this->StopClientComboBox->Hide();
		this->StopClient->Hide();
		this->StartText->Text = L"The server is not running and clients will not be able to connect to the server.\n\nClick START"
			L" button to start the server.";


		// kill the server
		try {
			if (myProcess->HasExited)
			{
				// Process has exited normally
			}
			else
			{
				myProcess->Kill();
				EmptyThreadTable();
			}
		}
		catch (Exception^ ex) {
			//MessageBox::Show(ex->Message);
		}
	}
	private: System::Void DIsplayButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DIsplayButton->Hide();
		this->hide->Show();

		this->OrderByCombo->Show();
		this->ClientComboBox->Show();
		this->SearchClientText->Show();
		this->OrderByText->Show();

		FillCombo();
		String^ constring = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDatabase1 = gcnew MySqlCommand("use sysmon; select clientName AS \"CLIENT NAME\", hddUtilization AS \"FREE SPACE (GB)\", availableRam AS \"FREE RAM (GB)\", cpuUtilization AS \"CPU UTILIZATION (%)\",currentTime AS \"DATE\", \"All Information >>\" AS \"-\" FROM sysinfo;", conDataBase);
		MySqlCommand^ cmdDatabase2 = gcnew MySqlCommand("use sysmon; select * from threadinfo", conDataBase);

		//int numberOfClients = mysql_num_rows(mysql_store_result(conn));
		MySqlDataReader^ myReader;
		MySqlDataReader^ myReader1;
		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDatabase1;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();

			bSource->DataSource = dbdataset;
			this->ClientDataTable->DataSource = bSource;
			sda->Update(dbdataset);

			//Check no of active connections
			conDataBase->Open();
			myReader1 = cmdDatabase2->ExecuteReader();
			int count = 0;
			while (myReader1->Read()) {
				count = count + 1;
			}
			ActiveClient->Show();
			ActiveClient->Text = "No. of Active connections: " + count;

		}
		catch (Exception^ ex) {
			//MessageBox::Show(ex->Message);
		}
	}
	private: System::Void LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Are you sure you want to logout ?", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			// kill the server
			try {
				if (myProcess->HasExited)
				{
					// Process has exited normally
				}
				else
				{
					myProcess->Kill();
					EmptyThreadTable();
				}
			}
			catch (Exception^ ex) {
				//MessageBox::Show(ex->Message);
			}
			this->Close();
		}
	}
	private: System::Void hide_Click(System::Object^ sender, System::EventArgs^ e) {
		this->hide->Hide();
		this->DIsplayButton->Show();

		this->OrderByCombo->Hide();
		this->ClientComboBox->Hide();
		this->SearchClientText->Hide();
		this->OrderByText->Hide();


		ActiveClient->Hide();
		empty_table();
		DataTable^ dataTable = gcnew DataTable();
		this->ClientComboBox->DataSource = dataTable;
	}
	private: System::Void ClientDataTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		try {
			if (ClientDataTable->Columns[e->ColumnIndex]->Name == "-") {
				clientName = Convert::ToString(ClientDataTable->Rows[e->RowIndex]->Cells["CLIENT NAME"]->Value);

				date = Convert::ToString(ClientDataTable->Rows[e->RowIndex]->Cells["DATE"]->Value);
				/*DateTime^ cdate = DateTime::ParseExact(date, "dd-MM-yyyy HH:mm:ss", System::Globalization::CultureInfo::InvariantCulture);
				date = cdate->ToString("yyyy-MM-dd HH:mm:ss");*/
				String^ constring = L"datasource=localhost;port=3306;username=root;password=123123";
				MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

				MySqlCommand^ cmdDatabase1 = gcnew MySqlCommand("USE sysmon;" +
					"select clientName AS \"Client Name\", " +
					"systemName AS \"System Name\", " +
					"userName AS \"User Name\"," +
					"cpuUtilization AS \"CPU Utilization (%)\", " +
					"availableRam AS \"Free RAM (GB)\", " +
					"totalRam AS \"Total RAM (GB)\", " +
					"IP AS \"IP Address\", " +
					"dSpeeed AS \"Download Speed (Mbps)\", " +
					"uSpeed AS \"Upload Speed (Mbps)\"," +
					"systemIdleWindow AS \"System Idle Window (sec)\", " +
					"currentTime AS \"Current Time (sec)\", " +
					"osName AS \"OS Name \", " +
					"osVersion AS \"OS Version\", " +
					"productID AS\"Product ID\", " +
					"systemType AS\"System Type\", " +
					"systemBootTime AS\"Boot Time\", " +
					"systemUpTime AS\"System Up Time \", " +
					"systemType AS\"System Type\", " +
					"hddUtilization AS\"HDD Utilization\" " +
					"FROM sysinfo WHERE clientName = @clientName and currentTime = @date; ", conDataBase);
				cmdDatabase1->Parameters->Add("@clientName", MySqlDbType::VarChar)->Value = clientName;
				cmdDatabase1->Parameters->Add("@date", MySqlDbType::VarChar)->Value = date;

				MySqlDataReader^ myReader;
				try {
					MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
					sda->SelectCommand = cmdDatabase1;
					DataTable^ oldTable = gcnew DataTable();
					sda->Fill(oldTable);

					DataTable^ newTable = gcnew System::Data::DataTable();
					newTable->Columns->Add("SYSTEM PARAMETERS");
					newTable->Columns->Add("SYSTEM INFORMATION");

					for (int i = 0; i < oldTable->Columns->Count; i++)
					{
						DataRow^ newRow = newTable->NewRow();

						newRow[0] = oldTable->Columns[i]->Caption;
						newRow[1] = oldTable->Rows[0]->ItemArray[i];
						newTable->Rows->Add(newRow);
					}

					BindingSource^ bSource = gcnew BindingSource();
					bSource->DataSource = newTable;
					try {

						SystemInformationGrid->Columns->Remove("parameters");
						SystemInformationGrid->Columns->Remove("systemInformation");
					}
					catch (Exception^ ex) {
						// There is an error
					}
					SystemInformationGrid->DataSource = bSource;
				}
				catch (Exception^ ex) {
					MessageBox::Show(ex->Message);
				}
				//MessageBox::Show("Success!!! " + clientName);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}

	private: System::Void ClientDataTable_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e) {
		if (e->ColumnIndex == 5) {
			e->CellStyle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
		}
	}

	private: System::Void ClientComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Connect to database
		String^ connectionString = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		connection->Open();

		// Prepare SQL query
		String^ selectedValue = this->ClientComboBox->Text;

		String^ sql = "use sysmon; select clientName AS \"CLIENT NAME\", hddUtilization AS \"FREE SPACE (GB)\", availableRam AS \"FREE RAM (GB)\", cpuUtilization AS \"CPU UTILIZATION (%)\",currentTime AS \"DATE\", \"All Information >>\" AS \"-\" FROM sysinfo WHERE clientName LIKE @username;";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, connection);
		cmd->Parameters->AddWithValue("@username", "%" + selectedValue + "%");


		// Load data into DataTable
		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmd;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();

			bSource->DataSource = dbdataset;
			this->ClientDataTable->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}

		// Close connection
		connection->Close();
	}

	private: System::Void ClientComboBox_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
		// Determine the background color based on the item index
		Color bgColor = (e->Index % 2 == 0) ? Color::White : System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));;

		// Set the background color of the item
		e->DrawBackground();

		if ((e->State & DrawItemState::Focus) == DrawItemState::Focus)
		{
			e->DrawFocusRectangle();
		}

		DataRowView^ selectedRow = dynamic_cast<DataRowView^>(ClientComboBox->Items[e->Index]);
		String^ text = Convert::ToString(selectedRow[0]);


		// Set the padding and alignment
		int padding = 10;
		StringFormat^ format = gcnew StringFormat();
		format->LineAlignment = StringAlignment::Center;

		// Draw the item text with padding and alignment
		e->Graphics->FillRectangle(gcnew SolidBrush(bgColor), e->Bounds);
		e->Graphics->DrawString(text, ClientComboBox->Font, Brushes::Black, RectangleF(e->Bounds.X + padding, e->Bounds.Y, e->Bounds.Width - 2 * padding, e->Bounds.Height), format);

		// Draw the focus rectangle
		e->DrawFocusRectangle();
	}
	private: System::Void ClientComboBox_TextUpdate(System::Object^ sender, System::EventArgs^ e) {
		// Connect to database
		if (ClientComboBox->Items->Count > 0) {
			String^ connectionString = L"datasource=localhost;port=3306;username=root;password=123123";
			MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
			connection->Open();

			// Prepare SQL query
			String^ selectedValue = this->ClientComboBox->Text;

			String^ sql = "use sysmon; select clientName AS \"CLIENT NAME\", hddUtilization AS \"FREE SPACE (GB)\", availableRam AS \"FREE RAM (GB)\", cpuUtilization AS \"CPU UTILIZATION (%)\",currentTime AS \"DATE\", \"All Information >>\" AS \"-\" FROM sysinfo WHERE clientName LIKE @username;";

			MySqlCommand^ cmd = gcnew MySqlCommand(sql, connection);
			cmd->Parameters->AddWithValue("@username", "%" + selectedValue + "%");


			// Load data into DataTable
			try {
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmd;
				DataTable^ dbdataset = gcnew DataTable();
				sda->Fill(dbdataset);
				BindingSource^ bSource = gcnew BindingSource();

				bSource->DataSource = dbdataset;
				this->ClientDataTable->DataSource = bSource;
				sda->Update(dbdataset);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

			// Close connection
			connection->Close();
		}
	}
	private: System::Void OrderByCombo_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {

		Color bgColor = (e->Index % 2 == 0) ? Color::White : System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));;
		/*DataRowView^ selectedRow = dynamic_cast<DataRowView^>(ClientComboBox->Items[e->Index]);
		String^ text = Convert::ToString(selectedRow[0]);*/


		// Set the padding and alignment
		int padding = 10;
		StringFormat^ format = gcnew StringFormat();
		format->LineAlignment = StringAlignment::Center;

		// Draw the item text with padding and alignment
		e->Graphics->FillRectangle(gcnew SolidBrush(bgColor), e->Bounds);
		e->Graphics->DrawString(OrderByCombo->Items[e->Index]->ToString(),
			OrderByCombo->Font, Brushes::Black, RectangleF(e->Bounds.X + padding, e->Bounds.Y, e->Bounds.Width - 2 * padding, e->Bounds.Height), format);


		// Draw the focus rectangle
		e->DrawFocusRectangle();
	}
	private: System::Void OrderByCombo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Connect to database
		String^ connectionString = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		connection->Open();

		// Prepare SQL query
		String^ selectedValue = this->OrderByCombo->Text;

		String^ sql = "use sysmon; " +
			" select clientName AS \"CLIENT NAME\", " +
			" hddUtilization AS \"FREE SPACE (GB)\", " +
			" availableRam AS \"FREE RAM (GB)\", " +
			" cpuUtilization AS \"CPU UTILIZATION (%)\", " +
			"currentTime AS \"DATE\", " +
			" \"All Information >>\" AS \"-\" " +
			" FROM (SELECT * FROM sysinfo WHERE clientName LIKE @username ORDER BY " + selectedValue + ") AS sysc;";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, connection);
		cmd->Parameters->AddWithValue("@username", "%" + this->ClientComboBox->Text + "%");


		// Load data into DataTable
		if (selectedValue != "") {
			try {
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmd;
				DataTable^ dbdataset = gcnew DataTable();
				sda->Fill(dbdataset);
				BindingSource^ bSource = gcnew BindingSource();

				bSource->DataSource = dbdataset;
				this->ClientDataTable->DataSource = bSource;
				sda->Update(dbdataset);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

		// Close connection
		connection->Close();
	}
	private: System::Void StopClient_Click(System::Object^ sender, System::EventArgs^ e) {
#define WM_MY_STRING_MESSAGE (WM_APP + 1)
#define msgID 7
		String^ client = StopClientComboBox->Text;
		// Connect to database    
		String^ constring = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDatabase1 = gcnew MySqlCommand("use sysmon; select * FROM threadinfo where clientName = '" + client + "';", conDataBase);
		MySqlDataReader^ myReader;
		try {
			//Get ID of active thread and stop that thread        
			conDataBase->Open();
			myReader = cmdDatabase1->ExecuteReader();
			int pId;
			while (myReader->Read()) {
				pId = myReader->GetInt32("threadID");
			}
			DWORD threadId = pId;
			HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, threadId);
			if (hThread == NULL) {
				MessageBox::Show("Thread Handle is empty");
			}

			// it sends message and forgets about it. ie returns        
			BOOL P = PostThreadMessageA(threadId, msgID, NULL, NULL);
			CloseHandle(hThread);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void StopClientComboBox_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
		Color bgColor = (e->Index % 2 == 0) ? Color::White : System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
			static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));;

		// Set the background color of the item
		e->DrawBackground();

		if ((e->State & DrawItemState::Focus) == DrawItemState::Focus)
		{
			e->DrawFocusRectangle();
		}

		DataRowView^ selectedRow = dynamic_cast<DataRowView^>(StopClientComboBox->Items[e->Index]);
		String^ text = Convert::ToString(selectedRow[0]);


		// Set the padding and alignment
		int padding = 10;
		StringFormat^ format = gcnew StringFormat();
		format->LineAlignment = StringAlignment::Center;

		// Draw the item text with padding and alignment
		e->Graphics->FillRectangle(gcnew SolidBrush(bgColor), e->Bounds);
		e->Graphics->DrawString(text, StopClientComboBox->Font, Brushes::Black, RectangleF(e->Bounds.X + padding, e->Bounds.Y, e->Bounds.Width - 2 * padding, e->Bounds.Height), format);

		// Draw the focus rectangle
		e->DrawFocusRectangle();
	}
	private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		// Close the server
		try {
			if (myProcess->HasExited)
			{
				// Process has exited normally
			}
			else
			{
				myProcess->Kill();
				EmptyThreadTable();
			}
		}
		catch (Exception^ ex) {
			//MessageBox::Show(ex->Message);
		}
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// Connect to database
		String^ connectionString = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		connection->Open();

		// Prepare SQL query
		String^ sql = "USE sysmon;" +
			"SET SQL_SAFE_UPDATES = 0;" +
			"update credentials set connStat = 'False' where connStat = 'True'; ";

		MySqlCommand^ cmd = gcnew MySqlCommand(sql, connection);

		// Execute the query
		cmd->ExecuteNonQuery();

		// Close connection
		connection->Close();
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		fillComboStop();
	}
	};
}
