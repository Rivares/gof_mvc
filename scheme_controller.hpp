#ifndef SCH_CONTROLLER_H
#define SCH_CONTROLLER_H

#include "scheme_model.hpp"
#include "scheme_view.hpp"

#include "elementbase_model.hpp"

#include <iostream>
#include <memory>

class SchemeModel;
class SchemeView;

enum class TypeElem;

//class ElementBaseModel;

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

    void addNewElem(const TypeElem& type)
    {}
    void remElem(ElementBaseModel* elem)
    {}
    void updateElem(ElementBaseModel* elem)
    {}

private:
    std::shared_ptr<SchemeController> m_controller;

    std::shared_ptr<SchemeModel> m_model;
    std::shared_ptr<SchemeView> m_view;
};


#endif
