#pragma once
#include <QString>


struct Student
{
	QString name;
	int		id;

	Student() {}
	Student(const Student& other)
	{
		name	= other.name;
		id		= other.id;
	}
};