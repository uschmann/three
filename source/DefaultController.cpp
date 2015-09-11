#include "three.h"

#include "FreeSans_ttf.h"
#include "3dbrew_png.h"

void DefaultController::onCreate(App *app) {
    Controller::onCreate(app);
    
    getApp()->getAssetManager()->loadTexture("android", "sdmc://android.png");
    getApp()->getAssetManager()->loadTexture("dices", "sdmc://dices.png");
    getApp()->getAssetManager()->loadFont("font", "sdmc://Pacifico.ttf");
    
    scrollView = new ScrollView();
    scrollView->setWidth(VIEW_FILL_PARENT);
    scrollView->setHeight(VIEW_FILL_PARENT);
    
    mainLayout = new VerticalLayout();
    mainLayout->setWidth(VIEW_FILL_PARENT);
    mainLayout->setHeight(VIEW_WRAP_CONTENT);
    mainLayout->setBackgroundColor(0x000000FF);
    
    

    ImageView *imageView = new ImageView();
    imageView->setWidth(100);
    imageView->setHeight(100);
    imageView->setTexture(getApp()->getAssetManager()->getTexture("android"));
    mainLayout->addChild(imageView);
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 1, 0xFFFFFFFF));
    
    imageView = new ImageView();
    imageView->setWidth(100);
    imageView->setHeight(100);
    imageView->setTexture(getApp()->getAssetManager()->getTexture("android"));
    mainLayout->addChild(imageView);
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 2, 0xFFFFFFFF));
    
    imageView = new ImageView();
    imageView->setWidth(100);
    imageView->setHeight(100);
    imageView->setTexture(getApp()->getAssetManager()->getTexture("dices"));
    mainLayout->addChild(imageView);
    mainLayout->addChild(new View(0, 0, VIEW_FILL_PARENT, 2, 0xFFFFFFFF));
    
    scrollView->addChild(mainLayout);
    setBottomContentView(scrollView);
    
    txtLog = new TextView();
    txtLog->setWidth(VIEW_FILL_PARENT);
    txtLog->setHeight(VIEW_WRAP_CONTENT);
    txtLog->setFont(getApp()->getAssetManager()->getFont("font"));
    txtLog->setTextSize(30);
    txtLog->setText("Hello World!");
    setTopContentView(txtLog);
}

void DefaultController::onFrame() {
    //char buffer[100];
    //sprintf(buffer, "SCROLLY: %d, H:%d, MH:%d", scrollView->getScrollY(), scrollView->getMeasuredHeight(), mainLayout->getMeasuredHeight());
    //txtLog->setText(buffer);
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