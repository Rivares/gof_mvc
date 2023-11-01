#ifndef ELEM_RECT_MODEL_H
#define ELEM_RECT_MODEL_H

#include "elementbase_model.hpp"

//enum class TypeElem;
//class ElementBaseModel;
//class ElementRectModel;
//class ElementLineModel;
//class ElementElipseModel;

// (доступ к данным)

#include <iostream>

#include <memory>
#include <list>


class ElementRectModel: public ElementBaseModel
{
public:

    ElementRectModel()
    {}
    ~ElementRectModel()
    {}

    Pos getPosCenter() const override
    {   return m_posCenter;   }
    std::string getColorBackground() const override
    {   return m_colorBackground;   }
    std::string getColorBorder() const override
    {   return m_colorBorder;   }


    void setPosCenter(Pos pos) override
    {   m_posCenter = pos;    }
    void setColorBackground(std::string color) override
    {   m_colorBackground = color;  }
    void setColorBorder(std::string color) override
    {   m_colorBorder = color;  }

private:

};

//class ElementLineModel: public ElementRectModel
//{
//public:

//    ElementLineModel()
//    {}
//    ~ElementLineModel()
//    {}

//private:

//};

//class ElementElipseModel: public ElementBaseModel
//{
//public:

//    ElementElipseModel()
//    {}
//    ~ElementElipseModel()
//    {}

//private:

//};


#endif
