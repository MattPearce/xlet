#pragma once

#include <hash_map>
#include <functional>
#include <typeinfo>

#include "DIRegistered.h"
#include "DIType.h"

class DIContainer
{
public:
    template<typename TInterface, typename TType>
    void RegisterTransient()
    {
        DIRegistered registration;

        registration.Factory = []() {
            return new TInterface();
        };

        registration.GiveOwnership = true;

        m_factories[typeid(TInterface).name()] = registration;
    }

    template<typename TInterface, typename TType>
    void RegisterSingleton()
    {
        DIRegistered registration;

        auto instance = new TInterface();

        registration.Factory = [=]() {
            return instance;
        };

        registration.GiveOwnership = false;

        m_factories[typeid(TInterface).name()] = registration;
    }

    template<typename TInterface>
    DIType<TInterface> Resolve()
    {
        auto& factory = m_factories[typeid(TInterface).name()];

        return DIType<TInterface>(factory.Factory(), factory.GiveOwnership);
    }

    static DIContainer* GetInstance()
    {
        return m_pInstance;
    }

private:
    static DIContainer* m_pInstance;

    std::hash_map<std::string, DIRegistered> m_factories;
};
