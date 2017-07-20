#pragma once

namespace MiniLZO
{
	public ref class CompressWorkBuffer sealed
	{
	private:
		initonly array<System::Byte>^ _Buffer;

	public:
		property array<System::Byte>^ Buffer
		{
			array<System::Byte>^ get() { return this->_Buffer; }
		}

		CompressWorkBuffer();
	};
}
