#pragma once

// STL容器
#include <vector>
#include <map>
using std::vector;
using std::map;

// 线程库
#include <mutex>
using std::mutex;

// 定义二维int数组类型
using TWO_ARRAY_TYPE = vector<vector<int>>;

// 点数据类
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
	static PointData*			m_pSelf;			// 指向唯一创建本类对象（单例模式）
	map<int, TWO_ARRAY_TYPE>	m_mapPoint;			// 二维数组映射表
	mutex						m_mapPointMutex;	// 二维数组映射表锁		

};

