#include <vector>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <functional>

class ThreadPool
{
public:
    void start();
    void queue_job(const std::function<void()> &job);
    void stop();
    bool busy();

private:
    void thread_loop();

    bool should_terminate = false;
    std::mutex queue_mutex;
    std::condition_variable mutex_condition;
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> jobs;
};