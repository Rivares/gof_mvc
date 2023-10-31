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

        m_controller = new SchemeController(this);
    }

    ~SchemeModel()
    {   std::cout << __PRETTY_FUNCTION__ << '\n';   }

private:

    SchemeController* m_controller = nullptr;
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
