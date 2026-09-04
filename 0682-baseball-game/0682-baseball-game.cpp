class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>stk;
        for(string op : ops){
            switch(op[0]){
                case 'D':
                    stk.push(stk.top() * 2);
                    break;
                case 'C':
                    stk.pop();
                    break;
                case '+':{
                    int val1 = stk.top();
                    stk.pop();
                    int val2 = stk.top();
                    stk.pop();
                    stk.push(val2);
                    stk.push(val1);
                    stk.push(val2 + val1);
                    break;
                }     
                default:
                    stk.push(stoi(op));
            }
        }
        int total = 0;
        while(!stk.empty()){
            total += stk.top();
            stk.pop();
        }
            
        return total;
    }
};