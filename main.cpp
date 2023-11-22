#include "scheme_model.hpp"
#include "scheme_controller.hpp"
#include "scheme_view.hpp"

#include <variant>
#include <string>
#include <memory>

class ProjectModel;
class ProjectController;
class ProjectView;

enum class TypeFile
{
    JSON,
    BINARY
};

class ProjectModel
{
public:

    explicit ProjectModel(const std::string& projName) :
        m_projName(projName)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';        
    }

    ~ProjectModel()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    ProjectModel(const ProjectModel&) = delete;
    ProjectModel(const ProjectModel&&) = delete;
    ProjectModel& operator = (const ProjectModel&) = delete;

    void setController(std::shared_ptr<ProjectController> controller)
    {   m_controller = controller;  }


    void createScheme()
    {
        m_schemeModel = std::make_shared<SchemeModel>();
        m_schemeController = std::make_shared<SchemeController>(m_schemeModel);
        m_schemeView = std::make_shared<SchemeView>(m_schemeController);

        m_schemeModel->setSchemeController(m_schemeController);
        m_schemeController->setSchemeView(m_schemeView);
    }

    void callSignalAddElem(const TypeElem& type)
    {
        m_schemeView->signalAddElem(type);
    }

    void callSignalRemElem(const size_t idx) // current Element. Need use ElementBase* elem...
    {
        m_schemeView->signalRemElem(idx);
    }

    // (to future to use protobuf)
    // write export to json file
    std::variant<ProjectModel> serialization();

    // read import to json file
    void deserialization(const std::variant<ProjectModel>& data);

private:
    std::string m_projName;

    std::shared_ptr<ProjectController> m_controller;

    std::shared_ptr<SchemeModel> m_schemeModel;
    std::shared_ptr<SchemeController> m_schemeController;
    std::shared_ptr<SchemeView> m_schemeView;
};



class ProjectController
{
public:

    explicit ProjectController(std::shared_ptr<ProjectModel> ptrToModel)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        m_model = ptrToModel;
    }
    ~ProjectController()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    void setView(std::shared_ptr<ProjectView> ptrToView)
    {   m_view = ptrToView;    }

    void exportToFile(const TypeFile& type = TypeFile::JSON);
    void importFromFile(const std::string& file);
    void saveProj()
    {   exportToFile(TypeFile::JSON); }

    // (to future to use protobuf)
    // write export to json file
    std::variant<ProjectController> serialization();

    // read import to json file
    void deserialization(const std::variant<ProjectController>& data);

private:

    std::weak_ptr<ProjectModel> m_model;
    std::weak_ptr<ProjectView> m_view;
};


class ProjectView
{
public:

    explicit ProjectView(std::shared_ptr<ProjectController>  ptrToController)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        m_controller = ptrToController;
    }
    ~ProjectView()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }


    // (to future to use protobuf)
    // write export to json file
    std::variant<ProjectView> serialization();

    // read import to json file
    void deserialization(const std::variant<ProjectView>& data);

private:

    std::weak_ptr<ProjectController> m_controller;
};



int main()
{

//    Спроектировать простейший графический векторный редактор. Подготовить макеты классов,
//    отражающих структуру будущего проекта.

//    Функционал для макетирования следующий:
//    - создание нового документа
//    - импорт документа из файла
//    - экспорт документа в файл
//    - создание графического примитива
//    - удаление графического примитива

//    Функции, являющиеся обработчиками GUI, собрать в одном файле с функцией `main`.

//    Задание считается выполненным успешно, если все файлы прошли стадию компиляции, все классы
//    охвачены диаграммами, код успешно прошел анализ.

//    Дополнительные рекомендации
//    1. Заложить в интерфейсы использование умных указателей, тем самым решив вопрос
//    владения объектами.
//    2. Помнить про принцип единственности ответственности, разделить код на логические
//    модули (классы, функции).



    std::shared_ptr<ProjectModel>       projModel(std::make_shared<ProjectModel>("nameProj"));
    std::shared_ptr<ProjectController>  projController(std::make_shared<ProjectController>(projModel));    
    std::shared_ptr<ProjectView>        projView(std::make_shared<ProjectView>(projController));

    projModel->setController(projController);
    projController->setView(projView);

    std::cout << '\n';
    projModel->createScheme();

    projModel->callSignalAddElem(TypeElem::RECT); // simulation call signal
    projModel->callSignalRemElem(0); // simulation call signal

    std::cout << '\n';

    return 0;
}

