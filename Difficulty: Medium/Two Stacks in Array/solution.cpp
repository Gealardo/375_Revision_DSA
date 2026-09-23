class twoStacks {
    int arr[100];
    int size = 100;
    int top1, top2;

  public:
    twoStacks() {
        // Initialize the top pointers of both stacks
        top1=-1;
        top2=size;
    }

    void push1(int x) {
        // Insert the given element at the top of the first stack
        top1++;
        arr[top1]=x;
    }

    void push2(int x) {
        // Insert the given element at the top of the second stack
        top2--;
        arr[top2]=x;
    }

    int pop1() {
        // Return -1 if the stack is empty
        // Remove and return the top element of the first stack
        if(top1==-1) return -1;
        else {
            int poped = arr[top1];
            top1--;
            return poped;
        }
    }

    int pop2() {
        // Remove and return the top element of the second stack
        // Return -1 if the stack is empty
        if(top2==size) return -1;
        else {
            int poped = arr[top2];
            top2++;
            return poped;
        }
    }
};
