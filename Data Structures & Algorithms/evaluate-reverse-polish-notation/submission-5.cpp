class Solution {
    map<string, function<int(int, int)>> operatorMap;

   public:
    void operations(vector<string>& tokens, stack<int>& temp, string op) {
        if (temp.empty()) return;
        int d1 = temp.top();
        temp.pop();
        int d2 = temp.top();
        temp.pop();
        cout << operatorMap[op](d1, d2) << endl;
        temp.push(operatorMap[op](d1, d2));
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        if (tokens.size() < 0) return 0;
        operatorMap["+"] = [](int a, int b) { return a + b; };
        operatorMap["-"] = [](int a, int b) { return b - a; };
        operatorMap["*"] = [](int a, int b) { return a * b; };
        operatorMap["/"] = [](int a, int b) { return b / a; };

        int dig1, dig2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                operations(tokens, temp, tokens[i]);
            } else
                temp.push(stoi(tokens[i]));
        }
        return temp.top();
    }
};
