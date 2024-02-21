#include"Ntn.h"

class ExampleLayer : public NTN::Layer 
{
public:
	ExampleLayer() :Layer("Example"){}

	void OnUpdate() override
	{
		NTN_CORE_INFO("Example Layer::Update");
	}

	void OnEvent(NTN::Event& event) override
	{
		NTN_CORE_INFO(event.ToString());
	}

};

class Sandbox :public NTN::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	};
	~Sandbox() {};

};

NTN::Application* NTN::CreateApplication()
{
	return new Sandbox();
}
