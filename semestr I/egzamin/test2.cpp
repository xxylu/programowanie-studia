#include <iostream>
#include <vector>
#include <algorithm>

// Przykładowa klasa Person
class Person {
private:
    std::string name;
    int age;
public:
    Person(const std::string name, int age) : name(name), age(age) {}
    // Metody dostępowe do pól prywatnych
    const std::string getName() const {return name;}
    int getAge() const { return age; }
};

// Funkcja porównująca dla std::sort()
bool comparePeople(const Person& a, const Person& b) {
    return a.getAge() < b.getAge(); // Sortowanie względem wieku
}

int main() {
    // Przykładowa tablica obiektów
    std::vector<Person> people = {
        {"John", 30},
        {"Alice", 25},
        {"Bob", 35}
    };

    // Sortowanie tablicy obiektów
    std::sort(people.begin(), people.end(), comparePeople);

    // Wyświetlanie posortowanej tablicy
    for (const auto& person : people) {
        std::cout << person.getName() << " - " << person.getAge() << std::endl;
    }

    return 0;
}