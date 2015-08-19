#pragma once

#include "BsD3D11Prerequisites.h"
#include "BsVertexBuffer.h"
#include "BsD3D11HardwareBuffer.h"

namespace BansheeEngine
{
	/**
	 * @brief	DirectX 11 implementation of a vertex buffer.
	 */
	class BS_D3D11_EXPORT D3D11VertexBufferCore : public VertexBufferCore
	{
	public:
		D3D11VertexBufferCore(D3D11Device& device, UINT32 vertexSize, UINT32 numVertices, 
			GpuBufferUsage usage, bool streamOut);

		~D3D11VertexBufferCore();

		/**
		 * @copydoc VertexBufferCore::readData
		 */
		void readData(UINT32 offset, UINT32 length, void* pDest) override;

		/**
		 * @copydoc VertexBufferCore::writeData
		 */
		void writeData(UINT32 offset, UINT32 length, const void* pSource, BufferWriteType writeFlags = BufferWriteType::Normal) override;

		/**
		 * @copydoc VertexBufferCore::copyData
		 */
		void copyData(HardwareBuffer& srcBuffer, UINT32 srcOffset, UINT32 dstOffset, UINT32 length, bool discardWholeBuffer = false) override;

		/**
		 * @brief	Get the D3D-specific index buffer
		 */
		ID3D11Buffer* getD3DVertexBuffer() const { return mBuffer->getD3DBuffer(); }		

	protected: 
		/**
		* @copydoc VertexBufferCore::lockImpl
		 */
		void* lockImpl(UINT32 offset, UINT32 length, GpuLockOptions options) override;

		/**
		 * @copydoc VertexBufferCore::unlockImpl
		 */
		void unlockImpl(void) override;

		/**
		 * @copydoc VertexBufferCore::initialize
		 */
		void initialize() override;

		D3D11HardwareBuffer* mBuffer;
		D3D11Device& mDevice;
		bool mStreamOut;
	};
}