/*
 * File: stringmap.h
 * -----------------
 * This interface exports a simplified version of Map class in which
 * the keys and values are always strings.
 */

#ifndef _stringmap_h
#define _stringmap_h

#include <string>

#include "vector.h"
class StringMap {

public:

/*
 * Constructor: StringMap
 * Usage: StringMap map;
 * ---------------------
 * Initializes a new empty map that uses strings as both keys and values.
 */

    StringMap();

/*
 * Destructor: ~StringMap
 * ----------------------
 * Frees any heap storage associated with this map.
 */

    std::string get(const std::string & key) const;

/*
 * Method: put
 * Usage: map.put(key, value);
 * ---------------------------
 * Associate key with value in this map.
 */

void put(const std::string & key, const std::string & value);

/*
 * Notes on representation
 * -----------------------
 * This version of the StringMap class uses a hash table that keeps the
 * key-value pairs in an array of buckets, each of which is a linked list
 * of keys that hash to that bucket.
 */

private:

/* Type definition for cells in the bucket chain */

    struct Cell {
        std::string key;
        std::string value;
        Cell *link;
    };

/* Constant definitions */

    static const int INITIAL_BUCKET_COUNT = 13;

/* Instance variables */

    Cell **buckets;         // Dynamic array of pointers to cells
    int nBuckets;           // The number of buckets in the array

/* Private methods */

    int hashCode(const string & str) const;
    Cell *findCell(int bucket, const std::string & key) const;

/* Make copying illegal */

    StringMap(const StringMap & src) { }
    StringMap & operator=(const StringMap & src) { return *this; }

};

#endif