// Approach1: max heap + queue
// Time: O()
// Space: O()

// class Cooldown {
// public:
//     char task;
//     int count;
//     int ready_time;
//     Cooldown(char task, int count, int ready_time) {
//         this->task = task;
//         this->count = count;
//         this->ready_time = ready_time;
//     }
// };

// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         priority_queue<pair<int, char>> task_counts; // count, task
//         queue<Cooldown*> cooldowns;

//         unordered_map<char, int> task_counts_map;
//         for (char task: tasks) task_counts_map[task]++;

//         for (auto task: task_counts_map) {
//             task_counts.push({ task.second, task.first });
//         }

//         int time = 0;

//         while (!task_counts.empty() || !cooldowns.empty()) {
//             // push the ready task into the max. heap
//             while (!cooldowns.empty() && cooldowns.front()->ready_time <= time) {
//                 Cooldown* ready_task = cooldowns.front();
//                 cooldowns.pop();
//                 task_counts.push({ ready_task->count, ready_task->task });
//             }

//             // there is no ready task in current time
//             if (task_counts.empty()) {
//                 time = cooldowns.front()->ready_time;
//                 continue;
//             }

//             auto current_task = task_counts.top();
//             task_counts.pop();
//             if (current_task.first > 1) {
//                 Cooldown* cool_task = new Cooldown(current_task.second, current_task.first - 1, time + n + 1);
//                 cooldowns.push(cool_task);
//             }

//             time++;
//         }

//         return time;
//     }
// };

// Actually we don't have to store the task name
// Approach1: optimized approach1

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> task_counts; // count
        queue<pair<int, int>> cooldowns; // count, ready time

        unordered_map<char, int> task_counts_map;
        for (char task: tasks) task_counts_map[task]++;

        for (auto task: task_counts_map) {
            task_counts.push(task.second);
        }

        int time = 0;

        while (!task_counts.empty() || !cooldowns.empty()) {
            time++;

            // push the ready task into the max. heap
            while (!cooldowns.empty() && cooldowns.front().second <= time) {
                auto ready_task = cooldowns.front();
                cooldowns.pop();
                task_counts.push(ready_task.first);
            }

            // there is no ready task in current time
            if (task_counts.empty()) {
                time = cooldowns.front().second - 1;
                continue;
            }

            int current_task_count = task_counts.top();
            task_counts.pop();
            if (current_task_count > 1) {
                cooldowns.push({ current_task_count - 1, time + n + 1 });
            }
        }

        return time;
    }
};

