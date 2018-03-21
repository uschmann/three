#include "three.h"

using namespace std;

TextView::TextView():View() {
    this->textSize = 16;
    this->textColor = 0xFFFFFFFF;
    this->isMultiline = true;
    this->width = VIEW_WRAP_CONTENT;
    this->height = VIEW_WRAP_CONTENT;
    this->x = 0;
    this->y = 0;
    // setFont(App::getInstance()->getAssetManager()->getFont("defaultFont"));
    setPadding(0);
}

void TextView::onMeasure(int x, int y, int width, int height) {
    View::onMeasure(x, y, width, height);
    int boundingWidth = 0;
    int boundingHeight = 0;
    if(isMultiline) {
        int lineWidth = this->measuredWidth - this->paddingLeft - this->paddingRight;
        if(lineWidth < 0) {
            lineWidth = 0;
        }
        // sftd_calc_bounding_box(&boundingWidth, &boundingHeight, this->font, this->textSize, lineWidth, this->text->c_str());
    }
    else {
        // boundingWidth = sftd_get_text_width(this->font, this->textSize, (char *)this->text->c_str());
        boundingHeight = this->textSize;
    }
    if(this->height == VIEW_WRAP_CONTENT) {
        this->measuredHeight = boundingHeight + paddingTop + paddingBottom;
    }
    if(this->width == VIEW_WRAP_CONTENT) {
        this->measuredWidth = boundingWidth + paddingLeft + paddingRight;
    }
}

void TextView::onDraw(gfxScreen_t screen, gfx3dSide_t side) {
    View::onDraw(screen, side);
    if(this->isMultiline) {
        int lineWidth = this->measuredWidth - this->paddingLeft - this->paddingRight;
        if(lineWidth < 0) {
            lineWidth = 0;
        }
        // sftd_draw_text_wrap(this->font, this->measuredX + this->paddingLeft, this->measuredY + this->paddingTop, this->textColor, this->textSize, lineWidth, this->text->c_str());
    }
    else {
        // sftd_draw_text(this->font, this->measuredX + this->paddingLeft, this->measuredY + this->paddingTop, this->textColor, this->textSize, this->text->c_str());
    }
}

void TextView::setText(const char *text) {
    this->text = new string(text);
}

void TextView::setText(string *text) {
    this->text = text;
}

// void TextView::setFont(sftd_font *font) {
//     this->font = font;
// }

void TextView::setTextColor(int textColor) {
    this->textColor = textColor;
}

void TextView::setTextSize(int textSize) {
    this->textSize = textSize;
}

void TextView::preventLineBreak(bool prevent) {
    this->isMultiline = !prevent;
}

std::string TextView::getText() {
    return *this->text;
}