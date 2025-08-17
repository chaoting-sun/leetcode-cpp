class Cooldown {
public:
    char task;
    int count;
    int ready_time;
    Cooldown(char task, int count, int ready_time) {
        this->task = task;
        this->count = count;
        this->ready_time = ready_time;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> task_counts; // count, task
        queue<Cooldown*> cooldowns;

        unordered_map<char, int> task_counts_map;
        for (char task: tasks) task_counts_map[task]++;

        for (auto task: task_counts_map) {
            task_counts.push({ task.second, task.first });
        }

        int time = 0;

        while (!task_counts.empty() || !cooldowns.empty()) {
            // push the ready task into the max. heap
            while (!cooldowns.empty() && cooldowns.front()->ready_time <= time) {
                Cooldown* ready_task = cooldowns.front();
                cooldowns.pop();
                task_counts.push({ ready_task->count, ready_task->task });
            }

            // there is no ready task in current time
            if (task_counts.empty()) {
                time = cooldowns.front()->ready_time;
                continue;
            }

            auto current_task = task_counts.top();
            task_counts.pop();
            if (current_task.first > 1) {
                Cooldown* cool_task = new Cooldown(current_task.second, current_task.first - 1, time + n + 1);
                cooldowns.push(cool_task);
            }

            time++;
        }

        return time;
    }
};

// task_counts: [(2,A), (2,B)], cooldowns: [], n=2
// time = 1: -> use A
//           -> task_counts: [(2,B)], cooldowns: [(A,1,4)]
// time = 2: -> use B
//           -> task_counts: [], cooldowns: [(A,1,4), (B,1,5)]
// time = 3  -> time = 4
// time =