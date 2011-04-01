//
//  Paddle.h
//  PaddleBall
//
//  Created by Z2Live QA on 4/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef PADDLE_H
#define PADDLE_H

#include "Vector2D.h"

class Paddle
{
public:
    static const int WIDTH = 80;
    static const int HEIGHT = 20;
    static const int SPEED = 200;

    Paddle(const int x, const int y);
    virtual ~Paddle();
    
    virtual void update(const unsigned int elapsedMS);
    virtual void render();
    
    virtual float getX() { return mPos.getX(); }
    virtual float getY() { return mPos.getY(); }

    virtual void setDir( int speed );
    virtual float getDir() { return mSpeed; }
private:
    Vector2D mPos;
    float mSpeed;

};

#endif // PADDLE_H