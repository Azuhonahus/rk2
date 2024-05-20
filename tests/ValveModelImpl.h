#ifndef VALVEMODELIMPL_H
#define VALVEMODELIMPL_H

#include <memory>
#include <vector>

class ValveModelImpl {
private:
    int value; // Значение открытия клапана

public:
    ValveModelImpl() : value(0) {}

    void widenOpening() {
        value = 1;
    }

    void narrowOpening() {
        value = -1;
    }

    int getValue() const {
        return value;
    }
};

class Observer {
public:
    virtual void update(int value) = 0;
};

class ValveViewLabel : public Observer {
private:
    std::shared_ptr<ValveModelImpl> model;

public:
    void attach(std::shared_ptr<ValveModelImpl> model) {
        this->model = model;
    }

    void update(int value) override {
        std::cout << "Label: " << value << std::endl;
    }
};

#endif // VALVEMODELIMPL_H

