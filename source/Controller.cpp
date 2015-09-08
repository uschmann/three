#include "three.h"

void Controller::onCreate(App *app) {
    this->app = app;
}

void Controller::onFrame() {
}

App *Controller::getApp() {
    return this->app;
}

void Controller::setBottomContentView(View *view) {
    getApp()->getBottomScreen()->setContentView(view);
}

void Controller::setTopContentView(View *view) {
    getApp()->getTopScreen()->setContentView(view);
}