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
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			panelWidth = panelSlider->Width;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  select_RC4_key;
	private: System::Windows::Forms::Button^  save_RC4_key;
	protected:


	private: System::Windows::Forms::Button^  crypt_decrypt_RC4_key;
	protected:


	protected:

	protected:


	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TextBox^  show_RC4_key;
	private:


	private:



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  select_file_with_data;
	public: System::Windows::Forms::TextBox^  show_data;
	private:





	private: System::Windows::Forms::Button^  crypt_data;
	private: System::Windows::Forms::Button^  decrypt_data;
	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		String^ RC4_key;
		const int maxFiles = 100;
		const int maxKeyLength = 40;
		String^ keyExt = "txt";
		array<String^>^ filesData = gcnew array<String^>(maxFiles);
		int TogMove;
		int MValX;
		int MValY;
		int panelWidth;
		bool Hidden = false;
		String^ publicRSA_key = "";
		String^ privateRSA_key = "";
		String^ RC4_key_for_encrypt;
		bool canDecrypt = true;
		bool canCryptDecrypt = true;

	private: System::Windows::Forms::Button^  clean_data;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panelSlider;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  generate_RSA_keys;
	private: System::Windows::Forms::Button^  select_private_RSA_key;




	private: System::Windows::Forms::Button^  select_public_RSA_key;
	private: System::Windows::Forms::Button^  decrypt_RC4_key;


	private: System::Windows::Forms::Button^  encrypt_RC4_key;


	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::Label^  label3;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->select_RC4_key = (gcnew System::Windows::Forms::Button());
			this->save_RC4_key = (gcnew System::Windows::Forms::Button());
			this->crypt_decrypt_RC4_key = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->show_RC4_key = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->select_file_with_data = (gcnew System::Windows::Forms::Button());
			this->show_data = (gcnew System::Windows::Forms::TextBox());
			this->crypt_data = (gcnew System::Windows::Forms::Button());
			this->decrypt_data = (gcnew System::Windows::Forms::Button());
			this->clean_data = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panelSlider = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->decrypt_RC4_key = (gcnew System::Windows::Forms::Button());
			this->encrypt_RC4_key = (gcnew System::Windows::Forms::Button());
			this->select_private_RSA_key = (gcnew System::Windows::Forms::Button());
			this->select_public_RSA_key = (gcnew System::Windows::Forms::Button());
			this->generate_RSA_keys = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panelSlider->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// select_RC4_key
			// 
			this->select_RC4_key->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->select_RC4_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->select_RC4_key->ForeColor = System::Drawing::Color::White;
			this->select_RC4_key->Location = System::Drawing::Point(42, 147);
			this->select_RC4_key->Name = L"select_RC4_key";
			this->select_RC4_key->Size = System::Drawing::Size(138, 45);
			this->select_RC4_key->TabIndex = 0;
			this->select_RC4_key->Text = L"Вибрати ключ";
			this->select_RC4_key->UseVisualStyleBackColor = false;
			this->select_RC4_key->Click += gcnew System::EventHandler(this, &Form1::select_RC4_key_Click);
			// 
			// save_RC4_key
			// 
			this->save_RC4_key->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->save_RC4_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->save_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->save_RC4_key->ForeColor = System::Drawing::Color::White;
			this->save_RC4_key->Location = System::Drawing::Point(195, 148);
			this->save_RC4_key->Name = L"save_RC4_key";
			this->save_RC4_key->Size = System::Drawing::Size(138, 45);
			this->save_RC4_key->TabIndex = 1;
			this->save_RC4_key->Text = L"Зберегти ключ";
			this->save_RC4_key->UseVisualStyleBackColor = false;
			this->save_RC4_key->Click += gcnew System::EventHandler(this, &Form1::save_RC4_key_Click);
			// 
			// crypt_decrypt_RC4_key
			// 
			this->crypt_decrypt_RC4_key->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->crypt_decrypt_RC4_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->crypt_decrypt_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->crypt_decrypt_RC4_key->ForeColor = System::Drawing::Color::White;
			this->crypt_decrypt_RC4_key->Location = System::Drawing::Point(41, 204);
			this->crypt_decrypt_RC4_key->Name = L"crypt_decrypt_RC4_key";
			this->crypt_decrypt_RC4_key->Size = System::Drawing::Size(292, 68);
			this->crypt_decrypt_RC4_key->TabIndex = 2;
			this->crypt_decrypt_RC4_key->Text = L"Шифрування ключа: Деактивовано";
			this->crypt_decrypt_RC4_key->UseVisualStyleBackColor = false;
			this->crypt_decrypt_RC4_key->Click += gcnew System::EventHandler(this, &Form1::crypt_decrypt_RC4_key_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->Location = System::Drawing::Point(85, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(216, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ключ (Максимум -  40 символів)";
			// 
			// show_RC4_key
			// 
			this->show_RC4_key->AllowDrop = true;
			this->show_RC4_key->BackColor = System::Drawing::SystemColors::Control;
			this->show_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->show_RC4_key->ForeColor = System::Drawing::Color::Gray;
			this->show_RC4_key->Location = System::Drawing::Point(42, 79);
			this->show_RC4_key->MaxLength = 40;
			this->show_RC4_key->Multiline = true;
			this->show_RC4_key->Name = L"show_RC4_key";
			this->show_RC4_key->Size = System::Drawing::Size(292, 57);
			this->show_RC4_key->TabIndex = 4;
			this->show_RC4_key->Text = L"Перемістіть файл з ключем у цю область";
			this->show_RC4_key->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->show_RC4_key->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::show_RC4_key_DragDrop);
			this->show_RC4_key->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::show_RC4_key_DragEnter);
			this->show_RC4_key->Enter += gcnew System::EventHandler(this, &Form1::show_RC4_key_Enter);
			this->show_RC4_key->Leave += gcnew System::EventHandler(this, &Form1::show_RC4_key_Leave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(159, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(392, 34);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Файли які будуть шифруватися(Максимум - 100 файлів та \r\n                        о"
				L"б\'ємом не більше 500 МБ кожен)";
			// 
			// select_file_with_data
			// 
			this->select_file_with_data->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select_file_with_data->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->select_file_with_data->Location = System::Drawing::Point(18, 72);
			this->select_file_with_data->Name = L"select_file_with_data";
			this->select_file_with_data->Size = System::Drawing::Size(138, 45);
			this->select_file_with_data->TabIndex = 6;
			this->select_file_with_data->Text = L"Вибрати файли";
			this->select_file_with_data->UseVisualStyleBackColor = true;
			this->select_file_with_data->Click += gcnew System::EventHandler(this, &Form1::select_file_with_data_Click);
			// 
			// show_data
			// 
			this->show_data->AllowDrop = true;
			this->show_data->BackColor = System::Drawing::SystemColors::Control;
			this->show_data->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->show_data->ForeColor = System::Drawing::Color::Gray;
			this->show_data->Location = System::Drawing::Point(162, 72);
			this->show_data->Multiline = true;
			this->show_data->Name = L"show_data";
			this->show_data->ReadOnly = true;
			this->show_data->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->show_data->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->show_data->Size = System::Drawing::Size(389, 230);
			this->show_data->TabIndex = 7;
			this->show_data->Text = L"Перемістіть вибрані файли у цю область";
			this->show_data->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->show_data->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::show_data_DragDrop);
			this->show_data->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::show_data_DragEnter);
			this->show_data->Enter += gcnew System::EventHandler(this, &Form1::show_data_Enter);
			this->show_data->Leave += gcnew System::EventHandler(this, &Form1::show_data_Leave);
			// 
			// crypt_data
			// 
			this->crypt_data->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->crypt_data->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->crypt_data->Location = System::Drawing::Point(18, 127);
			this->crypt_data->Name = L"crypt_data";
			this->crypt_data->Size = System::Drawing::Size(138, 45);
			this->crypt_data->TabIndex = 8;
			this->crypt_data->Text = L"Зашифрувати файли";
			this->crypt_data->UseVisualStyleBackColor = true;
			this->crypt_data->Click += gcnew System::EventHandler(this, &Form1::crypt_data_Click);
			// 
			// decrypt_data
			// 
			this->decrypt_data->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->decrypt_data->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->decrypt_data->Location = System::Drawing::Point(18, 182);
			this->decrypt_data->Name = L"decrypt_data";
			this->decrypt_data->Size = System::Drawing::Size(138, 45);
			this->decrypt_data->TabIndex = 9;
			this->decrypt_data->Text = L"Розшифрувати файли";
			this->decrypt_data->UseVisualStyleBackColor = true;
			this->decrypt_data->Click += gcnew System::EventHandler(this, &Form1::decrypt_data_Click);
			// 
			// clean_data
			// 
			this->clean_data->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clean_data->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clean_data->Location = System::Drawing::Point(162, 310);
			this->clean_data->Name = L"clean_data";
			this->clean_data->Size = System::Drawing::Size(389, 34);
			this->clean_data->TabIndex = 11;
			this->clean_data->Text = L"Очистити список файлів";
			this->clean_data->UseVisualStyleBackColor = true;
			this->clean_data->Click += gcnew System::EventHandler(this, &Form1::clean_data_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(967, 47);
			this->panel2->TabIndex = 13;
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(897, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(32, 47);
			this->button2->TabIndex = 16;
			this->button2->Text = L"_";
			this->button2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Right;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(931, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(36, 47);
			this->button1->TabIndex = 15;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(967, 47);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Програма гібридного шифрування даних";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label3_MouseDown);
			this->label3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label3_MouseMove);
			this->label3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label3_MouseUp);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->select_RC4_key);
			this->panel1->Controls->Add(this->save_RC4_key);
			this->panel1->Controls->Add(this->crypt_decrypt_RC4_key);
			this->panel1->Controls->Add(this->show_RC4_key);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 47);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(378, 387);
			this->panel1->TabIndex = 14;
			// 
			// panelSlider
			// 
			this->panelSlider->Controls->Add(this->label5);
			this->panelSlider->Controls->Add(this->clean_data);
			this->panelSlider->Controls->Add(this->show_data);
			this->panelSlider->Controls->Add(this->label2);
			this->panelSlider->Controls->Add(this->select_file_with_data);
			this->panelSlider->Controls->Add(this->decrypt_data);
			this->panelSlider->Controls->Add(this->crypt_data);
			this->panelSlider->Dock = System::Windows::Forms::DockStyle::Right;
			this->panelSlider->Location = System::Drawing::Point(378, 47);
			this->panelSlider->Name = L"panelSlider";
			this->panelSlider->Size = System::Drawing::Size(589, 387);
			this->panelSlider->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->label5->Dock = System::Windows::Forms::DockStyle::Left;
			this->label5->Location = System::Drawing::Point(0, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(10, 387);
			this->label5->TabIndex = 12;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel4->Controls->Add(this->decrypt_RC4_key);
			this->panel4->Controls->Add(this->encrypt_RC4_key);
			this->panel4->Controls->Add(this->select_private_RSA_key);
			this->panel4->Controls->Add(this->select_public_RSA_key);
			this->panel4->Controls->Add(this->generate_RSA_keys);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(378, 47);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(0, 387);
			this->panel4->TabIndex = 16;
			// 
			// decrypt_RC4_key
			// 
			this->decrypt_RC4_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->decrypt_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->decrypt_RC4_key->ForeColor = System::Drawing::Color::Black;
			this->decrypt_RC4_key->Location = System::Drawing::Point(304, 207);
			this->decrypt_RC4_key->Name = L"decrypt_RC4_key";
			this->decrypt_RC4_key->Size = System::Drawing::Size(223, 57);
			this->decrypt_RC4_key->TabIndex = 4;
			this->decrypt_RC4_key->Text = L"Розшифрувати ключ\r\n";
			this->decrypt_RC4_key->UseVisualStyleBackColor = false;
			this->decrypt_RC4_key->Click += gcnew System::EventHandler(this, &Form1::decrypt_RC4_key_Click);
			// 
			// encrypt_RC4_key
			// 
			this->encrypt_RC4_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->encrypt_RC4_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->encrypt_RC4_key->ForeColor = System::Drawing::Color::Black;
			this->encrypt_RC4_key->Location = System::Drawing::Point(66, 207);
			this->encrypt_RC4_key->Name = L"encrypt_RC4_key";
			this->encrypt_RC4_key->Size = System::Drawing::Size(223, 57);
			this->encrypt_RC4_key->TabIndex = 3;
			this->encrypt_RC4_key->Text = L"Зашифрувати ключ\r\n";
			this->encrypt_RC4_key->UseVisualStyleBackColor = false;
			this->encrypt_RC4_key->Click += gcnew System::EventHandler(this, &Form1::encrypt_RC4_key_Click);
			// 
			// select_private_RSA_key
			// 
			this->select_private_RSA_key->AllowDrop = true;
			this->select_private_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			this->select_private_RSA_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select_private_RSA_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->select_private_RSA_key->ForeColor = System::Drawing::Color::White;
			this->select_private_RSA_key->Location = System::Drawing::Point(304, 135);
			this->select_private_RSA_key->Name = L"select_private_RSA_key";
			this->select_private_RSA_key->Size = System::Drawing::Size(223, 57);
			this->select_private_RSA_key->TabIndex = 2;
			this->select_private_RSA_key->Text = L"Вибрати закритий ключ\r\n(Неообхідний для розшифровки)";
			this->select_private_RSA_key->UseVisualStyleBackColor = false;
			this->select_private_RSA_key->Click += gcnew System::EventHandler(this, &Form1::select_private_RSA_key_Click);
			this->select_private_RSA_key->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::select_private_RSA_key_DragDrop);
			this->select_private_RSA_key->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::select_private_RSA_key_DragEnter);
			// 
			// select_public_RSA_key
			// 
			this->select_public_RSA_key->AllowDrop = true;
			this->select_public_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			this->select_public_RSA_key->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->select_public_RSA_key->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->select_public_RSA_key->ForeColor = System::Drawing::Color::White;
			this->select_public_RSA_key->Location = System::Drawing::Point(66, 135);
			this->select_public_RSA_key->Name = L"select_public_RSA_key";
			this->select_public_RSA_key->Size = System::Drawing::Size(223, 57);
			this->select_public_RSA_key->TabIndex = 1;
			this->select_public_RSA_key->Text = L"Вибрати відкритий ключ\r\n(Необхідний для шифрування)\r\n";
			this->select_public_RSA_key->UseVisualStyleBackColor = false;
			this->select_public_RSA_key->Click += gcnew System::EventHandler(this, &Form1::select_public_RSA_key_Click);
			this->select_public_RSA_key->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::select_public_RSA_key_DragDrop);
			this->select_public_RSA_key->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::select_public_RSA_key_DragEnter);
			// 
			// generate_RSA_keys
			// 
			this->generate_RSA_keys->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->generate_RSA_keys->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->generate_RSA_keys->ForeColor = System::Drawing::Color::Black;
			this->generate_RSA_keys->Location = System::Drawing::Point(66, 75);
			this->generate_RSA_keys->Name = L"generate_RSA_keys";
			this->generate_RSA_keys->Size = System::Drawing::Size(461, 45);
			this->generate_RSA_keys->TabIndex = 0;
			this->generate_RSA_keys->Text = L"Генерувати нову пару ключів";
			this->generate_RSA_keys->UseVisualStyleBackColor = false;
			this->generate_RSA_keys->Click += gcnew System::EventHandler(this, &Form1::generate_RSA_keys_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(967, 434);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panelSlider);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Програма для гібридного шифрування даних";
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panelSlider->ResumeLayout(false);
			this->panelSlider->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void select_RC4_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_file_with_data_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void crypt_data_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void decrypt_data_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void save_RC4_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void crypt_decrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void show_data_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void show_data_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void show_RC4_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void show_RC4_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void clean_data_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void label3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void label3_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void label3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void show_RC4_key_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void show_RC4_key_Leave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void show_data_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void show_data_Leave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void generate_RSA_keys_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_public_RSA_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_private_RSA_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void encrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void decrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void select_public_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void select_public_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void select_private_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
	private: System::Void select_private_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e);
};
}
