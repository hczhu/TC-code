#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
#include	<vector>
#include	<string>
#include	<algorithm>
#include	<cctype>
#define pb push_back
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;
const int N = 10000;
string Arg(int &p);

bool ResultLL = 0;
bool ParseReturn = 0;
char str[N];
string id = "";
string last;
string typelist;

inline void NextToken(int &p) { while ( isspace(str[p]) ) ++p; }

string
Str(int &p)
{
	string res = "";
	while ( str[p] != '"' ) {
		res += str[p];
		++p;
	}
	return res;
}

string
NextID(void)
{
	int n = id.size() - 1;
	++id[n];
	while ( n >= 0 && id[n] > 'z' ) {
		id[n] = 'a';
		if ( n - 1 >= 0 ) ++id[n - 1];
		--n;
	}
	if ( n < 0 ) id += 'a';
	return id;
}

inline char *
Delim(const string type)
{
	if ( type == "string" ) return "\"";
	else return "";
}

inline void
GenPrimitive(string s, const string type)
{
	if ( type == "LL" || type == "long long" ) s += "LL";
	printf("\t%s %s = %s%s%s;\n", type.c_str(), NextID().c_str(), Delim(type), s.c_str(), Delim(type));
}

inline void
GenPB(string v, string c)
{
	printf("\t%s.pb(%s);\n", v.c_str(), c.c_str());
}

string
ArrayList(int &p)
{
	string tt = Arg(p);
	string a = last;
	string type = "vector< " + tt + " >";
	printf("\t%s %s;\n", type.c_str(), NextID().c_str());
	string v = id;
	GenPB(v, a);
	while ( 1 ) {
		NextToken(p);
		if ( str[p] != ',' ) break;
		//printf(",");
		++p;
		Arg(p);
		GenPB(v, last);
	}
	last = v;
	return type;
}

string
Arg(int &p)
{
	string type;
	NextToken(p);
	char ch = str[p];
	if ( ch == '"' ) {
		++p;
		string r = Str(p);
		++p;
		type = "string";
		GenPrimitive(r, type);
		last = id;
	} else if ( ch == '{' ) {
		++p;
		string type = ArrayList(p);
		++p;
		return type;
	} else {
		string r;
		while ( isdigit(str[p]) || str[p] == '-' ) {
			r += str[p];
			++p;
		}
		if ( str[p] == '.' || toupper(str[p]) == 'E' ) {
			++p;
			r += '.';
			while ( isdigit(str[p]) || toupper(str[p]) == 'E' || str[p] == '-' || str[p] == '+' ) {
				r += str[p];
				++p;
			}
			if ( ParseReturn ) type = "Double";
			else type = "double";
			GenPrimitive(r, type);
			last = id;
		} else {
			type = "int";
			if ( ParseReturn && ResultLL ) type = "LL";
			GenPrimitive(r, type);
			last = id;
		}
	}
	return type;
}

string
ArgList(int &p)
{
	string res;
	typelist = Arg(p);
	res = last;
	while ( 1 ) {
		NextToken(p);
		if ( str[p] != ',' ) break;
		//printf(",");
		++p;
		typelist += ", " + Arg(p);
		res += ", " + last;
	}
	return res;
}

int
main(int argc, char **argv)
{
	char *class_name = "Class";
	char *method_name = "Method";
	int testcase = 1;
	if ( argc >= 3 ) {
		class_name = argv[1];
		method_name = argv[2];
		if ( argc == 4 ) 
			testcase = atoi(argv[3]);
	}
	printf("int\nmain()\n{\n");
	printf("\ttestcase = %d;\n", testcase);
	fgets(str, sizeof str, stdin);
	int p = 0;
	string call = ArgList(p);
	ParseReturn = 1;
	string result = ArgList(p);
	string result_type = typelist;
	printf("\t%s %s;\n", class_name, NextID().c_str());
	string var = id;
	printf("\t%s %s = %s.%s(%s);\n", result_type.c_str(), NextID().c_str(), var.c_str(), 
			method_name, call.c_str());
	string output = id;
	printf("\tTestEqual(%s, %s);\n", result.c_str(), output.c_str());
	printf("}\n");
}
