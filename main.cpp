#include "lib.hpp"

#include "model.hpp"

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
    // singlton
    static ProjectModel* instance()
    {   return ((!m_instance)? new ProjectModel() : m_instance); }

    ~ProjectModel()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        if (m_instance)
        {
            m_instance = nullptr;
            delete m_instance;
        }
    }

    ProjectModel(const ProjectModel&) = delete;
    ProjectModel(const ProjectModel&&) = delete;
    ProjectModel& operator = (const ProjectModel&) = delete;


    // (to future to use protobuf)
    // write export to json file
    std::variant<ProjectModel> serialization();

    // read import to json file
    void deserialization(const std::variant<ProjectModel>& data);

private:
    explicit ProjectModel()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        m_instance = this;
        m_model = std::make_unique<SchemeModel>();
    }


    static ProjectModel* m_instance;

    std::unique_ptr<SchemeModel> m_model;
};
ProjectModel* ProjectModel::m_instance = nullptr;



class ProjectController
{
public:

    explicit ProjectController(ProjectModel* ptrToModel)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        std::shared_ptr<ProjectModel> tmpPtrToModel(ptrToModel);
        m_model = tmpPtrToModel;

        std::shared_ptr<ProjectController> tmpPtrToController(this);
        m_controller = tmpPtrToController;
    }
    ~ProjectController()
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }

    void setView(ProjectView* ptrToView)
    {
        std::shared_ptr<ProjectView> tmpPtrToView(ptrToView);
        m_view = tmpPtrToView;
    }

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

    std::shared_ptr<ProjectController> m_controller;

    std::shared_ptr<ProjectModel> m_model;
    std::shared_ptr<ProjectView> m_view;
};


class ProjectView
{
public:

    explicit ProjectView(ProjectController* ptrToController)
    {
        std::cout << __PRETTY_FUNCTION__ << '\n';

        std::shared_ptr<ProjectController> tmpPtrToController(ptrToController);
        m_controller = tmpPtrToController;
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

    std::shared_ptr<ProjectController> m_controller;
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

    ProjectModel*       projModel       = ProjectModel::instance();
    ProjectController*  projController  = new ProjectController(projModel);
    ProjectView*        projView        = new ProjectView(projController);

    projController->setView(projView);

    return 0;
}

