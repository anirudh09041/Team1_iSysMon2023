#pragma once
#include"windows.h"
#include "ClientPage.h"
#include "ClientSignup.h"
#include "socket.h"

namespace FinalLogin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data; 
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Diagnostics;



	/// <summary>
	/// Summary for ClientLogin
	/// </summary>
	public ref class ClientLogin : public System::Windows::Forms::Form
	{
	private:
		ClientSocket^ clientSocket;
		String^ loginVerified;
		Process^ process = gcnew Process();
		Form^ clientPage;
		Form^ clientSignup;
	public:
		Form^ homePageForm;
	private: System::Windows::Forms::Label^ PasswordCheckText;
	public:
	public: System::Windows::Forms::Label^ UsernameCheckText;
		   Form^ signupPage;
		ClientLogin(void)
		{
			InitializeComponent();
			//homePageForm = gcnew HomePage();
			ClientPasswordText->PasswordChar = '*';
			//added for back button functionality
			this->BackButton->Click += gcnew System::EventHandler(this, &ClientLogin::BackButton_Click);
			this->LoginLink->Click += gcnew System::EventHandler(this, &ClientLogin::SignupLink_Click);

		}
		ClientLogin(Form^ obj1) {
			homePageForm = obj1;
			InitializeComponent();
			ClientPasswordText->PasswordChar = '*';

			//added for back button functionality
			this->BackButton->Click += gcnew System::EventHandler(this, &ClientLogin::BackButton_Click);
			this->LoginLink->Click += gcnew System::EventHandler(this, &ClientLogin::SignupLink_Click);

		}
		ClientLogin(Form^ obj1, Form^ obj2) {
			homePageForm = obj1;
			signupPage = obj2;
			InitializeComponent();
			ClientPasswordText->PasswordChar = '*';

			//added for back button functionality
			this->BackButton->Click += gcnew System::EventHandler(this, &ClientLogin::BackButton_Click);
			this->LoginLink->Click += gcnew System::EventHandler(this, &ClientLogin::SignupLink_Click);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ClientLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Logo;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ WelcomeText;
	private: System::Windows::Forms::PictureBox^ WelcomeImage;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Label^ Or;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ ClientPasswordText;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ PasswordText;
	private: System::Windows::Forms::Label^ LoginLink;
	private: System::Windows::Forms::Label^ AlreadyAUserText;
	private: System::Windows::Forms::Label^ LoginText;
	private: System::Windows::Forms::Button^ LoginButton;
	private: System::Windows::Forms::TextBox^ ClientNameText;
	private: System::Windows::Forms::Label^ ClientText;
	private: System::Windows::Forms::Label^ Home;

	private: System::Windows::Forms::PictureBox^ BackButton;







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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ClientLogin::typeid));
			this->Logo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->WelcomeText = (gcnew System::Windows::Forms::Label());
			this->WelcomeImage = (gcnew System::Windows::Forms::PictureBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Or = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->ClientPasswordText = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->PasswordText = (gcnew System::Windows::Forms::Label());
			this->LoginLink = (gcnew System::Windows::Forms::Label());
			this->AlreadyAUserText = (gcnew System::Windows::Forms::Label());
			this->LoginText = (gcnew System::Windows::Forms::Label());
			this->LoginButton = (gcnew System::Windows::Forms::Button());
			this->ClientNameText = (gcnew System::Windows::Forms::TextBox());
			this->ClientText = (gcnew System::Windows::Forms::Label());
			this->Home = (gcnew System::Windows::Forms::Label());
			this->BackButton = (gcnew System::Windows::Forms::PictureBox());
			this->PasswordCheckText = (gcnew System::Windows::Forms::Label());
			this->UsernameCheckText = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WelcomeImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackButton))->BeginInit();
			this->SuspendLayout();
			// 
			// Logo
			// 
			this->Logo->AutoSize = true;
			this->Logo->BackColor = System::Drawing::Color::Transparent;
			this->Logo->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Logo->Location = System::Drawing::Point(1077, 149);
			this->Logo->Name = L"Logo";
			this->Logo->Size = System::Drawing::Size(301, 65);
			this->Logo->TabIndex = 58;
			this->Logo->Text = L"S Y S M O N";
			this->Logo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 16));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(241, 730);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(431, 30);
			this->label1->TabIndex = 57;
			this->label1->Text = L"Time to steal your system information...Again";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// WelcomeText
			// 
			this->WelcomeText->AutoSize = true;
			this->WelcomeText->BackColor = System::Drawing::Color::White;
			this->WelcomeText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold));
			this->WelcomeText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->WelcomeText->Location = System::Drawing::Point(212, 648);
			this->WelcomeText->Name = L"WelcomeText";
			this->WelcomeText->Size = System::Drawing::Size(503, 65);
			this->WelcomeText->TabIndex = 54;
			this->WelcomeText->Text = L"Welcome Back Chief!";
			this->WelcomeText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// WelcomeImage
			// 
			this->WelcomeImage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->WelcomeImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"WelcomeImage.Image")));
			this->WelcomeImage->Location = System::Drawing::Point(24, 54);
			this->WelcomeImage->Name = L"WelcomeImage";
			this->WelcomeImage->Size = System::Drawing::Size(900, 600);
			this->WelcomeImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->WelcomeImage->TabIndex = 55;
			this->WelcomeImage->TabStop = false;
			this->WelcomeImage->Click += gcnew System::EventHandler(this, &ClientLogin::WelcomeImage_Click);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::Color::White;
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listView1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(1, 0);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(950, 865);
			this->listView1->TabIndex = 56;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// Or
			// 
			this->Or->BackColor = System::Drawing::SystemColors::Control;
			this->Or->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Or->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Or->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Or->Location = System::Drawing::Point(1243, 638);
			this->Or->Margin = System::Windows::Forms::Padding(0);
			this->Or->Name = L"Or";
			this->Or->Size = System::Drawing::Size(30, 30);
			this->Or->TabIndex = 37;
			this->Or->Text = L"OR";
			this->Or->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(1087, 653);
			this->label5->Margin = System::Windows::Forms::Padding(0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(350, 1);
			this->label5->TabIndex = 53;
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(1087, 469);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(25, 25);
			this->pictureBox3->TabIndex = 48;
			this->pictureBox3->TabStop = false;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::White;
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(1087, 505);
			this->label13->Margin = System::Windows::Forms::Padding(0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(350, 1);
			this->label13->TabIndex = 47;
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ClientPasswordText
			// 
			this->ClientPasswordText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientPasswordText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClientPasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 14));
			this->ClientPasswordText->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->ClientPasswordText->Location = System::Drawing::Point(1117, 470);
			this->ClientPasswordText->Margin = System::Windows::Forms::Padding(4);
			this->ClientPasswordText->Name = L"ClientPasswordText";
			this->ClientPasswordText->Size = System::Drawing::Size(320, 25);
			this->ClientPasswordText->TabIndex = 46;
			this->ClientPasswordText->Text = L"Enter Password";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1087, 379);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 25);
			this->pictureBox1->TabIndex = 45;
			this->pictureBox1->TabStop = false;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(1087, 415);
			this->label9->Margin = System::Windows::Forms::Padding(0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(350, 1);
			this->label9->TabIndex = 44;
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PasswordText
			// 
			this->PasswordText->AutoSize = true;
			this->PasswordText->BackColor = System::Drawing::Color::Transparent;
			this->PasswordText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 12));
			this->PasswordText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->PasswordText->Location = System::Drawing::Point(1084, 441);
			this->PasswordText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->PasswordText->Name = L"PasswordText";
			this->PasswordText->Size = System::Drawing::Size(74, 21);
			this->PasswordText->TabIndex = 39;
			this->PasswordText->Text = L"Password";
			// 
			// LoginLink
			// 
			this->LoginLink->BackColor = System::Drawing::Color::Transparent;
			this->LoginLink->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LoginLink->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Underline));
			this->LoginLink->Location = System::Drawing::Point(1288, 692);
			this->LoginLink->Name = L"LoginLink";
			this->LoginLink->Size = System::Drawing::Size(79, 23);
			this->LoginLink->TabIndex = 43;
			this->LoginLink->Text = L"SIGN UP";
			this->LoginLink->Click += gcnew System::EventHandler(this, &ClientLogin::SignupLink_Click);
			// 
			// AlreadyAUserText
			// 
			this->AlreadyAUserText->BackColor = System::Drawing::Color::Transparent;
			this->AlreadyAUserText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->AlreadyAUserText->Location = System::Drawing::Point(1162, 692);
			this->AlreadyAUserText->Name = L"AlreadyAUserText";
			this->AlreadyAUserText->Size = System::Drawing::Size(130, 23);
			this->AlreadyAUserText->TabIndex = 36;
			this->AlreadyAUserText->Text = L"New to Sysmon\?";
			// 
			// LoginText
			// 
			this->LoginText->AutoSize = true;
			this->LoginText->BackColor = System::Drawing::Color::Transparent;
			this->LoginText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoginText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18, System::Drawing::FontStyle::Bold));
			this->LoginText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->LoginText->Location = System::Drawing::Point(1082, 278);
			this->LoginText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LoginText->Name = L"LoginText";
			this->LoginText->Size = System::Drawing::Size(85, 32);
			this->LoginText->TabIndex = 42;
			this->LoginText->Text = L"LOGIN";
			// 
			// LoginButton
			// 
			this->LoginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->LoginButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LoginButton->FlatAppearance->BorderSize = 0;
			this->LoginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoginButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginButton->ForeColor = System::Drawing::Color::White;
			this->LoginButton->Location = System::Drawing::Point(1087, 566);
			this->LoginButton->Margin = System::Windows::Forms::Padding(2);
			this->LoginButton->Name = L"LoginButton";
			this->LoginButton->Size = System::Drawing::Size(350, 34);
			this->LoginButton->TabIndex = 41;
			this->LoginButton->Text = L"LOGIN";
			this->LoginButton->UseVisualStyleBackColor = false;
			this->LoginButton->Click += gcnew System::EventHandler(this, &ClientLogin::LoginButton_Click);
			// 
			// ClientNameText
			// 
			this->ClientNameText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientNameText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClientNameText->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 14));
			this->ClientNameText->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->ClientNameText->Location = System::Drawing::Point(1117, 380);
			this->ClientNameText->Margin = System::Windows::Forms::Padding(4);
			this->ClientNameText->Name = L"ClientNameText";
			this->ClientNameText->Size = System::Drawing::Size(320, 25);
			this->ClientNameText->TabIndex = 40;
			this->ClientNameText->Text = L"Enter Client Name";
			// 
			// ClientText
			// 
			this->ClientText->AutoSize = true;
			this->ClientText->BackColor = System::Drawing::Color::Transparent;
			this->ClientText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ClientText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 12));
			this->ClientText->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ClientText->Location = System::Drawing::Point(1084, 352);
			this->ClientText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ClientText->Name = L"ClientText";
			this->ClientText->Size = System::Drawing::Size(95, 21);
			this->ClientText->TabIndex = 38;
			this->ClientText->Text = L"Client Name";
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
			this->Home->Location = System::Drawing::Point(59, 24);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(71, 30);
			this->Home->TabIndex = 66;
			this->Home->Text = L"Home";
			this->Home->Click += gcnew System::EventHandler(this, &ClientLogin::BackButton_Click);
			// 
			// BackButton
			// 
			this->BackButton->BackColor = System::Drawing::Color::White;
			this->BackButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BackButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackButton.Image")));
			this->BackButton->Location = System::Drawing::Point(25, 25);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(30, 30);
			this->BackButton->TabIndex = 65;
			this->BackButton->TabStop = false;
			this->BackButton->Click += gcnew System::EventHandler(this, &ClientLogin::BackButton_Click);
			// 
			// PasswordCheckText
			// 
			this->PasswordCheckText->AutoSize = true;
			this->PasswordCheckText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordCheckText->ForeColor = System::Drawing::Color::Red;
			this->PasswordCheckText->Location = System::Drawing::Point(1087, 508);
			this->PasswordCheckText->Name = L"PasswordCheckText";
			this->PasswordCheckText->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->PasswordCheckText->Size = System::Drawing::Size(0, 13);
			this->PasswordCheckText->TabIndex = 67;
			this->PasswordCheckText->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// UsernameCheckText
			// 
			this->UsernameCheckText->AutoSize = true;
			this->UsernameCheckText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UsernameCheckText->ForeColor = System::Drawing::Color::Red;
			this->UsernameCheckText->Location = System::Drawing::Point(1087, 418);
			this->UsernameCheckText->Name = L"UsernameCheckText";
			this->UsernameCheckText->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->UsernameCheckText->Size = System::Drawing::Size(0, 13);
			this->UsernameCheckText->TabIndex = 68;
			this->UsernameCheckText->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// ClientLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->ClientSize = System::Drawing::Size(1536, 864);
			this->Controls->Add(this->UsernameCheckText);
			this->Controls->Add(this->PasswordCheckText);
			this->Controls->Add(this->Home);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->Logo);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->WelcomeText);
			this->Controls->Add(this->WelcomeImage);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->Or);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->ClientPasswordText);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->PasswordText);
			this->Controls->Add(this->LoginLink);
			this->Controls->Add(this->AlreadyAUserText);
			this->Controls->Add(this->LoginText);
			this->Controls->Add(this->LoginButton);
			this->Controls->Add(this->ClientNameText);
			this->Controls->Add(this->ClientText);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"ClientLogin";
			this->Text = L"ClientLogin";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientLogin::ClientLogin_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ClientLogin::ClientLogin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->WelcomeImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackButton))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//homePageForm = gcnew HomePage(); // Create a new instance of the "HomePage" form
	this->Hide(); // Close the "clientLogin" form
	homePageForm->Show(); // Show the "HomePage" form
	//this->Close();

}
private: System::Void ClientLogin_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void LoginButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		loginVerified = clientSocket->SocketConnection(this->ClientNameText->Text, this->ClientPasswordText->Text, true);
		String^ check = "Credentials Verified";
		if (String::Equals(loginVerified->Substring(0, 25), "Connection already exists")) {
			this->UsernameCheckText->Text = "Client is already online";
			this->PasswordCheckText->Text = "";
			this->ClientPasswordText->Text = "";
			this->ClientNameText->Text = "";
		}
		else if (String::Equals(loginVerified->Substring(0, 19), "Credentials Invalid")) {
				this->UsernameCheckText->Text = "Credentials Invalid";
				this->PasswordCheckText->Text = "Credentials Invalid";
				this->ClientPasswordText->Text = "";
				this->ClientNameText->Text = "";
			}
		else if (String::Equals(loginVerified->Substring(0, 20), check->Substring(0, 20))) {
			clientPage = gcnew ClientPage(homePageForm, this->ClientNameText->Text);
			this->Hide();
			clientPage->Show();
			this->UsernameCheckText->Text = "";
			this->PasswordCheckText->Text = "";
			this->ClientPasswordText->Text = "";
			this->ClientNameText->Text = "";
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show(loginVerified);
		MessageBox::Show(ex->Message);
	}
}
private: System::Void SignupLink_Click(System::Object^ sender, System::EventArgs^ e) {
	clientSignup = gcnew ClientSignup(homePageForm, this);
	this->Hide();
	clientSignup->Show();
}
private: System::Void WelcomeImage_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ClientLogin_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	Application::Exit();
}
};
}
