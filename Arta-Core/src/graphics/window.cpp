#include "window.h"

namespace Arta {
	namespace Graphics {

		void window_resize(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int modes);


		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();
		
			INSTANCE = this;
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::update()
		{
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			//glViewport(0, 0, m_Width, m_Height) ;
			glfwSwapBuffers(m_Window);
		}

		

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::init()
		{
			if (!glfwInit()) {
				std::cout << "Failed to Initialize" << std::endl;
				return false;
			}


			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				glfwTerminate(); 
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, window_resize);

			// GLEW
			if (glewInit() != GLEW_OK)
			{
				std::cout << "could not init glew!\n";
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;


			return true;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void window_resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int modes)
		{
		}

	}
}