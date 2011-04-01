//
//  Paddle.cpp
//  PaddleBall
//
//  Created by Z2Live QA on 4/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Paddle.h"

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

Paddle::Paddle(const int x, const int y)
{
    mPos = Vector2D(x, y);
    mSpeed = 0;
}

Paddle::~Paddle()
{
    
}

void Paddle::update(const unsigned int elapsedMS)
{
    float newX = mPos.getX() + (elapsedMS * mSpeed / 1000);
    
    if (newX < (WIDTH >> 1))
    {
        newX = WIDTH >> 1;
    }
    if (newX > 320 - (WIDTH >> 1))
    {
        newX = 320 - (WIDTH >> 1);
    }
        
    
    mPos.setX(newX);
}

void Paddle::render()
{
    const int hw = WIDTH >> 1;
    const int hh = HEIGHT >> 1;
    
    static const GLfloat rectVertices[] = {
        -hw, -hh,
        hw, -hh,
        -hw,  hh,
        hw,  hh,
    };
    
    static const GLubyte rectColors[] = {
        192, 192, 192, 255,
        0, 255, 0, 255,
        0, 128, 0, 255,
        0, 64, 0, 255,
    };
    
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(mPos.getX(), mPos.getY(), 0.0f);
    
    glVertexPointer(2, GL_FLOAT, 0, rectVertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, rectColors);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    glPopMatrix();
}

void Paddle::setDir( int speed )
{
    if (speed == 0)
    {
        mSpeed = 0.0f;
    }
    else if (speed > 0)
    {
        mSpeed = SPEED;
    }
    else
    {
        mSpeed = -SPEED;
    }
}


