#ifndef MODEL_H
#define MODEL_H

#include "controller.hpp"

class ElementBaseModel;
class ElementRectModel;
class ElementLineModel;
class ElementElipseModel;

// (доступ к данным)

#include <iostream>

#include <memory>
#include <list>

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

private:

    std::shared_ptr<SchemeModel> m_model;

    std::shared_ptr<SchemeController> m_controller;
    std::list<std::unique_ptr<ElementBaseModel>> m_elems;
};

class ElementBaseModel
{
public:

    ElementBaseModel()
    {}

    ~ElementBaseModel()
    {}

private:

};

class ElementRectModel: public ElementBaseModel
{
public:

    ElementRectModel()
    {}
    ~ElementRectModel()
    {}

private:

};

class ElementLineModel: public ElementRectModel
{
public:

    ElementLineModel()
    {}
    ~ElementLineModel()
    {}

private:

};

class ElementElipseModel: public ElementBaseModel
{
public:

    ElementElipseModel()
    {}
    ~ElementElipseModel()
    {}

private:

};


#endif
