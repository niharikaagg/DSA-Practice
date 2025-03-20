// https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=page-faults-in-lru

/*
In operating systems that use paging for memory management, page replacement algorithm is needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.

Given a sequence of pages in an array pages[] of length N and memory capacity C, find the number of page faults using Least Recently Used (LRU) Algorithm. 
*/



class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_map<int, int> pageHistory;
        int pageFaults = 0;
        
        for(int i=0; i<N; i++)
        {
            if(pageHistory.size() < C)
            {
                if(pageHistory.find(pages[i]) == pageHistory.end())
                {
                    pageFaults++;
                }
            }
            
            else
            {
                if(pageHistory.find(pages[i]) == pageHistory.end())
                {
                    int min = INT_MAX, page;
                    
                    for(auto it : pageHistory)
                    {
                        if(it.second < min)
                        {
                            min = it.second;
                            page = it.first;
                        }
                    }
                    
                    pageHistory.erase(page);
                    pageFaults++;
                }
            }
            
            pageHistory[pages[i]] = i;
        }
        
        return pageFaults;
    }
};
