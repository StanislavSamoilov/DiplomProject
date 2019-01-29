#include "Form1.h"
#include "Form2.h"
#include "CustomMsgBox.h"

using namespace CryptoProgram;

String^ get_extRSA(String^ st);

System::Void Form2::generate_RSA_keys_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void Form2::select_public_RSA_key_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void Form2::select_private_RSA_key_Click(System::Object^  sender, System::EventArgs^  e)
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

System::Void Form2::encrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (publicRSA_key->Length > 0)
	{
		if (RC4_key_for_encrypt->Length > 40)
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
			array<unsigned char>^ RSA_encrypt_data = rsa->Encrypt(ucode->GetBytes(RC4_key_for_encrypt), true);
			array<unsigned char>^ keyAndRSAHash = gcnew array<unsigned char>(keyHash->Length + RSA_encrypt_data->Length);

			RSA_encrypt_data->CopyTo(keyAndRSAHash, 0);
			keyHash->CopyTo(keyAndRSAHash, RSA_encrypt_data->Length);

			Form1^ main = dynamic_cast<Form1^>(Owner);
			if (main != nullptr)
			{
				main->show_RC4_key->Clear();
				main->show_RC4_key->AppendText(Convert::ToBase64String(keyAndRSAHash));
			}

			RC4_key_for_encrypt = Convert::ToBase64String(keyAndRSAHash);
			canDecrypt = true;
		}
	}
	else
	{
		CustomMsgBox Msg("Потрібно визначити відкритий ключ");
	}
}

System::Void Form2::Form2_Load(System::Object^  sender, System::EventArgs^  e)
{
	Form1^ main = dynamic_cast<Form1^>(Owner);
	if (main != nullptr)
	{
		RC4_key_for_encrypt = main->show_RC4_key->Text;
	}
}

System::Void Form2::decrypt_RC4_key_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (privateRSA_key->Length > 0)
	{
		if (canDecrypt == true)
		{
			if (RC4_key_for_encrypt->Length < 40)
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
				array<unsigned char>^ keyAndRSAHash = Convert::FromBase64String(RC4_key_for_encrypt);

				array<unsigned char>^ rsaHash = gcnew array<unsigned char>(16);
				System::Array::Copy(keyAndRSAHash, (keyAndRSAHash->Length - 16), rsaHash, 0, 16);

				if (ucode->GetString(keyHash) == ucode->GetString(rsaHash))
				{
					System::Array::Resize(keyAndRSAHash, (keyAndRSAHash->Length - 16));

					array<unsigned char>^ RSA_decrypt_data = rsa->Decrypt(keyAndRSAHash, true);

					Form1^ main = dynamic_cast<Form1^>(Owner);
					if (main != nullptr)
					{
						main->show_RC4_key->Clear();
						main->show_RC4_key->AppendText(ucode->GetString(RSA_decrypt_data));
					}

					RC4_key_for_encrypt = ucode->GetString(RSA_decrypt_data);
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

System::Void Form2::select_public_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	e->Effect = DragDropEffects::All;
}

System::Void Form2::select_public_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	array<String^>^ filePath = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);

	if ("rsa" == get_extRSA(filePath[0]))
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

System::Void Form2::select_private_RSA_key_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	e->Effect = DragDropEffects::All;
}

System::Void Form2::select_private_RSA_key_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	array<String^>^ filePath = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);

	if ("rsa" == get_extRSA(filePath[0]))
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

System::Void Form2::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form::Close();
}

System::Void Form2::label1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	TogMove = 1;
	MValX = e->X;
	MValY = e->Y;
}

System::Void Form2::label1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (TogMove == 1)
	{
		this->SetDesktopLocation(MousePosition.X - MValX, MousePosition.Y - MValY);
	}
}

System::Void Form2::label1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	TogMove = 0;
}

String^ get_extRSA(String^ st)
{
	size_t pos = st->IndexOf('.');
	if (pos <= 0)
	{
		return "";
	}
	else
	{
		return st->Substring(pos + 1);
	}
}