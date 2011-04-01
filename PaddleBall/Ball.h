//
//  Ball.h
//  PaddleBall
//
//  Created by Z2Live QA on 4/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef BALL_H
#define BALL_H

#include "Vector2D.h"

class Ball
{
public:
    static const int WIDTH = 30;
    static const int HEIGHT = 30;
    static const int INITIAL_SPEED = 200;
    
    Ball(const int x, const int y);
    virtual ~Ball();
    
    virtual void update(const unsigned int elapsedMS);
    virtual void render();
    
    virtual void checkWallCollision(const float x, const float y,
                                    const float w, const float h);
    virtual void bounce(const Vector2D &surfaceVector);
    
    virtual float getX() { return mPos.getX(); }
    virtual float getY() { return mPos.getY(); }
    
private:
    Vector2D mPos;
    Vector2D mDir;
    float mSpeed;
};

#endif //BALL_H