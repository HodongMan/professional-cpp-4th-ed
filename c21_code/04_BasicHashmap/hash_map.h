#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <string>
#include <functional>

namespace ProCpp {

	// A default hash object
	template <typename T>
	class hash
	{
	public:
		size_t operator()(const T& key) const;
	};

	// A hash specialization for strings
	template <>
	class hash<std::string>
	{
	public:
		size_t operator()(const std::string& key) const;
	};




	template <typename Key, typename T,
		typename KeyEqual = std::equal_to<>,
		typename Hash = hash<Key>>
	class hash_map
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = std::pair<const Key, T>;

		// Virtual destructor
		virtual ~hash_map() = default;

		// Throws invalid_argument if the number of buckets is illegal.
		explicit hash_map(const KeyEqual& equal = KeyEqual(), size_t numBuckets = 101, const Hash& hash = Hash());

		// Copy constructor
		hash_map(const hash_map<Key, T, KeyEqual, Hash>& src) = default;
		// Move constructor
		hash_map(hash_map<Key, T, KeyEqual, Hash>&& src) noexcept = default;

		// Copy assignment operator
		hash_map<Key, T, KeyEqual, Hash>& operator=(const hash_map<Key, T, KeyEqual, Hash>& rhs);
		// Move assignment operator
		hash_map<Key, T, KeyEqual, Hash>& operator=(hash_map<Key, T, KeyEqual, Hash>&& rhs) noexcept;

		// Inserts the key/value pair x.
		void insert(const value_type& x);

		// Removes the element with key k, if it exists.
		void erase(const key_type& k);

		// Removes all elements.
		void clear() noexcept;

		// Find returns a pointer to the element with key k.
		// Returns nullptr if no element with that key exists.
		value_type* find(const key_type& k);
		const value_type* find(const key_type& k) const;

		// operator[] finds the element with key k, or inserts an
		// element with that key if none exists yet. Returns a reference to
		// the value corresponding to that key.
		T& operator[] (const key_type& k);

		// Swaps two hash_maps.
		void swap(hash_map<Key, T, KeyEqual, Hash>& other) noexcept;

	private:
		using ListType = std::list<value_type>;

		// Returns a pair containing an iterator to the found element with a given key,
		// and the index of that element's bucket.
		std::pair<typename ListType::iterator, size_t> findElement(const key_type& k);

		std::vector<ListType> mBuckets;
		size_t mSize = 0;
		KeyEqual mEqual;
		Hash mHash;
	};

}

#include "hash_map.inl"
