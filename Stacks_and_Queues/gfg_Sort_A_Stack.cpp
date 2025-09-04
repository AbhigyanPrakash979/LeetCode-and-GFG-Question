class SortedStack {
public:
    stack<int> s;

    void sort();

private:
    void checkSorted(stack<int>& s, int temp) {
        // Base case
        if (s.empty() || s.top() <= temp) {
            s.push(temp);
            return;
        }

        int top = s.top();
        s.pop();

        // Recursive call with original temp
        checkSorted(s, temp);

        // Backtrack
        s.push(top);
    }
};

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack::sort() {
    // Base case
    if (s.empty()) return;

    int temp = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sort();

    // Insert temp in sorted order
    checkSorted(s, temp);
}
