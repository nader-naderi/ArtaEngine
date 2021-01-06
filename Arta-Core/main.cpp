#include <iostream>
#include <glfw3.h>
#include "src/graphics/window.h"

int main()
{
	using namespace Arta;
	using namespace Graphics;

	Window window("Arta", 800, 600);

	while (!window.closed())
	{
		window.update();
	}

	system("PUASE");
	return 0;
}