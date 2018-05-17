#include <future>

void run_futures(int count) {
	if (count > 14){
		return;
		}
	if ((count % 2) == 0){
		++count;
		auto running_future_1 = std::async( std::launch::async, run_futures, count );
		auto running_future_2 = std::async( std::launch::async, run_futures, count );
		running_future_1.get();
		running_future_2.get();
		return;
		}
	++count;
	auto running_future_1 = std::async( std::launch::async, run_futures, count );
	running_future_1.get();
	return;
	}


int main() {
	run_futures(0);
	//futures_top.get();
	return 0;
	}