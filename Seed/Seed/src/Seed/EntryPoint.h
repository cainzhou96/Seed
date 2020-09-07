#pragma once

#ifdef SD_PLATFORM_WINDOWS

extern Seed::Application* Seed::createApplication(); 

int main(int argc, char** argv) {
	Seed::Log::init(); 

	SD_CORE_WARN("Core Hazel");
	std::string a = "Sandbox"; 
	SD_INFO("Client {0}", a);

	auto app = Seed::createApplication(); 
	app->run(); 
	delete app; 
}

#endif
