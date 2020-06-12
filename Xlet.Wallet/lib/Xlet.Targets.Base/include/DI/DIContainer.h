#pragma once

#include <unordered_map>
#include <functional>
#include <typeinfo>

#include "DIType.h"

struct DIRegistered
{
    std::function<void*()> Factory;

    bool GiveOwnership;
};

class DIContainer
{
public:
    template<typename TInterface, typename TType>
    void RegisterTransient(const std::string& interface)
    {
        DIRegistered registration;

        registration.Factory = []() {
            return new TType();
        };

        registration.GiveOwnership = true;

        m_factories[interface] = registration;
    }

    template<typename TInterface, typename TType>
    void RegisterSingleton(const std::string& interface)
    {
        DIRegistered registration;

        auto instance = new TType();

        registration.Factory = [=]() {
            return instance;
        };

        registration.GiveOwnership = false;

        m_factories[interface] = registration;
    }

    template<typename TInterface>
    DIType<TInterface>* Resolve(const std::string& interface)
    {
        auto& factory = m_factories[interface];

        return new DIType<TInterface>((TInterface*)factory.Factory(), factory.GiveOwnership);
    }

    static DIContainer* GetInstance()
    {
        if(m_pInstance == nullptr) {
            m_pInstance = new DIContainer();
        }

        return m_pInstance;
    }

private:
    static DIContainer* m_pInstance;

    std::unordered_map<std::string, DIRegistered> m_factories;
};
