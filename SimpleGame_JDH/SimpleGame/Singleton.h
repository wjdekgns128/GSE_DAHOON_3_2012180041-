#pragma once
#include "MyDefine.h"
template <class T>
class Singleton
{
protected:
	Singleton()
	{

	}
	virtual ~Singleton()
	{

	}
public:
	static T& getinstance()	
	{
		static T Instance;
		return Instance;
	}
	
private:
};
