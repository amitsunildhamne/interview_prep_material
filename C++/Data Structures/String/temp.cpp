#include <bits/stdc++.h>

using namespace std;

#define count_carry 

#if defined(string_compress)
string *StringCompress(string *ip)
{
	int i;
	int ctr = 0;
	string *ret = new string;

	if (ip->length() < 1) {
		printf("Null string\n");
		return ret;
	}

	for (i=1; i<=ip->length(); ++i) {
		++ctr;
		if ((i==ip->length()) || ((*ip)[i] != (*ip)[i-1])) {
			*ret += (*ip)[i-1];
			*ret += '0'+ctr;
			ctr=0;
		}
	}

	return ret;
}

int main(void)
{
	string a;
	cout<<"Enter new string\n:"<<endl;
	cin>>a;
	string *b = StringCompress(&a);
	cout<<*b<<endl;
	delete b;
	return 0;
}

#elif defined(check_paranthesis)
bool CheckParanthesis(string a)
{
	stack <char> stk;
	char ch;
	bool ret = false;

	for (int i=0; i<a.length(); ++i) {
		if (('{'==a[i]) || ('['==a[i]) || ('('==a[i])) {
			stk.push(a[i]);
		} else if (('}'==a[i]) || (']'==a[i]) || (')'==a[i])) {
			if (true == stk.empty()) {
				goto done;
			}
			ch = stk.top();
			if ((('}' == a[i]) && ('{' == ch)) ||
				((')' == a[i]) && ('(' == ch)) ||
				((']' == a[i]) && ('[' == ch))) {
				stk.pop();
			} else {
				goto done;
			}
		} else {
			cout<<"Unknown Error\n";
			goto done;
		}
	}

	ret = true;

done:
	return ret;
}

int main(void)
{
	string a;
	cout<<"Enter new paranthesis string\n:"<<endl;
	cin>>a;
	bool b = CheckParanthesis(a);
	cout<<"Is Balanced: "<<b<<endl;
	return 0;
}

#elif defined(count_carry)
void StringRev(char *str, int len)
{
	char ch;

	for (int i=0; i<len/2; ++i) {
		ch = str[i];
		str[i] = str[(len-1) - i];
		str[(len-1) - i] = ch;
	}
}

int CountCarry(char *a, char *b)
{
	int a_val=0;
	int b_val=0;
	int carry=0;
	int sum=0;
	int i;
	int a_len = strlen(a);
	int b_len = strlen(b);
	int ret=0;

	StringRev(a, a_len);
	StringRev(b, b_len);
	printf("DBG a:%s\tb:%s\n", a, b);

	for (i=0; (i<a_len)||(i<b_len); ++i) {
		if (i<a_len) {
			if (('0'>a[i]) || ('9'<a[i])) {
				ret = -1;
				goto done;
			}
			a_val = a[i]-'0';
		}

		if (i<b_len) {
			if (('0'>b[i]) || ('9'<b[i])) {
				ret = -2;
				goto done;
			}
			b_val = b[i]-'0';
		}

		sum = a_val + b_val + carry;
		carry = sum/10;
		if (0 < carry) {
			++ret;
		}
		printf("a:%d b:%d sum:%d carry:%d\n", a_val, b_val, sum, carry);
		a_val = b_val = 0;
	}

done:
	return ret;
}

int main(void)
{
	char a[100];
	char b[100];

	scanf("%s", a);
	scanf("%s", b);
	printf("a:%s\tb:%s\n", a, b);
	printf("\n");
	printf("%d\n", CountCarry(a, b));

	return 0;
}

#endif
