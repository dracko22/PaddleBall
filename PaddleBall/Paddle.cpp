//
//  Paddle.cpp
//  PaddleBall
//
//  Created by Z2Live QA on 4/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Paddle.h"

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

Paddle::Paddle(float w, float h)
: _dimensions(w,h), _position(0,0)
{
}

void Paddle::Render() const
{
    static const float hw = _dimensions.getX() / 2.0f;
    static const float hh = _dimensions.getY() / 2.0f;
    
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
    
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    
    glLoadIdentity();
    glTranslatef(_position.getX(), _position.getY(), 0);

    glVertexPointer(2, GL_FLOAT, 0, squareVertices);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    glPopMatrix();
}

void Paddle::Update(const unsigned int ms)
{
    float sec = ms / 1000.0f;
    static const int scale = 10;

    _position.setX( _position.getX() + scale * sec * _direction );
    
    // TODO
}


void Paddle::CheckCollisionWithWall(float left, float right)
{
    float l = _position.getX() - _dimensions.getX() / 2.0f;
    float r = _position.getX() + _dimensions.getX() / 2.0f;
    
    if( l < left )
        _direction = 0;
    if( r >= right )
        _direction = 0;    
    
}

void Paddle::SetDirection(const int direction)
{
     _direction = direction;
    
    if( _direction < -1 )
        _direction = -1;
    else if( _direction > 1 )
        _direction = 1;
}
