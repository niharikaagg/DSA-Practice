// https://leetcode.com/problems/accounts-merge/description/

/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
*/



class DisjointSet {
    vector<int> size, parent;
    
    public:
        DisjointSet(int n) {
            size.resize(n, 1);
            parent.resize(n);
            
            for(int i=0; i<n; i++)
                parent[i] = i;
        }
        
        int findUltimateParent(int node) {
            if(node == parent[node])
                return node;
                
            return findUltimateParent(parent[node]);
        }
        
        void unionBySize(int u, int v) {
            int pu = findUltimateParent(u);
            int pv = findUltimateParent(v);
            
            if(pu == pv)
                return;
                
            if(size[pu] < size[pv])
            {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            
            else
            {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        unordered_map<string, int> mailMap;
        DisjointSet ds(n);

        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string mail = accounts[i][j];

                if(mailMap.find(mail) == mailMap.end())
                    mailMap[mail] = i;

                else
                    ds.unionBySize(i, mailMap[mail]);
            }
        }

        vector<vector<string>> mergedMails(n);

        for(auto it : mailMap)
        {
            string mail = it.first;
            int node = ds.findUltimateParent(it.second);

            mergedMails[node].push_back(mail);
        }
        
        vector<vector<string>> ans;

        // Push names
        for(int i=0; i<n; i++)
        {
            if(mergedMails[i].size() == 0)
                continue;

            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            
            for(auto it : mergedMails[i])
                temp.push_back(it);

            ans.push_back(temp);
        }

        return ans;
    }
};
