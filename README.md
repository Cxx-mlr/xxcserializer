# xxcserializer

xxcserializer is a tiny Serializer / Deserializer library for C++17

//

```cpp
#include <iostream>
#include <xxcser/arithmetic.hpp> // basic serialization and deserialization functionalities

struct Person {
    std::string name;
    int age;
};

int main() {
    Person person{"Cxx", 18}, dest;
  
    io::write_object("path", person);
    io::read_object("path", dest);
  
    std::cout << dest.name << " is " << dest.age << " years old.\n"; // Cxx is 18 years old
}
```

//

```cpp
#include <iostream>
#include <xxcser/arithmetic.hpp>

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
    Person person("xXC", 18), dest;
  
    io::write_object("path", person);
    io::read_object("path", dest);
  
    std::cout << dest; // xXC is 18 years old
}
```

//

```cpp
#include <iostream>
#include <xxcser/arithmetic.hpp>

class Name {
    public:
        Name(std::string name) : name(std::move(name)) {}
        Name() {}

    private:
        std::string name;

    protected:
        io_serializable(&Name::name);
};

class Age {
    public:
        Age(int age) : age(age) {}
        Age() {}

    private:
        int age;

    protected:
        io_serializable(&Age::age);
};

class Person : Name, Age {
    public:
        Person(std::string name, int age) : Name(name), Age(age) {}
        Person() {}
    
        inline friend std::ostream& operator<< (std::ostream& out, const Person& person) {
            return out << person.name << " is " << person.age << " years old.\n";
        }
};

int main() {
    Person person("Cxx", 18), dest;
  
    io::write_object("path", person);
    io::write_object("path", dest);
  
    std::cout << dest; // Cxx is 18 years old
}
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
