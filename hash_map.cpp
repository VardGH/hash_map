#include "hash_map.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace container {

hash_map::hash_map() 
    : m_buckets(7) 
{    
}

hash_map::hash_map(int count) 
    : m_buckets(count) 
{    
}

hash_map::hash_map(const std::pair<std::string, std::string>& elem) 
    : m_buckets(7) 
{
    insert(elem.first, elem.second);
}

hash_map::hash_map(const std::initializer_list<std::pair<std::string, std::string>>& init_list) 
    : m_buckets(10) 
{    
    for (const auto& elem : init_list) {
        insert(elem.first, elem.second);
    }
}

hash_map::hash_map(const hash_map& other) 
    : m_buckets(other.m_buckets) 
{
}

hash_map& hash_map::operator=(const hash_map& other) 
{
    if (this != &other) {
        m_buckets = other.m_buckets;
    }
    return *this;
}

hash_map::hash_map(hash_map&& other) noexcept 
    : m_buckets(std::move(other.m_buckets)) 
{    
}

hash_map& hash_map::operator=(hash_map&& other) noexcept 
{
    if (this != &other) {
        m_buckets = std::move(other.m_buckets);
    }
    return *this;
}

hash_map::~hash_map() 
{
    clear();
}

void hash_map::insert(const std::string& key, const std::string& value) 
{
    update_load_factor();

    int index = hash_function(key);

    for (auto& elem : m_buckets[index]) {
        if (elem.first == key) {
            elem.second = value;
            return;
        }
    }

    m_buckets[index].emplace_front(key, value);
}

void hash_map::clear() 
{
    m_buckets.clear();
}

float hash_map::load_factor() const 
{
    // Load factor = (number of elements) / (number of buckets)
    int num_elements = size();
    int num_buckets = m_buckets.size();

    if (num_buckets == 0) {
        return 0.0;
    }

    return static_cast<float>(num_elements) / num_buckets;
}

int hash_map::size() const
{
    int elements = 0;
    for (const auto& bucket : m_buckets) {
        for (const auto& elem : bucket) {
            ++elements;
        }
    }
    return elements;
}

void hash_map::rehash(int count) 
{
    if (count <= 0) {
        return; // Invalid count
    }

    std::vector<std::forward_list<std::pair<std::string, std::string>>> new_map(count);

    for (const auto& bucket : m_buckets) {
        for (const auto& elem : bucket) {
            int index = hash_function(elem.first, count);
            new_map[index].emplace_front(elem.first, elem.second);
        }
    }

    m_buckets = std::move(new_map);
}

void hash_map::update_load_factor() 
{
    if (load_factor() > 0.75) {
        rehash(m_buckets.size() * 2);
    }
}

int hash_map::hash_function(const std::string& str, int bucket_count) 
{
    int hash = 0;
    for (char ch : str) {
        hash = (hash * 31) + ch;
    }
    return std::abs(hash) % bucket_count;
}

int hash_map::hash_function(const std::string& str) 
{
    return hash_function(str, m_buckets.size());
}

std::string& hash_map::operator[](const std::string& key) 
{
    int index = hash_function(key);

    for (auto& elem : m_buckets[index]) {
        if (elem.first == key) {
            return elem.second;
        }
    }

    m_buckets[index].emplace_front(key, std::string());
    return m_buckets[index].front().second;
}

void hash_map::remove(const std::string& key) 
{
    int index = hash_function(key);

    auto& bucket = m_buckets[index];
    auto prev = bucket.before_begin();

    for (auto it = bucket.begin(); it != bucket.end(); ++it, ++prev) {
        if (it->first == key) {
            bucket.erase_after(prev);
            return;
        }
    }
}

std::string& hash_map::at(const std::string& key) 
{
    int index = hash_function(key);
    
    auto& bucket = m_buckets[index];
    for (auto& elem : bucket) {
        if (elem.first == key) {
            return elem.second;
        }
    }

    throw std::out_of_range("Key not found in hash_map");
}

void hash_map::print() const 
{
    for (const auto& bucket : m_buckets) {
        for (const auto& elem : bucket) {
            std::cout << "Key: " << elem.first << ", Value: " << elem.second << std::endl;
        }
    }
}

int hash_map::bucket_count() const
{
    return m_buckets.size();
}

int hash_map::bucket_size(int index) const
{
    if (index >= m_buckets.size()) {
        return 0; // Invalid bucket index
    }

    size_t count = 0;
    for (const auto& elem : m_buckets[index]) {
        ++count;
    }
    return count;
}

bool hash_map::empty() const 
{
    for (const auto& bucket : m_buckets) {
        if (!bucket.empty()) {
            return false;
        }
    }
    return true;
}

} // namespace container