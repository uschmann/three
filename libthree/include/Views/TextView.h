#ifndef THREE_TEXT_VIEW
#define THREE_TEXT_VIEW


using namespace std;

class TextView:public View {
public:
    TextView();
    
    virtual void onDraw(SDL_Surface *surface);
    virtual void onMeasure(int x, int y, int width, int height);
    
    void setText(string *text);
    void setText(const char *text);
    // void setFont(sftd_font *font);
    void setTextColor(int textColor);
    void setTextSize(int textSize);
    void preventLineBreak(bool prevent);
    
    std::string getText();
    
protected:
    string *text;
    // sftd_font *font;
    int textColor;
    int textSize;
    bool isMultiline;
};

#endif