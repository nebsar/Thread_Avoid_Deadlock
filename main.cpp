/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 9, 2018, 7:29 PM
 */

#include <cstdlib>

#include "LogFile.h"
#include <iostream>
#include <thread>

using namespace std;

/*
 * 
 */

void function(LogFile& logf) {
    for (int i = 0; i>-100; i--) {
        logf.shared_print("T1 Thread", i);
    }
}

int main(int argc, char** argv) {

    LogFile logFile;

    thread t1(function, std::ref(logFile));

    for (int i = 0; i < 100; i++)
        logFile.shared_print2("From Main Thread", i);

    t1.join();

    return 0;
}

