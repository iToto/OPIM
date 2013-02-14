#include "delegateThread.h"

delegateThread::delegateThread( void* obj ) : _obj( obj ){ }

pthread_t delegateThread::startThread( func f, void* args )
{
	pthread_t th; //thread structure to return to the caller.
	threadNfo* tn = new threadNfo();

	tn->f = f; //target threaded member-function.
	tn->args = args; //parameters to pass.

	pthread_create( &th, NULL, doStartThread, (void*)tn ); //invoking the threaded function.

	return th;
}

void* delegateThread::doStartThread( void* ptr )
{
	threadNfo* tn = static_cast<threadNfo*>(ptr); //retreiving the thread information.
	func f = tn->f;

	f( tn->args ); //calling the member function, which is now in a seperate thread.

	delete tn; //cleaning up.

	return 0; //returning a dummy value.
}
