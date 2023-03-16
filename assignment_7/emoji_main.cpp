#include "AnimationWindow.h"
#include "Emoji.hpp"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	Point sentrum{xmax/2,ymax/2};

	std::vector<std::unique_ptr<Emoji>> emojis;
	emojis.emplace_back(new SmileyFace(sentrum,emojiRadius));
	emojis.emplace_back(new SadFace({sentrum.x+2*emojiRadius,sentrum.y},emojiRadius));
	emojis.emplace_back(new SuprisedFace({sentrum.x-2*emojiRadius,sentrum.y},emojiRadius));
	emojis.emplace_back(new AngryFace({sentrum.x-2*emojiRadius,sentrum.y+2*emojiRadius},emojiRadius));
	emojis.emplace_back(new WinkingFace({sentrum.x,sentrum.y+2*emojiRadius},emojiRadius));

	for(const auto& e:emojis){
		e ->draw(win);
	}

	win.wait_for_close();

	return 0;
}
