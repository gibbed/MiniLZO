#include "CompressWorkBuffer.hpp"

#include "native/minilzo.h"

using namespace System;
using namespace MiniLZO;

CompressWorkBuffer::CompressWorkBuffer()
{
	this->_Buffer = gcnew array<System::Byte>(LZO1X_MEM_COMPRESS);
}
