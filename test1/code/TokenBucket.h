#pragma once
/*
## Analyzing the `tokensToAdd` Calculation

**Breakdown of the `tokensToAdd` Calculation:**

```cpp
auto tokensToAdd = (now - m_lastRefillTS) * m_refillRate / 1e9;
```

This line calculates the number of tokens to be added to the bucket based on the elapsed time since the last refill and the 
specified refill rate.

### Explanation:

1. **Time Calculation:**
   - `now - m_lastRefillTS` calculates the elapsed time in nanoseconds.

2. **Multiplication:**
   - `(now - m_lastRefillTS) * m_refillRate` multiplies the elapsed time by the refill rate to get the number of tokens that should 
   have been added.

3. **Division:**
   - `/ 1e9` converts the result from nanoseconds to seconds. This is necessary because the `m_refillRate` is typically specified in
   tokens per second.

**Example:**
* If the elapsed time is 1 second and the refill rate is 10 tokens per second, `tokensToAdd` will be 10.
* If the elapsed time is 0.5 seconds and the refill rate is 20 tokens per second, `tokensToAdd` will be 10.

**Key Points:**

* The `refillRate` is essential for controlling the rate at which tokens are replenished.
* The `1e9` constant is used to convert nanoseconds to seconds.
* The calculated `tokensToAdd` value is then used to update the `m_currentBucketSize`.

**Would you like to explore other aspects of the `TokenBucket` class or discuss potential optimizations?**

*/

namespace TokenBucket
{
	template <typename Key, typename Value>
	class ConcurrentMap {
	public:
		ConcurrentMap() {}

		void insert(const Key& key, const Value& value) {
			lock_guard<std::mutex> lock(mutex_);
			map_[key] = value;
		}

		Value get(const Key& key) {
			lock_guard<std::mutex> lock(mutex_);
			return map_[key];
		}

		void erase(const Key& key) {
			lock_guard<std::mutex> lock(mutex_);
			map_.erase(key);
		}

	private:
		mutex mutex_;
		map<Key, Value> map_;
	};
	class TokenBucket
	{
		int m_maxBucketSize, m_refillRate, m_currentBucketSize;
		chrono::steady_clock::time_point m_lastRefillTS;
	public:
		TokenBucket(int capacity, int refillRate) : m_maxBucketSize(capacity), m_refillRate(refillRate), m_currentBucketSize(capacity)
		{
			m_lastRefillTS = chrono::high_resolution_clock::now();
		}

		bool allowRequest(int tokens)
		{
			refill();
			if (m_currentBucketSize > tokens)
			{
				m_currentBucketSize -= tokens;
				return true;
			}
			return false;
		}
		void refill()
		{
			auto now = chrono::high_resolution_clock::now();
			auto tokensToAdd = (now - m_lastRefillTS) * m_refillRate / 1e9; // 1e9 converts nano to seconds
			m_currentBucketSize = min(int(m_currentBucketSize + tokensToAdd.count()), m_maxBucketSize); // never exceed max capacity
			m_lastRefillTS = now;
		}

	};
	/* we need the following classes
	* JobScheduler
	* RulesCache
	* ClientIdentifier
	* RateLimniter
	*
	* */
	class JobScheduler
	{
		void start() {} // execute RetrieveRulesTask 
		void stop() {}
		void RetrieveRulesTask() {} // makes remote call to rules service, create token buckets and cache them
	};

	class RulesCache
	{
		ConcurrentMap<int, int>  m_map;
		void TokenRulesCache() {} // stores token bucket objects into concurrent map
	};

	class ClientIdentifier
	{
		void ClientIdentifierBuilder() {} // creates unique id for client from request context
	};
	class RateLimiter
	{
		void RetrieveToken() {}
		bool allowsRequest()
		{
			TokenBucket tb(1000, 10);
			return tb.allowRequest(6);
		}
	};

}


