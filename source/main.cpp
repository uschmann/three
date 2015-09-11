#include "three.h"

extern "C" {
    u32 __stacksize__ = 0x40000;
}

int main()
{
    App *app = App::getInstance();
    app->startController(new DefaultController());
    app->run(); // This will run the main loop
	return 0;
}
