#include"Ntn.h"

class Sandbox :public NTN::Application
{
public:
	Sandbox() {};
	~Sandbox() {};

};

NTN::Application* NTN::CreateApplication()
{
	return new Sandbox();
}
