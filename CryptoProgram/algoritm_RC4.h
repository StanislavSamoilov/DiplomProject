public ref class RC4
{
public:
	RC4(array<unsigned char>^ key)
	{
		init(key);
	}

	array<unsigned char>^ Encrypt(array<unsigned char>^ dataB)
	{
		array<unsigned char>^ cipher = gcnew array<unsigned char>(dataB->Length);

		for (int m = 0; m < dataB->Length; m++)
		{
			cipher[m] = (unsigned char)(dataB[m] ^ keyItem());
		}

		return cipher;
	}

	array<unsigned char>^ Decrypt(array<unsigned char>^ dataB)
	{
		return Encrypt(dataB);
	}

private:

	array<unsigned char>^ S = gcnew array<unsigned char>(256);
	int x = 0;
	int y = 0;

	void init(array<unsigned char>^ key)
	{
		int keyLength = key->Length;

		for (int i = 0; i < 256; i++)
		{
			S[i] = (unsigned char)i;
		}

		int j = 0;
		for (int i = 0; i < 256; i++)
		{
			j = (j + S[i] + key[i % keyLength]) % 256;
			Swap(S, i, j);
		}
	}

	unsigned char keyItem()
	{
		x = (x + 1) % 256;
		y = (y + S[x]) % 256;

		Swap(S, x, y);

		return S[(S[x] + S[y]) % 256];
	}

	static void Swap(array<unsigned char>^ s, int i, int j)
	{
		unsigned char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
};