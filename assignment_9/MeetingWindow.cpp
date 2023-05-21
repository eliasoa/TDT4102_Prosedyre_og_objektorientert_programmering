#include "MeetingWindow.h"


MeetingWindow::MeetingWindow(int x, int y, int width, int height, const std::string& title) : 
    AnimationWindow(x,y,width,height,title),

    quitBtn{TDT4102::Point{width - btnW - pad, pad + fieldH}, btnW, btnH, "Quit" },

    personName      {TDT4102::Point{fieldPad, pad + fieldH}, fieldW, btnH, "Name" },
	personEmail     {TDT4102::Point{fieldPad, (pad + fieldH) * 3}, fieldW, btnH, "Email" },
    personNewBtn    {TDT4102::Point{fieldPad, (pad + fieldH) * 6}, fieldW, btnH, "New Person" }

    {
    add(quitBtn);
    add(personName);
    add(personEmail);
    add(personNewBtn);

    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit,this));
    personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson,this));

}


void MeetingWindow::cb_quit(){
    this->close();
}

void MeetingWindow::newPerson(){
    
	const std::string& name = personName.getText();
	const std::string& email = personEmail.getText();

	people.emplace_back(new Person{ name, email});

    personName.setText("Name");
	personEmail.setText("Email");
}

void MeetingWindow::printPersons(){
    for (const auto& p:people){   
        std::cout << *p << std::endl;
    }
}