#ifndef ENCODING_EXCEPTION_H
#define ENCODING_EXCEPTION_H

#include <stdexcept>
#include <string>

class EncodingException : public std::runtime_error {
public:
    explicit EncodingException(const std::string& message);
};

#endif // ENCODING_EXCEPTION_H
