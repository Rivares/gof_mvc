#pragma once

#include "elementbase.hpp"

//enum class TypeElem;
//class ElementBase;
//class ElementRect;
//class ElementLine;
//class ElementElipsel;

// (доступ к данным)

#include <iostream>

#include <memory>
#include <list>


class ElementRect: public ElementBase
{
public:

    ElementRect()
    {}
    ~ElementRect()
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


