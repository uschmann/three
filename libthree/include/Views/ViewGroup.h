#ifndef THREE_VIEW_GROUP
#define THREE_VIEW_GROUP

class ViewGroup:public View {
public:
    ViewGroup();
    
    virtual void onMeasure(int x, int y, int width, int height);
    virtual void onDraw(SDL_Surface *surface);
    virtual void addChild(View *child);
    
    int getNumberOfChildren();
    void setOverflowHidden(bool hidden);
    
    virtual bool onTouchDown(touchPosition *touch);
    virtual bool onTouchUp(touchPosition *touch);
    virtual bool onTouchMove(touchPosition *touch, int deltaX, int deltaY);
    
protected:
    std::vector<View*> children;
    bool isOverflowHidden;
    virtual void measureChild(View *child, int position);
    virtual void layoutChild(View *child, int position);
};

#endif
