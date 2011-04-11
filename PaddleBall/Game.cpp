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
    
    mBall = NULL;
    mPaddle = new Paddle(100,30);
}

Game::~Game()
{
    if (mBall)
        delete mBall;
    
    delete mPaddle;
}

void Game::update(unsigned int const elapsedMS)
{
    if (mBall)
        mBall->update(elapsedMS);
    
    if (mPaddle)
        mPaddle->Update(elapsedMS);

    // Check Ball Wall Collision
    if (mBall)
        mBall->checkWallCollision(0, 0, mWidth, mHeight);
    
    if( mPaddle )
        mPaddle->CheckCollisionWithWall(0, mWidth);
}

void Game::render()
{
    if (mBall)
        mBall->render();
    
    if( mPaddle )
        mPaddle->Render();
}

void Game::touchBegin(const int x, const int y)
{
    if( y > mHeight / 2)
    {
        if( mPaddle )
        {
            if( x < mWidth/2 )
            {
                mPaddle->SetDirection(-1);
            }
            else if( x > mWidth/2)
            {
                mPaddle->SetDirection(1);
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
        if (mBall) delete mBall;
        mBall = new Ball(mWidth / 2, 3 * mHeight / 4);
    }
    else
    {
        if( mPaddle )
        {
            mPaddle->SetDirection(0);
        }
    }
        
}