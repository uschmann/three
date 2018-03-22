#ifndef THREE_SCREEN
#define THREE_SCREEN

class Screen {
public:
    Screen();
    
    virtual void setContentView(View *view);
    virtual void update();
    SDL_Surface *getSurface();
    
protected:
    View *contentView;
    SDL_Surface *surface;
    void drawContentView();
};

#endif