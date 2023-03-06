#include "HomePage.h"
#include"ClientLogin.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace std;


[STAThread]
void Main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	FinalLogin::HomePage form;
	Application::Run(% form);
}