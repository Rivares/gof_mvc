#pragma once

#include "controller.hpp"

#include <memory>

// (методs отображения)
class SchemeView
{
public:
    SchemeView()
    {}

    ~SchemeView()
    {}
private:
    std::shared_ptr<SchemeController> m_controller;
};
