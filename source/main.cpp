#include "three.h"

int main()
{
    App *app = App::getInstance();
    app->startController(new DefaultController());
    app->run(); // This will run the main loop
	return 0;
}
