# hash_map

`container::hash_map` is a C++ implementation of a hash map data structure. It provides a dynamic key-value storage and retrieval system, allowing efficient insertion, removal, and querying of elements based on their keys.

## Table of Contents

- [Features](#features)
- [Functions](#functions)

## Features

- Dynamic resizing of the underlying hash table to maintain efficient performance.
- Support for constant load factor management.
- Easy-to-use interface for inserting, removing, and querying key-value pairs.

## Functions

- **`hash_map()`**
  - Initializes an empty hash map with a default number of buckets.

- **`explicit hash_map(int count)`**
  - Initializes an empty hash map with a specified number of buckets (`count`).

- **`hash_map(const std::pair<std::string, std::string>& elem)`**
  - Initializes a hash map with an initial key-value pair (`elem`).

- **`hash_map(const std::initializer_list<std::pair<std::string, std::string>>& init_list)`**
  - Initializes a hash map with key-value pairs from an initializer list (`init_list`).

- **`hash_map(const hash_map& other)`**
  - Creates a new hash map as a copy of another hash map (`other`).

- **`hash_map& operator=(const hash_map& other)`**
  - Assigns the content of another hash map (`other`) to the current hash map.

- **`hash_map(hash_map&& other)`**
  - Creates a new hash map by moving the content of another hash map (`other`).

- **`hash_map& operator=(hash_map&& other)`**
  - Assigns the content of another hash map (`other`) to the current hash map.

- **`~hash_map()`**
  - Cleans up the resources used by the hash map.

- **`void insert(const std::string& key, const std::string& value)`**
  - Inserts a key-value pair into the hash map.

- **`void remove(const std::string& key)`**
  - Removes a key-value pair with the specified key from the hash map.

- **`void clear()`**
  - Clears all key-value pairs from the hash map.

- **`std::string& operator[](const std::string& key)`**
  - Accesses or inserts a key-value pair into the hash map using the specified key.

- **`std::string& at(const std::string& key)`**
  - Accesses a key-value pair with bounds checking based on the specified key.

- **`float load_factor() const`**
  - Calculates and returns the current load factor of the hash map.

- **`int bucket_count() const`**
  - Gets the total number of buckets in the hash map.

- **`int bucket_size(int index) const`**
  - Gets the size (number of key-value pairs) of a specific bucket in the hash map.

- **`int size() const`**
  - Gets the number of key-value pairs in the hash map.

- **`bool empty() const`**
  - Checks if the hash map is empty.

- **`void print() const`**
  - Prints the contents of the hash map to the console.
