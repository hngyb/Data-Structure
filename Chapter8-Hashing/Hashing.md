# 8. Hasing
## Ideal Hashing
- Uses a 1D array (or table) __table[O:b-1]__.
    - Each position of this array is a bucket.
    - A bucket can normally hold only one dictionary pair.
- Uses a has function f that converts each key k into an index in the range[0, b-1].
    - f(k) is the home bucket for key k.
- Every dictionary pair (key, element) is stored in its home bucket table[f[key]].
## What Can Go Wrong?
- A __collision__ occurs when the home bucket for a new pair is occupied by a pair with a different key.
- An __overflow__ occurs when there is no space in the home bucket for the new pair.
## Hash Table Issues
- Choice of hash function.
- Overflow handling method.
- Size (number of buckets) of hash table.
 ## Hash Functions
 - Two parts:
    - Convert key into a nonnegative integer in case the key is not an integer.
- Map an integer into a home bucket.
    - f(k) is an integer in the range [0, b-1], where b is the number of buckets in the table.
## Overflow Handling
- Linear probing (linear open addressing)
- Quadratic probing
- Random probing