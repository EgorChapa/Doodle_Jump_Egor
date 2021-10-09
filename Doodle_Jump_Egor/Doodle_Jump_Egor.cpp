#include <iostream>
#include "Window.h"
int main()
{
	Window* window = new Window(532, 850);

	window->show();

	delete window;
}
