
#include <chrono>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

std::recursive_mutex rlock;
std::mutex mlock;
class MySingleton{
	public:
		static MySingleton* getInstance(){
			if (!instance)
			{
				//	std::lock_guard<std::mutex> lock(slock);
				if(rlock.try_lock())
				{
					std::lock_guard<std::mutex> lock(mlock);
					if (!instance)
					{
						instance= new MySingleton;
					}
				}
			}
			return instance;
		}
	private:
		MySingleton()= default;
		~MySingleton()= default;
		MySingleton(const MySingleton&)= delete;
		MySingleton& operator=(const MySingleton&)= delete;

		static MySingleton* instance;

};

MySingleton* MySingleton::instance= nullptr;

void fun()
{
	while(1)
	{
		MySingleton *p = MySingleton::getInstance();
		if (p)
		{
			std::cout << "In : " << std::this_thread::get_id() << "-->Thread\t " << p << std::endl;
			break;
		}
	}
}
int main()
{
	std::thread t1(fun);
	std::thread t2(fun);
	std::thread t3(fun);
	std::thread t4(fun);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}

