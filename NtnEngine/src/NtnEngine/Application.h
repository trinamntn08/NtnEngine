#pragma once

#include"Core.h"

namespace NTN
{
	class NTN_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

	};

	Application* CreateApplication();

}

