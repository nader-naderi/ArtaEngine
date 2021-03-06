#pragma once

#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>

namespace Arta {
	namespace Graphics {

#define MAX_KEYS 1024
#define MAX_BTNS 32

		class Window
		{
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;
	
			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BTNS];
			static double m_X, m_Y;

		public:
			// Methods
			Window(const char* name, int width, int height);
			~Window();
			void update();
			bool closed() const;
			void clear() const;

			//Properties
			inline int getHeight() const { return m_Height; }
			inline int getWidth() const { return m_Width; }


		private:
			bool init();
		};
	}
}