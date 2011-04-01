//
//  Shader.fsh
//  PaddleBall
//
//  Created by Z2Live QA on 3/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
