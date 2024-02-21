#pragma once

#include"Core.h"
#include"Window.h"
#include"Events/ApplicationEvent.h"
#include"LayerStack.h"
#include"Layer.h"

namespace NTN
{
	class NTN_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& e);


		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);

	private:		
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

