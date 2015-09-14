#include "three.h"

#include "button_png.h"

extern "C" {
    u32 __stacksize__ = 0x400000;
}

int main()
{
    App *app = App::getInstance();
    
    app->getAssetManager()->loadNinePatch("button", button_png);
    
    app->startController(new DefaultController());
    app->run(); // This will run the main loop
	return 0;
}
