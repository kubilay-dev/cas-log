/*
 * Copyright (c) 2023 https://github.com/kubilay-dev/cas-log
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#define CASLOG_HPP
#ifdef CASLOG_HPP

#pragma once

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include <fstream>

namespace logger {

    enum LogLevel {
        INFO,
        WARNING,
        ERR
    };

    inline void output( LogLevel level, const char* format, va_list args ) {
        std::time_t t = std::time( nullptr );
        std::tm tm;

        localtime_s( &tm, &t );

        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

        SetConsoleTextAttribute( hConsole, 13 );
        std::cout << "[" << std::put_time( &tm, "%Y-%m-%d %H:%M:%S" ) << "] ";

        switch (level) {
        case LogLevel::INFO:
            SetConsoleTextAttribute( hConsole, 11 );
            std::cout << "[INFO] ";
            break;
        case LogLevel::WARNING:
            SetConsoleTextAttribute( hConsole, 14 );
            std::cout << "[WARNING] ";
            break;
        case LogLevel::ERR:
            SetConsoleTextAttribute( hConsole, 12 );
            std::cout << "[ERROR] ";
            break;
        }

        SetConsoleTextAttribute( hConsole, 15 );
        std::vprintf( format, args );

        va_list args_copy;
        va_copy( args_copy, args );

        std::ofstream logFile( "C:\\log.txt", std::ios_base::app );
        if (logFile) {
            logFile << "[" << std::put_time( &tm, "%Y-%m-%d %H:%M:%S" ) << "] ";

            switch (level) {
            case LogLevel::INFO:
                logFile << "[INFO] ";
                break;
            case LogLevel::WARNING:
                logFile << "[WARNING] ";
                break;
            case LogLevel::ERR:
                logFile << "[ERROR] ";
                break;
            }

            char buf[1024];
            std::vsnprintf( buf, 1024, format, args_copy );
            logFile << buf << std::endl;
            logFile.close( );
        }

        va_end( args_copy );
    }


    inline void info( const char* format, ... ) {
        va_list args;
        va_start( args, format );
        output( LogLevel::INFO, format, args );
        va_end( args );
    }

    inline void warning( const char* format, ... ) {
        va_list args;
        va_start( args, format );
        output( LogLevel::WARNING, format, args );
        va_end( args );
    }

    inline void error( const char* format, ... ) {
        va_list args;
        va_start( args, format );
        output( LogLevel::ERR, format, args );
        va_end( args );
    }

}

#endif // CASLOG_HPP
