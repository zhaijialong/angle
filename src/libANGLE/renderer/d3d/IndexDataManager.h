//
// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// IndexDataManager.h: Defines the IndexDataManager, a class that
// runs the Buffer translation process for index buffers.

#ifndef LIBANGLE_INDEXDATAMANAGER_H_
#define LIBANGLE_INDEXDATAMANAGER_H_

#include <GLES2/gl2.h>

#include "common/angleutils.h"
#include "common/mathutil.h"
#include "libANGLE/Error.h"
#include "libANGLE/renderer/d3d/RendererD3D.h"

namespace
{
    enum { INITIAL_INDEX_BUFFER_SIZE = 4096 * sizeof(GLuint) };
}

namespace gl
{
class Buffer;
}

namespace rx
{
class IndexBufferInterface;
class StaticIndexBufferInterface;
class StreamingIndexBufferInterface;
class IndexBuffer;
class BufferD3D;
class RendererD3D;

struct TranslatedIndexData
{
    gl::RangeUI indexRange;
    unsigned int startIndex;
    unsigned int startOffset;   // In bytes

    IndexBuffer *indexBuffer;
    BufferD3D *storage;
    GLenum indexType;
    unsigned int serial;
};

struct SourceIndexData
{
    const GLvoid *srcIndices;
    unsigned int srcCount;
    GLenum srcIndexType;
    bool srcIndicesChanged;
};

class IndexDataManager : angle::NonCopyable
{
  public:
    explicit IndexDataManager(BufferFactoryD3D *factory, RendererClass rendererClass);
    virtual ~IndexDataManager();

    gl::Error prepareIndexData(GLenum type, GLsizei count, gl::Buffer *arrayElementBuffer, const GLvoid *indices, TranslatedIndexData *translated, SourceIndexData *sourceData);

  private:
    gl::Error getStreamingIndexBuffer(GLenum destinationIndexType, IndexBufferInterface **outBuffer);

    BufferFactoryD3D *const mFactory;
    RendererClass mRendererClass;
    StreamingIndexBufferInterface *mStreamingBufferShort;
    StreamingIndexBufferInterface *mStreamingBufferInt;
};

}

#endif   // LIBANGLE_INDEXDATAMANAGER_H_
