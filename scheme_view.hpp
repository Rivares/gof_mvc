#pragma once

#include "scheme_controller.hpp"

#include "elementbase.hpp"

#include <iostream>
#include <memory>

enum class TypeElem;

class SchemeController;

// (методы отображения)

class SchemeView
{
public:
    SchemeView(std::shared_ptr<SchemeController> ptrToController);
    ~SchemeView();

    void signalAddElem(const TypeElem& type);
    void signalRemElem(const size_t idx); // current Element. Need use ElementBase* elem...
    void signalUpdateElem(ElementBase* elem);


private:
    std::shared_ptr<SchemeController> m_controller;
};

