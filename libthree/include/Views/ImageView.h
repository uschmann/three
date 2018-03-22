#ifndef THREE_IMAGE
#define THREE_IMAGE

class ImageView:public View {
public:
    ImageView();
    
    virtual void onMeasure(int x, int y, int width, int height);
    virtual void onDraw(SDL_Surface *surface);
    
    // void setTexture(sf2d_texture *texture);
    void setTint(int tint);
protected:
    // sf2d_texture *texture;
    int mTint;
};

#endif