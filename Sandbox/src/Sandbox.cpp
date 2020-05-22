#include "mgpch.h"
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
	MG_INFO("Info log");
	return new Sandbox();
}