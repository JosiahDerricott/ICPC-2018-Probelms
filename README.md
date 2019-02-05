# Random Index Vectors

A *Random Index Vector* (RIV) is a data structure that can represent very large arrays where most
elements are zero. Here, we consider a version of RIVs which can contain only −1, 0, and +1 as
elements. There are three basic operations on RIVs:

* Addition of two RIVs *a* and *b*; the resulting RIV *c* is defined by *c<sub>i</sub>* = *a<sub>i</sub>* + *b<sub>i</sub>* The values are clamped at ± 1, *i.e.,* we define 1 + 1 = 1 and (−1) + (−1) = −1.
* Multiplication of two RIVs *a* and *b*; the resulting RIV *d* is defined by *d<sub>i</sub>* = *a<sub>i</sub>b<sub>i</sub>*
* Rotation of an RIV a by some integer *k*; this shifts all of the values in *a* to the left by *k* indices. The first *k* values at the start of a go to the end of the array and become the rightmost values.

An RIV is written in its *condensed form.* This representation is a list that starts with the number
of nonzero values, followed by a sorted list of indices (1-indexed) that have nonzero values, where
the indices are negated if the values there are −1.

For example, consider an RIV representing an array
                                        (1, 0, −1, 0, 0, 0, −1, 0, 0, 1, 0).
There are 4 nonzero elements at indices 1, 3, 7 and 10, and the values at 3 and 7 are −1, so the condensed form of this RIV is
                                                 (4, 1, −3, −7, 10).
Given two RIVs in condensed form, add them, multiply them, and rotate them both. Output the
results in condensed form.

## Input

The first line of input contains two space-separated integers *n* and *k* (1 ≤ k ≤ n ≤ 10^18), where *n* is the full (uncondensed) length of the RIVs and *k* is the number of indices to rotate by.

Each of the next two lines contains a condensed form of an RIV, starting with an integer *m* (0 ≤ m ≤ 1,000), followed by *m* space-separated indices *i<sub>1</sub>, . . . , i<sub>m</sub>.* Each index *i<sub>j</sub>* is a nonzero integer between −*n* and *n* (inclusive).

## Output

Output four vectors, one per line, in condensed form:
* Sum of the two input RIVs.
* Product of the two input RIVs.
* First RIV rotated by *k*.
* Second RIV rotated by *k*.

###### Sample Input and Output

```
30 13                             |   12 -1 3 6 7 -9 11 18 19 20 22 26 -27
6 6 -9 -13 18 22 26               |   1 -13
8 -1 3 7 11 13 19 20 -27          |   6 5 9 13 23 -26 -30
                                  |   8 6 7 -14 -18 20 24 28 30
```
```
20 4                              |   8 -2 5 -8 -10 -12 15 18 19
9 -2 -4 -8 -11 -12 15 18 19 20    |   5 -4 -11 15 18 -20
7 4 5 -10 11 15 18 -20            |   9 -4 -7 -8 11 14 15 16 -18 -20
                                  |   7 1 -6 7 11 14 -16 20
```
