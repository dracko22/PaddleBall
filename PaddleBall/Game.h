//
//  Game.h
//  PaddleBall
//
//  Created by Z2Live QA on 4/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

#include <list>

class Ball;
class Paddle;

class Game
{
public:
    Game(unsigned int const width, unsigned int const height);
    virtual ~Game();
    
    virtual void update(unsigned int const elapsedMS);
    virtual void render();
	
	virtual void checkBallPaddleCollision(Ball* b);
    
    virtual void touchBegin(const int x, const int y);
    virtual void touchMoved(const int x, const int y);
    virtual void touchEnd(const int x, const int y);
    
    virtual unsigned int const getWidth() { return mWidth; }
    virtual unsigned int const getHeight() { return mHeight; }
    
private:
    unsigned int mWidth;
    unsigned int mHeight;
    
	std::list<Ball*> ballList;
	Paddle* mPaddle;
};

#endif //GAME_H