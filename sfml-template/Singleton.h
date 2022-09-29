#pragma once

template <typename T>
class Singleton
{
private:
	static T* instance;
public:
	static T* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new T();
		}
		return instance;
	}

	static void Destroy()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
};
template <typename T>
T* Singleton<T>::instance = nullptr;