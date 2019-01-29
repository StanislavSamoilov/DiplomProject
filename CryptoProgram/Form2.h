#pragma once

namespace CryptoProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Security::Cryptography;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  select_private_RSA_key;
	protected:

	private: System::Windows::Forms::Button^  select_public_RSA_key;

	private: System::Windows::Forms::Button^  generate_RSA_keys;
	private: System::Windows::Forms::Button^  encrypt_RC4_key;
	private: System::Windows::Forms::Button^  decrypt_RC4_key;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		String^ publicRSA_key = "";
		String^ privateRSA_key = "";
		String^ RC4_key_for_encrypt;
		bool canDecrypt = true;
		int TogMove;
		int MValX;
		int MValY;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->select_private_RSA_key = (gcnew System::Windows::Forms::Button());
			this->select_public_RSA_key = (gcnew System::Windows::Forms::Button());
			this->generate_RSA_keys = (gcnew System::Windows::Forms::Button());
			this->encrypt_RC4_key = (gcnew System::Windows::Forms::Button());
			this->decrypt_RC4_key = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// select_private_RSA_key
			// 
			this->select_private_RSA_key->AllowDrop = true;
			this->select_private_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			this->select_private_RSA_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select_private_RSA_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->select_private_RSA_key->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->select_private_RSA_key->Location = System::Drawing::Point(241, 93);
			this->select_private_RSA_key->Name = L"select_private_RSA_key";
			this->select_private_RSA_key->Size = System::Drawing::Size(223, 57);
			this->select_private_RSA_key->TabIndex = 0;
			this->select_private_RSA_key->Text = L"Вибрати закритий ключ\r\n(Неообхідний для розшифровки)";
			this->select_private_RSA_key->UseVisualStyleBackColor = false;
			this->select_private_RSA_key->Click += gcnew System::EventHandler(this, &Form2::select_private_RSA_key_Click);
			this->select_private_RSA_key->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form2::select_private_RSA_key_DragDrop);
			this->select_private_RSA_key->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form2::select_private_RSA_key_DragEnter);
			// 
			// select_public_RSA_key
			// 
			this->select_public_RSA_key->AllowDrop = true;
			this->select_public_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			this->select_public_RSA_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select_public_RSA_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->select_public_RSA_key->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->select_public_RSA_key->Location = System::Drawing::Point(12, 93);
			this->select_public_RSA_key->Name = L"select_public_RSA_key";
			this->select_public_RSA_key->Size = System::Drawing::Size(223, 57);
			this->select_public_RSA_key->TabIndex = 1;
			this->select_public_RSA_key->Text = L"Вибрати відкритий ключ\r\n(Необхідний для шифрування)";
			this->select_public_RSA_key->UseVisualStyleBackColor = false;
			this->select_public_RSA_key->Click += gcnew System::EventHandler(this, &Form2::select_public_RSA_key_Click);
			this->select_public_RSA_key->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form2::select_public_RSA_key_DragDrop);
			this->select_public_RSA_key->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form2::select_public_RSA_key_DragEnter);
			// 
			// generate_RSA_keys
			// 
			this->generate_RSA_keys->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->generate_RSA_keys->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->generate_RSA_keys->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->generate_RSA_keys->ForeColor = System::Drawing::SystemColors::ControlText;
			this->generate_RSA_keys->Location = System::Drawing::Point(12, 42);
			this->generate_RSA_keys->Name = L"generate_RSA_keys";
			this->generate_RSA_keys->Size = System::Drawing::Size(452, 45);
			this->generate_RSA_keys->TabIndex = 2;
			this->generate_RSA_keys->Text = L"Генерувати нову пару ключів";
			this->generate_RSA_keys->UseVisualStyleBackColor = false;
			this->generate_RSA_keys->Click += gcnew System::EventHandler(this, &Form2::generate_RSA_keys_Click);
			// 
			// encrypt_RC4_key
			// 
			this->encrypt_RC4_key->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->encrypt_RC4_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->encrypt_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->encrypt_RC4_key->ForeColor = System::Drawing::SystemColors::ControlText;
			this->encrypt_RC4_key->Location = System::Drawing::Point(12, 156);
			this->encrypt_RC4_key->Name = L"encrypt_RC4_key";
			this->encrypt_RC4_key->Size = System::Drawing::Size(223, 45);
			this->encrypt_RC4_key->TabIndex = 3;
			this->encrypt_RC4_key->Text = L"Зашифрувати ключ";
			this->encrypt_RC4_key->UseVisualStyleBackColor = false;
			this->encrypt_RC4_key->Click += gcnew System::EventHandler(this, &Form2::encrypt_RC4_key_Click);
			// 
			// decrypt_RC4_key
			// 
			this->decrypt_RC4_key->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->decrypt_RC4_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->decrypt_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->decrypt_RC4_key->ForeColor = System::Drawing::SystemColors::ControlText;
			this->decrypt_RC4_key->Location = System::Drawing::Point(241, 156);
			this->decrypt_RC4_key->Name = L"decrypt_RC4_key";
			this->decrypt_RC4_key->Size = System::Drawing::Size(223, 45);
			this->decrypt_RC4_key->TabIndex = 4;
			this->decrypt_RC4_key->Text = L"Розшифрувати ключ";
			this->decrypt_RC4_key->UseVisualStyleBackColor = false;
			this->decrypt_RC4_key->Click += gcnew System::EventHandler(this, &Form2::decrypt_RC4_key_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(480, 35);
			this->panel1->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Right;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(439, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(41, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(480, 35);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Шифрування ключа";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::label1_MouseDown);
			this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::label1_MouseMove);
			this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::label1_MouseUp);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(480, 218);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->decrypt_RC4_key);
			this->Controls->Add(this->encrypt_RC4_key);
			this->Controls->Add(this->generate_RSA_keys);
			this->Controls->Add(this->select_public_RSA_key);
			this->Controls->Add(this->select_private_RSA_key);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Шифрування ключа";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void generate_RSA_keys_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_public_RSA_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_private_RSA_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void encrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e);
	public: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void decrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_public_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void select_public_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void select_private_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void select_private_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void label1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void label1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void label1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
};
}
