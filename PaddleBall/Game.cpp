//
//  Game.cpp
//  PaddleBall
//
//  Created by Z2Live QA on 4/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Game.h"

#include "Ball.h"
#include "Paddle.h"

Game::Game(unsigned int const width, unsigned int const height)
{
    mWidth = width;
    mHeight = height;
    
    //mBall = NULL;
	mPaddle = new Paddle();
}

Game::~Game()
{
    
}

void Game::update(unsigned int const elapsedMS)
{
	if (mPaddle)
		mPaddle->update(elapsedMS);
	
    if (!ballList.empty())
	{
        //mBall->update(elapsedMS);
		std::list<Ball*>::iterator i = ballList.begin();
		
		Ball* temp_ball;
		
		while(i != ballList.end())
		{
			(*i)->update(elapsedMS);
			
			(*i)->checkWallCollision(0, 0, mWidth, mHeight);
			
			if((*i)->checkBottomWallCollision(0, 0, mWidth, mHeight))
			{
				temp_ball = (*i);
				++i;
				ballList.remove(temp_ball);
				delete temp_ball;
			}
			else
			{
				checkBallPaddleCollision(*i);
				++i;
			}
		}
	}
	
	if (mPaddle)
		mPaddle->checkWallCollision(0, 0, mWidth, mHeight);
	
}

void Game::render()
{
	if (mPaddle)
		mPaddle->render();
	
	if (!ballList.empty())
	{
		std::list<Ball*>::iterator i = ballList.begin();
		
		while(i != ballList.end())
		{
			(*i)->render();
			++i;
		}
	}
}

void Game::checkBallPaddleCollision(Ball* b)
{
	if(mPaddle && b)
	{
		b->checkObjectCollision(mPaddle->getX(),mPaddle->getY(),
									mPaddle->WIDTH,mPaddle->HEIGHT);
	}
}

void Game::touchBegin(const int x, const int y)
{
	if(mPaddle)
	{
		if(y > mHeight / 2)
		{
			if(x < mWidth / 2)
			{
				mPaddle->moveLeft();
			}
			else
			{
				mPaddle->moveRight();
			}
		}
	}
}

void Game::touchMoved(const int x, const int y)
{
    
}

void Game::touchEnd(const int x, const int y)
{
    if (y < mHeight / 2)
    {
        //if (mBall) delete mBall;
        ballList.push_back(new Ball(mWidth / 2, 3 * mHeight / 4));
    }
	
	if(mPaddle)
	{
		mPaddle->stopMoving();
	}
        
}