/*
** EPITECH PROJECT, 2025
** Circuit.cpp
** File description:
** Circuit.cpp
*/

#include "ComponentOutput.hpp"
#include "ComponentClock.hpp"
#include "ComponentInput.hpp"
#include "Circuit.hpp"

nts::Circuit::Circuit()
    : AComponent("Circuit")
{
    _ticks_passed = 0;
}

void nts::Circuit::simulate(std::size_t tick)
{
    _ticks_passed += tick;
    for (auto &component : _internComponents) {
        component->simulate(tick);
        component->setNotComputed();
    }
    for (auto &component : _internComponents) {
        if (dynamic_cast<nts::ComponentOutput *>(component.get()))
            component->compute(0);
    }
}

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    (void)pin;
    return NOTCOMPUTED;
}

static void displayVector(std::vector<std::shared_ptr<nts::IComponent>> vec)
{
    std::sort(vec.begin(), vec.end(), [](const std::shared_ptr<nts::IComponent> &a,
        const std::shared_ptr<nts::IComponent> &b) {
        return a->getName() < b->getName();
    });
    for (auto &v : vec)
        std::cout << "  " << v->getName() << ": " <<
            ((v->getValueComputed() == nts::UNDEFINED) ?
            "U" : std::to_string(v->getValueComputed())) << std::endl;
}

void nts::Circuit::display(void)
{
    std::vector<std::shared_ptr<nts::IComponent>> inputs;
    std::vector<std::shared_ptr<nts::IComponent>> outputs;

    for (auto &component : _internComponents) {
        if (dynamic_cast<nts::ComponentInput *>(component.get()))
            inputs.push_back(component);
        if (dynamic_cast<nts::ComponentClock *>(component.get()))
            inputs.push_back(component);
        if (dynamic_cast<nts::ComponentOutput *>(component.get()))
            outputs.push_back(component);
    }
    std::cout << "tick: " << _ticks_passed << std::endl;
    std::cout << "input(s):" << std::endl;
    displayVector(inputs);
    std::cout << "output(s):" << std::endl;
    displayVector(outputs);
}

void nts::Circuit::setValue(std::string const &name, nts::Tristate value)
{
    for (auto &component : _internComponents) {
        if (component->getName() != name)
            continue;
        if (dynamic_cast<nts::ComponentInput *>(component.get())){
            dynamic_cast<nts::ComponentInput *>(component.get())->setValue(value);
            return;
        }
        if (dynamic_cast<nts::ComponentClock *>(component.get())){
            dynamic_cast<nts::ComponentClock *>(component.get())->setValue(value);
            return;
        }
    }
    throw nts::Circuit::Errors("Component not found");
}

void nts::Circuit::addComponent(std::unique_ptr<IComponent> component)
{
    for (auto &comp : _internComponents) {
        if (comp->getName() == component->getName())
            throw nts::Circuit::Errors("Component already exists with same name");
    }
    _internComponents.push_back(std::move(component));
}

nts::IComponent &nts::Circuit::getComponent(std::string const &name)
{
    for (auto &component : _internComponents) {
        if (component->getName() == name)
            return *component;
    }
    throw nts::Circuit::Errors("Component not found");
}
