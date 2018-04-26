#pragma once

template <typename T>
class Pointer
{
public:
	Pointer(T* ptr);
	virtual ~Pointer();
	
	// Prevent assignment and pass by value.
	Pointer(const Pointer<T>& src) = delete;
	Pointer<T>& operator=(const Pointer<T>& rhs) = delete;

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

	operator bool() const;

	//template <typename T>
	//friend bool operator!=(const Pointer<T>& lhs, std::nullptr_t rhs);

private:
	T* mPtr = nullptr;
};

//template <typename T>
//bool operator!=(const Pointer<T>& lhs, std::nullptr_t rhs)
//{
//	return lhs.mPtr != rhs;
//}

template <typename T>
Pointer<T>::Pointer(T* ptr) : mPtr(ptr)
{
}

template <typename T>
Pointer<T>::~Pointer()
{
	delete mPtr;
	mPtr = nullptr;
}

template <typename T>
T& Pointer<T>::operator*()
{
	return *mPtr;
}

template <typename T>
const T& Pointer<T>::operator*() const
{
	return *mPtr;
}

template <typename T>
T* Pointer<T>::operator->()
{
	return mPtr;
}

template <typename T>
const T* Pointer<T>::operator->() const
{
	return mPtr;
}

template <typename T>
Pointer<T>::operator bool() const
{
	return mPtr != nullptr;
}
