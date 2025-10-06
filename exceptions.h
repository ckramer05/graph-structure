#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <stdexcept> 
#include <string>

using namespace std;

class NoSuchObject : public logic_error {
  public:
    NoSuchObject(string = "ERROR: NoSuchObject");
};

#endif // EXCEPTIONS_H
