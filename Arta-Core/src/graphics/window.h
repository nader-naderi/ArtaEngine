#pragma once

#include <glfw3.h>

namespace Arta {
	namespace Graphics {

		class Window
		{
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;
		public:
			Window(const char* name, int width, int height);
			~Window();
			void update() const;
			bool closed() const;
		private:
			bool init();

		};
	}
}