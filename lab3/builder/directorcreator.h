#ifndef DIRECTORCREATOR_H
#define DIRECTORCREATOR_H

#include "basedirector.h"

template <typename Derived, typename Base>
concept Derivative = std::is_abstract_v<Base> && std::is_base_of_v<Base, Derived>;

template <typename Type>
concept NotAbstract = !std::is_abstract_v<Type>;

template<typename Type, typename... Args>
concept Constructible = std::is_constructible_v<Type, Args...>;


class DirectorCreator
{
public:
    DirectorCreator();

    template<Derivative<BaseDirector> director, typename ...Args>
    requires NotAbstract<director> && Constructible<director, Args...>
    static std::shared_ptr<BaseDirector> create(Args&& ...args)
    {
        return std::make_shared<director>(std::forward<Args>(args)...);
    }
};

#endif // DIRECTORCREATOR_H
