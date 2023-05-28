#include <iostream>
#include "Course.h"

Course::Course(const std::string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new std::string[capacity];
}

Course::Course(const Course& course) {
	numberOfStudents = course.getNumberOfStudents();
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	//this->students = course.students;
	this->students = new std::string[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {
	if (numberOfStudents >= capacity) {
		std::string* tempStudents = new std::string[capacity + 1];
		for (int i = 0; i < capacity; i++) {
			tempStudents[i] = students[i];
		}
		capacity += 1;
		students = tempStudents;
	}

	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const std::string& name) {
	std::string* tempStudents = new std::string[capacity];
	int tempNumOfStudents = 0;

	for (int i = 0; i < numberOfStudents; i++)
	{
		if (students[i] != name)
		{
			tempStudents[tempNumOfStudents] = students[i];
			tempNumOfStudents++;
		}
	}

	students = tempStudents;
	numberOfStudents--;
}


std::string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

void Course::clear()
{
	students = new std::string[capacity];
	numberOfStudents = 0;
}
