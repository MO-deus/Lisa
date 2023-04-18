
#pragma once

#ifdef GRIM_CORE_WINDOW_PLATFORM

extern Grim::Application* Grim::CreateApplication();

int main(int argc, int** argv)
{
	Grim::Log::Init();
	GRIM_CORE_WARN("Grimoire Summoned");
	GRIM_CLIENT_INFO("Welcome to Lisa.... ");

	auto obj = Grim::CreateApplication();
	obj->Game_loop();
	delete obj; 
}

#endif GRIM_CORE_WINDOW_PLATFORM