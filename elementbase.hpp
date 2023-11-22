#pragma once


// (доступ к данным)

#include <iostream>

#include <memory>
#include <list>


enum class TypeElem
{
    BASE,
    RECT,
    LINE,
    ELIPS
};

class ElementBase
{
public:

    struct Pos
    {   float x = 0.0; float y = 0.0;   };

    ElementBase()
    {}

    ~ElementBase()
    {}

    virtual Pos getPosCenter() const = 0;
    virtual std::string getColorBackground() const = 0;
    virtual std::string getColorBorder() const = 0;

    virtual void setPosCenter(Pos pos) = 0;
    virtual void setColorBackground(std::string color) = 0;
    virtual void setColorBorder(std::string color) = 0;

protected:

    Pos m_posCenter{0.0, 0.0};
    std::string m_colorBackground = "#fffff";
    std::string m_colorBorder = "#bag21f";
};


