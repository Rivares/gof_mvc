#include "project_view.hpp"


ProjectView::ProjectView(std::shared_ptr<ProjectController>  ptrToController)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';

    m_controller = ptrToController;
}

ProjectView::~ProjectView()
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}


std::variant<ProjectView> ProjectView::serialization()
{}

void ProjectView::deserialization(const std::variant<ProjectView>& data)
{}


