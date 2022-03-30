// TOPIC: std::lock_guard In C++
// usage: std::lock_guard<mutex> lock(m1);
// NOTES:
// 0. It is very light weight wrapper for owning mutex on scoped basis.
// 1. It acquires mutex lock the moment you create the object of lock_guard.
// 2. It automatically removes the lock while goes out of scope.
// 3. You can not explicitly unlock the lock_guard.
// 4. You can not copy lock_guard.



// TOPIC: unique_lock In C++
// usage: std::unique_lock<mutex> lock(m1);     // this is same as lock_gaurd but additional uses are shown below in locking strategies
// NOTES:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//     a. Can Have Different Locking Strategies
//     b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//     c. recursive locking
//     d. transfer of lock ownership (move not copy)
//     e. condition variables. (See this in coming videos)

// Locking Strategies
// TYPE             EFFECTS(S)

// 1. defer_lock    do not acquire ownership of the mutex immediately at declaration, then whenever we want in between we can acquire lock by using unique_lock_name.lock().
// usage: std::unique_lock<mutex> lock(m1, std::defer_lock);

// 2. try_to_lock   try to acquire ownership of the mutex without blocking.
// usage: std::unique_lock<mutex> lock(m1, std::try_to_lock);

// 3. adopt_lock    assume the calling thread already has ownership of the mutex.
// usage: std::unique_lock<mutex> lock(m1, std::adopt_lock);