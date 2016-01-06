/*
 * KeyboardListener.h
 *
 *  Created on: 06.01.2016
 *      Author: andreuschmann
 */

#ifndef LIBTHREE_SOURCE_KEYBOARDLISTENER_H_
#define LIBTHREE_SOURCE_KEYBOARDLISTENER_H_

class KeyboardView;

class KeyboardListener {
public:
	virtual bool onKeyPressed(KeyboardView *keyboard, const char *key);
};

#endif /* LIBTHREE_SOURCE_KEYBOARDLISTENER_H_ */
