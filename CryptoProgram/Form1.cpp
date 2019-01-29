#include "Form1.h"
#include "algoritm_RC4.h"
#include "CustomMsgBox.h"

using namespace CryptoProgram;

String^ get_ext(String^ st);

System::Void Form1::select_RC4_key_Click(System::Object^  sender, System::EventArgs^  e) 
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "Text File|*.txt";
	ofd->Title = "Вибір файлу з ключем";

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamReader^ sr = File::OpenText(ofd->FileName);
		String^ tempRC4_key = sr->ReadToEnd();
		sr->Close();

		if (tempRC4_key->Length <= 0)
		{
			CustomMsgBox Msg("Файл не містить даних");
		}
		else
		{
			RC4_key = tempRC4_key;
			show_RC4_key->Clear();
			show_RC4_key->AppendText(RC4_key);
			show_RC4_key->ForeColor = Color::Black;
			show_RC4_key->TextAlign = HorizontalAlignment::Left;
			show_RC4_key->Font = gcnew System::Drawing::Font("Century Gothic", 10);
		}
	}
}

System::Void Form1::select_file_with_data_Click(System::Object^  sender, System::EventArgs^  e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Multiselect = true;
	ofd->Title = "Вибір файлів";

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		show_data->Clear();
		show_data->ForeColor = Color::Black;
		show_data->TextAlign = HorizontalAlignment::Left;
		show_data->Font = gcnew System::Drawing::Font("Century Gothic", 10);
		for (int i = 0; i < maxFiles; i++)
		{
			filesData[i] = nullptr;
		}

		int i = 0;

		for each (String^ file in ofd->FileNames)
		{
			if (maxFiles == i)
			{
				CustomMsgBox Msg("Привищено максимальну кількість файлів(100 шт), були вибрані тільки перші 100 файлів!");
				break;
			}
			show_data->AppendText(Path::GetFileName(file) + "\n");
			filesData[i] = file;
			i++;
		}
	}
}

System::Void Form1::crypt_data_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (show_RC4_key->TextLength > 0 && show_RC4_key->Text != "Перемістіть файл з ключем у цю область")
	{
		if (show_RC4_key->TextLength <= maxKeyLength)
		{
			if (filesData[0] != nullptr)
			{
				Encoding^ ucode = Encoding::Unicode;
				MD5^ md5Hash = MD5::Create();
				array<unsigned char>^ keyHash = md5Hash->ComputeHash(ucode->GetBytes(show_RC4_key->Text));
				int i = 0;

				for each (String^ file in filesData)
				{
					RC4 encrypter(ucode->GetBytes(show_RC4_key->Text));
					if (maxFiles == i || !file)
					{
						break;
					}
					array<unsigned char>^ dataFormFile = File::ReadAllBytes(file);

					if (dataFormFile->Length >= 16)
					{
						array<unsigned char>^ hashFromFile = gcnew array<unsigned char>(16);
						System::Array::Copy(dataFormFile, (dataFormFile->Length - 16), hashFromFile, 0, 16);

						if (ucode->GetString(keyHash) != ucode->GetString(hashFromFile))
						{
							array<unsigned char>^ encryptData = encrypter.Encrypt(dataFormFile);
							array<unsigned char>^ dataAndHash = gcnew array<unsigned char>(keyHash->Length + encryptData->Length);

							encryptData->CopyTo(dataAndHash, 0);
							keyHash->CopyTo(dataAndHash, encryptData->Length);

							File::WriteAllBytes(file, dataAndHash);

							show_data->AppendText("Файл: " + Path::GetFileName(file) + " - Зашифровано!\n");

						}
						else
						{
							show_data->AppendText("Файл: " + Path::GetFileName(file) + " - Помилка: файл вже зашифрований цим ключем!\n");
						}
					}
					else
					{
						array<unsigned char>^ encryptData = encrypter.Encrypt(dataFormFile);
						array<unsigned char>^ dataAndHash = gcnew array<unsigned char>(keyHash->Length + encryptData->Length);

						encryptData->CopyTo(dataAndHash, 0);
						keyHash->CopyTo(dataAndHash, encryptData->Length);

						File::WriteAllBytes(file, dataAndHash);

						show_data->AppendText("Файл: " + Path::GetFileName(file) + " - Зашифровано!\n");
					}
					i++;
				}
			}
			else
			{
				CustomMsgBox Msg("Потрібно вказати Файл(и)");
			}
		}
		else
		{
			CustomMsgBox Msg("Максимальна довжина ключа - " + maxKeyLength + " символів");
		}
	}
	else
	{
		CustomMsgBox Msg("Потрібно визначити ключ");
	}
}

