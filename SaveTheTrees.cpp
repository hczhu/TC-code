// BEGIN CUT HERE
// PROBLEM STATEMENT
// John has a very beautiful garden of trees near his home. The vector <int>s x and y contain the cartesian coordinates of all the trees in the garden. The i-th tree can be treated as a point on plane positioned at (x[i], y[i]).
Recently, a new law was issued, and it requires each garden to be surrounded by a fence. This fence must have a rectangular form with all its sides parallel to the coordinate axes. All trees in the garden must be inside the fence or on its border.
After hearing about this law John became very sad. Unfortunately, he doesn't have wood to build the fence and doesn't have extra money to buy wood. So, the only choice he has is to cut down some of his trees to obtain some wood and to build the fence around the remaining trees using this wood. You are given a vector <int> h, where h[i] represents the length of the fence that can be built using the wood obtained from cutting down the i-th tree. John can build the fence if and only if its perimeter is less than or equal to the sum of the elements of h corresponding to the trees he will cut down.
Of course, John likes his trees very much, so he wants to cut down as few of them as possible. Return the minimal number of trees that John must cut down in order to build a fence that will satisfy the law.

DEFINITION
Class:SaveTheTrees
Method:minimumCut
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int minimumCut(vector <int> x, vector <int> y, vector <int> h)


CONSTRAINTS
-x, y and h will each contain between 2 and 40 elements, inclusive.
-x, y and h will contain the same number of elements.
-Each element of x, y and h will be between 1 and 1,000,000, inclusive.
-All elements of x will be distinct.
-All elements of y will be distinct.


EXAMPLES

0)
{1, 2, 8, 9, 5}
{1, 8, 2, 9, 5}
{1, 1, 1, 1, 32}

Returns: 1

You can cut down the tree at (5, 5) and have just enough wood to build the fence with vertices at (1, 1) - (1, 9) - (9, 9) - (9, 1).

1)
{1, 2, 8, 9, 5}
{1, 8, 2, 9, 5}
{1, 1, 1, 1, 27}

Returns: 2

Now, cutting down the tree at (5, 5) doesn't give you enough wood, so you have to cut down one more tree. For example, you can cut 2 trees at (1, 1) and (5, 5) and build the fence with vertices at (2, 2) - (2, 9) - (9, 9) - (9, 2).

2)
{1, 2, 8, 9, 5}
{1, 8, 2, 9, 5}
{4, 4, 4, 4, 4}

Returns: 3

Cut down the trees at (1, 1), (2, 8), (9, 9) and build the fence with vertices at (5, 2) - (5, 5) - (8, 5) - (8, 2).

3)
{1, 2, 8, 9, 5}
{1, 8, 2, 9, 5}
{3, 3, 3, 3, 3}

Returns: 4

Cut down any 4 trees and build the fence around the remaining one.

4)
{3, 10, 6, 2, 8, 7, 5, 4, 9, 1}
{4, 10, 6, 9, 8, 7, 3, 2, 5, 1}
{4, 2, 2, 4, 4, 5, 4, 4, 2, 3}

Returns: 5

Cut down the trees at (3, 4), (2, 9), (5, 3), (4, 2), (1, 1) and build the fence with vertices at (6, 5) - (6, 10) - (10, 10) - (10, 5).

5)
{55, 67, 100, 38, 80, 98, 47, 58, 61, 33}
{87, 17, 20, 7, 57, 19, 23, 68, 27, 39}
{6, 2, 8, 8, 31, 25, 23, 19, 45, 4}

Returns: 6



// END CUT HERE
#line 82 "SaveTheTrees.cpp"
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <cstring>
#include <complex>
#include <numeric>
#include <functional>
//#define NDEBUG
#include <assert.h>
using namespace std;
#ifndef NDEBUG
    #define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
    #define hline() cerr<<"-----------------------------------------"<<endl;
#else
    #define debug(x)
    #define hline()
#endif



class SaveTheTrees {
	public:
	int minimumCut(vector <int> x, vector <int> y, vector <int> h) {
		
	}
};
