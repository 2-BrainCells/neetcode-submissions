class MinStack {
   private:
    long min;
    long top_elm;
    vector<long> arr;

   public:
    MinStack() { top_elm = -1; }

    void push(int val) {
        arr.push_back(val);
        top_elm += 1;
    }

    void pop() {
        arr.pop_back();
        top_elm -= 1;
    }

    int top() {
        return arr[top_elm];
    }

    int getMin() { 
        min = arr[0];
        for(int ele: arr){
            if(min > ele){
                min = ele;
            }
        }
        return min;
    }
};
