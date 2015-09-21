#ifndef THREE_DEFAULT_CONTROLLRER
#define THREE_DEFAULT_CONTROLLRER

class DefaultController:public Controller,
public TouchDownListener, public TouchUpListener, public TouchMoveListener, public ClickListener, public SliderChangeListener {
public:
    virtual void onCreate(App *app);
    virtual void onFrame();
    
    virtual bool onTouchDown(View *view, TouchEvent *event);
    virtual bool onTouchMove(View *view, TouchMoveEvent *event);
    virtual bool onTouchUp(View *view, TouchEvent *event);
    virtual bool onClick(View *view);
    virtual bool onSliderChanged(Slider *slider, int value);
private:
    TextView *txtLog;
    VerticalLayout *mainLayout;
    ScrollView *scrollView;
};

#endif