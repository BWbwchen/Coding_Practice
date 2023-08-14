class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        // calculate number of idle
        int idle = 0;
        int total_task = tasks.size();

        int max_frequency = 0;
        int num_task_is_max_frequency = 0;

        vector<int> cnt(26, 0);
        for (auto &c : tasks) {
            cnt[c - 'A']++;
        }

        for (int i = 0; i < cnt.size(); ++i) {
            if (max_frequency < cnt[i]) {
                max_frequency = cnt[i];
                num_task_is_max_frequency = 1;
            } else if (max_frequency == cnt[i]) {
                num_task_is_max_frequency++;
            }
        }

        int gap = max_frequency - 1;
        int gap_len = n - (num_task_is_max_frequency - 1);

        int available_empty = gap * gap_len;
        int demand_task =
            total_task - max_frequency * num_task_is_max_frequency;

        idle = max(0, available_empty - demand_task);

        return total_task + idle;
    }
};
