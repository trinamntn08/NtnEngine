#pragma once


#ifdef NTN_PLATFORM_WINDOWS

extern NTN::Application* NTN::CreateApplication();

int main(int argc, char** argv)
{
	NTN::Log::Init();
	NTN::Log::Info("Hi!");
	NTN::Log::Warning("Hi!");
	NTN::Log::Error("Hi!");

	auto app = NTN::CreateApplication();
	app->Run();
	delete app;
}
#endif