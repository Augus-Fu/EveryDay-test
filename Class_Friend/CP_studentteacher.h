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
	void get_score() { cout << "���ĳɼ��ǣ�" << m_score << endl; }
	friend class teacher;
};