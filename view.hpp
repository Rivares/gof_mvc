#ifndef VIEW_H
#define VIEW_H

#include "controller.hpp"

#include <iostream>
#include <memory>

class SchemeController;

// (методы отображения)
class SchemeView
{
public:
    SchemeView(std::shared_ptr<SchemeController> ptrToController)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        m_controller = ptrToController;
    }

    ~SchemeView()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

private:
    std::shared_ptr<SchemeController> m_controller;
};


#endif
