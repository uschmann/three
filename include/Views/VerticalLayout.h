#ifndef THREE_VERTICAL_LAYOUT
#define THREE_VERTICAL_LAYOUT

class VerticalLayout:public ViewGroup {
public:
    virtual void onMeasure(int x, int y, int width, int height);
protected:
    virtual void layoutChild(View *child, int position);
};

#endif