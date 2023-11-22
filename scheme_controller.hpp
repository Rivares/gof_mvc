#pragma once

#include "scheme_model.hpp"
#include "scheme_view.hpp"

#include "elementbase.hpp"

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
    SchemeController(std::shared_ptr<SchemeModel> ptrToModel);
    ~SchemeController();

    void setSchemeView(std::shared_ptr<SchemeView> ptrToView);

    void addNewElem(const TypeElem& type);
    void remElem(ElementBase* elem);
    void updateElem(ElementBase* elem);

private:

    std::weak_ptr<SchemeModel> m_model;
    std::weak_ptr<SchemeView> m_view;
};


