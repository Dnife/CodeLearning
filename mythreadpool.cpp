#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

template<typename T>
class mythreadpool
{
public:
    mythreadpool(int n = 1);
    ~mythreadpool();
    queue<T *> tasks_queue;
    void append(T* request);
    bool isIdle();
private:
    void work_func();
private:
    int thread_number;
    bool stop;
    vector<thread> thread_pool;
    queue<int> status_queue;
    mutex queue_mutex;
    condition_variable condition;
};

template <typename T>
mythreadpool<T>::mythreadpool(int n):stop(false)
{
    thread_number = n;
    for (int i = 0; i < thread_number; i++)
    {
        thread_pool.emplace_back(&work_func,this);
    }
    cout<<"Creat "<< thread_number<<" threads."<<endl;
}

template <typename T>
mythreadpool<T>::~mythreadpool()
{
    while (!status_queue.empty())
    {
        this_thread::yield();
    }
    stop = true;
    condition.notify_all();
    for (auto &thread: thread_pool){
        thread.join();
    }
    cout<<"析构pool"<<endl;
}

template <typename T>
void mythreadpool<T>::work_func(){
    // size_t seed = std::hash<std::thread::id>{}(std::this_thread::get_id());
    srand(std::hash<std::thread::id>{}(std::this_thread::get_id()));
    while (!stop)
    {
        unique_lock<mutex> locker(queue_mutex);
        this->condition.wait(locker,[this](){ return !tasks_queue.empty()||stop;});
        if (stop)
        {
            continue;
        }
        else{
            T* request = tasks_queue.front();
            tasks_queue.pop();
            status_queue.push(1);
            locker.unlock();
            if (request) request->process();
            locker.lock();
            status_queue.pop();
            locker.unlock();
        }
    }
}

template <typename T>
void mythreadpool<T>::append(T* request){

    {
        unique_lock<mutex> locker(queue_mutex);
        tasks_queue.push(request);
    }
    condition.notify_one();
    
}

template <typename T>
bool mythreadpool<T>::isIdle(){
    return status_queue.empty();
}
// using namespace std;
class Task
{
public:
    Task(int n)
    {
        id = n;
        // cout<<"Task"<< id << " 构造"<<endl;
        
    }
    int id;
    void process()
    {
        // cout << "Task " << id;
        // cout << " run in " << this_thread::get_id() << endl; // 测试任务数量
        // thread::id id = (this_thread::get_id());
        // srand(seed);
        long i = 1'000*(rand()%100);
        long init =i;
        while (i != 0)
        {
            int j = sqrt(i);
            j = sqrt(i);
            i--;
        }
        string info = "Task " + to_string(id) + " is completed with " + to_string(init)+ " in ";
        
        cout<<info<<this_thread::get_id()<<endl;
    }
    ~Task(){
        // cout<<"Task"<< id << " 析构"<<endl;
    }
};

int main(){
    mythreadpool<Task> pool(2); // 6个线程，vector
    for (int i = 0; i < 10; i++)
    {

        // Task *tt = new Task(i+1); // 使用智能指针
        // pool.append(tt);            // 不停的添加任务，任务是队列queue，因为只有固定的线程数
        // delete tt;

        // Task *t1 = new Task((i+1)*10); // 使用智能指针
        // pool.append(t1);
        // delete t1;
        
        // 不停的添加任务，任务是队列queue，因为只有固定的线程数
        unique_ptr<Task> t1(new Task(i)); // 使用智能指针
        pool.append(t1.get());            // 不停的添加任务，任务是队列queue，因为只有固定的线程数
        // cout << "等待中的任务数量：" << pool.tasks_queue.size() << endl;
    }
    

    cout << "tasks-add complete" << endl;
    while(!pool.isIdle())
    {
        this_thread::yield();
    }
    
    cout << "main run out." << endl;
    return 0;
    return 0;
}