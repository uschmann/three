#pragma once

#define VIEW_FILL_PARENT -1
#define VIEW_WRAP_CONTENT -2

/**
 * Base class for all Views
 */
class View {
public:
    View();
    View(int x, int y, int width, int height, int backgroundColor);
    
    /**
     * @brief Will be called when the view needs to measure it´s dimensions.
     * @param int x The x position of the parent element.
     * @param int y The y position of the parent element.
     * @param int width The maximum width the View should take.
     * @param int height The maximum height the View should take.
     */
    virtual void onMeasure(int x, int y, int width, int height);
    virtual void onLayout(int offsetX, int offsetY);
    virtual void onDraw(gfxScreen_t screen, gfx3dSide_t side);
    
    void setTouchDownListener(TouchDownListener *listener);
    void setTouchUpListener(TouchUpListener *listener);
    void setTouchMoveListener(TouchMoveListener *listener);
    
    virtual bool onTouchDown(touchPosition *touch);
    virtual bool onTouchUp(touchPosition *touch);
    virtual bool onTouchMove(touchPosition *touch, int deltaX, int deltaY);
    
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setBackgroundColor(int backgroundColor);
    void setBorderColor(int color);
    void setBorderColor(int colorTop, int colorRight, int colorBottom, int colorLeft);
    void setBorderWidth(int width);
    void setBorderWidth(int widthTop, int widthRight, int widthBottom, int widthLeft);
    void setPadding(int padding);
    void setPadding(int paddingTop, int paddingRight, int paddingBottom, int paddingLeft);
    void setRotation(int rotation);
    void setBackgroundImage(NinePatch *image);
    void setBackgroundImageTint(int tint);
    
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getBackgroundColor();
    int getMeasuredWidth();
    int getMeasuredHeight();
    
    /** The x-position that was calculated after measurement.*/
    int measuredX;
    /** The y-position that was calculated after measurement.*/
    int measuredY;
protected:
    int x;
    int y;
    int width;
    int height;
    int measuredWidth;
    int measuredHeight;
    int backgroundColor;
    int borderTopWidth;
    int borderRightWidth;
    int borderBottomWidth;
    int borderLeftWidth;
    int borderTopColor;
    int borderRightColor;
    int borderBottomColor;
    int borderLeftColor;
    int paddingTop;
    int paddingRight;
    int paddingBottom;
    int paddingLeft;
    float rotation;
    NinePatch *backgroundNinePatch;
    int backgroundImageTint;
    
    TouchDownListener *touchDownListener;
    TouchUpListener *touchUpListener;
    TouchMoveListener *touchMoveListener;
    
    bool isTouched(touchPosition *touch);
};
