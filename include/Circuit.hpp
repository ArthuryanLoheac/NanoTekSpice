/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** ACircuit
*/

#pragma once
#include "AComponent.hpp"
#include "AInput.hpp"
#include "ComponentOutput.hpp"
#include "ComponentClock.hpp"
#include "ComponentInput.hpp"
#include <iostream>
#include <algorithm>
#include <utility>

namespace nts {
    class Circuit : public AComponent
    {
        public:
            class Errors : public std::exception
        {
            public:
                Errors(std::string const &message)
                    : _message(message) {};
                const char *what() const noexcept override
                {
                    return _message.c_str();
                }
            private:
                std::string _message;
        };

        private:
            std::size_t _ticks_passed;
        public:
            Circuit();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void display(void);
            void setValue(std::string const &name, nts::Tristate value);
            void addComponent(std::unique_ptr<IComponent> component);
            IComponent &getComponent(std::string const &name);
    };
}