#pragma once
#include "Core.h"

namespace Seed {

	class SEED_API Application {
	public: 
		Application(); 
		virtual ~Application(); 

		void run(); 
	};

	Application* createApplication(); 
}

