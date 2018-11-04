#pragma once

// STL����
#include <vector>
#include <map>
using std::vector;
using std::map;

// �߳̿�
#include <mutex>
using std::mutex;

// �����άint��������
using TWO_ARRAY_TYPE = vector<vector<int>>;

// ��������
class PointData
{
public:
	static	PointData*		Instance();
	static	void			Uninstance();

	virtual int				PushPoint(TWO_ARRAY_TYPE stlArrays);
	virtual TWO_ARRAY_TYPE	PopPoint(int iIndex);

protected:
	PointData();
	virtual ~PointData();

private:
	static PointData*			m_pSelf;			// ָ��Ψһ����������󣨵���ģʽ��
	map<int, TWO_ARRAY_TYPE>	m_mapPoint;			// ��ά����ӳ���
	mutex						m_mapPointMutex;	// ��ά����ӳ�����		

};

