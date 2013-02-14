#ifndef __DELEGATE_THREAD_H__
#define __DELEGATE_THREAD_H__

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <pthread.h>

using namespace std;

typedef boost::function<void* (void*)> func;

struct threadNfo
{
	func f;
	void* args;
};

class delegateThread
{
	public:
		virtual pthread_t startThread( func, void* );
		delegateThread( void* obj );

	private:
		static void* doStartThread( void* );
		void* _obj;
};

#endif
