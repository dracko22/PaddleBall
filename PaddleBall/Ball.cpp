//
//  Ball.cpp
//  PaddleBall
//
//  Created by Z2Live QA on 4/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Ball.h"

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

Ball::Ball(const int x, const int y)
{
    mPos = Vector2D(x, y);
    
    int dir = (rand() % 2);
    mDir = Vector2D(1 + (-2 * dir), 1);
    mDir.normalize();
    mSpeed = INITIAL_SPEED;
}

Ball::~Ball()
{
    
}

void Ball::update(const unsigned int elapsedMS)
{
    mPos = mPos + mDir * (elapsedMS * mSpeed / 1000);
}

void Ball::render()
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
        192, 192, 192, 255,
        255, 0, 0, 255,
        128, 0, 0, 0,
        64, 0, 0, 255,
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

void Ball::checkWallCollision(const float x, const float y,
                        const float w, const float h)
{
    if (getX() <= x)
        bounce(Vector2D(-1.0f, 0.0f));
    if (getY() <= y)
        bounce(Vector2D(0.0f, -1.0f));
    
    if (getX() >= w)
        bounce(Vector2D(1.0f, 0.0f));
    if (getY() >= h)
        bounce(Vector2D(0.0f, 1.0f));
}

void Ball::bounce(const Vector2D &surfaceVector)
{
    Vector2D reflectionVector = surfaceVector * -1.0f;
    mDir = mDir - reflectionVector * 2 * reflectionVector.dot(mDir);
}
