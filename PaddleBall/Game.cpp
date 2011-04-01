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
    mPaddle = NULL;
}

Game::~Game()
{
    if (mBall)
        delete mBall;
    if (mPaddle)
        delete mPaddle;
    
}

void Game::update(unsigned int const elapsedMS)
{
    if (mBall)
        mBall->update(elapsedMS);

    // Check Ball Wall Collision
    if (mBall)
        mBall->checkWallCollision(0, 0, mWidth, mHeight);

    if (mPaddle)
        mPaddle->update(elapsedMS);
}

void Game::render()
{
    if (mBall)
        mBall->render();
    if (mPaddle)
        mPaddle->render();
}

void Game::touchBegin(const int x, const int y)
{
    if (y >= mHeight / 2)
    if (mPaddle)
        mPaddle->setDir(x < mWidth / 2 ? -1 : 1);
    
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
        if (mPaddle) delete mPaddle;
        mPaddle = new Paddle(mWidth / 2, mHeight / 4);
    }
    if (mPaddle)
        mPaddle->setDir(0);
}