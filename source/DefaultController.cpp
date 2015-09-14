#include "three.h"

#include "FreeSans_ttf.h"
#include "3dbrew_png.h"

void DefaultController::onCreate(App *app) {
    Controller::onCreate(app);
    
    //getApp()->getAssetManager()->loadTexture("android", "sdmc://android.png");
    //getApp()->getAssetManager()->loadTexture("dices", "sdmc://dices.png");
    getApp()->getAssetManager()->loadFont("font", "sdmc://FreeSans.ttf");
    
    scrollView = new ScrollView();
    scrollView->setWidth(VIEW_FILL_PARENT);
    scrollView->setHeight(VIEW_FILL_PARENT);
    scrollView->setOverflowHidden(false);
    
    mainLayout = new VerticalLayout();
    mainLayout->setWidth(VIEW_FILL_PARENT);
    mainLayout->setHeight(VIEW_WRAP_CONTENT);
    mainLayout->setBackgroundColor(0xFFFFFFFF);
    
    View *button = new View();
    button->setBackgroundImage(getApp()->getAssetManager()->getNinePatch("button"));
    button->setWidth(VIEW_FILL_PARENT);
    button->setHeight(100);
    mainLayout->addChild(button);
    
    HorizontalLayout *row = new HorizontalLayout();
    row->setWidth(VIEW_FILL_PARENT);
    row->setHeight(VIEW_WRAP_CONTENT);
    
    button = new View();
    button->setBackgroundImage(getApp()->getAssetManager()->getNinePatch("button"));
    button->setWidth(100);
    button->setHeight(100);
    button->setBackgroundImageTint(0xFF0000FF);
    row->addChild(button);
    button = new View();
    button->setBackgroundImage(getApp()->getAssetManager()->getNinePatch("button"));
    button->setWidth(100);
    button->setHeight(100);
    button->setBackgroundImageTint(0x00FF00FF);
    row->addChild(button);
    button = new View();
    button->setBackgroundImage(getApp()->getAssetManager()->getNinePatch("button"));
    button->setWidth(100);
    button->setHeight(100);
    button->setBackgroundImageTint(0x0000FFFF);
    row->addChild(button);
    mainLayout->addChild(row);
    
    button = new View();
    button->setBackgroundImage(getApp()->getAssetManager()->getNinePatch("button"));
    button->setWidth(VIEW_FILL_PARENT);
    button->setHeight(400);
    button->setBackgroundImageTint(0xFF0000FF);
    mainLayout->addChild(button);
    
    scrollView->addChild(mainLayout);
    setBottomContentView(scrollView);
    
    txtLog = new TextView();
    txtLog->setWidth(100);
    txtLog->setBackgroundImage(getApp()->getAssetManager()->getNinePatch("button"));
    txtLog->setHeight(VIEW_WRAP_CONTENT);
    txtLog->setBackgroundColor(0xaa0000FF);
    txtLog->setFont(getApp()->getAssetManager()->getFont("font"));
    txtLog->preventLineBreak(false);
    txtLog->setTextSize(16);
    txtLog->setText("Hello World! Lorem ipsum dolor sit amet.Hello World! Lorem ipsum dolor sit amet Hello World! Lorem ipsum dolor sit amet");
    setTopContentView(txtLog);
}

void DefaultController::onFrame() {

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