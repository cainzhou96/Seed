#pragma once

#ifdef SD_PLATFORM_WINDOWS

extern Seed::Application* Seed::createApplication(); 

int main(int argc, char** argv) {
	printf("engine starts\n"); 
	auto app = Seed::createApplication(); 
	app->run(); 
	delete app; 
}

#endif
