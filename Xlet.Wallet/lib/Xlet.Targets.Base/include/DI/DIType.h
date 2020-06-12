#pragma once

template<typename TInterface>
class DIType
{
public:
    DIType(TInterface* pInstance, bool hasOwnership)
    {
        m_pInstance = pInstance;

        m_hasOwnership = hasOwnership;
    }

    ~DIType()
    {
        if(m_hasOwnership)
        {
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }

    TInterface* GetInstance()
    {
        return m_pInstance;
    }

private:
    // Disable copying
    DIType(const DIType&) = delete;

    bool m_hasOwnership;

    TInterface* m_pInstance;
};
