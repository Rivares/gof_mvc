#include "project_model.hpp"


ProjectModel::ProjectModel(const std::string& projName) :
    m_projName(projName)
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

ProjectModel::~ProjectModel()
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
}


void ProjectModel::setController(std::shared_ptr<ProjectController> ptrToController)
{   m_controller = ptrToController;  }


void ProjectModel::createScheme()
{
    m_schemeModel = std::make_shared<SchemeModel>();
    m_schemeController = std::make_shared<SchemeController>(m_schemeModel);
    m_schemeView = std::make_shared<SchemeView>(m_schemeController);

    m_schemeModel->setSchemeController(m_schemeController);
    m_schemeController->setSchemeView(m_schemeView);
}


void ProjectModel::callSignalAddElem(const TypeElem& type)
{
    m_schemeView->signalAddElem(type);
}


void ProjectModel::callSignalRemElem(const size_t idx) /// Current Element. Need use ElementBase* elem...
{
    m_schemeView->signalRemElem(idx);
}


std::variant<ProjectModel> ProjectModel::serialization()
{}

void ProjectModel::deserialization(const std::variant<ProjectModel>& data)
{}
