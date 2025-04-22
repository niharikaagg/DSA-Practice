// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

/*
Given an array par[] that stores all number from 1 to n (both inclusive and sorted) and k queries.

The task is to do the following operations on array elements :

1. UNION x z : Perform union of x and z i.e. parent of z will become the parent of x.
2. FIND x: Find the ultimate parent of x and print it.

Note: Initially all are the parent of themselves.The ultimate parent is the topmost node such that par[node]=node.
*/



// Disjoint sets can perform the find ultimate parent operation in constant time and used for dynamic graphs.

int find(int par[], int x) {
    // Find ultimate parent

    if(par[x] == x)
        return x;
    
    return find(par, par[x]);

}

void unionSet(int par[], int x, int z) {
    int px = find(par, x);
    int pz = find(par, z);
    
    if(px != pz)
        par[px] = pz;
}
