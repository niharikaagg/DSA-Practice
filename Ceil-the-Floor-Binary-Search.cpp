// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM

/*
You're given a sorted array 'a' of 'n' integers and an integer 'x'.

Find the floor and ceiling of 'x' in 'a[0..n-1]'.

Note:
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.
*/



pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int, int> ans;

	int s=0, e=n-1;
	int floor=-1;

	while(s<=e)
	{
		int mid = s+(e-s)/2;

		if(a[mid]<=x)
		{
			floor = a[mid];
			s = mid+1;
		}

		else	// (a[mid] > x)
		{
			e = mid-1;
		}
	}

	s=0, e=n-1;
	int ceil=-1;

	while(s<=e)
	{
		int mid = s+(e-s)/2;

		if(a[mid]>=x)
		{
			ceil = a[mid];
			e = mid-1;
		}

		else	// (a[mid] < x)
		{
			s = mid+1;
		}
	}

	ans = make_pair(floor, ceil);

	return ans;
}
