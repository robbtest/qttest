#include "PointData.h"

PointData* PointData::m_pSelf = nullptr;

PointData::PointData()
{
}


PointData::~PointData()
{
}

PointData*	PointData::Instance()
{
	if (m_pSelf != nullptr)
	{
		m_pSelf = new PointData();
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

int PointData::PushPoint(TWO_ARRAY_TYPE stlArrays)
{
	// 涉及到多线程放数据 上锁
	m_mapPointMutex.lock();
	m_mapPoint[m_mapPoint.size()] = stlArrays;
	int iSize = m_mapPoint.size();
	m_mapPointMutex.unlock();

	return iSize;
}

TWO_ARRAY_TYPE PointData::PopPoint(int iIndex)
{
	// 涉及到多线程取数据 上锁
	m_mapPointMutex.lock();
	TWO_ARRAY_TYPE stlArrays = m_mapPoint[m_mapPoint.size()];
	m_mapPoint.erase(m_mapPoint.size());
	m_mapPointMutex.unlock();

	return stlArrays;
}