System::Void Form1::decrypt_data_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (show_RC4_key->TextLength > 0 && show_RC4_key->Text != "Перемістіть файл з ключем у цю область")
	{
		if (show_RC4_key->TextLength <= maxKeyLength)
		{
			if (filesData[0] != nullptr)
			{
				Encoding^ ucode = Encoding::Unicode;
				MD5^ md5Hash = MD5::Create();
				array<unsigned char>^ keyHash = md5Hash->ComputeHash(ucode->GetBytes(show_RC4_key->Text));
				int i = 0;

				for each(String^ file in filesData)
				{
					RC4 decrypter(ucode->GetBytes(show_RC4_key->Text));
					if (maxFiles == i || !file)
					{
						break;
					}
					array<unsigned char>^ dataFormFile = File::ReadAllBytes(file);

					if (dataFormFile->Length >= 16)
					{
						array<unsigned char>^ hashFromFile = gcnew array<unsigned char>(16);
						System::Array::Copy(dataFormFile, (dataFormFile->Length - 16), hashFromFile, 0, 16);

						if (ucode->GetString(keyHash) == ucode->GetString(hashFromFile))
						{
							System::Array::Resize(dataFormFile, (dataFormFile->Length - 16));

							File::WriteAllBytes(file, decrypter.Decrypt(dataFormFile));

							show_data->AppendText("Файл: " + Path::GetFileName(file) + " - Розшифровано!\n");
						}
						else
						{
							show_data->AppendText("Файл: " + Path::GetFileName(file) + " - Помилка: невірно заданий ключ або файл незашифрований!\n");
						}
					}
					else
					{
						show_data->AppendText("Файл: " + Path::GetFileName(file) + " - Помилка: файл незашифрований!\n");
					}
					i++;
				}
			}
			else
			{
				CustomMsgBox Msg("Потрібно вказати файл(и)");
			}
		}
		else
		{
			CustomMsgBox Msg("Максимальна довжина ключа - " + maxKeyLength + " символів");
		}
	}
	else
	{
		CustomMsgBox Msg("Потрібно визначити ключ");
	}
}

System::Void Form1::save_RC4_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (show_RC4_key->Text != "" && show_RC4_key->Text != "Перемістіть файл з ключем у цю область")
	{
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		sfd->Filter = "Text File|*.txt";
		sfd->FileName = "RC4_Key";
		sfd->Title = "Збереження RC4 ключа";

		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
			sw->Write(show_RC4_key->Text);
			sw->Close();
		}
	}
	else
	{
		CustomMsgBox Msg("Потрібно визначити ключ");
	}
}

System::Void Form1::crypt_decrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (true == canCryptDecrypt)
	{
		crypt_decrypt_RC4_key->BackColor = System::Drawing::Color::FromArgb(255, 224, 224, 224);
		crypt_decrypt_RC4_key->ForeColor = System::Drawing::Color::FromArgb(255, 35, 35, 35);
		crypt_decrypt_RC4_key->Text = "Шифрування ключа: Активовано";
		timer1->Start();
	}
	else
	{
		crypt_decrypt_RC4_key->BackColor = System::Drawing::Color::FromArgb(255, 35, 35, 35);
		crypt_decrypt_RC4_key->ForeColor = System::Drawing::Color::FromArgb(255, 224, 224, 224);
		crypt_decrypt_RC4_key->Text = "Шифрування ключа: Деактивовано";
		timer1->Start();
	}
}

System::Void Form1::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if (Hidden)
	{
		panelSlider->Width = panelSlider->Width + 25;
		if (panelSlider->Width >= panelWidth)
		{
			timer1->Stop();
			canCryptDecrypt = true;
			Hidden = false;
			this->Refresh();
		}
	}
	else
	{
		panelSlider->Width = panelSlider->Width - 25;
		if (panelSlider->Width <= 0)
		{
			timer1->Stop();
			canCryptDecrypt = false;
			Hidden = true;
			this->Refresh();
		}
	}
}

String^ get_ext(String^ st)
{
	size_t pos = st->IndexOf('.');
	if (pos <= 0)
	{
		return "";
	}
	else
	{
		return st->Substring(pos+1);
	}
}

