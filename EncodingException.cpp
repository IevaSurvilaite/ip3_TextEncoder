#include "EncodingException.h"

EncodingException::EncodingException(const std::string& message)
    : std::runtime_error(message)
{

}
