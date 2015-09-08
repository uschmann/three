#ifndef THREE_SCREEN
#define THREE_SCREEN

class Screen {
public:
    Screen();
    
    virtual void setContentView(View *view);
    virtual void update();
    
protected:
    View *contentView;
    
    void drawContentView();
};

#endif