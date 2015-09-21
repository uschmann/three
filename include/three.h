#ifndef THREE
#define THREE
#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>
#include <sftd.h>

#include <string>
#include <functional>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>

// Default assets
#include "RobotoRegular_ttf.h"

// Utils
#include "Utils/Log.h"

// Drawable
#include "Drawable/NinePatch.h"

// Services
#include "Services/AssetManager.h"

// Events
#include "Events/TouchEvent.h"
#include "Events/TouchMoveEvent.h"

// Listeners
#include "Listeners/TouchDownListener.h"
#include "Listeners/TouchMoveListener.h"
#include "Listeners/TouchUpListener.h"

// Views
#include "Views/View.h"
#include "Views/ViewGroup.h"
#include "Views/VerticalLayout.h"
#include "Views/HorizontalLayout.h"
#include "Views/ScrollView.h"
#include "Views/TextView.h"
#include "Views/ImageView.h"
#include "Views/Button.h"

// Screens
#include "Screens/Screen.h"
#include "Screens/BottomScreen.h"

// App
#include "App.h"

#include "Controllers/Controller.h"
#include "Controllers/DefaultController.h"

#endif