#include "three.h"

using namespace std;

TextView::TextView():View() {
    this->textSize = 16;
    this->textColor = 0xFFFFFFFF;
    this->isMultiline = true;
    this->width = VIEW_FILL_PARENT;
    this->height = VIEW_WRAP_CONTENT;
    this->x = 0;
    this->y = 0;
    setPadding(0);
}

void TextView::onMeasure(int x, int y, int width, int height) {
    View::onMeasure(x, y, width, height);
    if(this->height == VIEW_WRAP_CONTENT) {
        int charsPerLine = this->measuredWidth / (this->textSize/2);
        std::vector<std::string> lines = this->split(*this->text, charsPerLine);
        if(lines.size() == 0 || this->isMultiline == false) {
            this->measuredHeight = this->textSize + this->paddingBottom + this->paddingTop;
        }
        else {
            this->measuredHeight = lines.size() * this->textSize + this->paddingBottom + this->paddingTop;
        }
    }
}

void TextView::onDraw(gfxScreen_t screen, gfx3dSide_t side) {
    View::onDraw(screen, side);
    if(this->isMultiline) {
        int charsPerLine = (this->measuredWidth - this->paddingLeft - this->paddingRight) / (this->textSize/2);
        std::vector<std::string> lines = this->split(*this->text, charsPerLine);
        for(u32 i=0; i<lines.size(); i++) {
            sftd_draw_textf(this->font, this->measuredX + this->paddingLeft, this->measuredY + this->paddingTop + (this->textSize * i), this->textColor, this->textSize, lines[i].c_str());
        }
    }
    else {
        sftd_draw_textf(this->font, this->measuredX + this->paddingLeft, this->measuredY + this->paddingTop, this->textColor, this->textSize, this->text->c_str());
    }
}

void TextView::setText(const char *text) {
    this->text = new string(text);
}

void TextView::setText(string *text) {
    this->text = text;
}

void TextView::setFont(sftd_font *font) {
    this->font = font;
}

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

std::vector<std::string> TextView::split(const std::string& str, int splitLength)
{
    int NumSubstrings = str.length() / splitLength;
    std::vector<std::string> ret;
    
    for (auto i = 0; i < NumSubstrings; i++)
    {
        ret.push_back(str.substr(i * splitLength, splitLength));
    }
    
    // If there are leftover characters, create a shorter item at the end.
    if (str.length() % splitLength != 0)
    {
        ret.push_back(str.substr(splitLength * NumSubstrings));
    }
    
    
    return ret;
}