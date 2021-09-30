#include "Core/Application.h"


int main(int argc, char** argv)
{
	Core::Application* application = new Core::Application;
	application->Run();
	delete application;
}