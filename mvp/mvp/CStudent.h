#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <QString>

class CStudent
{
public:
	CStudent();
	~CStudent();

	QString name;
	QString phoneNumber;

	// query by name
	bool operator==(QString name)
	{
		return (this->name == name);
	}

	// sort
	bool operator<(const CStudent& other)
	{
		return (this->name < other.name);
	}
};

class CStudentCompare
{
public:
	enum SortFlag {SORT_BY_NAME, SORT_BY_PHONE} sortFlag;

	explicit CStudentCompare(SortFlag sortFlag)
		: sortFlag(sortFlag)
	{
	}

	bool operator()(const CStudent& lhs, const CStudent& rhs)
	{
		switch (sortFlag)
		{
		case SORT_BY_NAME:
			return (lhs.name < rhs.name);
			break;

		case SORT_BY_PHONE:
			return (lhs.phoneNumber < rhs.phoneNumber);
			break;
		}

		return false;
	}
};

#endif // CSTUDENT_H
