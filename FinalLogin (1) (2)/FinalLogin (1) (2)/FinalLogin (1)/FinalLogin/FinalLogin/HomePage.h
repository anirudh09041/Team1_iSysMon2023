#pragma once
#include"ClientLogin.h"
#include"ClientSignup.h"

namespace FinalLogin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for HomePage
	/// </summary>
	public ref class HomePage : public System::Windows::Forms::Form
	{
	private:
		cli::array<String^>^ imagePaths;
		cli::array<String^>^ imageTitle;
		int currentImageIndex;
		Timer^ timer;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private: System::Windows::Forms::Button^ GetStarted;
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ Subtitle;
	private: System::Windows::Forms::Label^ ImageTitle;
	private: System::Windows::Forms::Label^ label1;

	public:
		Form^ clientLoginPage;
		Form^ clientSignupPage;
		HomePage(void)
		{
			InitializeComponent();
			clientLoginPage = gcnew ClientLogin(this);
			clientSignupPage = gcnew ClientSignup(this, clientLoginPage);
			imagePaths = gcnew cli::array<String^> { 
				"../images/5137782.png", 
				"../images/5137774.jpg",
				"../images/5137812.jpg" 
			};
			imageTitle = gcnew cli::array<String^>{
				"KEEP TRACK OF YOUR SYSTEM INFORMATION",
				"DETAILED REPORTS ON SYSTEM ACTIVITIES",
				"TRACK AND MONITOR VARIOUS SYSTEM STATISTICS"
			};
			currentImageIndex = 0;
			timer = gcnew Timer();
			timer->Interval = 5000; // change image every 5 seconds
			timer->Tick += gcnew EventHandler(this, &HomePage::timer_Tick);
			timer->Start();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		private:
        void timer_Tick(Object^ sender, EventArgs^ e)
        {
            currentImageIndex++;
            if (currentImageIndex >= imagePaths->Length)
            {
                currentImageIndex = 0;
            }
            pictureBox1->Image = Image::FromFile(imagePaths[currentImageIndex]);
			ImageTitle->Text = imageTitle[currentImageIndex];
        }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HomePage()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ ClientSignupOptionBtn;



	private: System::Windows::Forms::Button^ clientLoginOptionBtn;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HomePage::typeid));
			this->ClientSignupOptionBtn = (gcnew System::Windows::Forms::Button());
			this->clientLoginOptionBtn = (gcnew System::Windows::Forms::Button());
			this->Logo = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->GetStarted = (gcnew System::Windows::Forms::Button());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->Subtitle = (gcnew System::Windows::Forms::Label());
			this->ImageTitle = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// ClientSignupOptionBtn
			// 
			this->ClientSignupOptionBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSignupOptionBtn->BackColor = System::Drawing::Color::Transparent;
			this->ClientSignupOptionBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ClientSignupOptionBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClientSignupOptionBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->ClientSignupOptionBtn->Location = System::Drawing::Point(1370, 38);
			this->ClientSignupOptionBtn->Margin = System::Windows::Forms::Padding(7);
			this->ClientSignupOptionBtn->Name = L"ClientSignupOptionBtn";
			this->ClientSignupOptionBtn->Padding = System::Windows::Forms::Padding(15, 5, 15, 5);
			this->ClientSignupOptionBtn->Size = System::Drawing::Size(130, 42);
			this->ClientSignupOptionBtn->TabIndex = 17;
			this->ClientSignupOptionBtn->Text = L"Sign Up";
			this->ClientSignupOptionBtn->UseVisualStyleBackColor = false;
			this->ClientSignupOptionBtn->Click += gcnew System::EventHandler(this, &HomePage::button1_Click);
			// 
			// clientLoginOptionBtn
			// 
			this->clientLoginOptionBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->clientLoginOptionBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(127)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->clientLoginOptionBtn->FlatAppearance->BorderSize = 0;
			this->clientLoginOptionBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clientLoginOptionBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientLoginOptionBtn->ForeColor = System::Drawing::Color::White;
			this->clientLoginOptionBtn->Location = System::Drawing::Point(1226, 38);
			this->clientLoginOptionBtn->Margin = System::Windows::Forms::Padding(7);
			this->clientLoginOptionBtn->Name = L"clientLoginOptionBtn";
			this->clientLoginOptionBtn->Padding = System::Windows::Forms::Padding(15, 5, 15, 5);
			this->clientLoginOptionBtn->Size = System::Drawing::Size(130, 42);
			this->clientLoginOptionBtn->TabIndex = 14;
			this->clientLoginOptionBtn->Text = L"Log In";
			this->clientLoginOptionBtn->UseVisualStyleBackColor = false;
			this->clientLoginOptionBtn->Click += gcnew System::EventHandler(this, &HomePage::clientLoginHomepage_Click);
			// 
			// Logo
			// 
			this->Logo->AutoSize = true;
			this->Logo->BackColor = System::Drawing::Color::Transparent;
			this->Logo->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Logo->Location = System::Drawing::Point(25, 25);
			this->Logo->Margin = System::Windows::Forms::Padding(0);
			this->Logo->Name = L"Logo";
			this->Logo->Size = System::Drawing::Size(301, 65);
			this->Logo->TabIndex = 59;
			this->Logo->Text = L"S Y S M O N";
			this->Logo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(600, 167);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(11);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(900, 506);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 60;
			this->pictureBox1->TabStop = false;
			// 
			// GetStarted
			// 
			this->GetStarted->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->GetStarted->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->GetStarted->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GetStarted->FlatAppearance->BorderSize = 0;
			this->GetStarted->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GetStarted->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GetStarted->ForeColor = System::Drawing::Color::White;
			this->GetStarted->Location = System::Drawing::Point(36, 541);
			this->GetStarted->Margin = System::Windows::Forms::Padding(7);
			this->GetStarted->Name = L"GetStarted";
			this->GetStarted->Padding = System::Windows::Forms::Padding(15, 5, 15, 5);
			this->GetStarted->Size = System::Drawing::Size(249, 54);
			this->GetStarted->TabIndex = 63;
			this->GetStarted->Text = L"Get Started";
			this->GetStarted->UseVisualStyleBackColor = false;
			this->GetStarted->Click += gcnew System::EventHandler(this, &HomePage::button1_Click);
			// 
			// Title
			// 
			this->Title->BackColor = System::Drawing::Color::Transparent;
			this->Title->Location = System::Drawing::Point(28, 273);
			this->Title->Margin = System::Windows::Forms::Padding(11, 0, 11, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(470, 94);
			this->Title->TabIndex = 64;
			this->Title->Text = L"MONITOR YOUR SYSTEM WITH EASE\r\n";
			// 
			// Subtitle
			// 
			this->Subtitle->BackColor = System::Drawing::Color::Transparent;
			this->Subtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Subtitle->Location = System::Drawing::Point(32, 396);
			this->Subtitle->Name = L"Subtitle";
			this->Subtitle->Size = System::Drawing::Size(466, 116);
			this->Subtitle->TabIndex = 65;
			this->Subtitle->Text = resources->GetString(L"Subtitle.Text");
			// 
			// ImageTitle
			// 
			this->ImageTitle->BackColor = System::Drawing::Color::Transparent;
			this->ImageTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImageTitle->Location = System::Drawing::Point(600, 715);
			this->ImageTitle->Name = L"ImageTitle";
			this->ImageTitle->Size = System::Drawing::Size(900, 47);
			this->ImageTitle->TabIndex = 66;
			this->ImageTitle->Text = L"KEEP TRACK OF YOUR SYSTEM INFORMATION";
			this->ImageTitle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(32, 736);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(254, 21);
			this->label1->TabIndex = 67;
			this->label1->Text = L"Contact us at support@sysmon.com";
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(22, 47);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1536, 864);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ImageTitle);
			this->Controls->Add(this->Subtitle);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->GetStarted);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Logo);
			this->Controls->Add(this->ClientSignupOptionBtn);
			this->Controls->Add(this->clientLoginOptionBtn);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(7);
			this->MinimumSize = System::Drawing::Size(1534, 862);
			this->Name = L"HomePage";
			this->Text = L"S Y S M O N";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void clientLoginHomepage_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		//Form^ clientLoginPage = gcnew ClientLogin(this);
		clientLoginPage->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		clientSignupPage->Show();
	}
};
}
