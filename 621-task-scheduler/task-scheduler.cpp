class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
    // Step 1: Count the frequency of each task
    unordered_map<char, int> taskCount;
    for (char task : tasks) {
        taskCount[task]++;
    }

    // Step 2: Use a max heap to keep track of the tasks' frequencies
    priority_queue<int> maxHeap;
    for (auto& entry : taskCount) {
        maxHeap.push(entry.second);
    }

    int intervals = 0;
    
    // Step 3: Simulate the process of executing tasks
    while (!maxHeap.empty()) {
        int cycles = n + 1; // The number of slots in each interval
        vector<int> tempList; // To store tasks that are cooling down

        // Execute as many as possible in the current cycle
        while (cycles > 0 && !maxHeap.empty()) {
            int currentTaskCount = maxHeap.top();
            maxHeap.pop();
            currentTaskCount--;
            if (currentTaskCount > 0) {
                tempList.push_back(currentTaskCount);
            }
            cycles--;
            intervals++;
        }

        // Push remaining tasks back to the max heap
        for (int count : tempList) {
            maxHeap.push(count);
        }

        // If there are still tasks left to execute, account for idle time
        if (!maxHeap.empty()) {
            intervals += cycles; // Add remaining idle time if any
        }
    }

    return intervals;
}
};