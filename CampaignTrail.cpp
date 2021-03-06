// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Your are running for president of a country that uses an electoral college to select its leader.
The country is comprised of states, each having a set number of electors.
All electors support the presidential candidate who wins the popular vote in their state.
The candidate supported by the greatest number of electors wins the election.



National election laws permit you to campaign in a limited number of states,
given as an int visits.
You are given the number of electors in each state as a vector <int> electors.
Your estimates of the probabilies you have for winning the popular vote in each state
with and without visiting it are given as vector <int>s winCurrent and winIfVisited,
respectively, both expressed as percents.



The states hold their elections one at a time (in the order they are represented in electors,
winCurrent, and winIfVisited).
You get to see the result of each election before deciding if you wish to visit the next state to hold an election.



Compute your chance of winning the election, assuming that you make optimal choices regarding which state(s) to visit.


DEFINITION
Class:CampaignTrail
Method:probWin
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double probWin(vector <int> electors, vector <int> winCurrent, vector <int> winIfVisited, int visits)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1e-9.
-You want to win the election.  A tie results in a drawn-out legal battle, which as far as you are concerned is just as bad as losing.


CONSTRAINTS
-electors will contain between 1 and 50 elements, inclusive.
-electors, winCurrent, and winIfVisited will each have the same number of elements.
-Each element of electors will be between 1 and 50, inclusive.
-Each element of winCurrent and winIfVisited will be between 0 and 100, inclusive.
-visits will be between 0 and the number of elements in electors, inclusive.


EXAMPLES

0)
{ 5, 1, 5 }
{ 0, 50, 0 }
{ 50, 100, 50 }
2

Returns: 0.625

You should definitely visit the first state.
If you win the first state, then you can guarantee yourself the support of 6 electors by visiting the second state.
If you lose the first state, your only chance is to visit the third state instead.

1)
{ 4, 9, 5 }
{ 0, 50, 50 }
{ 100, 100, 0 }
1

Returns: 0.5

If you visit the second state, you will win the election if and only if you win the third state, so your chances are 50%.

2)
{ 5, 9, 4 }
{ 50, 50, 0 }
{ 0, 100, 100 }
1

Returns: 0.75

The same data as in the previous example, but in the reverse order. Here the following strategy guarantees you winning the election with 75% probability. Wait for the results in the first state. If you win there, then you can guarantee winning the election by visiting the second state. Otherwise, it's better to visit the third state to obtain 50% probability of winning the election.

3)
{ 1, 1, 1, 1, 3 }
{ 0, 0, 0, 0, 49 }
{ 100, 100, 100, 100, 51 }
1

Returns: 0.49


There are 4 states with 1 elector each.  You will win each of those states that you visit with 100% probability, and will lose each that you do not.  If you visit the fifth state (with 3 electors) you will increase your chance from 49% to 51%.



With only time to visit 1 state, your best option is to visit one of the first 4.  Then you will win the election if and only if you win the 5th state.  If instead you chose to visit the 5th state, you would have a 0% chance of winning the election.


4)
{ 1, 1, 1, 1, 3 }
{ 0, 0, 0, 0, 49 }
{ 100, 100, 100, 100, 51 }
2

Returns: 0.51

With time to visit 2 states, you can now visit the 5th state and increase your chance of winning to 51%. 

5)
{ 1, 1, 1, 1, 3 }
{ 0, 0, 0, 0, 49 }
{ 100, 100, 100, 100, 51 }
4

Returns: 1.0

With time to visit 4 states, you can change your strategy and visit all the single-elector states and ignore the 5th state.

6)
{ 1, 1, 1 }
{ 25, 50, 25 }
{ 50, 25, 50 }
3

Returns: 0.5

You better stay away from the second state, as campaigning there will decrease your chance of winning.

7)
{ 1, 1 }
{ 0, 0 }
{ 0, 100 }
1

Returns: 0.0

It is impossible to win the election outright.

// END CUT HERE
#line 142 "CampaignTrail.cpp"
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



class CampaignTrail {
	public:
	double probWin(vector <int> electors, vector <int> winCurrent, vector <int> winIfVisited, int visits) {
		
	}
};
