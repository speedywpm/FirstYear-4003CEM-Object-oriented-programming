#ifndef CAPTUREIO_H
#define CAPTUREIO_H

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <cxxabi.h>

class CaptureStream: public std::ostringstream
{
private:
    std::ostream& stream;
    std::streambuf* rdbuf;
public:    
    CaptureStream( std::ostream &_stream ) : stream(_stream), rdbuf(_stream.rdbuf())
    {}

    void capture()
    {
        stream.rdbuf( std::ostringstream::rdbuf() );
    }

    void release()
    {
        stream.rdbuf( rdbuf );
    }

    virtual ~CaptureStream() {}
};

class InjectStream/*: public std::ostream*/
{
private:
	std::stringstream ss;
    std::istream& stream;
    std::streambuf* rdbuf;
public:

	InjectStream( std::istream& _stream ) : stream(_stream), rdbuf(_stream.rdbuf())
	{}

	void capture()
	{
		stream.rdbuf( ss.rdbuf() );
	}

	void release()
	{
		stream.rdbuf( rdbuf );
	}

	template<typename T>
	InjectStream& operator<<( T const& rhs )
	{
		ss << rhs;
		return *this;
	}
};

template <class T>
std::string type_name()
{
    // credit to https://stackoverflow.com/a/20170989

    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
    (
#ifndef _MSC_VER
        abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
#else
        nullptr,
#endif
        std::free
    );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

#endif