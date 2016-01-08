/*
 * KeyboardView.h
 *
 *  Created on: 04.01.2016
 *      Author: andreuschmann
 */

#ifndef LIBTHREE_SOURCE_KEYBOARDVIEW_H_
#define LIBTHREE_SOURCE_KEYBOARDVIEW_H_

class KeyboardView: public VerticalLayout, public ClickListener {
public:
	KeyboardView();
	bool onClick(View *view);
	void setKeyboardListener(KeyboardListener *listener);
private:
	KeyboardListener *mKeyboadListener;
	void createLowerCase();
	void createButton(const char *c, ViewGroup *container);
};

#endif /* LIBTHREE_SOURCE_KEYBOARDVIEW_H_ */
