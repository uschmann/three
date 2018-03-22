//
//  Button.h
//  three
//
//  Created by Andre Uschmann on 21.09.15.
//  Copyright © 2015 Andre Uschmann. All rights reserved.
//

#ifndef THREE_Button_h
#define THREE_Button_h

#define BUTTON_STATE_DEFAULT 0
#define BUTTON_STATE_DOWN 1

#include <SDL/SDL_ttf.h>

class Button:public View, public TouchDownListener, public TouchUpListener {
public:
    Button();
    ~Button();
    
    virtual void onMeasure(int x, int y, int width, int height);
    virtual void onDraw(SDL_Surface *suface);
    virtual bool onTouchDown(View *view, TouchEvent *event);
    virtual bool onTouchUp(View *view, TouchEvent *event);
    
    void setBackgroundColorTouchDown(int backgroundColorTouchDown);
    void setText(const char *text);
    void setFont(TTF_Font * font);
    void setTextColor(Uint32 textColor);
    void setTextColorTouchDown(int textColorTouchDown);
    void setTextSize(int textSize);
    const char *getText();
    void setClickListener(ClickListener *clickListener);
protected:
    const char* mText;
    int mTextSize;
    Uint32 mTextColor;
    int mTextColorTouchDown;
    int mBackgroundColorTouchDown;
    int mState;
    TTF_Font *mFont;
    ClickListener *mClickListener;
};


#endif /* Button_h */