System::Void Form1::show_data_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	e->Effect = DragDropEffects::All;
}

System::Void Form1::show_data_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	Encoding^ ucode = Encoding::Unicode;

	show_data->Clear();
	show_data->ForeColor = Color::Black;
	show_data->TextAlign = HorizontalAlignment::Left;
	show_data->Font = gcnew System::Drawing::Font("Century Gothic", 10);
	for (int i = 0; i < maxFiles; i++)
	{
		filesData[i] = nullptr;
	}

	array<String^>^ filePath = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);

	int i = 0;

	for each (String^ file in filePath)
	{
		if (maxFiles == i)
		{
			CustomMsgBox Msg("Привищено максимальну кількість файлів(100 шт), були вибрані тільки перші 100 файлів!");
			break;
		}
		show_data->AppendText(Path::GetFileName(file) + "\n");
		filesData[i] = file;
		i++;
	}
}

System::Void Form1::show_RC4_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	e->Effect = DragDropEffects::All;
}

System::Void Form1::show_RC4_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	array<String^>^ filePath = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	keyExt = get_ext(filePath[0]);

	if ("txt" == keyExt)
	{
		StreamReader^ sr = File::OpenText(filePath[0]);
		String^ tempRC4_key = sr->ReadToEnd();
		sr->Close();

		if (tempRC4_key->Length <= 0)
		{
			CustomMsgBox Msg("Файл не містить даних");
		}
		else
		{
			RC4_key = tempRC4_key;
			show_RC4_key->Clear();
			show_RC4_key->AppendText(RC4_key);
			show_RC4_key->ForeColor = Color::Black;
			show_RC4_key->TextAlign = HorizontalAlignment::Left;
			show_RC4_key->Font = gcnew System::Drawing::Font("Century Gothic", 10);
		}
	}
	else
	{
		CustomMsgBox Msg("Ключ повинен бути у форматі - .txt");
	}
}

System::Void Form1::clean_data_Click(System::Object^  sender, System::EventArgs^  e)
{
	show_data->Clear();
	show_data->AppendText("Перемістіть вибрані файли у цю область");
	show_data->ForeColor = Color::Gray;
	show_data->TextAlign = HorizontalAlignment::Center;
	show_data->Font = gcnew System::Drawing::Font("Century Gothic", 12);
	for (int i = 0; i < maxFiles; i++)
	{
		filesData[i] = nullptr;
	}
}

System::Void Form1::label3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	TogMove = 1;
	MValX = e->X;
	MValY = e->Y;
}

System::Void Form1::label3_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (TogMove == 1)
	{
		this->SetDesktopLocation(MousePosition.X - MValX, MousePosition.Y - MValY);
	}
}

System::Void Form1::label3_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	TogMove = 0;
}

System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}

System::Void Form1::show_RC4_key_Enter(System::Object^  sender, System::EventArgs^  e)
{
	if (show_RC4_key->Text == "Перемістіть файл з ключем у цю область")
	{
		show_RC4_key->Text = "";
		show_RC4_key->ForeColor = Color::Black;
		show_RC4_key->TextAlign = HorizontalAlignment::Left;
		show_RC4_key->Font = gcnew System::Drawing::Font("Century Gothic", 10);
	}
}

System::Void Form1::show_RC4_key_Leave(System::Object^  sender, System::EventArgs^  e)
{
	if (show_RC4_key->Text == "")
	{
		show_RC4_key->Text = const_cast<String^>("Перемістіть файл з ключем у цю область");
		show_RC4_key->ForeColor = Color::Gray;
		show_RC4_key->TextAlign = HorizontalAlignment::Center;
		show_RC4_key->Font = gcnew System::Drawing::Font("Century Gothic", 12);
	}
}

System::Void Form1::show_data_Enter(System::Object^  sender, System::EventArgs^  e)
{
	if (show_data->Text == "Перемістіть вибрані файли у цю область")
	{
		show_data->Text = "";
		show_data->ForeColor = Color::Black;
		show_data->TextAlign = HorizontalAlignment::Left;
		show_data->Font = gcnew System::Drawing::Font("Century Gothic", 10);
	}
}

System::Void Form1::show_data_Leave(System::Object^  sender, System::EventArgs^  e)
{
	if (show_data->Text == "")
	{
		show_data->Text = "Перемістіть вибрані файли у цю область";
		show_data->ForeColor = Color::Gray;
		show_data->TextAlign = HorizontalAlignment::Center;
		show_data->Font = gcnew System::Drawing::Font("Century Gothic", 12);
	}
}

