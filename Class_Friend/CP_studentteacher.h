#pragma once
class student;
class teacher
{
public:
	void set_score(student& s, int i);
};

class student
{
private:
	int m_score;
public:
	void get_score() { cout << "ÄúµÄ³É¼¨ÊÇ£º" << m_score << endl; }
	friend class teacher;
};