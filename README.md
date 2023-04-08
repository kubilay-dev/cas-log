# ⭐ cas-log ⭐

cas-log is a **lightweight header-only logging library for C++**. It provides a simple interface to log messages to the console and a file.

## Getting Started

To use cas-log, simply include the `caslog.hpp` header file in your C++ project. The library requires C++14 or later.

## Outputting log entries

To output a log entry, call one of the following functions:

- `logger::info(const char* format, ...)`: Outputs an informational log entry with the given format string and arguments.
- `logger::warning(const char* format, ...)`: Outputs a warning log entry with the given format string and arguments.
- `logger::error(const char* format, ...)`: Outputs an error log entry with the given format string and arguments.

Each of these functions takes a printf-style format string and any additional arguments that will be formatted and outputted.

## Log levels

You can customize which log levels are outputted by changing the `LogLevel` enumeration in the `cas-log.hpp` file. By default, all log levels are enabled.

## Log-to-file

`cas-log` writes log entries to a log file located at `C:\log.txt`. You can change the filename by editing the `log.txt` name in the `output` function in the `cas-log.hpp` file.

## Usage

There are three log levels available: `INFO`, `WARNING`, and `ERR`. Each level corresponds to a different color output in the console.

To log a message, simply call one of the three functions provided by the library: `info`, `warning`, or `error`. These functions take a printf-style format string and any additional arguments necessary to fill in the placeholders in the format string.

Here's an example:

```cpp
#include "caslog.hpp"

int main()
{
    logger::info( "this is a info print without any arguments.\n" );
    logger::info( "this is a info print with a int argument, %d\n", 69 );
    logger::warning( "this is a warning print without any arguments.\n" );
    logger::warning( "this is a warning print with a int argument, %d\n", 178326 );
    logger::error( "this is a error print without any arguments.\n" );
    logger::error( "this is a error print with a int argument, %d\n", 3874 );
}
```

This will output the following to the console:

```csharp
[2023-04-08 20:40:05] [INFO] this is a info print without any arguments.
[2023-04-08 20:40:05] [INFO] this is a info print with a int argument, 69
[2023-04-08 20:40:05] [WARNING] this is a warning print without any arguments.
[2023-04-08 20:40:05] [WARNING] this is a warning print with a int argument, 178326
[2023-04-08 20:40:05] [ERROR] this is a error print without any arguments.
[2023-04-08 20:40:05] [ERROR] this is a error print with a int argument, 3874
```

And the following entries will be written to the log file:

```csharp
[2023-04-08 20:20:51] [INFO] this is a info print without any arguments.

[2023-04-08 20:20:51] [INFO] this is a info print with a int argument, 69

[2023-04-08 20:20:51] [WARNING] this is a warning print without any arguments.

[2023-04-08 20:20:51] [WARNING] this is a warning print with a int argument, 178326

[2023-04-08 20:20:51] [ERROR] this is a error print without any arguments.

[2023-04-08 20:20:51] [ERROR] this is a error print with a int argument, 3874

[2023-04-08 20:25:32] [INFO] this is a info print without any arguments.

[2023-04-08 20:25:32] [INFO] this is a info print with a int argument, 69

[2023-04-08 20:25:32] [WARNING] this is a warning print without any arguments.

[2023-04-08 20:25:32] [WARNING] this is a warning print with a int argument, 178326

[2023-04-08 20:25:32] [ERROR] this is a error print without any arguments.

[2023-04-08 20:25:32] [ERROR] this is a error print with a int argument, 3874
```

## License
This project is licensed under the **MIT License**. See the `LICENSE` file for details.
