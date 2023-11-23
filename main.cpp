#include "project_model.hpp"
#include "project_controller.hpp"
#include "project_view.hpp"

int main()
{

///   Спроектировать простейший графический векторный редактор.
///   Подготовить макеты классов, отражающих структуру будущего проекта.
/*!
    Функционал для макетирования следующий:
    - создание нового документа
    - импорт документа из файла
    - экспорт документа в файл
    - создание графического примитива
    - удаление графического примитива

    Функции, являющиеся обработчиками GUI, собрать в одном файле с функцией `main`.

    Задание считается выполненным успешно, если все файлы прошли стадию компиляции, все классы
    охвачены диаграммами, код успешно прошел анализ.

    Дополнительные рекомендации
    1. Заложить в интерфейсы использование умных указателей, тем самым решив вопрос
    владения объектами.
    2. Помнить про принцип единственности ответственности, разделить код на логические
    модули (классы, функции).
*/
    {
        std::cout << "Constructions project of objects:\n\n";
        std::shared_ptr<ProjectModel>       projModel(std::make_shared<ProjectModel>("nameProj"));
        std::shared_ptr<ProjectController>  projController(std::make_shared<ProjectController>(projModel));
        std::shared_ptr<ProjectView>        projView(std::make_shared<ProjectView>(projController));

        projModel->setController(projController);
        projController->setView(projView);

        std::cout << "\n\nConstructions inner objects:\n\n";
        projModel->createScheme();

        std::cout << "\n\nCall signals:\n\n";
        projModel->callSignalAddElem(TypeElem::RECT);   /// Simulation call signal
        projModel->callSignalRemElem(0);                /// Simulation call signal

        std::cout << "\n\nDestructions objects:\n";
    }

    std::cout << "\n";

    return 0;
}

