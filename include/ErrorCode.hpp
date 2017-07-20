#pragma once

namespace MiniLZO
{
	// this should mirror what is in lzoconf.h
	public enum class ErrorCode
	{
		Success = 0, // LZO_E_OK
		GenericError = -1, // LZO_E_ERROR
		OutOfMemory = -2, // LZO_E_OUT_OF_MEMORY
		NotCompressible = -3, // LZO_E_NOT_COMPRESSIBLE
		InputOverrun = -4, // LZO_E_INPUT_OVERRUN
		OutputOverrun = -5, // LZO_E_OUTPUT_OVERRUN
		LookbehindOverrun = -6, // LZO_E_LOOKBEHIND_OVERRUN
		EndOfFileNotFound = -7, // LZO_E_EOF_NOT_FOUND
		InputNotConsumed = -8, // LZO_E_INPUT_NOT_CONSUMED
		NotImplemented = -9, // LZO_E_NOT_YET_IMPLEMENTED
		InvalidArgument = -10, // LZO_E_INVALID_ARGUMENT
		InvalidAlignment = -11, // LZO_E_INVALID_ALIGNMENT
		OutputNotConsumed = -12, // LZO_E_OUTPUT_NOT_CONSUMED
		InternalError = -99, // LZO_E_INTERNAL_ERROR
	};
}
