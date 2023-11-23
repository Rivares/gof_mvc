#define GOOGLE_TEST_MODULE test_main_google

#include "test_main_google.hpp"

#include <gtest/gtest.h>

/*
TEST(TestGroupName, Subtest_1)
{    
    {
        std::cout << "Constructions project of objects:\n\n";
        std::shared_ptr<ProjectModel>       projModel(std::make_shared<ProjectModel>("nameProj"));
        EXPECT_NE(projModel, nullptr);

        std::shared_ptr<ProjectController>  projController(std::make_shared<ProjectController>(projModel));
        EXPECT_NE(projController, nullptr);

        std::shared_ptr<ProjectView>        projView(std::make_shared<ProjectView>(projController));
        EXPECT_NE(projView, nullptr);

        projModel->setController(projController);
        projController->setView(projView);

        std::cout << "\n\nConstructions inner objects:\n\n";
        projModel->createScheme();

        std::cout << "\n\nDestructions objects:\n";
    }

    EXPECT_EQ(projModel, nullptr);
    EXPECT_EQ(projController, nullptr);
    EXPECT_EQ(projView, nullptr);
}

TEST(TestGroupName, Subtest_2)
{
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
        EXPECT_NO_THROW(
            projModel->callSignalAddElem(TypeElem::RECT); // simulation call signal
                );

        EXPECT_NO_THROW(
            projModel->callSignalRemElem(0); // simulation call signal
                );

        std::cout << "\n\nDestructions objects:\n";
    }

    std::cout << "\n";
}
*/
