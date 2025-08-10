// two integers n and k, where n is the number of digits and k [0,k-1] digits can be in this range.
// X is set of all possible N digit numbers that can be formed using the digits
// we need to find minimum length string that contains all the numbers in xor
// eg) n=2,k=2 then x = {00,01,10,11} and ans_string = "00110"

// idea is to build a graph where each node is a number in the set X and edges are formed by :
// Node A is connected to Node B if last N-1 digits of nodeA when appended with a digit between 0-k-1 gives nodeB
// then use DFS to find a path that visits all nodes exactly once (Hamiltonian path) and return the path as a string

// we always resuse the last N-1 digits of the previous number to form the next number so after we get string from dfs 
// we need to get rid of n-1 adjacent digits k^n-1 times 

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool dfs(int n, int k, int total_possibilities, string &path, set<string> &visited){
        if(visited.size() == total_possibilities){
            return true;
        }
        for(int i = 0; i < k; i++){
            string curr_node = path.substr(path.size() - n + 1);
            curr_node.push_back('0' + i);
            if(visited.find(curr_node) == visited.end()){
                visited.insert(curr_node);
                path.push_back('0' + i);
                if(dfs(n, k, total_possibilities, path, visited) == true){
                    return true;
                }
                path.pop_back();
                visited.erase(curr_node);
            }
        }
        return false;
    }
    string crackSafe(int n, int k) {
        string path = string(n - 1, '0');
        set<string> visited;
        int total_possibilities = pow(k, n);
        dfs(n, k, total_possibilities, path, visited);
        return path;
    }
};