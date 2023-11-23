#pragma once

#include "common.hpp"

#include "project_controller.hpp"

#include "scheme_model.hpp"
#include "scheme_controller.hpp"
#include "scheme_view.hpp"

#include <variant>
#include <memory>


class ProjectController;

/*!
    \brief Class of view for view and geting signals
    \author Rivares
    \version 1.0
    \date 20.11.2023
    \warning Данный класс создан только в учебных целях

    Обычный класс
*/
class ProjectView
{
public:

    explicit ProjectView(std::shared_ptr<ProjectController>  ptrToController);
    ~ProjectView();


    /*!
    Write export to json file
    \return Project data
    (to future to use protobuf)
    */
    std::variant<ProjectView> serialization();


    /*!
    read import to json file
    \param[in] data Project data
    (to future to use protobuf)
    */
    void deserialization(const std::variant<ProjectView>& data);

private:

    std::weak_ptr<ProjectController> m_controller;
};
