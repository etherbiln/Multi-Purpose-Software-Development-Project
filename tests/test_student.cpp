#include <gtest/gtest.h>
#include "../include/student_manager.h"

TEST(StudentManagerTest, AddStudent) {
    StudentManager manager;
    Student student(95, 1, "John", "Doe");
    manager.addStudent(student);
    EXPECT_EQ(manager.findStudent(1)->getNote(), 95);
}

TEST(StudentManagerTest, RemoveStudent) {
    StudentManager manager;
    Student student(95, 1, "John", "Doe");
    manager.addStudent(student);
    manager.removeStudent(1);
    EXPECT_EQ(manager.findStudent(1), nullptr);
}
