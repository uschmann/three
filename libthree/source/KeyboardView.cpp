/*
 * KeyboardView.cpp
 *
 *  Created on: 04.01.2016
 *      Author: andreuschmann
 */
#include "three.h"

KeyboardView::KeyboardView():VerticalLayout() {

	mFirstRow = new ViewGroup();
	mFirstRow->setWidth(VIEW_FILL_PARENT);
	mFirstRow->setHeight(VIEW_FILL_PARENT);
	mFirstRow->setBackgroundColor(0xaa0000ff);
	createButton("1", mFirstRow);
	createButton("2", mFirstRow);
	createButton("3", mFirstRow);
	createButton("4", mFirstRow);
	createButton("5", mFirstRow);
	createButton("6", mFirstRow);
	createButton("7", mFirstRow);
	createButton("8", mFirstRow);
	createButton("9", mFirstRow);
	createButton("0", mFirstRow);
	addChild(mFirstRow);

	mSecondRow = new ViewGroup();
	/*mSecondRow = new HorizontalLayout();
	mSecondRow->setWidth(VIEW_FILL_PARENT);
	mSecondRow->setHeight(VIEW_FILL_PARENT);
	mSecondRow->setBackgroundColor(0xaa0000ff);
	createButton("q", mSecondRow);
	createButton("w", mSecondRow);
	createButton("e", mSecondRow);
	createButton("r", mSecondRow);
	createButton("t", mSecondRow);
	createButton("z", mSecondRow);
	createButton("u", mSecondRow);
	createButton("i", mSecondRow);
	createButton("o", mSecondRow);
	createButton("p", mSecondRow);
	addChild(mSecondRow);*/
}

void KeyboardView::createButton(const char *c, ViewGroup *container) {
	return;
	Button *button = new Button();
	button->setWidth(30);
	button->setHeight(30);
	button->setText(c);
	button->setClickListener(this);
	container->addChild(button);
}

bool KeyboardView::onClick(View *view) {
	Button *button = (Button*)view;
	Log::printf("Click: %s", button->getText());
	return true;
}
