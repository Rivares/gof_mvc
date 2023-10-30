#pragma once


// (доступ к данным)

class Model
{
public:

    Model() = default;
    ~Model() = default;

private:

};

class ElementBase
{
public:

    ElementBase();
    ~ElementBase();

private:

};

class ElementRect: public ElementBase
{
public:

    ElementRect();
    ~ElementRect();

private:

};

class ElementLine: public ElementRect
{
public:

    ElementLine();
    ~ElementLine();

private:

};

class ElementElipse: public ElementBase
{
public:

    ElementElipse();
    ~ElementElipse();

private:

};
