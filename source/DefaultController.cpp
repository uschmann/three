#include "three.h"

#include "FreeSans_ttf.h"
#include "3dbrew_png.h"

void DefaultController::onCreate(App *app) {
    Controller::onCreate(app);
    
    scrollView = new ScrollView();
    scrollView->setWidth(VIEW_FILL_PARENT);
    scrollView->setHeight(VIEW_FILL_PARENT);
    scrollView->setOverflowHidden(false);
    
    mainLayout = new VerticalLayout();
    mainLayout->setWidth(VIEW_FILL_PARENT);
    mainLayout->setHeight(VIEW_WRAP_CONTENT);
    
    Button *button = new Button();
    button->setText("Click me!");
    mainLayout->addChild(button);
    setBottomContentView(mainLayout);
    
    button = new Button();
    button->setWidth(VIEW_FILL_PARENT);
    button->setHeight(300);
    button->setText("This is another button!!!");
    button->setBackgroundColor(0x123456FF);
    
    mainLayout->addChild(button);
    scrollView->addChild(mainLayout);
    setBottomContentView(scrollView);
    
    txtLog = new TextView();
    txtLog->setWidth(VIEW_FILL_PARENT);
    txtLog->setHeight(VIEW_FILL_PARENT);
    txtLog->setBackgroundImage(getApp()->getAssetManager()->getNinePatch("button"));
    txtLog->preventLineBreak(false);
    txtLog->setTextColor(0x000000FF);
    txtLog->setBackgroundImageTint(0xFFFF00FF);
    txtLog->setPadding(20);
    txtLog->setText("Hello World! THREE now support 9Patch-Images!");
    setTopContentView(txtLog);
    
    getApp()->getBottomScreen()->addTouchMoveListener(this);
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