/*
** EPITECH PROJECT, 2025
** ComponentFactory.hpp
** File description:
** ComponentFactory.hpp
*/

#ifndef COMPONENT_FACTORY_HPP
#define COMPONENT_FACTORY_HPP

#include <memory>
#include <unordered_map>
#include <functional>

#include "IComponent.hpp"

namespace nts
{
    class ComponentFactory
    {
    public:
        ComponentFactory();
        std::unique_ptr<IComponent> createComponent(const std::string &type);

    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<IComponent>()>> _factoryMap;
    };
}

#endif /* !COMPONENT_FACTORY_HPP */
