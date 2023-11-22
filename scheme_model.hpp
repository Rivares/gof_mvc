#pragma once

#include "scheme_controller.hpp"

#include "elementbase.hpp"
#include "elementrect.hpp"

// (доступ к данным)

#include <iostream>

#include <memory>
#include <unordered_set>

enum class TypeElem;

class SchemeController;

class ElementBase;

class SchemeModel
{
public:

    SchemeModel();
    ~SchemeModel();

    void setSchemeController(std::shared_ptr<SchemeController> controller);

    void addNewElem(const TypeElem& type);
    void remElem(ElementBase* elem);
    void updateElem(ElementBase* elem);

private:

    std::weak_ptr<SchemeController> m_controller;

    std::unordered_set<std::unique_ptr<ElementBase>> m_elems;
};

