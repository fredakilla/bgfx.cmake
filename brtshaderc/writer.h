#include <bx/file.h>
#include <vector>



struct MemoryBuffer
{
    uint8_t* data;
    uint32_t size;
};


class BufferWriter : public bx::FileWriter
{
public:
    ///
    BufferWriter(MemoryBuffer* memPtr) :
        _memPtr(memPtr)
    {
    }

    virtual ~BufferWriter()
    {
    }

    virtual bool open(const bx::FilePath& _filePath, bool _append, bx::Error* _err) override
    {
    }

    virtual void close() override
    {
        if(_memPtr)
        {
            bx::DefaultAllocator crtAllocator;
            size_t size = m_buffer.size() + 1;
            _memPtr->data = (uint8_t*)bx::alloc(&crtAllocator, size);
            _memPtr->size = size;

            bx::memCopy(_memPtr->data, m_buffer.data(), m_buffer.size());
            _memPtr->data[_memPtr->size - 1] = '\0';
        }
    }

    virtual int64_t seek(int64_t _offset = 0, bx::Whence::Enum _whence = bx::Whence::Current) override
    {
    }

    virtual int32_t write(const void* _data, int32_t _size, bx::Error* _err) override
    {
        const char* data = (const char*)_data;
        m_buffer.insert(m_buffer.end(), data, data+_size);
        return _size;
    }

private:
    BX_ALIGN_DECL(16, uint8_t) m_internal[64];

    typedef std::vector<uint8_t> Buffer;
    Buffer m_buffer;
    MemoryBuffer* _memPtr;
};

