#include "lib.hpp"

#include "model.hpp"

#include <variant>
#include <string>
#include <memory>

enum class TypeFile
{
    JSON,
    BINARY
};

class Project
{
public:
    // singlton
    static Project* instance()
    {   return ((!m_instance)? new Project() : m_instance); }

    Project(const Project&) = delete;
    Project(const Project&&) = delete;
    Project& operator = (const Project&) = delete;

    void exportToFile(const TypeFile& type = TypeFile::JSON);
    void importFromFile(const std::string& file);

    // (to future to use protobuf)
    // write export to json file
    std::variant<Model> serialization();

    // read import to json file
    void deserialization(const std::variant<Model>& data);

private:
    explicit Project()
    {
        m_instance = this;
        m_model = std::make_unique<Model>();
    }
    ~Project()
    {
        if (m_instance)
        {
            m_instance = nullptr;
            delete m_instance;
        }
    }

    static Project* m_instance;

    std::unique_ptr<Model> m_model;
};
Project* Project::m_instance = nullptr;

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

    Project* initialProj = Project::instance();

    return 0;
}

