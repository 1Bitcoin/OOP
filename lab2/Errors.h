#ifndef Errors_h
#define Errors_h

#include <iostream>	
#include <string>
#include <exception>

class CommonError : public std::exception
{
public:
	CommonError(std::string filename, int line, const char *time,
		std::string info = "Error")
	{
		message_error = "\nFile name: " + filename + "\nLine#: " + std::to_string(line) +
			"\nTime: " + time + "Info: " + info;
	}
	virtual const char* what() const noexcept override
	{
		return message_error.c_str();
	}
protected:
	std::string message_error;
};

class SizeError : public CommonError
{
public:
	SizeError(std::string filename, int line, const char *time,
		std::string info = "Sizes mismatch") :
		CommonError(filename, line, time, info) {};
};

class EmptyError : public CommonError
{
public:
	EmptyError(std::string filename, int line, const char *time,
		std::string info = "Try to use empty vector") :
		CommonError(filename, line, time, info) {};
};

class DivisionByZeroError : public CommonError
{
public:
	DivisionByZeroError(std::string filename, int line, const char *time,
		std::string info = "Zero division error") :
		CommonError(filename, line, time, info) {};
};

class BoundariesError : public CommonError
{
public:
	BoundariesError(std::string filename, int line, const char *time,
               std::string info = "Index is out of boundaries") :
		CommonError(filename, line, time, info) {};
};

class MemoryError : public CommonError
{
public:
	MemoryError(std::string filename, int line, const char *time,
		std::string info = "Memory error") : CommonError(filename, line, time, info) {};
};

class DeletedObj : public CommonError
{
public:
	DeletedObj(std::string filename, int line, const char *time,
		std::string info = "Work with deleted object") :
		CommonError(filename, line, time, info) {};
};

#endif /* Errors_h */
