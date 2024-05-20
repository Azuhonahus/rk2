#include <gtest/gtest.h>
#include "ValveModelImpl.h"


TEST(ValveModelImplTest, WidenOpeningTest) {
    ValveModelImpl model;
    model.widenOpening();
    EXPECT_EQ(model.getValue(), 1);
}

// Тестирование уменьшения открытия клапана
TEST(ValveModelImplTest, NarrowOpeningTest) {
    ValveModelImpl model;
    model.narrowOpening();
    EXPECT_EQ(model.getValue(), -1);
}

// Тестирование наблюдателя
TEST(ValveViewLabelTest, ValveValueChangedTest) {
    ValveModelImpl model;
    ValveViewLabel labelView;
    labelView.attach(std::make_shared<ValveModelImpl>(model));

    testing::internal::CaptureStdout(); // Захват вывода на консоль
    model.widenOpening();
    std::string output = testing::internal::GetCapturedStdout(); // Получение захваченного вывода
    EXPECT_EQ(output, "Label: 1\n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