System::Void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->WindowState = FormWindowState::Minimized;
}

System::Void Form1::generate_RSA_keys_Click(System::Object^  sender, System::EventArgs^  e)
{
	FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
	fbd->Description = "Вибір директорії в яку будуть збережені згенеровані RSA ключі";
	if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider(2048);

		String^ fileName = fbd->SelectedPath + "\\MyPublicRSAKey.rsa";
		StreamWriter^ sw = gcnew StreamWriter(fileName);
		sw->Write(rsa->ToXmlString(false));
		sw->Close();

		fileName = fbd->SelectedPath + "\\MyPrivateRSAKey.rsa";
		sw = gcnew StreamWriter(fileName);
		sw->Write(rsa->ToXmlString(true));
		sw->Close();

		CustomMsgBox Msg("Відкритий та закритий ключі успішно згенеровані та збережені у вибрану директорію");
	}
}

System::Void Form1::select_public_RSA_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "Text File|*.rsa";
	ofd->Title = "Вибір файлу з відкритим RSA ключем";

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamReader^ sr = File::OpenText(ofd->FileName);
		String^ tempPublicRSA_key = sr->ReadToEnd();
		sr->Close();

		RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider(2048);
		rsa->FromXmlString(tempPublicRSA_key);

		if (rsa->PublicOnly)
		{
			select_public_RSA_key->BackColor = System::Drawing::Color::LightGreen;
			select_public_RSA_key->ForeColor = System::Drawing::Color::Black;
			publicRSA_key = tempPublicRSA_key;
		}
		else
		{
			CustomMsgBox Msg("Закритий ключ неможе слугувати для шифрування");
			select_public_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			select_public_RSA_key->ForeColor = System::Drawing::Color::White;
			publicRSA_key = "";
		}
	}
}

System::Void Form1::select_private_RSA_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "Text File|*.rsa";
	ofd->Title = "Вибір файлу з закритим RSA ключем";

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamReader^ sr = File::OpenText(ofd->FileName);
		String^ tempPrivateRSA_key = sr->ReadToEnd();
		sr->Close();

		RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider(2048);
		rsa->FromXmlString(tempPrivateRSA_key);

		if (!rsa->PublicOnly)
		{
			select_private_RSA_key->BackColor = System::Drawing::Color::LightGreen;
			select_private_RSA_key->ForeColor = System::Drawing::Color::Black;
			privateRSA_key = tempPrivateRSA_key;
		}
		else
		{
			CustomMsgBox Msg("Відкритий ключ не може слугувати для розшифровування");
			select_private_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			select_private_RSA_key->ForeColor = System::Drawing::Color::White;
			privateRSA_key = "";
		}
	}
}

System::Void Form1::encrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (show_RC4_key->Text->Length <= 0 || "Перемістіть файл з ключем у цю область" == show_RC4_key->Text)
	{
		CustomMsgBox Msg("Потрібно визначити ключ");
	}
	else
	{
		if (publicRSA_key->Length > 0)
		{
			if (show_RC4_key->Text->Length > 40)
			{
				CustomMsgBox Msg("Ключ перевищює максимальну довжину в 40 символів або вже зашифрований");
			}
			else
			{
				Encoding^ ucode = Encoding::Unicode;
				MD5^ md5Hash = MD5::Create();
				RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider(2048);
				rsa->FromXmlString(publicRSA_key);

				array<unsigned char>^ keyHash = md5Hash->ComputeHash(ucode->GetBytes(publicRSA_key));
				array<unsigned char>^ RSA_encrypt_data = rsa->Encrypt(ucode->GetBytes(show_RC4_key->Text), true);
				array<unsigned char>^ keyAndRSAHash = gcnew array<unsigned char>(keyHash->Length + RSA_encrypt_data->Length);

				RSA_encrypt_data->CopyTo(keyAndRSAHash, 0);
				keyHash->CopyTo(keyAndRSAHash, RSA_encrypt_data->Length);

				show_RC4_key->Text = Convert::ToBase64String(keyAndRSAHash);
				canDecrypt = true;
			}
		}
		else
		{
			CustomMsgBox Msg("Потрібно визначити відкритий ключ");
		}
	}
}

