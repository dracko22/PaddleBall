//
//  Vector2D.h
//  PaddleBall
//
//  Created by Z2Live QA on 4/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
    Vector2D(const float x = 0, const float y = 0) : mX(x), mY(y) {}
    Vector2D(const Vector2D &v) : mX(v.mX), mY(v.mY) {}
    virtual ~Vector2D() {}
    
    float getX() { return mX; }
    float getY() { return mY; }
    
    Vector2D operator=(const Vector2D &v)
	{
        mX = v.mX;
        mY = v.mY;
		return *this;
	}
    
    Vector2D operator*(float scalar) const
	{
		return Vector2D(mX * scalar, mY * scalar);
	}
    
    Vector2D operator+(const Vector2D &vect) const
	{
		return Vector2D(mX + vect.mX, mY + vect.mY);
	}
    
	Vector2D operator-(const Vector2D &vect) const
	{
		return Vector2D(mX - vect.mX, mY - vect.mY);
	}
    
    float dot(const Vector2D &vect) const
	{
		return (mX * vect.mX) + (mY * vect.mY);
	}
    
    float magnitude()
	{
		return sqrtf(mX * mX + mY * mY);
	}
    
	void normalize()
	{
		float mag = magnitude();
		mX = mX / mag;
		mY = mY / mag;
	}
    
private:
    float mX;
    float mY;
};

#endif //VECTOR2D_H