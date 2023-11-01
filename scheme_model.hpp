#ifndef SCH_MODEL_H
#define SCH_MODEL_H

#include "scheme_controller.hpp"

#include "elementbase_model.hpp"
#include "elementrect_model.hpp"

// (доступ к данным)

#include <iostream>

#include <memory>
#include <list>

enum class TypeElem;

class SchemeController;

class ElementBaseModel;

class SchemeModel
{
public:

    SchemeModel()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        std::shared_ptr<SchemeModel> model(this);
        m_model = std::move(model);
        m_controller = std::make_shared<SchemeController>(m_model);
    }

    ~SchemeModel()
    {   std::cout << __PRETTY_FUNCTION__ << '\n';   }

    void addNewElem(const TypeElem& type)
    {
        switch (type)
        {
            case TypeElem::RECT:
                m_elems.push_back(std::move(std::make_unique<ElementRectModel>()));
            break;
        }
    }
    void remElem(ElementBaseModel* elem)
    {
        if (elem)
        {
            for(auto& item: m_elems)
            {
                if (item.get() == elem)
                {
                    auto ptr = item.release();
                    m_elems.remove(item);
                    ptr = nullptr;
                    delete ptr;

                    break;
                }
            }
        }
    }
    void updateElem(ElementBaseModel* elem)
    {}

private:

    std::shared_ptr<SchemeModel> m_model;

    std::shared_ptr<SchemeController> m_controller;

    std::list<std::unique_ptr<ElementBaseModel>> m_elems;
};


#endif
