#include <Midgar.h>

class Sandbox : public Midgar::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Midgar::Application* Midgar::CreateApplication()
{
	return new Sandbox();
}