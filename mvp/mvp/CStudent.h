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
		switch (sortFlag)
		{
		case 1:
			return (this->name < other.name);
			break;

		case 2:
			return (this->phoneNumber < other.phoneNumber);
			break;
		}

		return false;
	}

    static int sortFlag;
};

#endif // CSTUDENT_H
