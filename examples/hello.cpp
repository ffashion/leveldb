#include <stdio.h>
class hello {
public:
    static void Open();
};

class helloImpl: public hello {
public: 
    void Open() {
        printf("hello world\n");
    }
};

void hello::Open() {
    printf("hello world\n");
}

int	main(int argc, char **argv) {
    hello::Open();

    return 0;
}
