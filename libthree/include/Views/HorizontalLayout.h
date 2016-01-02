#ifndef THREE_HORIZONTAL_LAYOUT
#define THREE_HORIZONTAL_LAYOUT

class HorizontalLayout:public ViewGroup {
public:
    virtual void onMeasure(int x, int y, int width, int height);
protected:
    virtual void layoutChild(View *child, int position);
};

#endif