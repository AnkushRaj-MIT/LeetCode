/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;
    int dfs(int id) {
        Employee* emp = mp[id];
        int sum = emp->importance;
        for (int sub : emp->subordinates) {
            sum += dfs(sub);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto emp : employees) {
            mp[emp->id] = emp;
        }
        return dfs(id);
    }
};