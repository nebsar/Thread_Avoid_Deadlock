/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.h
 * Author: Eagleye
 *
 * Created on September 9, 2018, 7:30 PM
 */

#ifndef LOGFILE_H
#define LOGFILE_H

#include <fstream>
#include <mutex>

using namespace std;

class LogFile {
public:
    LogFile();
    virtual ~LogFile();

    void shared_print(const char* msg, int i);

    void shared_print2(const char* msg, int i);

    ofstream m_oFstream;
    mutex m_mutex;
    mutex m_mutex2;

};

#endif /* LOGFILE_H */

