struct Semaphore {
	int value;
  //Counting Semaphore 
	// q contains all Process Control Blocks(PCBs)
	// corresponding to processes got blocked
	// while performing down operation.
	Queue<process> q;

} P(Semaphore s)
{
	s.value = s.value - 1;
	if (s.value < 0) {

		// add process to queue
		// here p is a process which is currently executing
		q.push(p);
		block();
	}
	else
		return;
}

V(Semaphore s)
{
	s.value = s.value + 1;
	if (s.value <= 0) {

		// remove process p from queue
		Process p=q.pop();
		wakeup(p);
	}
	else
		return;
}


P operation is also called wait, sleep or down operation and V operation is also called signal, wake-up or up operation.
Both operations are atomic and semaphore(s) is always initialized to one.Here atomic means that variable on which read, modify and update happens 
at the same time/moment with no pre-emption i.e. in between read, modify and update no other operation is performed that may change the variable.
A critical section is surrounded by both operations to implement process synchronization.See below image.critical section of Process P is in between P and V
operation

===============================================================================================================================================================

struct semaphore {
	enum value(0, 1);

	// q contains all Process Control Blocks (PCBs)
	// corresponding to processes got blocked
	// while performing down operation.
	Queue<process> q;

} P(semaphore s)
{
	if (s.value == 1) {
		s.value = 0;
	}
	else {
		// add the process to the waiting queue
		q.push(P)
			sleep();
	}
}
V(Semaphore s)
{
	if (s.q is empty) {
		s.value = 1;
	}
	else {

		// select a process from waiting queue
		s.value = 1;
		Process p=q.pop();
		wakeup(p);
	}
}

=================================================================================================================================================================



