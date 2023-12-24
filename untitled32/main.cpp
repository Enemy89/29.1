#include <iostream>
#include <string>
#include <vector>

class Talent {
public:
    virtual void show() const = 0;
    virtual ~Talent() {}
};

class Swimming : public Talent {
public:
    void show() const override {
        std::cout << "Can swim" << std::endl;
    }
};

class Dancing : public Talent {
public:
    void show() const override {
        std::cout << "Can dance" << std::endl;
    }
};

class Counting : public Talent {
public:
    void show() const override {
        std::cout << "Can count" << std::endl;
    }
};

class Dog {
    std::string name;
    std::vector<Talent*> talents;

public:
    std::string getName () const {
        return name;
    }
    void setName (std::string &inName) {
        name=inName;
    }
    void add_swimming() {
        talents.push_back(new Swimming());
    }

    void add_dancing() {
        talents.push_back(new Dancing());
    }

    void add_counting() {
        talents.push_back(new Counting());
    }

    void show_talents() const {
        std::cout<< getName() << " talents:" << std::endl;
        for (int i=0; i<talents.size(); ++i) {
            talents[i]->show();
        }
    }

    ~Dog() {
        for (int i = 0; i < talents.size(); ++i) {
            delete talents[i];
        }
        talents.clear();
    }
};

int main() {
    std::string user_name;
    std::cout<<"Enter dog name: "<<std::endl;
    std::cin>>user_name;

    Dog myDog;
    myDog.setName(user_name);

    std::string user_command;
    while (user_command!="show") {
        std::cout << "Enter dog talent (swim, dance, count) or show talents (show): " << std::endl;
        std::cin>>user_command;

        if (user_command=="swim") {
            myDog.add_swimming();
        } else if (user_command=="dance") {
            myDog.add_dancing();
        } else if (user_command=="count") {
            myDog.add_counting();
        }
    }

    myDog.show_talents();
}