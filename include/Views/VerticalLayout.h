#ifndef THREE_VERTICAL_LAYOUT
#define THREE_VERTICAL_LAYOUT

class VerticalLayout:public ViewGroup {
protected:
    virtual void layoutChild(View *child, int position);
};

#endif