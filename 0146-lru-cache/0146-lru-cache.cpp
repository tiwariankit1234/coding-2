#include <unordered_map>
#include <algorithm>
#include <limits>

class LRUCache {
private:
    int capacity;
    int currentTime; // Sequence number to track order of usage
    std::unordered_map<int, int> cache;             // Stores key-value pairs
    std::unordered_map<int, int> usageOrder;        // Stores key-access time to determine LRU

public:
    LRUCache(int capacity) : capacity(capacity), currentTime(0) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }

        // Update access time
        usageOrder[key] = ++currentTime;
        return cache[key];
    }

    void put(int key, int value) {
        if (cache.size() >= capacity && cache.find(key) == cache.end()) {
            // Evict the least recently used item
            int lruKey = -1;
            int oldestTime = std::numeric_limits<int>::max();

            for (const auto& entry : usageOrder) {
                if (entry.second < oldestTime) {
                    oldestTime = entry.second;
                    lruKey = entry.first;
                }
            }

            // Remove the least recently used key from both maps
            if (lruKey != -1) {
                cache.erase(lruKey);
                usageOrder.erase(lruKey);
            }
        }

        // Insert or update the key-value pair and update access time
        cache[key] = value;
        usageOrder[key] = ++currentTime;
    }
};
