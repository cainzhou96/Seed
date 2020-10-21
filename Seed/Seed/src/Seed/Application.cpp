#include "Application.h"

#include "Seed/Events/ApplicationEvent.h"
#include "Seed/Log.h"

namespace Seed {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowResizeEvent e(1280, 720); 
		if (e.isInCategory(EventCategoryApplication)) {
			SD_TRACE(e); 
		}
		if (e.isInCategory(EventCategoryInput)) {
			SD_TRACE(e); 
		}
		while (true); 
	}
}
