//
// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef COMPILER_UNIFORM_H_
#define COMPILER_UNIFORM_H_

#include <string>
#include <vector>

#define GL_APICALL
#include <GLES2/gl2.h>

namespace sh
{

struct Uniform
{
    Uniform(GLenum type, const char *name, int arraySize, int registerIndex);

    GLenum type;
    std::string name;
    int arraySize;
    
    int registerIndex;
};

typedef std::vector<Uniform> ActiveUniforms;

}

#endif   // COMPILER_UNIFORM_H_