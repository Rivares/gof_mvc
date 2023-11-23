#include "project_controller.hpp"


ProjectController::ProjectController(std::shared_ptr<ProjectModel> ptrToModel)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';

    m_model = ptrToModel;
}

ProjectController::~ProjectController()
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}


void ProjectController::setView(std::shared_ptr<ProjectView> ptrToView)
{   m_view = ptrToView;    }

void ProjectController::exportToFile(const TypeFile& type)
{}

void ProjectController::importFromFile(const std::string& file)
{}

void ProjectController::saveProj()
{   exportToFile(TypeFile::JSON); }

std::variant<ProjectController> ProjectController::serialization()
{}

void ProjectController::deserialization(const std::variant<ProjectController>& data)
{}
