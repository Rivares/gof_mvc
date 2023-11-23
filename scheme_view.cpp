#include "scheme_view.hpp"

SchemeView::SchemeView(std::shared_ptr<SchemeController> ptrToController)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';

    m_controller = ptrToController;
}

SchemeView::~SchemeView()
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

void SchemeView::signalAddElem(const TypeElem& type)
{   m_controller->addNewElem(type); }

void SchemeView::signalRemElem(const size_t idx) // current Element. Need use ElementBase* elem...
{   m_controller->remElem(nullptr); }   // dummy arg



