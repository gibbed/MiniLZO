#include "LZO.hpp"
#include "ErrorCode.hpp"
#include "CompressWorkBuffer.hpp"

#include "native/minilzo.h"

using namespace System;
using namespace MiniLZO;

LZO::LZO()
{
	auto result = lzo_init();
	if (result != LZO_E_OK)
	{
		throw gcnew InvalidOperationException("LZO initialization failed");
	}
}

String^ LZO::Copyright::get()
{
	return
		"\r\n\n"
		"LZO data compression library.\n"
		"$Copyright: LZO Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer\n"
		"<markus@oberhumer.com>\n"
		"http://www.oberhumer.com $\n\n"
		"$Id: LZO version: v" LZO_VERSION_STRING ", " LZO_VERSION_DATE " $\n"
		"$Info: " LZO_INFO_STRING " $\n";
}

unsigned int LZO::Version::get()
{
	return LZO_VERSION;
}

String^ LZO::VersionString::get()
{
	return LZO_VERSION_STRING;
}

String^ LZO::VersionDate::get()
{
	return LZO_VERSION_DATE;
}

ErrorCode LZO::Compress(
	array<Byte>^ inputBytes,
	int inputOffset,
	int inputCount,
	array<Byte>^ outputBytes,
	int outputOffset,
	int% outputCount,
	CompressWorkBuffer^ workBuffer)
{
	if (inputBytes == nullptr)
	{
		throw gcnew ArgumentNullException("inputBytes");
	}

	if (inputOffset < 0 || inputOffset >= inputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("inputOffset");
	}

	if (inputCount <= 0 || inputOffset + inputCount > inputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("inputCount");
	}

	if (outputBytes == nullptr)
	{
		throw gcnew ArgumentNullException("outputBytes");
	}

	if (outputOffset < 0 || outputOffset >= outputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("outputOffset");
	}

	if (outputCount <= 0 || outputOffset + outputCount > outputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("outputCount");
	}

	if (workBuffer == nullptr)
	{
		throw gcnew ArgumentNullException("workBuffer");
	}

	pin_ptr<unsigned char> inputBuffer = &inputBytes[inputOffset];
	pin_ptr<unsigned char> outputBuffer = &outputBytes[outputOffset];
	pin_ptr<unsigned char> workMemory = &workBuffer->Buffer[0];

	ErrorCode result;
	lzo_uint dummy = outputCount;
	result = (ErrorCode)lzo1x_1_compress(
		inputBuffer,
		inputCount,
		outputBuffer,
		&dummy,
		workMemory);
	outputCount = (int)dummy;
	return result;
}

ErrorCode LZO::Decompress(
	array<Byte>^ inputBytes,
	int inputOffset,
	int inputCount,
	array<Byte>^ outputBytes,
	int outputOffset,
	int% outputCount)
{
	if (inputBytes == nullptr)
	{
		throw gcnew ArgumentNullException("inputBytes");
	}

	if (inputOffset < 0 || inputOffset >= inputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("inputOffset");
	}

	if (inputCount <= 0 || inputOffset + inputCount > inputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("inputCount");
	}

	if (outputBytes == nullptr)
	{
		throw gcnew ArgumentNullException("outputBytes");
	}

	if (outputOffset < 0 || outputOffset >= outputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("outputOffset");
	}

	if (outputCount <= 0 || outputOffset + outputCount > outputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("outputCount");
	}

	pin_ptr<unsigned char> inputBuffer = &inputBytes[inputOffset];
	pin_ptr<unsigned char> outputBuffer = &outputBytes[outputOffset];

	lzo_uint dummy = outputCount;
	auto result = static_cast<ErrorCode>(lzo1x_decompress(
		inputBuffer,
		inputCount,
		outputBuffer,
		&dummy,
		nullptr));
	outputCount = dummy;
	return result;
}

ErrorCode LZO::DecompressSafe(
	array<Byte>^ inputBytes,
	int inputOffset,
	int inputCount,
	array<Byte>^ outputBytes,
	int outputOffset,
	int% outputCount)
{
	if (inputBytes == nullptr)
	{
		throw gcnew ArgumentNullException("inputBytes");
	}

	if (inputOffset < 0 || inputOffset >= inputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("inputOffset");
	}

	if (inputCount <= 0 || inputOffset + inputCount > inputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("inputCount");
	}

	if (outputBytes == nullptr)
	{
		throw gcnew ArgumentNullException("outputBytes");
	}

	if (outputOffset < 0 || outputOffset >= outputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("outputOffset");
	}

	if (outputCount <= 0 || outputOffset + outputCount > outputBytes->Length)
	{
		throw gcnew ArgumentOutOfRangeException("outputCount");
	}

	pin_ptr<unsigned char> inputBuffer = &inputBytes[inputOffset];
	pin_ptr<unsigned char> outputBuffer = &outputBytes[outputOffset];

	lzo_uint dummy = outputCount;
	auto result = static_cast<ErrorCode>(lzo1x_decompress_safe(
		inputBuffer,
		inputCount,
		outputBuffer,
		&dummy,
		nullptr));
	outputCount = dummy;
	return result;
}
