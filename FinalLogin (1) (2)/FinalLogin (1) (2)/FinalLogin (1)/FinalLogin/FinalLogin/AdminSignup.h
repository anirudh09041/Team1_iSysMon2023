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
	/// Summary for AdminSignup
	/// </summary>
	public ref class AdminSignup : public System::Windows::Forms::Form
	{
	public:
		AdminSignup(void)
		{
			InitializeComponent();
			adminPasswordText->PasswordChar = '*';
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminSignup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ adminPasswordText;
	protected:

	private: System::Windows::Forms::TextBox^ adminIdText;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminSignup::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->adminPasswordText = (gcnew System::Windows::Forms::TextBox());
			this->adminIdText = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Teal;
			this->button1->Location = System::Drawing::Point(580, 298);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(285, 52);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Sign up";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminSignup::button1_Click);
			// 
			// adminPasswordText
			// 
			this->adminPasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminPasswordText->ForeColor = System::Drawing::Color::Teal;
			this->adminPasswordText->Location = System::Drawing::Point(569, 227);
			this->adminPasswordText->Margin = System::Windows::Forms::Padding(6);
			this->adminPasswordText->Name = L"adminPasswordText";
			this->adminPasswordText->Size = System::Drawing::Size(315, 39);
			this->adminPasswordText->TabIndex = 8;
			// 
			// adminIdText
			// 
			this->adminIdText->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminIdText->ForeColor = System::Drawing::Color::Teal;
			this->adminIdText->Location = System::Drawing::Point(569, 110);
			this->adminIdText->Margin = System::Windows::Forms::Padding(6);
			this->adminIdText->Name = L"adminIdText";
			this->adminIdText->Size = System::Drawing::Size(315, 39);
			this->adminIdText->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Window;
			this->label2->Location = System::Drawing::Point(564, 181);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 32);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Password";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Window;
			this->label1->Location = System::Drawing::Point(564, 64);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 32);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Admin ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Window;
			this->label3->Location = System::Drawing::Point(599, 9);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(237, 32);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Sign Up as an Admin";
			// 
			// AdminSignup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1449, 414);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->adminPasswordText);
			this->Controls->Add(this->adminIdText);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AdminSignup";
			this->Text = L"AdminSignup";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ constring = L"datasource = localhost;port=3306;username=root;password=Akeeb123";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDatabase = gcnew MySqlCommand("insert into database.admin_table(admin_id,password) values('" + this->adminIdText->Text + "','" + this->adminPasswordText->Text + "');", conDatabase);

		MySqlDataReader^ myReader;

		try {
			conDatabase->Open();
			myReader = cmdDatabase->ExecuteReader();
			MessageBox::Show("Saved");
			while (myReader->Read()) {

			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);

		}
	}
};
}
