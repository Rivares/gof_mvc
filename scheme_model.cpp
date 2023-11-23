#include "scheme_model.hpp"

SchemeModel::SchemeModel()
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

SchemeModel::~SchemeModel()
{   std::cout << __PRETTY_FUNCTION__ << '\n';   }

void SchemeModel::setSchemeController(std::shared_ptr<SchemeController> controller)
{   m_controller = controller;  }

void SchemeModel::addNewElem(const TypeElem& type)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';

    switch (type)
    {
        case TypeElem::RECT:
            m_elems.insert(std::move(std::make_unique<ElementRect>()));
        break;
    }
}

void SchemeModel::remElem(ElementBase* elem)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';

    if (elem)
    {
        for(auto& item: m_elems)
        {
            if (item.get() == elem)
            {
                m_elems.erase(item);

                break;
            }
        }
    }
}

