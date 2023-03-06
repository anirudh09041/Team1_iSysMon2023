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
	/// Summary for AdminLogin
	/// </summary>
	public ref class AdminLogin : public System::Windows::Forms::Form
	{
	public:
		AdminLogin(void)
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
		~AdminLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ adminLoginBtn;
	protected:

	private: System::Windows::Forms::TextBox^ adminPasswordText;
	protected:

	private: System::Windows::Forms::TextBox^ adminIdText;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminLogin::typeid));
			this->adminLoginBtn = (gcnew System::Windows::Forms::Button());
			this->adminPasswordText = (gcnew System::Windows::Forms::TextBox());
			this->adminIdText = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// adminLoginBtn
			// 
			this->adminLoginBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->adminLoginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminLoginBtn->ForeColor = System::Drawing::Color::Teal;
			this->adminLoginBtn->Location = System::Drawing::Point(547, 321);
			this->adminLoginBtn->Name = L"adminLoginBtn";
			this->adminLoginBtn->Size = System::Drawing::Size(238, 52);
			this->adminLoginBtn->TabIndex = 9;
			this->adminLoginBtn->Text = L"Log in as Admin";
			this->adminLoginBtn->UseVisualStyleBackColor = true;
			this->adminLoginBtn->Click += gcnew System::EventHandler(this, &AdminLogin::adminLoginBtn_Click);
			// 
			// adminPasswordText
			// 
			this->adminPasswordText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminPasswordText->Location = System::Drawing::Point(537, 227);
			this->adminPasswordText->Margin = System::Windows::Forms::Padding(6);
			this->adminPasswordText->Name = L"adminPasswordText";
			this->adminPasswordText->Size = System::Drawing::Size(429, 35);
			this->adminPasswordText->TabIndex = 8;
			// 
			// adminIdText
			// 
			this->adminIdText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adminIdText->Location = System::Drawing::Point(537, 100);
			this->adminIdText->Margin = System::Windows::Forms::Padding(6);
			this->adminIdText->Name = L"adminIdText";
			this->adminIdText->Size = System::Drawing::Size(429, 35);
			this->adminIdText->TabIndex = 7;
			this->adminIdText->TextChanged += gcnew System::EventHandler(this, &AdminLogin::adminIdText_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Window;
			this->label2->Location = System::Drawing::Point(532, 168);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 29);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Password";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Window;
			this->label1->Location = System::Drawing::Point(532, 45);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Admin ID";
			// 
			// AdminLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1435, 529);
			this->Controls->Add(this->adminLoginBtn);
			this->Controls->Add(this->adminPasswordText);
			this->Controls->Add(this->adminIdText);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AdminLogin";
			this->Text = L"AdminLogin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void adminLoginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ constring = L"datasource=localhost;port=3306;username=root;password=Akeeb123";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDatabase = gcnew MySqlCommand("SELECT admin_id, password FROM database.admin_table WHERE admin_id = '" + this->adminIdText->Text + "' AND password = '" + this->adminPasswordText->Text + "'", conDatabase);
		MySqlDataReader^ myReader;

		try {
			conDatabase->Open();
			myReader = cmdDatabase->ExecuteReader();

			while (myReader->Read()) {
				// Read the value of the username field and store it in a variable
				String^ admin_id = myReader->GetString("admin_id");

				// Read the value of the password field and store it in a variable
				String^ password = myReader->GetString("password");

				// Compare the variables with the text boxes
				if (admin_id == this->adminIdText->Text && password == this->adminPasswordText->Text) {
					// The username and password match, do something
					MessageBox::Show("Login successful!");
				}
				else {
					// The username and/or password do not match, do something else
					MessageBox::Show("Invalid username and/or password");
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
		finally {
			if (myReader != nullptr) {
				myReader->Close();
			}
			if (conDatabase != nullptr) {
				conDatabase->Close();
			}
		}

	}
private: System::Void adminIdText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
