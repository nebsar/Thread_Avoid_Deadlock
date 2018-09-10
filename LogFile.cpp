/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.cpp
 * Author: Eagleye
 * 
 * Created on September 9, 2018, 7:30 PM
 */

#include "LogFile.h"
#include <iostream>
#include <mutex>

using namespace std;

/** @brief default LogFile constructor
 *  Constructs LofFile class and creates "DeadLockAvoid.txt" file in the same directory
 */
LogFile::LogFile() {
    m_oFstream.open("DeadLockAvoid.txt");
}

/** @brief Destructor of LogFile
 *  closes ofstream while exiting the program
 */
LogFile::~LogFile() {
    m_oFstream.close();
}

/** @brief prints out threads string and integer arguments
 *  @param char* msg - string message from thread
 *  @param int i - integer value from thread
 */
void LogFile::shared_print(const char* msg, int i) {
    lock(m_mutex, m_mutex2);
    lock_guard<mutex> guard(m_mutex, adopt_lock);
    lock_guard<mutex> guard2(m_mutex2, adopt_lock);
    m_oFstream << "From " << msg << " " << i << endl;
}

void LogFile::shared_print2(const char* msg, int i) {
    lock(m_mutex, m_mutex2);
    lock_guard<mutex> guard(m_mutex, adopt_lock);
    lock_guard<mutex> guard2(m_mutex2, adopt_lock);
    m_oFstream << "From " << msg << " " << i << endl;
}

