#pragma once
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <memory.h>
#include "Person.h"
#include "Meeting.h"

class MeetingWindow : public TDT4102::AnimationWindow
{
private:
    static constexpr int pad = 4;
	static constexpr int btnW = 100;
	static constexpr int btnH = 20;
	static constexpr int fieldW = 200;
	static constexpr int fieldH = 20;
	static constexpr int fieldPad = 80;
	static constexpr int headerFontSize = 20;

	std::vector<std::shared_ptr<Person>> people;

	TDT4102::Button quitBtn;
	TDT4102::TextInput personName;
	TDT4102::TextInput personEmail;
	TDT4102::Button personNewBtn;

    
public:
	MeetingWindow(int x, int y, int width, int height, const std::string& title);

	void cb_quit();

	void newPerson();

	void printPersons();
	
};