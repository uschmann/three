#include "three.h"

void DefaultController::onCreate(App *app) {
    Controller::onCreate(app);
    
    scrollView = new ScrollView();
    scrollView->setWidth(VIEW_FILL_PARENT);
    scrollView->setHeight(VIEW_FILL_PARENT);
    scrollView->setOverflowHidden(false);
    
    mainLayout = new VerticalLayout();
    mainLayout->setWidth(VIEW_FILL_PARENT);
    mainLayout->setHeight(VIEW_FILL_PARENT);
    mainLayout->setBackgroundColor(0x111111FF);
    
    slider = new Slider();
    slider->setX(0);
    slider->setWidth(VIEW_FILL_PARENT);
    slider->setHeight(100);
    slider->setSliderChangedListener(this);
    mainLayout->addChild(slider);
    
    otherSlider = new Slider();
    otherSlider->setX(0);
    otherSlider->setColor(0xAABB00FF);
    otherSlider->setWidth(VIEW_FILL_PARENT);
    mainLayout->addChild(otherSlider);
    
    Button *button = new Button();
    button->setWidth(VIEW_FILL_PARENT);
    button->setText("Click me!");
    button->setClickListener(this);
    mainLayout->addChild(button);
    
    setBottomContentView(mainLayout);
    
    txtLog = new TextView();
    txtLog->setWidth(VIEW_FILL_PARENT);
    txtLog->setHeight(VIEW_FILL_PARENT);
    txtLog->preventLineBreak(false);
    txtLog->setPadding(20);
    txtLog->setText("Hello World! THREE now supports 9Patch-Images!");
    setTopContentView(txtLog);
    
    getApp()->getBottomScreen()->addTouchMoveListener(this);
}

void DefaultController::onFrame() {

}

bool DefaultController::onSliderChanged(Slider *slider, int value) {
    char buffer[100];
    sprintf(buffer, "Value:%d", value);
    txtLog->setText(buffer);
    otherSlider->setValue(value);
}

bool DefaultController::onTouchDown(View *view, TouchEvent *event) {
    txtLog->setText("TouchDown");
    return true;
}

bool DefaultController::onTouchMove(View *view, TouchMoveEvent *e) {
    return true;
}

bool DefaultController::onTouchUp(View *view, TouchEvent *event) {
    return true;
}

bool DefaultController::onClick(View *view) {
    txtLog->setText("CLICK");
    Log::print("Click");
    slider->setValue(50);
    return true;
}
