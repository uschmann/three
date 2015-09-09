#include "three.h"

#include "FreeSans_ttf.h"
#include "3dbrew_png.h"

void DefaultController::onCreate(App *app) {
    Controller::onCreate(app);
    
    sftd_font *font = sftd_load_font_mem(FreeSans_ttf, FreeSans_ttf_size);
    sf2d_texture *tex = sfil_load_PNG_buffer(_3dbrew_png, SF2D_PLACE_RAM);
    
    scrollView = new ScrollView();
    scrollView->setWidth(VIEW_FILL_PARENT);
    scrollView->setHeight(VIEW_FILL_PARENT);
    
    mainLayout = new VerticalLayout();
    mainLayout->setWidth(VIEW_FILL_PARENT);
    mainLayout->setHeight(VIEW_WRAP_CONTENT);
    mainLayout->setBackgroundColor(0xFF0000FF);
    
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 50, 0xFF0000FF));
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 50, 0x00FF00FF));
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 50, 0xFF0000FF));
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 50, 0x00FF00FF));
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 50, 0x00FFFFFF));
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 50, 0xFF0000FF));
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 50, 0x00FF00FF));
    
     
    scrollView->addChild(mainLayout);
    setBottomContentView(scrollView);
    
    txtLog = new TextView();
    txtLog->setWidth(VIEW_FILL_PARENT);
    txtLog->setHeight(VIEW_WRAP_CONTENT);
    txtLog->setFont(font);
    txtLog->setText("Hello World!");
    setTopContentView(txtLog);
    
    
}

void DefaultController::onFrame() {
    char buffer[100];
    sprintf(buffer, "SCROLLY: %d, H:%d, MH:%d", scrollView->getScrollY(), scrollView->getMeasuredHeight(), mainLayout->getMeasuredHeight());
    txtLog->setText(buffer);
}

bool DefaultController::onTouchDown(View *view, TouchEvent *event) {

    return true;
}

bool DefaultController::onTouchMove(View *view, TouchMoveEvent *e) {

    return true;
}

bool DefaultController::onTouchUp(View *view, TouchEvent *event) {

    return true;
}