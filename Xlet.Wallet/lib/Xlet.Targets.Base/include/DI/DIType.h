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
        // This extra step is necessary as the contained type may be registered
        // as a singleton or transient, in which case it needs to be handled
        // differently
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
