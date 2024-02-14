#pragma once


#ifdef NTN_PLATFORM_WINDOWS

extern NTN::Application* NTN::CreateApplication();

int main(int argc, char** argv)
{
	NTN::Log::Init();
	NTN_CORE_INFO("Hi from NTN Engine!");
	NTN_CLIENT_ERROR("Hi from Sandbox Client side!");

	auto app = NTN::CreateApplication();
	app->Run();
	delete app;
}
#endif