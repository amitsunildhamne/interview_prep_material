#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int find_max_position(unsigned int itr,const unsigned int n, unsigned int array[])
{
	unsigned int ret_val;
	if(itr < n) {
		if (itr + array[itr] < n) {
			ret_val = itr +  distance(array, max_element(array + itr, array + itr + array[itr]));
			cout<< "c1 " << ret_val<< endl;
		} else {
			ret_val = itr + distance(array, max_element(array + itr, array + n - 1));
			cout << "c2 "<< ret_val<< endl;
		}
	} else {
		ret_val = itr;
		cout<< "c3 "<< ret_val<< endl;
	}

	return ret_val;
}

int min_hops(const unsigned int n, unsigned int array[])
{
	unsigned int itr = 0, hops = 0;
	if (n < 0 )
		return -1;
	else if (n == 0)
		return 0;

	while(1) {
		itr = find_max_position(itr, n, array);
        hops++;
		if (itr >= n-1) break;
	}
	return hops;
}

int main()
{
	unsigned int array[] = {4, 3, 2, 6, 8, 3, 1 , 9, 6, 2};
	const unsigned int n = sizeof(array)/sizeof(array[0]);
	cout<<min_hops(n, array)<<endl;
	return 0;	
}
