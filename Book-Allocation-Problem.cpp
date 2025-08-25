// https://www.naukri.com/code360/problems/allocate-books_1090540

/*
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

There are ‘m’ number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

If the allocation of books is not possible, return -1.
*/



int studentsToBooks(vector<int> &arr, int n, int m, int maxPages)
{
    int students = 1, pages = 0;
    for(int i = 0; i<n; i++)
    {
        if(pages + arr[i] > maxPages)
        {
            students++;
            pages = arr[i];
        }
        else
            pages += arr[i];
    }

    return students;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
        return -1;

    int s = *max_element(arr.begin(), arr.end());
    int e = accumulate(arr.begin(), arr.end(), 0);

    while(s <= e)
    {
        int mid = s + (e-s)/2;

        if(studentsToBooks(arr, n, m, mid) <= m)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return s;
}
