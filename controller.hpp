#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.hpp"
#include "view.hpp"

#include <iostream>
#include <memory>

class SchemeModel;
class SchemeView;

// (методы редактирования)
class SchemeController
{
public:
    SchemeController(SchemeModel* ptrToModel)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        m_model = ptrToModel;
        m_view = new SchemeView(this);
    }

    ~SchemeController()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }


private:
    SchemeModel* m_model = nullptr;
    SchemeView* m_view = nullptr;
};


#endif
