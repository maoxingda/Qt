#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <QString>
#include <QMetaType>

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

	// sort by name
	bool operator<(const CStudent& other)
	{
		return (this->name < other.name);
	}
};

Q_DECLARE_METATYPE(CStudent)

#endif // CSTUDENT_H
