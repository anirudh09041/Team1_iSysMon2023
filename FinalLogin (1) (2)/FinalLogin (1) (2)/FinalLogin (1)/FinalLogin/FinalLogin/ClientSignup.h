
#include <iostream>
#include "socket.h"
#include "ClientPage.h"
//#include "ClientLogin.h"
 
//#include <winsock2.h>
//#include <Windows.h>
//#include <msclr\marshal_cppstd.h>
//#pragma comment(lib, "ws2_32.lib")
#pragma once

namespace FinalLogin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for ClientSignup
	/// </summary>
	public ref class ClientSignup : public System::Windows::Forms::Form
	{
	private: 
		ClientSocket^ clientSocket;
		Form^ clientPage;
		Form^ loginPage;
		Form^ clientLogin;
		String^ loginVerified;
	private: System::Windows::Forms::Label^ Home;

	private: System::Windows::Forms::PictureBox^ BackButton;
	private: System::Windows::Forms::Label^ UsernameCheckText;
	private: System::Windows::Forms::Label^ PasswordCheckText;
	public:
		Form^ homePageForm;
		ClientSignup(void)
		{
			InitializeComponent();
			clientSocket = gcnew ClientSocket();

			/*clientPasswordConfirmationText->PasswordChar = '*';
			clientPasswordText->PasswordChar = '*';*/
			//
			//TODO: Add the constructor code here
			//
		}
		ClientSignup(Form^ obj1) {
			homePageForm = obj1;
			InitializeComponent();
			clientSocket = gcnew ClientSocket();
			this->BackButton->Click += gcnew System::EventHandler(this, &ClientSignup::BackButton_Click);

			//
			//TODO: Add the constructor code here
			//
		}
		ClientSignup(Form^ obj1, Form^ obj2) {
			homePageForm = obj1;
			loginPage = obj2;
			InitializeComponent();
			clientSocket = gcnew ClientSocket();
			this->BackButton->Click += gcnew System::EventHandler(this, &ClientSignup::BackButton_Click);
			this->LoginLink->Click += gcnew System::EventHandler(this, &ClientSignup::LoginLink_Click);

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ClientSignup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ SignUpButton;
	protected:

	private: System::Windows::Forms::TextBox^ ClientNameText;

	protected:


	private: System::Windows::Forms::Label^ PasswordText;

	private: System::Windows::Forms::Label^ ClientText;

	private: System::Windows::Forms::Label^ SignUpText;
	private: System::Windows::Forms::Label^ Or;




	private: System::Windows::Forms::Label^ AlreadyAUserText;



	private: System::Windows::Forms::Label^ LoginLink;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::PictureBox^ pictureBox1;




	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ ClientPasswordText;



	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ ClientPasswordConfirmationText;

	private: System::Windows::Forms::Label^ ConfirmPasswordText;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ WelcomeText;
	private: System::Windows::Forms::PictureBox^ WelcomeImage;

	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ Logo;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClientSignup::typeid));
			this->SignUpButton = (gcnew System::Windows::Forms::Button());
			this->ClientNameText = (gcnew System::Windows::Forms::TextBox());
			this->PasswordText = (gcnew System::Windows::Forms::Label());
			this->ClientText = (gcnew System::Windows::Forms::Label());
			this->SignUpText = (gcnew System::Windows::Forms::Label());
			this->Or = (gcnew System::Windows::Forms::Label());
			this->AlreadyAUserText = (gcnew System::Windows::Forms::Label());
			this->LoginLink = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->ClientPasswordText = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->ClientPasswordConfirmationText = (gcnew System::Windows::Forms::TextBox());
			this->ConfirmPasswordText = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->WelcomeText = (gcnew System::Windows::Forms::Label());
			this->WelcomeImage = (gcnew System::Windows::Forms::PictureBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Logo = (gcnew System::Windows::Forms::Label());
			this->Home = (gcnew System::Windows::Forms::Label());
			this->BackButton = (gcnew System::Windows::Forms::PictureBox());
			this->UsernameCheckText = (gcnew System::Windows::Forms::Label());
			this->PasswordCheckText = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WelcomeImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackButton))->BeginInit();
			this->SuspendLayout();
			// 
			// SignUpButton
			// 
			this->SignUpButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->SignUpButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SignUpButton->FlatAppearance->BorderSize = 0;
			this->SignUpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SignUpButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SignUpButton->ForeColor = System::Drawing::Color::White;
			this->SignUpButton->Location = System::Drawing::Point(1085, 614);
			this->SignUpButton->Margin = System::Windows::Forms::Padding(2);
			this->SignUpButton->Name = L"SignUpButton";
			this->SignUpButton->Size = System::Drawing::Size(350, 34);
			this->SignUpButton->TabIndex = 9;
			this->SignUpButton->Text = L"SIGN UP";
			this->SignUpButton->UseVisualStyleBackColor = false;
			this->SignUpButton->Click += gcnew System::EventHandler(this, &ClientSignup::SignUpButton_Click);
			// 
			// ClientNameText
			// 
			this->ClientNameText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientNameText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClientNameText->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 14));
			this->ClientNameText->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->ClientNameText->Location = System::Drawing::Point(1115, 332);
			this->ClientNameText->Margin = System::Windows::Forms::Padding(4);
			this->ClientNameText->Name = L"ClientNameText";
			this->ClientNameText->Size = System::Drawing::Size(320, 25);
			this->ClientNameText->TabIndex = 7;
			this->ClientNameText->Text = L"Type Client Name";
			// 
			// PasswordText
			// 
			this->PasswordText->AutoSize = true;
			this->PasswordText->BackColor = System::Drawing::Color::Transparent;
			this->PasswordText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 12));
			this->PasswordText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->PasswordText->Location = System::Drawing::Point(1082, 393);
			this->PasswordText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->PasswordText->Name = L"PasswordText";
			this->PasswordText->Size = System::Drawing::Size(74, 21);
			this->PasswordText->TabIndex = 6;
			this->PasswordText->Text = L"Password";
			this->PasswordText->Click += gcnew System::EventHandler(this, &ClientSignup::label2_Click);
			// 
			// ClientText
			// 
			this->ClientText->AutoSize = true;
			this->ClientText->BackColor = System::Drawing::Color::Transparent;
			this->ClientText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ClientText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 12));
			this->ClientText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ClientText->Location = System::Drawing::Point(1082, 304);
			this->ClientText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ClientText->Name = L"ClientText";
			this->ClientText->Size = System::Drawing::Size(95, 21);
			this->ClientText->TabIndex = 5;
			this->ClientText->Text = L"Client Name";
			// 
			// SignUpText
			// 
			this->SignUpText->AutoSize = true;
			this->SignUpText->BackColor = System::Drawing::Color::Transparent;
			this->SignUpText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SignUpText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold));
			this->SignUpText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->SignUpText->Location = System::Drawing::Point(1080, 230);
			this->SignUpText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SignUpText->Name = L"SignUpText";
			this->SignUpText->Size = System::Drawing::Size(107, 32);
			this->SignUpText->TabIndex = 10;
			this->SignUpText->Text = L"SIGN UP";
			this->SignUpText->Click += gcnew System::EventHandler(this, &ClientSignup::label3_Click);
			// 
			// Or
			// 
			this->Or->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->Or->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Or->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Or->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Or->Location = System::Drawing::Point(1241, 686);
			this->Or->Margin = System::Windows::Forms::Padding(0);
			this->Or->Name = L"Or";
			this->Or->Size = System::Drawing::Size(30, 30);
			this->Or->TabIndex = 0;
			this->Or->Text = L"OR";
			this->Or->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AlreadyAUserText
			// 
			this->AlreadyAUserText->BackColor = System::Drawing::Color::Transparent;
			this->AlreadyAUserText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->AlreadyAUserText->Location = System::Drawing::Point(1169, 740);
			this->AlreadyAUserText->Name = L"AlreadyAUserText";
			this->AlreadyAUserText->Size = System::Drawing::Size(130, 23);
			this->AlreadyAUserText->TabIndex = 0;
			this->AlreadyAUserText->Text = L"Already a user\?";
			// 
			// LoginLink
			// 
			this->LoginLink->BackColor = System::Drawing::Color::Transparent;
			this->LoginLink->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LoginLink->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Underline));
			this->LoginLink->Location = System::Drawing::Point(1286, 740);
			this->LoginLink->Name = L"LoginLink";
			this->LoginLink->Size = System::Drawing::Size(69, 23);
			this->LoginLink->TabIndex = 15;
			this->LoginLink->Text = L"LOGIN";
			this->LoginLink->Click += gcnew System::EventHandler(this, &ClientSignup::LoginLink_Click);
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(1085, 367);
			this->label9->Margin = System::Windows::Forms::Padding(0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(350, 1);
			this->label9->TabIndex = 16;
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1085, 331);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 25);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(1085, 421);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(25, 25);
			this->pictureBox3->TabIndex = 24;
			this->pictureBox3->TabStop = false;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::White;
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(1085, 457);
			this->label13->Margin = System::Windows::Forms::Padding(0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(350, 1);
			this->label13->TabIndex = 23;
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ClientPasswordText
			// 
			this->ClientPasswordText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientPasswordText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClientPasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 14));
			this->ClientPasswordText->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->ClientPasswordText->Location = System::Drawing::Point(1115, 422);
			this->ClientPasswordText->Margin = System::Windows::Forms::Padding(4);
			this->ClientPasswordText->Name = L"ClientPasswordText";
			this->ClientPasswordText->Size = System::Drawing::Size(320, 25);
			this->ClientPasswordText->TabIndex = 22;
			this->ClientPasswordText->Text = L"Enter Password";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1085, 518);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(25, 25);
			this->pictureBox2->TabIndex = 29;
			this->pictureBox2->TabStop = false;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::Color::White;
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(1085, 554);
			this->label14->Margin = System::Windows::Forms::Padding(0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(350, 1);
			this->label14->TabIndex = 28;
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ClientPasswordConfirmationText
			// 
			this->ClientPasswordConfirmationText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientPasswordConfirmationText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClientPasswordConfirmationText->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 14));
			this->ClientPasswordConfirmationText->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->ClientPasswordConfirmationText->Location = System::Drawing::Point(1115, 519);
			this->ClientPasswordConfirmationText->Margin = System::Windows::Forms::Padding(4);
			this->ClientPasswordConfirmationText->Name = L"ClientPasswordConfirmationText";
			this->ClientPasswordConfirmationText->Size = System::Drawing::Size(320, 25);
			this->ClientPasswordConfirmationText->TabIndex = 27;
			this->ClientPasswordConfirmationText->Text = L"Enter Password Again";
			// 
			// ConfirmPasswordText
			// 
			this->ConfirmPasswordText->AutoSize = true;
			this->ConfirmPasswordText->BackColor = System::Drawing::Color::Transparent;
			this->ConfirmPasswordText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ConfirmPasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 12));
			this->ConfirmPasswordText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ConfirmPasswordText->Location = System::Drawing::Point(1082, 490);
			this->ConfirmPasswordText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ConfirmPasswordText->Name = L"ConfirmPasswordText";
			this->ConfirmPasswordText->Size = System::Drawing::Size(133, 21);
			this->ConfirmPasswordText->TabIndex = 26;
			this->ConfirmPasswordText->Text = L"Confirm Password";
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(1085, 701);
			this->label5->Margin = System::Windows::Forms::Padding(0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(350, 1);
			this->label5->TabIndex = 30;
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// WelcomeText
			// 
			this->WelcomeText->AutoSize = true;
			this->WelcomeText->BackColor = System::Drawing::Color::White;
			this->WelcomeText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold));
			this->WelcomeText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->WelcomeText->Location = System::Drawing::Point(126, 686);
			this->WelcomeText->Name = L"WelcomeText";
			this->WelcomeText->Size = System::Drawing::Size(653, 65);
			this->WelcomeText->TabIndex = 31;
			this->WelcomeText->Text = L"Create a new account today";
			this->WelcomeText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->WelcomeText->Click += gcnew System::EventHandler(this, &ClientSignup::WelcomeText_Click);
			// 
			// WelcomeImage
			// 
			this->WelcomeImage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->WelcomeImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"WelcomeImage.Image")));
			this->WelcomeImage->Location = System::Drawing::Point(24, 52);
			this->WelcomeImage->Name = L"WelcomeImage";
			this->WelcomeImage->Size = System::Drawing::Size(900, 633);
			this->WelcomeImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->WelcomeImage->TabIndex = 32;
			this->WelcomeImage->TabStop = false;
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::Color::White;
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(-1, -1);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(950, 865);
			this->listView1->TabIndex = 33;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 16));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(253, 770);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(386, 30);
			this->label1->TabIndex = 34;
			this->label1->Text = L"And let us steal your system information";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &ClientSignup::label1_Click);
			// 
			// Logo
			// 
			this->Logo->AutoSize = true;
			this->Logo->BackColor = System::Drawing::Color::Transparent;
			this->Logo->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Logo->Location = System::Drawing::Point(1075, 101);
			this->Logo->Name = L"Logo";
			this->Logo->Size = System::Drawing::Size(301, 65);
			this->Logo->TabIndex = 35;
			this->Logo->Text = L"S Y S M O N";
			this->Logo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Home
			// 
			this->Home->AutoSize = true;
			this->Home->BackColor = System::Drawing::Color::White;
			this->Home->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Home->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Home->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Home->Location = System::Drawing::Point(59, 25);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(71, 30);
			this->Home->TabIndex = 64;
			this->Home->Text = L"Home";
			this->Home->Click += gcnew System::EventHandler(this, &ClientSignup::BackButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->BackColor = System::Drawing::Color::White;
			this->BackButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BackButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton.Image")));
			this->BackButton->Location = System::Drawing::Point(25, 25);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(30, 30);
			this->BackButton->TabIndex = 63;
			this->BackButton->TabStop = false;
			this->BackButton->Click += gcnew System::EventHandler(this, &ClientSignup::BackButton_Click);
			// 
			// UsernameCheckText
			// 
			this->UsernameCheckText->AutoSize = true;
			this->UsernameCheckText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UsernameCheckText->ForeColor = System::Drawing::Color::Red;
			this->UsernameCheckText->Location = System::Drawing::Point(1085, 370);
			this->UsernameCheckText->Name = L"UsernameCheckText";
			this->UsernameCheckText->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->UsernameCheckText->Size = System::Drawing::Size(0, 13);
			this->UsernameCheckText->TabIndex = 68;
			this->UsernameCheckText->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// PasswordCheckText
			// 
			this->PasswordCheckText->AutoSize = true;
			this->PasswordCheckText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordCheckText->ForeColor = System::Drawing::Color::Red;
			this->PasswordCheckText->Location = System::Drawing::Point(1086, 460);
			this->PasswordCheckText->Name = L"PasswordCheckText";
			this->PasswordCheckText->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PasswordCheckText->Size = System::Drawing::Size(0, 13);
			this->PasswordCheckText->TabIndex = 69;
			this->PasswordCheckText->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// ClientSignup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientSize = System::Drawing::Size(1536, 864);
			this->Controls->Add(this->PasswordCheckText);
			this->Controls->Add(this->UsernameCheckText);
			this->Controls->Add(this->Home);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->Logo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->WelcomeText);
			this->Controls->Add(this->WelcomeImage);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->Or);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->ClientPasswordConfirmationText);
			this->Controls->Add(this->ConfirmPasswordText);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->ClientPasswordText);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->PasswordText);
			this->Controls->Add(this->LoginLink);
			this->Controls->Add(this->AlreadyAUserText);
			this->Controls->Add(this->SignUpText);
			this->Controls->Add(this->SignUpButton);
			this->Controls->Add(this->ClientNameText);
			this->Controls->Add(this->ClientText);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ClientSignup";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientSignup::ClientSignup_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ClientSignup::ClientSignup_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WelcomeImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackButton))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ClientSignup_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
	private: System::Void SignUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ inputString = this->ClientNameText->Text;
		bool isLetterOrDigitOnly = true;
		for (int i = 0; i < inputString->Length; i++) {
			if (!Char::IsLetterOrDigit(inputString[i])) {
				isLetterOrDigitOnly = false;
				break;
			}
		}
		if (!isLetterOrDigitOnly) {
			this->UsernameCheckText->Text = "You can only use Letters and Numbers as your Client Name!";
			this->ClientNameText->Text = "";
			this->ClientPasswordText->Text = "";
			this->ClientPasswordConfirmationText->Text = "";
		}
		else if (this->ClientPasswordText->TextLength < 8) {
			this->PasswordCheckText->Text = "Please Enter A Password With Atleast 8 Character";
			this->UsernameCheckText->Text = "";
			this->ClientPasswordText->Text = "";
			this->ClientPasswordConfirmationText->Text = "";
		}
		else if (this->ClientPasswordText->Text == this->ClientPasswordConfirmationText->Text) {
			try {
				loginVerified = clientSocket->SocketConnection(this->ClientNameText->Text, this->ClientPasswordText->Text, false);
				MessageBox::Show(loginVerified);
				String^ check = "Signed Up Successfully";
				if (String::Equals(loginVerified->Substring(0, 22), check->Substring(0, 22))) {
					clientPage = gcnew ClientPage(homePageForm, this->ClientNameText->Text);
					this->UsernameCheckText->Text = "";
					this->PasswordCheckText->Text = "";
					this->ClientNameText->Text = "Enter Client Name";
					this->ClientPasswordText->Text = "Enter Password";
					this->ClientPasswordConfirmationText->Text = "Enter Password Again";
					this->Hide();
					clientPage->Show();
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(loginVerified);
				MessageBox::Show(ex->Message);
			}
		}
		else{
			MessageBox::Show("Your passwords doesn't match");
			this->ClientPasswordText->Text = "";
			this->ClientPasswordConfirmationText->Text = "";
		}
	}
private: System::Void WelcomeText_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide(); // Close the "clientLogin" form
	homePageForm->Show(); // Show the "HomePage" form
}
private: System::Void LoginLink_Click(System::Object^ sender, System::EventArgs^ e) {
	//clientLogin = gcnew ClientLogin(homePageForm);
	//(homePageForm)->clientLoginPage->Show();
	this->Hide();
	loginPage->Show();
}
private: System::Void ClientSignup_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	Application::Exit();
}
};
}
