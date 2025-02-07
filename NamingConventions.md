# Naming Conventions

This document describes the naming conventions used in the whole repository.

## Files

`PascalCase` is used for file names.

## Directories

`PascalCase` is used for directory names.

## C++ Convention

C++ convention is used for everything, you might find them [here](https://www.geeksforgeeks.org/naming-convention-in-c/) if you want a more detailed explanation than the one provided here.

### Extensions

`.cpp` is used for C++ source files.

`.hpp` is used for C++ header files.

### Elements

#### Classes

`PascalCase` is used for class names.

#### Functions and Methods

`camelCase` is used for function and method names.

#### Variables

`camelCase` is used for variable names.

#### Constants

`UPPER_CASE_SNAKE_CASE` is used for constants.

#### Macros

`UPPER_CASE_SNAKE_CASE` is used for macros, prefixed with a unique identifier to prevent naming collisions.

#### Enums

`PascalCase` is used for enum names.

`UPPER_CASE_SNAKE_CASE` is used for enum values.

#### Namespaces

`PascalCase` is used for namespace names.

#### Template Parameters

`PascalCase` is used for template parameter names.

#### Global Variables

`g\_` prefix followed by`camelCase` is used for global variables to distinguish them from local variables.

#### Member Variables

`m\_` prefix followed by`camelCase` is used for member variables to differentiate them from local variables.

#### Static Variables

`s\_` prefix followed by`camelCase` is used for static variables.

#### Pointers

Pointer variables should have a `p` prefix followed by`camelCase`, e.g., `pMyPointer`.

#### References

Reference variables should have an `r` prefix followed by`camelCase`, e.g., `rMyReference`.

### Code Examples

```cpp
#include <iostream>

#define PROJECT_VERSION "1.0.0"

namespace MyNamespace {

const int MAX_LIMIT = 100;

class SampleClass {
public:
    SampleClass(int value) : m_value(value) {}

    void displayValue() {
        std::cout << "Value: " << m_value << std::endl;
    }

    static void setStaticValue(int value) {
        s_staticValue = value;
    }

    static int getStaticValue() {
        return s_staticValue;
    }

private:
    int m_value;
    static int s_staticValue;
};

int SampleClass::s_staticValue = 0;

enum Color {
    RED,
    GREEN,
    BLUE
};

void processPointer(int* pNumber) {
    if (pNumber) {
        std::cout << "Pointer value: " << *pNumber << std::endl;
    }
}

void processReference(int& rNumber) {
    std::cout << "Reference value: " << rNumber << std::endl;
}

} // namespace MyNamespace

int g_globalCounter = 0;

int main() {
    MyNamespace::SampleClass obj(42);
    obj.displayValue();

    MyNamespace::SampleClass::setStaticValue(10);
    std::cout << "Static Value: " << MyNamespace::SampleClass::getStaticValue() << std::endl;

    int localVar = 5;
    int* pLocalVar = &localVar;
    int& rLocalVar = localVar;

    MyNamespace::processPointer(pLocalVar);
    MyNamespace::processReference(rLocalVar);

    g_globalCounter++;
    std::cout << "Global Counter: " << g_globalCounter << std::endl;

    return 0;
}
```
