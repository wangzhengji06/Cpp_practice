#define MY_ID 1

#if MY_ID == 0

#elif MY_ID == 1
#warning "MY_ID == 1"
#else
#error "MY_ID should be either 0 or 1"
#endif

int main() {}