System::Void Form1::decrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (show_RC4_key->Text->Length <= 0 || "Перемістіть файл з ключем у цю область" == show_RC4_key->Text)
	{
		CustomMsgBox Msg("Потрібно визначити ключ");
	}
	else
	{
		if (privateRSA_key->Length > 0)
		{
			if (canDecrypt == true)
			{
				if (show_RC4_key->Text->Length < 40)
				{
					CustomMsgBox Msg("Ключ не зашифрований");
				}
				else
				{
					Encoding^ ucode = Encoding::Unicode;
					MD5^ md5Hash = MD5::Create();
					RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider(2048);
					rsa->FromXmlString(privateRSA_key);

					String^ tempPublicRSA_key = rsa->ToXmlString(false);

					array<unsigned char>^ keyHash = md5Hash->ComputeHash(ucode->GetBytes(tempPublicRSA_key));
					array<unsigned char>^ keyAndRSAHash = Convert::FromBase64String(show_RC4_key->Text);

					array<unsigned char>^ rsaHash = gcnew array<unsigned char>(16);
					System::Array::Copy(keyAndRSAHash, (keyAndRSAHash->Length - 16), rsaHash, 0, 16);

					if (ucode->GetString(keyHash) == ucode->GetString(rsaHash))
					{
						System::Array::Resize(keyAndRSAHash, (keyAndRSAHash->Length - 16));

						array<unsigned char>^ RSA_decrypt_data = rsa->Decrypt(keyAndRSAHash, true);

						show_RC4_key->Text = ucode->GetString(RSA_decrypt_data);
						canDecrypt = false;
					}
					else
					{
						CustomMsgBox Msg("Невірний закритий ключ або ключ не зашифрований");
						select_private_RSA_key->BackColor = System::Drawing::Color::Firebrick;
						select_private_RSA_key->ForeColor = System::Drawing::Color::White;
						privateRSA_key = "";
						canDecrypt = true;
					}
				}
			}
			else
			{
				CustomMsgBox Msg("Ключ вже розшифровано");
			}
		}
		else
		{
			CustomMsgBox Msg("Потрібно визначити закритий ключ");
		}
	}
}

System::Void Form1::select_public_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	e->Effect = DragDropEffects::All;
}

System::Void Form1::select_public_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	array<String^>^ filePath = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);

	if ("rsa" == get_ext(filePath[0]))
	{
		StreamReader^ sr = File::OpenText(filePath[0]);
		String^ tempPublicRSA_key = sr->ReadToEnd();
		sr->Close();

		RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider(2048);
		rsa->FromXmlString(tempPublicRSA_key);

		if (rsa->PublicOnly)
		{
			select_public_RSA_key->BackColor = System::Drawing::Color::LightGreen;
			select_public_RSA_key->ForeColor = System::Drawing::Color::Black;
			publicRSA_key = tempPublicRSA_key;
		}
		else
		{
			CustomMsgBox Msg("Закритий ключ неможе слугувати для шифрування");
			select_public_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			select_public_RSA_key->ForeColor = System::Drawing::Color::White;
			publicRSA_key = "";
		}
	}
	else
	{
		CustomMsgBox Msg("Ключ повинен бути у форматі - .rsa");
	}
}

System::Void Form1::select_private_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	e->Effect = DragDropEffects::All;
}

System::Void Form1::select_private_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	array<String^>^ filePath = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);

	if ("rsa" == get_ext(filePath[0]))
	{
		StreamReader^ sr = File::OpenText(filePath[0]);
		String^ tempPrivateRSA_key = sr->ReadToEnd();
		sr->Close();

		RSACryptoServiceProvider^ rsa = gcnew RSACryptoServiceProvider(2048);
		rsa->FromXmlString(tempPrivateRSA_key);

		if (!rsa->PublicOnly)
		{
			select_private_RSA_key->BackColor = System::Drawing::Color::LightGreen;
			select_private_RSA_key->ForeColor = System::Drawing::Color::Black;
			privateRSA_key = tempPrivateRSA_key;
		}
		else
		{
			CustomMsgBox Msg("Відкритий ключ не може слугувати для розшифровування ключа!");
			select_private_RSA_key->BackColor = System::Drawing::Color::Firebrick;
			select_private_RSA_key->ForeColor = System::Drawing::Color::White;
			privateRSA_key = "";
		}
	}
	else
	{
		CustomMsgBox Msg("Ключ повинен бути у форматі - .rsa");
	}
}