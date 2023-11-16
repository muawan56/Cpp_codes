#include <iostream>

class Instructor
{
private:
    std::string firstName;
    std::string lastName;
    std::string officeNumber;

public:
    Instructor(const std::string &firstName, const std::string &lastName, const std::string &officeNumber = "")
        : firstName{firstName}, lastName{lastName}, officeNumber{officeNumber} {}

    friend std::ostream &operator<<(std::ostream &out, const Instructor &instructor)
    {
        out << "Instructor: " << instructor.firstName << " " << instructor.lastName << std::endl
            << "Office Number: " << instructor.officeNumber << std::endl;
        return out;
    }
};

class Classroom
{
private:
    char building;
    int roomNumber;

public:
    Classroom(char building = 'A', int roomNumber = 101)
        : building{building}, roomNumber{roomNumber} {}

    friend std::ostream &operator<<(std::ostream &out, const Classroom &classroom)
    {
        out << "Building: " << classroom.building << std::endl
            << "Room Number: " << classroom.roomNumber << std::endl;
        return out;
    }
};

class CollegeCourse
{
private:
    Instructor instructor;
    Classroom classroom;
    int credits;

public:
    CollegeCourse(const std::string &instructorFirstName, const std::string &instructorLastName,
                  const std::string &instructorOfficeNumber, char classroomBuilding, int classroomRoomNumber, int credits)
        : instructor{instructorFirstName, instructorLastName, instructorOfficeNumber},
          classroom{classroomBuilding, classroomRoomNumber}, credits{credits} {}

    friend std::ostream &operator<<(std::ostream &out, const CollegeCourse &course)
    {
        out << course.instructor << std::endl;
        out << course.classroom << std::endl;
        out << "Credits: " << course.credits << std::endl;
        return out;
    }
};

int main()
{
    CollegeCourse course1{"John", "Doe", "1234", 'B', 202, 3};
    CollegeCourse course2{"Jane", "Smith", "5678", 'C', 303, 4};

    std::cout << "Course 1: " << std::endl;
    std::cout << course1 << std::endl;

    std::cout << "Course 2: " << std::endl;
    std::cout << course2 << std::endl;

    return 0;
}