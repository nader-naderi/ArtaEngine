#include "src/graphics/window.h"

int main()
{
	using namespace Arta;
	using namespace Graphics;

	Window window("Arta", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	
	while (!window.closed())
	{
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();
#if 1	
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		window.update();
	}

	return 0;
}