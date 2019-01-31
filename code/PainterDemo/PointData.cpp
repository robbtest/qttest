#include "PointData.h"
#include <QDebug>

PointData* PointData::m_pSelf = nullptr;

PointData::PointData()
{
}


PointData::~PointData()
{
}

PointData*	PointData::Instance()
{
	if (m_pSelf == nullptr)
	{
		m_pSelf = new PointData();
		qDebug() <<"m_pSelf addr is"<< m_pSelf;
	}

	return m_pSelf;
}

void PointData::Uninstance()
{
	if (m_pSelf != nullptr)
	{
		delete m_pSelf;
		m_pSelf = nullptr;
	}
}

int PointData::PushPoint(ARRAY_TYPE stlArrays)
{
	// �漰�����̷߳����� ����
	m_mapPointMutex.lock();
	m_mapPoint[m_mapPoint.size()] = stlArrays;
	int iSize = m_mapPoint.size()-1;
	m_mapPointMutex.unlock();

	return iSize;
}

ARRAY_TYPE PointData::PopPoint(int iIndex)
{
	// �漰�����߳�ȡ���� ����
	m_mapPointMutex.lock();
	ARRAY_TYPE stlArrays = m_mapPoint[iIndex];
	m_mapPoint.erase(iIndex);
	m_mapPointMutex.unlock();

	return stlArrays;
}