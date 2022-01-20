//
// Created by admin on 2021/11/14.
//

#include <string>
#include <queue>

using namespace std;

class Pet {
private:
    string type;
public:
    Pet(string type): type(type){}
    string PetType() {return type;}
};

class Dog: public Pet {
public:
    Dog(): Pet("dog") {}
};

class Cat: public Pet {
public:
    Cat(): Pet("cat") {}
};

class PetEnter {
private:
    Pet pet;
    long cnt;
public:
    PetEnter(Pet pet, long cnt): pet(pet), cnt(cnt){};
    long Cnt() {return cnt;}
    Pet Pet() {return pet;}
};

class DogCatQueue {
private:
    queue<PetEnter> catQueue;
    queue<PetEnter> dogQueue;
    long cnt;
public:
    void Add(Pet pet) {
        if (pet.PetType() == "dog") {
            dogQueue.push(PetEnter(pet, cnt++));
        } else if (pet.PetType() == "cat") {
            catQueue.push(PetEnter(pet, cnt++));
        } else {
            throw runtime_error("error: not dog or cat");
        }
    }
    Pet PollAll() {
        if (!catQueue.empty() && !dogQueue.empty()) {
            if (catQueue.front().Cnt() > dogQueue.front().Cnt()) {
                PetEnter p = catQueue.front();
                catQueue.pop();
                return p.Pet();
            } else  {
                PetEnter p = dogQueue.front();
                dogQueue.pop();
                return p.Pet();
            }
        } else if (!catQueue.empty()) {
            PetEnter p = catQueue.front();
            catQueue.pop();
            return p.Pet();
        } else if (!dogQueue.empty()) {
            PetEnter p = dogQueue.front();
            dogQueue.pop();
            return p.Pet();
        } else {
            throw runtime_error("error: queues are both empty");
        }
    }
    Pet PollDog() {
        if (!dogQueue.empty()) {
            PetEnter p = dogQueue.front();
            dogQueue.pop();
            return p.Pet();
        } else {
            throw runtime_error("error: dog queue is empty");
        }
    }
    Pet PollCat() {
        if (!catQueue.empty()) {
            PetEnter p = catQueue.front();
            catQueue.pop();
            return p.Pet();
        } else {
            throw runtime_error("error: cat queue is empty");
        }
    }

    bool Empty() {
        return dogQueue.empty() && catQueue.empty();
    }

    bool CatEmpty() {
        return catQueue.empty();
    }

    bool DogEmpty() {
        return dogQueue.empty();
    }
};

void TestCatDogQueue() {
    Dog dog; Cat cat;
    DogCatQueue q;
    q.Add(dog);
    q.Add(cat);
    q.Add(dog);
    q.Add(cat);

    q.PollAll();
    q.PollAll();
}