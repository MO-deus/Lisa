
#pragma once

#include "Grim_core.h"

namespace Grim {
	
class GRIM_API Application
{
	public:
		Application();

		// class will be inherited by other classes
		// virtual dest to ensure the deletion of objects created by deriving classes
		virtual ~Application();  

		void Game_loop();
		 
};

		// to be defined in the client
		Application* CreateApplication();
}

