
#pragma once

#include<functional>
#include<chrono>
#include<thread>
#include<atomic>
#include<memory>
#include<mutex>
#include<condition_variable>

class Timer {
public:
    Timer() : expired_(true), try_to_expire_(false) {}

    Timer(const Timer &t) {
        expired_ = t.expired_.load();
        try_to_expire_ = t.try_to_expire_.load();
    }

    ~Timer() {
        Expire();
    }

public:
    void StartTimer(int interval, std::function<void()> task) {
        if (expired_ == false) {
            return;
        }
        expired_ = false;
        std::thread([this, interval, task]() {
            while (!try_to_expire_) {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                task();
            }

            {
                std::lock_guard<std::mutex> locker(mutex_);
                expired_ = true;
                expired_cond_.notify_one();
            }
        }).detach();
    }

    void Expire() {
        if (expired_) {
            return;
        }

        if (try_to_expire_) {
            return;
        }

        try_to_expire_ = true;
        {
            std::unique_lock<std::mutex> locker(mutex_);
            expired_cond_.wait(locker, [this] { return expired_ == true; });
            if (expired_ == true) {
                try_to_expire_ = false;
            }
        }
    }

public:
    template<typename callable, class... arguments>
    void SyncWait(int after, callable &&f, arguments &&... args) {
        std::function<typename std::result_of<callable(arguments...)>::type()> task
            (std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));
        std::this_thread::sleep_for(std::chrono::milliseconds(after));
        task();
    }

    template<typename callable, class... arguments>
    void AsyncWait(int after, callable &&f, arguments &&... args) {
        std::function<typename std::result_of<callable(arguments...)>::type()> task
            (std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));
        std::thread([after, task]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(after));
            task();
        }).detach();
    }

private:
    std::atomic<bool> expired_;
    std::atomic<bool> try_to_expire_;
    std::mutex mutex_;
    std::condition_variable expired_cond_;
};

// example:
//int main(){
//  Timer t;
//
//  //???????????????????????????
//  t.StartTimer(1000, std::bind(EchoFunc,"hello world!"));
//  std::this_thread::sleep_for(std::chrono::seconds(4));
//  std::cout << "try to expire timer!" << std::endl;
//  t.Expire();
//
//  //???????????????????????????
//  t.StartTimer(1000, std::bind(EchoFunc,  "hello c++11!"));
//  std::this_thread::sleep_for(std::chrono::seconds(4));
//  std::cout << "try to expire timer!" << std::endl;
//  t.Expire();
//
//  std::this_thread::sleep_for(std::chrono::seconds(2));
//
//  //???????????????????????????
//  //??????
//  t.SyncWait(1000, EchoFunc, "hello world!");
//  //??????
//  t.AsyncWait(1000, EchoFunc, "hello c++11!");
//
//  std::this_thread::sleep_for(std::chrono::seconds(2));
//
//  return 0;
//}
