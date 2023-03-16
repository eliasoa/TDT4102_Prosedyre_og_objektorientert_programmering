#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "mastermind.h"



void playMastermindVisual(){
	
	constexpr int size = 4;
    constexpr int letters = 6;
    char lowerBound = 'A';
    char upperBound = 'A'+ (letters-1);
    string code = randomizeString(4,lowerBound,upperBound);
    string guess;

	MastermindWindow mwin{800, 20, winW, winH, size, "Mastermind"};

    int correctPosition = 0;
    int correctChars = 0;
    int numberOfGuesses = 3;
    cout << code << endl;

    while (correctPosition < size)
    {
        guess = mwin.getInput(4,lowerBound,upperBound);
        correctPosition = checkCharactersAndPosition(code,guess);
        correctChars = checkCharacters(code,guess);
        cout << "Number of correct characters: " << correctChars << "\n" <<
        "Characters in correct position: " << correctPosition << endl;
        numberOfGuesses -= 1;
        if (numberOfGuesses<1)
        {
            break;
        }
    }
    if (correctPosition==size)
    {
        cout << "You are the mastermind ;)" << endl;
    }
    else
    {
        cout << "You are not the mastermind :(" << endl;
    }
}

void addGuess(MastermindWindow &mwin, const std::string code, const char startLetter)
{
	// definer addGuess
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// definer addFeedback
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const std::string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::newGuess, this));
};

string MastermindWindow::wait_for_guess()
{

	std::map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::green},
    {3, Color::yellow},
    {4, Color::blue},
    {5, Color::blue_violet},
    {6, Color::dark_cyan}
	};

	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			{
                // Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge

			}
		}

		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			// Implementer feedback

			for (int i = 0; i < size; i++)
			{
				// Tegn sirkler ved hjelp av draw_circle
				
			}
		}

		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");
	
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}