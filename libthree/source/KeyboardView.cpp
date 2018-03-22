/*
 * KeyboardView.cpp
 *
 *  Created on: 04.01.2016
 *      Author: andreuschmann
 */
#include "three.h"

KeyboardView::KeyboardView():VerticalLayout() {
	mKeyboadListener = 0;
	createLowerCase();
}

void KeyboardView::createLowerCase() {
	HorizontalLayout *row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("1", row);
	createButton("2", row);
	createButton("3", row);
	createButton("4", row);
	createButton("5", row);
	createButton("6", row);
	createButton("7", row);
	createButton("8", row);
	createButton("9", row);
	createButton("0", row);
	createButton("=", row);
	Button *button = new Button();
	button->setWidth(50);
	button->setHeight(25);
	button->setText("<-");
	button->setTextSize(14);
	button->setClickListener(this);
	row->addChild(button);
	this->addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("q", row);
	createButton("w", row);
	createButton("e", row);
	createButton("r", row);
	createButton("t", row);
	createButton("z", row);
	createButton("u", row);
	createButton("i", row);
	createButton("o", row);
	createButton("p", row);
	createButton("+", row);
	createButton("{", row);
	createButton("}", row);
	this->addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("a", row);
	createButton("s", row);
	createButton("d", row);
	createButton("f", row);
	createButton("g", row);
	createButton("h", row);
	createButton("j", row);
	createButton("k", row);
	createButton("l", row);
	createButton("\~", row);
	createButton("-", row);
	createButton("[", row);
	createButton("]", row);
	this->addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("y", row);
	createButton("x", row);
	createButton("c", row);
	createButton("v", row);
	createButton("b", row);
	createButton("n", row);
	createButton("m", row);
	createButton(",", row);
	createButton(".", row);
	createButton(";", row);
	createButton("*", row);
	createButton("(", row);
	createButton(")", row);
	this->addChild(row);

	row = new HorizontalLayout();
	row->setWidth(VIEW_FILL_PARENT);
	row->setHeight(VIEW_WRAP_CONTENT);
	createButton("\"", row);
	createButton("'", row);
	createButton("<", row);
	createButton(">", row);
	button = new Button();
	button->setWidth(125);
	button->setHeight(25);
	button->setText(" ");
	button->setTextSize(14);
	button->setClickListener(this);
	row->addChild(button);
	createButton("_", row);
	createButton("\/", row);
	this->addChild(row);
}

void KeyboardView::createButton(const char *c, ViewGroup *container) {
	Button *button = new Button();
	button->setWidth(25);
	button->setHeight(25);
	button->setText(c);
	button->setClickListener(this);
	container->addChild(button);
}

bool KeyboardView::onClick(View *view) {
	Button *button = (Button*)view;
	if(mKeyboadListener) {
		mKeyboadListener->onKeyPressed(this, button->getText());
	}
	return true;
}


void KeyboardView::setKeyboardListener(KeyboardListener *listener) {
	mKeyboadListener = listener;
}
