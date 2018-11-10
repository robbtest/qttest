#pragma once

// STL容器
#include <vector>
#include <map>
using std::vector;
using std::map;

// 线程库
#include <mutex>
using std::mutex;

// 定义int数组类型
using ARRAY_TYPE = vector<int>;

// 点数据类
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
	static PointData*		m_pSelf;			// 指向唯一创建本类对象（单例模式）
	map<int, ARRAY_TYPE>	m_mapPoint;			// 数组映射表
	mutex					m_mapPointMutex;	// 数组映射表锁		

};

