#pragma once

#include "common.hpp"

#include "project_model.hpp"
#include "project_view.hpp"

#include "scheme_model.hpp"
#include "scheme_controller.hpp"
#include "scheme_view.hpp"

#include <variant>
#include <memory>


class ProjectModel;
class ProjectView;

/*!
    \brief Class of control for redirection of signals
    \author Rivares
    \version 1.0
    \date 20.11.2023
    \warning Данный класс создан только в учебных целях

    Обычный класс
*/
class ProjectController
{
public:

    explicit ProjectController(std::shared_ptr<ProjectModel> ptrToModel);
    ~ProjectController();

    /*!
    setView connection
    \param[in] ptrToView Smart pointer to ProjectView
    */
    void setView(std::shared_ptr<ProjectView> ptrToView);

    void exportToFile(const TypeFile& type = TypeFile::JSON);
    void importFromFile(const std::string& file);
    void saveProj();


    /*!
    Write export to json file
    \return Project data
    (to future to use protobuf)
    */
    std::variant<ProjectController> serialization();


    /*!
    read import to json file
    \param[in] data Project data
    (to future to use protobuf)
    */
    void deserialization(const std::variant<ProjectController>& data);

private:

    std::weak_ptr<ProjectModel> m_model;    ///< ProjectController is't own ptr to ProjectModel
    std::weak_ptr<ProjectView>  m_view;      ///< ProjectController is't own ptr to ProjectView
};
