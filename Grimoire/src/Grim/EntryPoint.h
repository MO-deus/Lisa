
#pragma once

#ifdef GRIM_CORE_WINDOW_PLATFORM

extern Grim::Application* Grim::CreateApplication();

int main(int argc, int** argv)
{
	Grim::Log::Init();
	GRIM_CORE_ERROR("Grimoire Summoned");
	int a = 2;
	GRIM_CLIENT_INFO("Welcome to Lisa.... Var = {0}", a);

	auto obj = Grim::CreateApplication();
	obj->Game_loop();
	delete obj; 
}

#endif GRIM_CORE_WINDOW_PLATFORM