#pragma once

#include "model.hpp"
#include "view.hpp"

#include <memory>

// (методы редактирования)
class SchemeController
{
public:
    SchemeController(std::shared_ptr<SchemeModel> ptrToModel)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        std::shared_ptr<ProjectModel> tmpPtrToModel(ptrToModel);
        m_model = tmpPtrToModel;
    }

    ~SchemeController()
    {}
private:
    std::shared_ptr<SchemeModel> m_model;
    std::shared_ptr<SchemeView> m_view;
};
