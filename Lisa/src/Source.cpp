
#include "Grim.h"

class Lisa : public Grim::Application
{
public :
	Lisa() {

	}
	~Lisa() {

	}
};


Grim::Application* Grim::CreateApplication()
{
	return new Lisa();
}