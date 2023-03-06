#pragma once


namespace FinalLogin {

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
	/// Summary for ClientPage
	/// </summary>
	public ref class ClientPage : public System::Windows::Forms::Form
	{
	private: 
		String^ ArgClientName;
		Form^ homePage;
		Timer^ timer;
	public:
		ClientPage(Form^ frm, String^ arg)
		{
			homePage = frm;
			ArgClientName = arg;
			InitializeComponent();
			this->StopButton->Hide();
			this->hide->Hide();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ClientPage()
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

	private: System::Windows::Forms::Button^ hide;
	private: System::Windows::Forms::DataGridView^ SystemInformationGrid;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ parameters;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ systemInformation;


















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClientPage::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->hide = (gcnew System::Windows::Forms::Button());
			this->SystemInformationGrid = (gcnew System::Windows::Forms::DataGridView());
			this->parameters = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->systemInformation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientDataTable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SystemInformationGrid))->BeginInit();
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
			this->pictureBox1->Click += gcnew System::EventHandler(this, &ClientPage::pictureBox1_Click);
			// 
			// ClientName
			// 
			this->ClientName->AutoSize = true;
			this->ClientName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClientName->Location = System::Drawing::Point(64, 19);
			this->ClientName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ClientName->Name = L"ClientName";
			this->ClientName->Text = ArgClientName;
			this->ClientName->Size = System::Drawing::Size(0, 21);
			this->ClientName->TabIndex = 1;
			this->ClientName->Click += gcnew System::EventHandler(this, &ClientPage::ClientName_Click);
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
			this->label1->Click += gcnew System::EventHandler(this, &ClientPage::label1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->ErrorImage = nullptr;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1422, 19);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(32, 32);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &ClientPage::pictureBox2_Click);
			// 
			// StartText
			// 
			this->StartText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartText->Location = System::Drawing::Point(12, 95);
			this->StartText->Name = L"StartText";
			this->StartText->Size = System::Drawing::Size(361, 114);
			this->StartText->TabIndex = 5;
			this->StartText->Text = L"You are currently not sending your system information to the server.\n\nClick START"
				L" button to start sending your system information periodically.";
			this->StartText->Click += gcnew System::EventHandler(this, &ClientPage::StartText_Click);
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
			this->StartButton->Location = System::Drawing::Point(12, 212);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			this->StartButton->Size = System::Drawing::Size(87, 41);
			this->StartButton->TabIndex = 6;
			this->StartButton->Text = L"START";
			this->StartButton->UseVisualStyleBackColor = false;
			this->StartButton->Click += gcnew System::EventHandler(this, &ClientPage::StartButton_Click);
			this->StartButton->MouseHover += gcnew System::EventHandler(this, &ClientPage::StartButton_MouseHover);
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
			this->LogoutButton->Location = System::Drawing::Point(1454, 16);
			this->LogoutButton->Name = L"LogoutButton";
			this->LogoutButton->Size = System::Drawing::Size(75, 36);
			this->LogoutButton->TabIndex = 7;
			this->LogoutButton->Text = L"Logout";
			this->LogoutButton->UseVisualStyleBackColor = false;
			this->LogoutButton->Click += gcnew System::EventHandler(this, &ClientPage::LogoutButton_Click);
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
			this->StopButton->Location = System::Drawing::Point(12, 212);
			this->StopButton->Name = L"StopButton";
			this->StopButton->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			this->StopButton->Size = System::Drawing::Size(79, 41);
			this->StopButton->TabIndex = 8;
			this->StopButton->Text = L"STOP";
			this->StopButton->UseVisualStyleBackColor = false;
			this->StopButton->Click += gcnew System::EventHandler(this, &ClientPage::StopButton_Click);
			// 
			// DisplayText
			// 
			this->DisplayText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DisplayText->Location = System::Drawing::Point(413, 95);
			this->DisplayText->Name = L"DisplayText";
			this->DisplayText->Size = System::Drawing::Size(666, 27);
			this->DisplayText->TabIndex = 9;
			this->DisplayText->Text = L"Click the DISPLAY button to display all the information sent to the server by you"
				L".";
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
			this->DIsplayButton->Click += gcnew System::EventHandler(this, &ClientPage::DIsplayButton_Click);
			// 
			// ClientDataTable
			// 
			this->ClientDataTable->AllowUserToDeleteRows = false;
			this->ClientDataTable->AllowUserToOrderColumns = true;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->NullValue = L"-";
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::White;
			this->ClientDataTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->ClientDataTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->ClientDataTable->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->ClientDataTable->BackgroundColor = System::Drawing::SystemColors::Control;
			this->ClientDataTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClientDataTable->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->ClientDataTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->NullValue = L"-";
			dataGridViewCellStyle2->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ClientDataTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->ClientDataTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle3->NullValue = L"-";
			dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->ClientDataTable->DefaultCellStyle = dataGridViewCellStyle3;
			this->ClientDataTable->EnableHeadersVisualStyles = false;
			this->ClientDataTable->GridColor = System::Drawing::Color::White;
			this->ClientDataTable->Location = System::Drawing::Point(417, 209);
			this->ClientDataTable->Name = L"ClientDataTable";
			this->ClientDataTable->ReadOnly = true;
			this->ClientDataTable->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->NullValue = L"-";
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ClientDataTable->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->ClientDataTable->RowHeadersVisible = false;
			this->ClientDataTable->RowHeadersWidth = 51;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->NullValue = L"-";
			dataGridViewCellStyle5->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ClientDataTable->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->ClientDataTable->ShowEditingIcon = false;
			this->ClientDataTable->Size = System::Drawing::Size(1073, 586);
			this->ClientDataTable->TabIndex = 11;
			this->ClientDataTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ClientPage::ClientDataTable_CellClick);
			this->ClientDataTable->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &ClientPage::ClientDataTable_CellFormatting);
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
			this->hide->Click += gcnew System::EventHandler(this, &ClientPage::hide_Click);
			// 
			// SystemInformationGrid
			// 
			this->SystemInformationGrid->AllowUserToDeleteRows = false;
			this->SystemInformationGrid->AllowUserToOrderColumns = true;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->NullValue = L"-";
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::White;
			this->SystemInformationGrid->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle6;
			this->SystemInformationGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SystemInformationGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->SystemInformationGrid->BackgroundColor = System::Drawing::SystemColors::Control;
			this->SystemInformationGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SystemInformationGrid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->SystemInformationGrid->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->NullValue = L"-";
			dataGridViewCellStyle7->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SystemInformationGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->SystemInformationGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SystemInformationGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->parameters,
					this->systemInformation
			});
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle8->NullValue = L"-";
			dataGridViewCellStyle8->Padding = System::Windows::Forms::Padding(10, 5, 10, 5);
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SystemInformationGrid->DefaultCellStyle = dataGridViewCellStyle8;
			this->SystemInformationGrid->EnableHeadersVisualStyles = false;
			this->SystemInformationGrid->GridColor = System::Drawing::Color::White;
			this->SystemInformationGrid->Location = System::Drawing::Point(12, 280);
			this->SystemInformationGrid->Name = L"SystemInformationGrid";
			this->SystemInformationGrid->ReadOnly = true;
			this->SystemInformationGrid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle9->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle9->NullValue = L"-";
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SystemInformationGrid->RowHeadersDefaultCellStyle = dataGridViewCellStyle9;
			this->SystemInformationGrid->RowHeadersVisible = false;
			this->SystemInformationGrid->RowHeadersWidth = 51;
			dataGridViewCellStyle10->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle10->NullValue = L"-";
			dataGridViewCellStyle10->Padding = System::Windows::Forms::Padding(15);
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SystemInformationGrid->RowsDefaultCellStyle = dataGridViewCellStyle10;
			this->SystemInformationGrid->ShowEditingIcon = false;
			this->SystemInformationGrid->Size = System::Drawing::Size(361, 515);
			this->SystemInformationGrid->TabIndex = 15;
			this->SystemInformationGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ClientPage::dataGridView1_CellContentClick);
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
			// ClientPage
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1536, 845);
			this->Controls->Add(this->SystemInformationGrid);
			this->Controls->Add(this->hide);
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
			this->Name = L"ClientPage";
			this->Text = L"Client Page";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientPage::ClientPage_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ClientPage::ClientPage_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClientDataTable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SystemInformationGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   static String^ clientId;
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
	private: System::Void ClientPage_Load(System::Object^ sender, System::EventArgs^ e) {
		empty_table();
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Are you sure you want to logout ?", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->Close();
			homePage->Show();
			try {
				if (myProcess->HasExited)
				{
					// Process has exited normally
				}
				else
				{
					myProcess->Kill();
				}
			}
			catch (Exception^ ex) {
				//MessageBox::Show(ex->Message);
			}
		}
	}
	private: System::Void Logout_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void StartText_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void CheckProcessStatus(Object^ sender, EventArgs^ e) {
		try {
			if (myProcess->HasExited)
			{
				timer->Stop();
				MessageBox::Show("Process was closed unexpectly");
				this->StartText->Text = L"You are currently not sending your system information to the server.\n\nClick START"
					L" button to start sending your system information periodically.";
				this->StopButton->Hide();
				this->StartButton->Show();
			}
		}
		catch (Exception^ ex) {
			//MessageBox::Show(ex->Message);
		}
	}
	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->StartButton->Hide();
		this->StopButton->Show();
		this->StartText->Text = L"You are now sending your system information to the server.\n\nClick STOP"
			L" button to stop sending your system information.";
		try {
			String^ hostname = "P1-3TS2MQ3-L";
			myProcess = Process::Start("C:\\Users\\anirudh.kaushal\\Downloads\\FinalClient (3)\\FinalClient (3)\\FinalClient\\x64\\Debug\\FinalClient.exe", 
				String::Format("{0} {1}", hostname, ArgClientName));
			timer = gcnew Timer();
			timer->Interval = 1000; // checks process status every second
			timer->Tick += gcnew EventHandler(this, &ClientPage::CheckProcessStatus);
			timer->Start();
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
		this->StartText->Text = L"You are currently not sending your system information to the server.\n\nClick START"
			L" button to start sending your system information periodically.";

		try {
			if (myProcess->HasExited)
			{
				// Process has exited normally
			}
			else
			{
				myProcess->Kill();
			}
		}
		catch (Exception^ ex) {
			//MessageBox::Show(ex->Message);
		}
	}
	private: System::Void DIsplayButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DIsplayButton->Hide();
		this->hide->Show();
		String^ constring = L"datasource=localhost;port=3306;username=root;password=123123";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDatabase1 = gcnew MySqlCommand("USE sysmon; "+
			"SELECT clientName AS \"CLIENT NAME\", " +
			" hddUtilization AS \"FREE SPACE (GB)\", " +
			 " availableRam AS \"FREE RAM (GB)\", " +
			 " cpuUtilization AS \"CPU UTILIZATION (%)\", " +
			 "currentTime AS \"DATE\", " +
			 " \"All Information >>\" AS \"-\" " +
			 " FROM sysinfo WHERE clientName = '" + ArgClientName + "';", conDataBase);
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
	private: System::Void LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Are you sure you want to logout ?", "Message", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->Hide();
			homePage->Show();
		}
	}
	private: System::Void ClientDataTable_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
	private: System::Void SystemInformationGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
	private: System::Void hide_Click(System::Object^ sender, System::EventArgs^ e) {
		this->hide->Hide();
		this->DIsplayButton->Show();
		empty_table();
	}
	private: System::Void ClientDataTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		try {
			if (ClientDataTable->Columns[e->ColumnIndex]->Name == "-") {
				clientId = Convert::ToString(ClientDataTable->Rows[e->RowIndex]->Cells["CLIENT NAME"]->Value);
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
				cmdDatabase1->Parameters->Add("@clientName", MySqlDbType::VarChar)->Value = clientId;
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
				//MessageBox::Show("Success!!! " + clientId);
			}
		}
		catch (Exception^ ex) {
			// There is an error
		}
	}
	private: System::Void ClientDataTable_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e) {
		if (e->ColumnIndex == 5) {
			e->CellStyle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void ClientPage_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
		try {
			if (myProcess->HasExited)
			{
				// Process has exited normally
			}
			else
			{
				myProcess->Kill();
			}
		}
		catch (Exception^ ex) {
			//MessageBox::Show(ex->Message);
		}
	}
};
}
