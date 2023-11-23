#include "scheme_controller.hpp"

SchemeController::SchemeController(std::shared_ptr<SchemeModel> ptrToModel)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';

    m_model = ptrToModel;
}

SchemeController::~SchemeController()
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

void SchemeController::setSchemeView(std::shared_ptr<SchemeView> ptrToView)
{   m_view = ptrToView;    }

void SchemeController::addNewElem(const TypeElem& type)
{   m_model.lock()->addNewElem(type);   }

void SchemeController::remElem(ElementBase* elem)
{   m_model.lock()->remElem(elem);   }


