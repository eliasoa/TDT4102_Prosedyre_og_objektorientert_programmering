#pragma once
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"

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
    
    MeetingWindow(Point position, int width, int height, const std::string& title);
public:

};