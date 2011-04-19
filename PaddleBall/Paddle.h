//
//  Paddle.h
//  PaddleBall
//
//  Created by Ryan Murphy on 4/19/11.
//  Copyright 2011 Z2Live, Inc. All rights reserved.
//

#ifndef PADDLE_H
#define PADDLE_H

#include "Vector2D.h"

class Paddle
{
public:
    static const int WIDTH = 80;
    static const int HEIGHT = 30;
	
	static const int INITIAL_POSITION_X = 160;
	static const int INITIAL_POSITION_Y = 30;
	
    static const int PADDLE_SPEED = 200;
    
    Paddle();
    virtual ~Paddle();
    
    virtual void update(const unsigned int elapsedMS);
    virtual void render();
    
    virtual void checkWallCollision(const float x, const float y,
                                    const float w, const float h);
    //virtual void bounce(const Vector2D &surfaceVector);
	
	virtual void moveLeft();
	virtual void moveRight();
	virtual void stopMoving();
    
    virtual float getX() { return mPos.getX(); }
    virtual float getY() { return mPos.getY(); }
    
private:
    Vector2D mPos;
    Vector2D mDir;
    float mSpeed;
};


#endif