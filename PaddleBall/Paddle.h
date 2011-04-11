//
//  Paddle.h
//  PaddleBall
//
//  Created by Z2Live QA on 4/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Vector2D.h"
#import <Foundation/Foundation.h>

class Paddle
{
public:
    
    Paddle(float w, float h);
    void Render(void) const;
    void Update( const unsigned int ms );
    
    void CheckCollisionWithWall(float left, float right);

    void SetDirection(const int direction);
    
private:
    
        
    Vector2D _position;
    const Vector2D _dimensions;
    int _direction;
};