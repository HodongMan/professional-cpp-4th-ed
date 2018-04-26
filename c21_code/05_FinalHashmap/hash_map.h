#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <iterator> 
#include <string>
#include <initializer_list>
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




	// const_hash_map_iterator class definition
	template <typename HashMap>
	class const_hash_map_iterator
	{
		// The hash_map class needs access to all members of the const_hash_map_iterator
		friend HashMap;

	public:
		using value_type = typename HashMap::value_type;
		using difference_type = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = value_type*;
		using reference = value_type&;
		using list_iterator_type = typename HashMap::ListType::const_iterator;

		// Bidirectional iterators must supply a default constructor.
		// Using an iterator constructed with the default constructor
		// is undefined, so it doesn't matter how it's initialized.
		const_hash_map_iterator() = default;

		const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* hashmap);

		// Don't need to define a copy constructor or operator= because the
		// default behavior is what we want.

		// Don't need destructor because the default behavior
		// (not deleting mHashmap) is what we want!

		const value_type& operator*() const;

		// Return type must be something to which -> can be applied.
		// Return a pointer to a pair<const Key, T>, to which the compiler
		// will apply -> again.
		const value_type* operator->() const;

		const_hash_map_iterator<HashMap>& operator++();
		const_hash_map_iterator<HashMap> operator++(int);

		const_hash_map_iterator<HashMap>& operator--();
		const_hash_map_iterator<HashMap> operator--(int);

		// The following are ok as member functions because we don't
		// support comparisons of different types to this one.
		bool operator==(const const_hash_map_iterator<HashMap>& rhs) const;
		bool operator!=(const const_hash_map_iterator<HashMap>& rhs) const;

	protected:
		size_t mBucketIndex = 0;
		list_iterator_type mListIterator;
		const HashMap* mHashmap = nullptr;

		// Helper methods for operator++ and operator--
		void increment();
		void decrement();
	};

	template <typename HashMap>
	class hash_map_iterator : public const_hash_map_iterator<HashMap>
	{
		// The hash_map class needs access to all members of the hash_map_iterator
		friend HashMap;

	public:
		using value_type = typename const_hash_map_iterator<HashMap>::value_type;
		using difference_type = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = value_type*;
		using reference = value_type&;
		using list_iterator_type = typename HashMap::ListType::iterator;

		hash_map_iterator() = default;
		hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* hashmap);
		
		value_type& operator*();
		value_type* operator->();

		hash_map_iterator<HashMap>& operator++();
		hash_map_iterator<HashMap> operator++(int);

		hash_map_iterator<HashMap>& operator--();
		hash_map_iterator<HashMap> operator--(int);
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
		using hasher = Hash;
		using key_equal = KeyEqual;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using hash_map_type = hash_map<Key, T, KeyEqual, Hash>;
		using iterator = hash_map_iterator<hash_map_type>;
		using const_iterator = const_hash_map_iterator<hash_map_type>;

	private:
		using ListType = std::list<value_type>;
	public:
		using local_iterator = typename ListType::iterator;
		using const_local_iterator = typename ListType::const_iterator;

		// The iterator classes need access to all members of the hash_map
		friend class hash_map_iterator<hash_map_type>;
		friend class const_hash_map_iterator<hash_map_type>;

		// Virtual destructor
		virtual ~hash_map() = default;

		// Throws invalid_argument if the number of buckets is illegal.
		explicit hash_map(const KeyEqual& equal = KeyEqual(), size_type numBuckets = 101, const Hash& hash = Hash());

		// Throws invalid_argument if the number of buckets is illegal.
		template <typename InputIterator>
		hash_map(InputIterator first, InputIterator last, const KeyEqual& equal = KeyEqual(),
			size_type numBuckets = 101, const Hash& hash = Hash());

		// Initializer list constructor
		// Throws invalid_argument if the number of buckets is illegal. 
		explicit hash_map(std::initializer_list<value_type> il, const KeyEqual& equal = KeyEqual(),
			size_type numBuckets = 101, const Hash& hash = Hash());

		// Copy constructor
		hash_map(const hash_map_type& src) = default;
		// Move constructor
		hash_map(hash_map_type&& src) noexcept = default;

		// Copy assignment operator
		hash_map_type& operator=(const hash_map_type& rhs);
		// Move assignment operator
		hash_map_type& operator=(hash_map_type&& rhs) noexcept;
		// Initializer list assignment operator
		hash_map_type& operator=(std::initializer_list<value_type> il);

		// Iterator methods
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		const_iterator cbegin() const;
		const_iterator cend() const;

		// Size methods
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		// Element insert methods
		T& operator[](const key_type& k);
		std::pair<iterator, bool> insert(const value_type& x);
		iterator insert(const_iterator hint, const value_type& x);
		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last);
		void insert(std::initializer_list<value_type> il);

		// Element delete methods
		size_type erase(const key_type& k);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);

		// Other modifying utilities
		void swap(hash_map_type& other) noexcept;
		void clear() noexcept;

		// Access methods for Standard Library conformity
		key_equal key_eq() const;
		hasher hash_function() const;

		// Lookup methods
		iterator find(const key_type& k);
		const_iterator find(const key_type& k) const;
		std::pair<iterator, iterator> equal_range(const key_type& k);
		std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

		size_type count(const key_type& k) const;

		size_type bucket_count() const;
		size_type max_bucket_count() const;
		size_type bucket(const Key& k) const;
		size_type bucket_size(size_type n) const;
		local_iterator begin(size_type n);
		const_local_iterator begin(size_type n) const;
		const_local_iterator cbegin(size_type n) const;
		local_iterator end(size_type n);
		const_local_iterator end(size_type n) const;
		const_local_iterator cend(size_type n) const;

	private:
		// Returns a pair containing an iterator to the found element with
		// a given key, and the index of that element's bucket.
		std::pair<typename ListType::iterator, size_t> findElement(const key_type& k);

		std::vector<ListType> mBuckets;
		size_type mSize = 0;
		KeyEqual mEqual;
		Hash mHash;
	};

}

#include "hash_map.inl"
