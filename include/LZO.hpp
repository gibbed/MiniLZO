#pragma once

#include "ErrorCode.hpp"

namespace MiniLZO
{
	ref class CompressWorkBuffer;

	public ref class LZO abstract sealed
	{
		static LZO();

	public:
		static property System::String^ Copyright
		{
			System::String^ get();
		}

		static property unsigned int Version
		{
			unsigned int get();
		}

		static property System::String^ VersionString
		{
			System::String^ get();
		}

		static property System::String^ VersionDate
		{
			System::String^ get();
		}

		static ErrorCode Compress(
			array<System::Byte>^ inputBytes,
			int inputOffset,
			int inputCount,
			array<System::Byte>^ outputBytes,
			int outputOffset,
			int% outputCount,
			CompressWorkBuffer^ workBuffer);

		static ErrorCode Decompress(
			array<System::Byte>^ inputBytes,
			int inputOffset,
			int inputCount,
			array<System::Byte>^ outputBytes,
			int outputOffset,
			int% outputCount);

		static ErrorCode DecompressSafe(
			array<System::Byte>^ inputBytes,
			int inputOffset,
			int inputCount,
			array<System::Byte>^ outputBytes,
			int outputOffset,
			int% outputCount);
	};
}
