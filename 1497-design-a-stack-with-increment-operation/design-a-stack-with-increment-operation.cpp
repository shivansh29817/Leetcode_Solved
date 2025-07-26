class CustomStack {
private:
    vector<int> stack;
    vector<int> inc;
    int maxSize, index = 0;
public:
    CustomStack(int maxSize) {
        stack.assign(maxSize , 0);
        inc.assign(maxSize , 0);
        this->maxSize = maxSize;
    }
    void push(int x) {
        if (index < maxSize) {
            stack[index] = x;
            inc[index] = 0;
            ++index;
        }
    }
    int pop() {
        if (index == 0) return -1;
        int idx = index - 1;
        int val = stack[idx] + inc[idx];
        if (idx > 0) inc[idx - 1] += inc[idx];
        --index;
        return val;
    }
    void increment(int k, int val) {
        int idx = min(k, index) - 1;
        if (idx >= 0) inc[idx] += val;
    }
};