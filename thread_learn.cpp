#include <iostream>
#include <thread>
#include <future>
#include <atomic>


using namespace std;

void doit(){
    cout<<"World!"<<endl;
}

template<class T>
void changevalue(T &x, T val){
    x = val;
}

template<class ... Agrs>
decltype(auto) sum(Agrs&& ... args){
    //c++17折叠表达式
    return (0+...+ args);
}

void count_big_number(){
    for (int i = 0; i < 1'000'000'000; i++);
}

template<class ... Args>
void thread_sum(promise <long long> &ret, Args && ... args){
    ret.set_value(sum(args...));
    }

atomic_bool ready = false;//atmoic变量可实现多线程共享
void sleep(uintmax_t ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void count(){
    while(!ready) this_thread::yield();
    for (int i = 0; i < 10'0000'0000; i++);
    cout<<"Thread "<<this_thread::get_id()<<" finished!"<<endl;
}

    mutex m;
    condition_variable cnv;
    int cargo = 0;

bool consumer_fnc(){
    return cargo !=0;
}

bool flag = false; 

void wait_thread_func()
{
    unique_lock<mutex> lock(m);
    cout << "等待线程sub(" << this_thread::get_id() << "): 开始等待通知..." << endl;
    cnv.wait(lock);
    cout << "等待线程sub(" << this_thread::get_id() << "): 继续执行代码..." << endl;
}

int main(){
    /* 
    //基础多线程操作

    // thread a([]{
    //     cout<<"Hello, "<<flush;
    // }),b(doit),c([]{
    //     cout<<"~test"<<endl;});
    // a.join();
    // b.join();
    // c.join();


    //多线程引用如何传入
    // thread th[100];
    // int nums[100];
    // for (int i = 0; i 100; i++)
    // {
    //     th[i]= thread(changevalue<int>,ref(nums[i]),i*2);
    // }
    // for (int i = 0; i < 100; i++)
    // {
    //     th[i].join();
    //     cout<<nums[i]<<endl;
    // }
    
    // async解决mutex.lock的低效问题
    // async(launch::async,[](const char* message){
    //     cout<<message<<flush;
    // },"Hello, ");
    // cout<<"World!"<<endl;   

    //future取得返回值async
    // future <int> val = async(launch::async, [](int args){
    //     return args +1;
    // }, 10);
    // cout<<val.get()<<endl;

    // future <int> val = async(launch::async, sum<int,int,int>, 1,1,1);

    //无返回值，但可判断多线程状态
    // future<void> fut = async(launch::async, count_big_number);
    // cout<<"Please wait"<<endl;
    // while (fut.wait_for(chrono::seconds(1)) != future_status::ready)
    // {
    //     cout<<"."<<flush;
    // }
    // cout<<"Finished"<<endl;


    //future是const，利用promise取得thread返回值，可修改
    // promise<long long> res;
    // thread get_sum(thread_sum<int,int,int>, ref(res), 1,10,100);
    // cout<<res.get_future().get()<<endl;
    // get_sum.join();

    //this_thread操作线程自身
    // thread th[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     th[i] = thread(count);
    // }
    // sleep(5000);
    // ready = true;
    // cout<<"Start!"<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     th[i].join();
    // }

    // thread consumer_thread(consume, 10);
    // auto consumer_fnc = [](){return cargo !=0;};
    // thread consumer_thread1([](int n){
    // for (int i = 0; i < n; ++i)
    //     {
    //         unique_lock locker(m);
    //         cout<<"thread1: before wait, cargo is "<<cargo<<endl;
    //         cnv.wait(locker,consumer_fnc);
    //         cout<<"thread1: after wait, cargo is "<<cargo<<endl;
    //         cout<<cargo<<'\n';
    //         cargo = 0;
    //     }
    // }, 10);

    // thread consumer_thread2([](int n){
    //     for (int i = 0; i < n; ++i)
    //     {
    //         unique_lock locker(m);
    //         cout<<"thread2: cargo is "<<cargo<<endl;
    //         cnv.wait(locker,consumer_fnc);
    //         cout<<cargo<<'\n';
    //         cargo = 0;
    //     }
    // }, 10);

    // for (int i = 0; i < 10; i++)
    // {
    //     while (consumer_fnc()) 
    //     {
    //         // cout<<"main: cargo is "<<cargo<<endl;
    //         this_thread::yield;
    //     }
    //     unique_lock locker(m);
    //     cargo = i+1;
    //     cnv.notify_one();
    // }
    // consumer_thread1.join();
    // consumer_thread2.join();
    // thread wait_thread(wait_thread_func);

    // this_thread::sleep_for(1s); // 等待1秒后进行通知
    // cout << "通知线程main(" << this_thread::get_id() << "): 开始通知等待线程..." << endl;
    // cnv.notify_one();
    // wait_thread.join();
    // cout << "--- main结束 ---" << endl;
    */
    
    //线程池
    
    return 0;

}
