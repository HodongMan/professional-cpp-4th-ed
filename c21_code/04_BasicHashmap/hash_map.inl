#include <stdexcept>
#include <algorithm>
#include <utility>

namespace ProCpp {

	// Calculate a hash by treating the key as a sequence
	// of bytes and summing the ASCII values of the bytes.
	template <typename T>
	size_t hash<T>::operator()(const T& key) const
	{
		const size_t bytes = sizeof(key);
		size_t sum = 0;
		for (size_t i = 0; i < bytes; ++i) {
			unsigned char b = *(reinterpret_cast<const unsigned char*>(&key) + i);
			sum += b;
		}
		return sum;
	}




	// Calculate a hash by summing the ASCII values of all characters.
	size_t hash<std::string>::operator()(const std::string& key) const
	{
		size_t sum = 0;
		for (auto c : key) {
			sum += static_cast<unsigned char>(c);
		}
		return sum;
	}




	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void swap(hash_map<Key, T, KeyEqual, Hash>& first, hash_map<Key, T, KeyEqual, Hash>& second) noexcept
	{
		first.swap(second);
	}




	// Construct mBuckets with the correct number of buckets.
	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>::hash_map(const KeyEqual& equal, size_t numBuckets, const Hash& hash)
		: mBuckets(numBuckets), mEqual(equal), mHash(hash)
	{
		if (numBuckets == 0) {
			throw std::invalid_argument("Number of buckets must be positive");
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>& hash_map<Key, T, KeyEqual, Hash>::operator=(const hash_map<Key, T, KeyEqual, Hash>& rhs)
	{
		// check for self-assignment
		if (this == &rhs) {
			return *this;
		}

		// Copy-and-swap idiom
		auto copy = rhs;  // Do all the work in a temporary instance
		swap(copy);       // Commit the work with only non-throwing operations
		return *this;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>& hash_map<Key, T, KeyEqual, Hash>::operator=(hash_map<Key, T, KeyEqual, Hash>&& rhs) noexcept
	{
		swap(rhs);
		return *this;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	std::pair<typename hash_map<Key, T, KeyEqual, Hash>::ListType::iterator, size_t>
		hash_map<Key, T, KeyEqual, Hash>::findElement(const key_type& k)
	{
		// Hash the key to get the bucket.
		size_t bucket = mHash(k) % mBuckets.size();

		// Search for the key in the bucket.
		auto iter = find_if(begin(mBuckets[bucket]), end(mBuckets[bucket]),
			[this, &k](const auto& element) { return mEqual(element.first, k); });

		// Return a pair of the iterator and the bucket index.
		return std::make_pair(iter, bucket);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::value_type* hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k)
	{
		// Use the findElement() helper, and C++17 structured bindings.
		auto[it, bucket] = findElement(k);
		if (it == end(mBuckets[bucket])) {
			// Element not found -- return nullptr.
			return nullptr;
		}
		// Element found -- return a pointer to it.
		return &(*it);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	const typename hash_map<Key, T, KeyEqual, Hash>::value_type* hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k) const
	{
		return const_cast<hash_map<Key, T, KeyEqual, Hash>*>(this)->find(k);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	T& hash_map<Key, T, KeyEqual, Hash>::operator[] (const key_type& k)
	{
		// Try to find the element. If it doesn't exist, add a new element.
		auto[it, bucket] = findElement(k);
		if (it == end(mBuckets[bucket])) {
			mSize++;
			mBuckets[bucket].push_back(std::make_pair(k, T()));
			return mBuckets[bucket].back().second;
		} else {
			return it->second;
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::insert(const value_type& x)
	{
		// Try to find the element.
		auto[it, bucket] = findElement(x.first);

		if (it != end(mBuckets[bucket])) {
			// The element already exists.
			return;
		} else {
			// We didn't find the element, so insert a new one.
			mSize++;
			mBuckets[bucket].push_back(x);
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::erase(const key_type& k)
	{
		// First, try to find the element.
		auto[it, bucket] = findElement(k);

		if (it != end(mBuckets[bucket])) {
			// The element exists -- erase it.
			mBuckets[bucket].erase(it);
			mSize--;
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::clear() noexcept
	{
		// Call clear on each bucket.
		for (auto& bucket : mBuckets) {
			bucket.clear();
		}
		mSize = 0;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::swap(hash_map<Key, T, KeyEqual, Hash>& other) noexcept
	{
		using std::swap;

		swap(mBuckets, other.mBuckets);
		swap(mSize, other.mSize);
		swap(mEqual, other.mEqual);
		swap(mHash, other.mHash);
	}

}