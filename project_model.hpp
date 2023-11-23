#pragma once

#include "common.hpp"

#include "project_controller.hpp"

#include "scheme_controller.hpp"
#include "scheme_view.hpp"

#include <variant>
#include <string>
#include <memory>


class ProjectController;

/*!
    \brief Class of data for store all information
    \author Rivares
    \version 1.0
    \date 20.11.2023
    \warning Данный класс создан только в учебных целях

    Обычный класс
*/
class ProjectModel
{
public:

    explicit ProjectModel(const std::string& projName);

    ~ProjectModel();

    ProjectModel(const ProjectModel&) = delete;
    ProjectModel(const ProjectModel&&) = delete;
    ProjectModel& operator = (const ProjectModel&) = delete;

    /*!
    setContraller connection
    \param[in] ptrToController  Smart pointer to ProjectController
    */
    void setController(std::shared_ptr<ProjectController> ptrToController);

    /*!
    Only ProjectModel own all of data
    */
    void createScheme();

    /*!
    Call signal for addition elem to scheme
    \param[in] type Type of Elem
    */
    void callSignalAddElem(const TypeElem& type);

    /*!
    Call signal for deleting elem from scheme
    \param[in] idx Dummy index. Need use ElementBase* elem...
    */
    void callSignalRemElem(const size_t idx); /// Current Element. Need use ElementBase* elem...


    /*!
    Write export to json file
    \return Project data
    (to future to use protobuf)
    */
    std::variant<ProjectModel> serialization();


    /*!
    read import to json file
    \param[in] data Project data
    (to future to use protobuf)
    */
    void deserialization(const std::variant<ProjectModel>& data);

private:
    std::string m_projName;

    std::shared_ptr<ProjectController>  m_controller;

    std::shared_ptr<SchemeModel>        m_schemeModel;
    std::shared_ptr<SchemeController>   m_schemeController;
    std::shared_ptr<SchemeView>         m_schemeView;
};
