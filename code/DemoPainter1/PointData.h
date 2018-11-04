#pragma once

// STL����
#include <vector>
#include <map>
using std::vector;
using std::map;

// �߳̿�
#include <mutex>
using std::mutex;

// ����int��������
using ARRAY_TYPE = vector<int>;

// ��������
class PointData
{
public:
	static	PointData*	Instance();
	static	void		Uninstance();

	virtual int			PushPoint(ARRAY_TYPE stlArrays);
	virtual ARRAY_TYPE	PopPoint(int iIndex);

protected:
	PointData();
	virtual ~PointData();

private:
	static PointData*		m_pSelf;			// ָ��Ψһ����������󣨵���ģʽ��
	map<int, ARRAY_TYPE>	m_mapPoint;			// ����ӳ���
	mutex					m_mapPointMutex;	// ����ӳ�����		

};

