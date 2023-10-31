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
    SchemeController(std::shared_ptr<SchemeModel> ptrToModel)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        m_model = ptrToModel;

        std::shared_ptr<SchemeController> controller(this);
        m_controller = std::move(controller);

        m_view = std::make_shared<SchemeView>(m_controller);
    }

    ~SchemeController()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }


private:
    std::shared_ptr<SchemeController> m_controller;

    std::shared_ptr<SchemeModel> m_model;
    std::shared_ptr<SchemeView> m_view;
};


#endif
