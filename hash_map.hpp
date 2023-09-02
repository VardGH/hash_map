#ifndef HASH_MAP
#define HASH_MAP

#include <vector>
#include <forward_list>
#include <string>
#include <initializer_list>
#include <utility>

namespace container {

class hash_map
{
public:
    // Constructors
    hash_map();
    explicit hash_map(int count);
    hash_map(const std::pair<std::string, std::string>& elem);
    hash_map(const std::initializer_list<std::pair<std::string, std::string>>& init_list);

    hash_map(const hash_map& other); // Copy Constructor
    hash_map& operator=(const hash_map& other); // Copy Assignment Operator
    hash_map(hash_map&& other)  noexcept; // Move Constructor
    hash_map& operator=(hash_map&& other)  noexcept; // Move Assignment Operator
    ~hash_map(); // Destructor

public:
    // Modifiers
    void insert(const std::string& key, const std::string& value); // Inserts elements 
    void remove(const std::string& key); // Remove an element
    void clear(); // Clears the contents

    // Lookup
    std::string& operator[](const std::string& key); // Access or insert specified element
    std::string& at(const std::string& key); // Access specified element with bounds checking

    // Hash policy
    float load_factor() const; // Calculate the current load factor

    // Bucket interface
    int bucket_count() const; // Get the total number of buckets
    int bucket_size(int index) const; // Get the size of a specific bucket

    // Capacity
    int size() const; // Get the number of elements
    bool empty() const; // Check if the hash set is empty

    // helper
    void print() const; // Print the contents of the hash map  

private:
    int hash_function(const std::string& str);  // Compute the hash value for a key
    int hash_function(const std::string& str, int bucket_count);
    void rehash(int count); // Rehash the hash set with a new count
    void update_load_factor(); // Helper function for load factor updates

private:
    std::vector<std::forward_list<std::pair<std::string, std::string>>> m_buckets;
};

} // namespace container

#endif // HASH_MAP