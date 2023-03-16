#include "Emoji.hpp"


Face::Face(Point centre, int radius): centre{centre}, radius{radius} {};

void Face::draw(AnimationWindow& win)
{
    win.draw_circle(centre,radius,Color::yellow);
};

EmptyFace::EmptyFace(Point centre, int radius) : Face{centre,radius},
                                    leftEye{centre.x-15,centre.y-10}, //x-15 y -10
                                    rightEye{centre.x+15,centre.y-10}, 
                                    eyeRadius{10} {};

void EmptyFace::draw(AnimationWindow& win){
    Face::draw(win);
    win.draw_circle(leftEye,eyeRadius,Color::black);
    win.draw_circle(rightEye,eyeRadius,Color::black);
};

SmileyFace::SmileyFace(Point centre, int radius) : EmptyFace{centre,radius},
                                    mouthPosition{centre.x,centre.y+5},
                                    mouthWidth{radius-20},
                                    mouthHeight{-30},
                                    startDegree{0},
                                    endDegree{180} {};

void SmileyFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(mouthPosition,mouthWidth,mouthHeight,startDegree,endDegree);
};

SadFace::SadFace(Point centre, int radius) : EmptyFace{centre,radius},
                                    mouthPosition{centre.x,centre.y+30},
                                    mouthWidth{radius-20},
                                    mouthHeight{30},
                                    startDegree{0},
                                    endDegree{180} {};

void SadFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(mouthPosition,mouthWidth,mouthHeight,startDegree,endDegree);
};


SuprisedFace::SuprisedFace(Point centre, int radius) : EmptyFace(centre,radius),
                                                        mouthPosition{centre.x,centre.y+20},
                                                        mouthWidth{radius/4},
                                                        mouthHeight{radius/3},
                                                        startDegree{0},
                                                        endDegree{360} {};
void SuprisedFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(mouthPosition,mouthWidth,mouthHeight,startDegree,endDegree);
};

AngryFace::AngryFace(Point centre, int radius) : EmptyFace(centre, radius){};

void AngryFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    Point mouthPosition{centre.x,centre.y+30};
    int mouthWidth{radius-30};
    int mouthHeight{10};
    int startDegree{0};
    int endDegree{180};


    win.draw_line({leftEye.x+10,leftEye.y-10},{leftEye.x-10,leftEye.y-20});
    win.draw_line({rightEye.x+10,rightEye.y-20},{rightEye.x-10,rightEye.y-10});
    win.draw_arc(mouthPosition,mouthWidth,mouthHeight,startDegree,endDegree);
};


WinkingFace::WinkingFace(Point centre, int radius) :    Face(centre, radius),
                                                        rightEye{centre.x+15,centre.y-10},
                                                        eyeRadius{10},
                                                        leftEye{centre.x-15,centre.y-10},
                                                        eyeWidth{10},
                                                        eyeHeight{10},
                                                        eyeStartDegree{0},
                                                        eyeEndDegree{180},
                                                        mouthPosition{centre.x,centre.y+5},
                                                        mouthWidth{radius-20},
                                                        mouthHeight{-30},
                                                        startDegree{0},
                                                        endDegree{180} {};

void WinkingFace::draw(AnimationWindow& win){
    Face::draw(win);
    win.draw_circle(rightEye,eyeRadius,Color::black);
    win.draw_arc(leftEye,eyeWidth,eyeHeight,eyeStartDegree,eyeEndDegree);
    win.draw_arc(mouthPosition,mouthWidth,mouthHeight,startDegree,endDegree);
    
};