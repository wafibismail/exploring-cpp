/*
 * File: set.h
 * -----------
 * This interface exports the Set class, a collection for storing a set
 * of distinct elements
 */

#ifndef _set_h
#define _set_h

#include "map.h" // from the Stanford libraries, not in my repo
#include "vector.h"

/*
 * Class: Set<ValueType>
 * ---------------------
 * This template class stores a collection of distinct elements.
 */

template <typename Value>
class Set {

public:

/*
 * Constructor: Set
 * Usage: Set<ValueType> set;
 * --------------------------
 * Initializes an empty set of the specified value type.
 */

    Set();

/*
 * Destructor: ~Set
 * ----------------
 * Frees any heap storage associated with set.
 */

    ~Set();

/*
 * Method: size
 * Usage: int count = set.size();
 * ------------------------------
 * Returns the number of elements in this set.
 */

    int size() const;

/*
 * Method: isEmpty
 * Usage: if (set.isEmpty()) . . .
 * -------------------------------
 * Returns true if this set contains no elements.
 */

    bool isEmpty() const;

/*
 * Method: add
 * Usage: set.add(value);
 * ----------------------
 * Adds an element to this set if it is not already there.
 */

    void add(const ValueType & value);

/*
 * Method: remove
 * Usage: set.remove(value);
 * -------------------------
 * Removes an element from this set. If the value was not contained in the
 * set, the set remains unchanged.
 */

    void remove(const ValueType & value);

/*
 * Method: contains
 * Usage: if (set.contains(value)) . . .
 * -------------------------------------
 * Returns true if the specified value is in this set.
 */

    bool contains(const ValueType & value) const;

/*
 * Method: clear
 * Usage: set.clear();
 * ------------------
 * Removes all elements from this set.
 */

    void clear();

/*
 * Method: isSubsetOf
 * Usage: if (set.isSubsetOf(set2)) . . .
 * --------------------------------------
 * Implements the subset relation for sets. This method returns true
 * if every element of this set is contained in set2.
 */

    bool isSubsetOf(const Set & set2) const;

/*
 * Operator: ==
 * Usage: set1 == set2
 * -------------------
 * Returns true if set1 and set2 contain the same elements.
 */

    bool operator==(const Set * set2) const;

/*
 * Operator: !=
 * Usage: set1 != set2
 * -------------------
 * Returns true if set1 and set2 are different.
 */

    bool operator!=(const Set * set2) const;

/*
 * Operator: +
 * Usage: set1 + set2
 *        set1 + value
 * -------------------
 * Returns the union of sets set1 and set2, which is the set of elements
 * that appear in at least one of the two sets. The second form returns
 * the set formed by adding a single element.
 */

    Set operator+(const Set & set2) const;
    Set operator+(const ValueType & value) const;

/*
 * Operator: *
 * Usage: set1 * set2
 * ------------------
 * Returns the intersection of sets set1 and set2, which is the set of all
 * elements that appear in both.
 */

    Set operator*(const Set & set2) const;

/*
 * Operator: -
 * Usage: set1 - set2
 *        set1 - value
 * -------------------
 * Returns the difference of sets set1 and set2, which is all the
 * elements that appear in set1 but not set2. The second form returns
 * the set formed by removing a single element.
 */

    Set operator-(const Set & set2) const;
    Set operator-(const ValueType & value) const;

/*
 * Operator: +=
 * Usage: set1 += set2;
 *        set1 += value;
 * ---------------------
 * Adds all elements from set2 (or the single specified value) to set1;
 */

    Set & operator+=(const Set & set2);
    Set & operator+=(const ValueType & value);

/*
 * Operator: *=
 * Usage: set1 *= set2;
 * ---------------------
 * Removes any elements from set1 that are not present in set2;
 */

    Set & operator*=(const Set & set2);

/*
 * Operator: *=
 * Usage: set1 *= set2;
 *        set1 *= value;
 * ---------------------
 * Removes all elements from set2 (or a single value) from set1;
 */

    Set & operator*=(const Set & set2);
    Set & operator*=(const ValueType & value);

};

#endif