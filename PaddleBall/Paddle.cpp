//
//  Paddle.cpp
//  PaddleBall
//
//  Created by Ryan Murphy on 4/19/11.
//  Copyright 2011 Z2Live, Inc. All rights reserved.
//

#include "Paddle.h"

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

Paddle::Paddle()
{
    mPos = Vector2D(INITIAL_POSITION_X,INITIAL_POSITION_Y);
    
    int dir = (rand() % 2);
    mDir = Vector2D(1 + (-2 * dir), 1);
    mDir.normalize();
    mSpeed = 0;
}

Paddle::~Paddle()
{
    
}

void Paddle::update(const unsigned int elapsedMS)
{
    mPos = mPos + mDir * (elapsedMS * mSpeed / 1000);
}

void Paddle::render()
{
    const int hw = WIDTH >> 1;
    const int hh = HEIGHT >> 1;
    
    static const GLfloat squareVertices[] = {
        -hw, -hh,
        hw, -hh,
        -hw,  hh,
        hw,  hh,
    };
    
    static const GLubyte squareColors[] = {
        255, 0, 0, 255,
        255, 0, 0, 255,
        128, 0, 255, 255,
        64, 255, 0, 255,
    };
    
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(mPos.getX(), mPos.getY(), 0.0f);
    
    glVertexPointer(2, GL_FLOAT, 0, squareVertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    glPopMatrix();
}

void Paddle::moveLeft()
{
	mDir = Vector2D(-1,0);
	mSpeed = PADDLE_SPEED;
}


void Paddle::moveRight()
{
	mDir = Vector2D(1,0);
	mSpeed = PADDLE_SPEED;
}

void Paddle::stopMoving()
{
	mSpeed = 0;
}


void Paddle::checkWallCollision(const float x, const float y,
							  const float w, const float h)
{
    if (getX()-(WIDTH/2) <= x || getX()+(WIDTH/2) >= w)
	{
		mSpeed = 0;
	}
}

 /*
void Paddle::bounce(const Vector2D &surfaceVector)
{
    Vector2D reflectionVector = surfaceVector * -1.0f;
    mDir = mDir - reflectionVector * 2 * reflectionVector.dot(mDir);
}*/
