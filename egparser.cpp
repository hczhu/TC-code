#include	<cstdio>
#include	<cstdlib>
#include	<cstring>
#include	<string>
using namespace std;

char buf[1000];
char tc[100];
string Arg(void);

int
Trim(void)
{
	int n = strlen(buf);
	int i;
	for ( i = n - 1; i >= 0 && isspace(buf[i]); i-- ) ;
	n = i + 1;
	buf[n] = 0;
	for ( i = 0; i < n && isspace(buf[i]); i++ ) ;
	memmove(buf, buf + i, n - i);
	n -= i;
	buf[n] = 0;
	return n;
}

void
NextToken(void)
{
	int c;
	while ( c = getchar(), isspace(c) || ! isascii(c) ) ;
	ungetc(c, stdin);
}

string
ReadString(void)
{
	string r;
	int c;
	while ( (c = getchar()) != '"' ) r += c;
	return r + '"';
}

string
ArrayList(void)
{
	string r = "{" + Arg();
	int c;
	while ( 1 ) {
		NextToken();
		c = getchar();
		if ( c == ',' ) r += "," + Arg();
		else break;
	}
	r += '}';
	return r;
}

string
ReadToken(void)
{
	string r;
	int ch;
	while ( ! isspace(ch = getchar()) && ch != '}' && ch != ',' ) 
		r += ch;
	ungetc(ch, stdin);
	return r;
}

string
Arg(void)
{
	NextToken();
	int c;
	c = getchar();
	if ( c == 'R' ) return "R";
	else if ( c == '"' ) return '"' + ReadString();
	else if ( c == '{' ) return ArrayList();
	else return char(c) + ReadToken();
}

string
ArgList(void)
{
	string r = Arg();
	while ( 1 ) {
		string a = Arg();
		if ( a == "R" ) break;
		r += "," + a;
	}
	return r;
}

void
ParseOneCase(void)
{
	string a = ArgList();
	scanf("eturns:");
	string r = Arg();
	printf("%s %s\n", a.c_str(), r.c_str());
}

int
main()
{
	int t = 0;
	sprintf(tc, "%d)", t);
	while ( fgets(buf, sizeof buf, stdin) ) {
		int n = Trim();
		if ( strcmp(tc, buf) ) continue;
		ParseOneCase();
		sprintf(tc, "%d)", ++t);
	}
}
