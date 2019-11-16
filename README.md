# xxcserializer

xxcserializer is a tiny Serializer / Deserializer library for C++17

//

```cpp
#include <xxcser/string.hpp>

struct Person {
  std::string name;
  int age;
};

int main() {
  Person person{"Cxx", 18}, dest;
  
  io::write_object("path", person);
  io::read_object("path", dest);
  
  std::cout << dest.name << " is " << dest.age << " years old.\n";
}
```

//

```cpp
#include <xxcser/string.hpp>

class Person {
private:
  std::string name;
  int age;
  
public:
  Person(std::string name, int age) : name(std::move(name)), age(age) {}
  Person() = default;
  
  inline friend std::ostream& operator<< (std::ostream& out, const Person& person) {
    return out << person.name << " is " << person.age << " years old.\n";
  }
  
  io_serializable(&Person::name, &Person::age);
};

int main() {
  Person person("Cxx", 18), dest;
  
  io::write_object("path", person);
  io::read_object("path", dest);
  
  std::cout << dest;
}
```
