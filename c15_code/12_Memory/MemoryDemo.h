#pragma once

#include <cstddef>
#include <new>

class MemoryDemo
{
public:
	virtual ~MemoryDemo() = default;

	void* operator new(size_t size);
	void operator delete(void* ptr) noexcept;
	//void operator delete(void* ptr, size_t size) noexcept;

	void* operator new[](size_t size);
	void operator delete[](void* ptr) noexcept;
	
	void* operator new(size_t size, const std::nothrow_t&) noexcept;
	void operator delete(void* ptr, const std::nothrow_t&) noexcept;

	void* operator new[](size_t size, const std::nothrow_t&) noexcept;
	void operator delete[](void* ptr, const std::nothrow_t&) noexcept;


	void* operator new(size_t size, int extra);
	void operator delete(void* ptr, int extra) noexcept;
};
