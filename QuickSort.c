#include &lt;stdio.h&gt;
#include &lt;pthread.h&gt;
#include &lt;unistd.h&gt;
#define N 5 // Number of philosophers
pthread_mutex_t forks[N]; // One mutex per fork
pthread_t philosophers[N];
void* philosopher(void* num)
{
int id = *(int*)num;
int left = id; // left fork index
int right = (id + 1) % N; // right fork index
while (1)
{
printf(&quot;Philosopher %d is thinking.\n&quot;, id);
sleep(1); // Thinking
// To avoid deadlock, philosophers with even id pick left, then right,
// odd id pick right, then left.
if (id % 2 == 0)
{
// Pick up left fork
pthread_mutex_lock(&amp;forks[left]);
printf(&quot;Philosopher %d picked up left fork %d.\n&quot;, id, left);
// Pick up right fork
pthread_mutex_lock(&amp;forks[right]);
printf(&quot;Philosopher %d picked up right fork %d.\n&quot;, id, right);
}
else
{
// Pick up right fork
pthread_mutex_lock(&amp;forks[right]);
printf(&quot;Philosopher %d picked up right fork %d.\n&quot;, id, right);

// Pick up left fork
pthread_mutex_lock(&amp;forks[left]);
printf(&quot;Philosopher %d picked up left fork %d.\n&quot;, id, left);
}
// Eating
printf(&quot;Philosopher %d is eating.\n&quot;, id);
sleep(2);
// Put down forks
pthread_mutex_unlock(&amp;forks[left]);
pthread_mutex_unlock(&amp;forks[right]);
printf(&quot;Philosopher %d put down forks %d and %d.\n&quot;, id, left, right);
}
return NULL;
}
int main()
{
int i;
int ids[N];
// Initialize forks (mutexes)
for (i = 0; i &lt; N; i++)
{
pthread_mutex_init(&amp;forks[i], NULL);
ids[i] = i;
}
// Create philosopher threads
for (i = 0; i &lt; N; i++)
{
pthread_create(&amp;philosophers[i], NULL, philosopher, &amp;ids[i]);
}
// Join threads (will never happen here, but good practice)
for (i = 0; i &lt; N; i++)
{
pthread_join(philosophers[i], NULL);
}