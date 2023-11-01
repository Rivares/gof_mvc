#ifndef SCH_VIEW_H
#define SCH_VIEW_H

#include "scheme_controller.hpp"

#include "elementbase_model.hpp"

#include <iostream>
#include <memory>

enum class TypeElem;

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

    void signalAddElem(const TypeElem& type);
    void signalRemElem(ElementBaseModel* elem);
    void signalUpdateElem(ElementBaseModel* elem);


private:
    std::shared_ptr<SchemeController> m_controller;
};


#endif
