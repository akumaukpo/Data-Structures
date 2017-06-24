
class Record
{
public:
	int StudentIDNumber;
	double Score;
	Record(int id,double score)
	{
		StudentIDNumber=id;
		Score=score;
	}

	int GetKeyValue()
	{
		return StudentIDNumber;
	}

	bool operator<(const int& rhs) const
	{
		return this->StudentIDNumber<rhs;
	}
	bool operator>(const int& rhs) const
	{
		return this->StudentIDNumber>rhs;
	}
	bool operator==(const int& rhs) const
	{
		return this->StudentIDNumber==rhs;
	}
};
