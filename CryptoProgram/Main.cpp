#include "Form1.h"
#include "Form2.h"

using namespace CryptoProgram;

[STAThreadAttribute]
int main(array<System::String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Form1());
	return 0;
}