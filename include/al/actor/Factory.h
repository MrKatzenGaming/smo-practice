#pragma once

namespace al
{
    class LiveActor;

    struct FactoryEntry
    {
        const char* mName;
        void* mCreationFunction;
    };

    template<typename T>
    class Factory
    {
    public:
        inline Factory() {}
        
        virtual const char* convertName(const char *) const;
    };

    class ActorFactory : public al::Factory<al::LiveActor * (*)(char const *)>
    {
    public:
        ActorFactory(const char *);

        const char* mFactoryName;
        al::FactoryEntry** mFactoryEntries;
        int mNumFactoryEntries;
    };
    
    class ProjectActorFactory : public al::ActorFactory
    {
    public:
        ProjectActorFactory();
    };
};
