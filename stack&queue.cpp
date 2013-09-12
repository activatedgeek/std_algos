/*******Stack using array, constant amortized complexity for push operations***********/
class Stack{
private:
	int *arr,head,size;
	friend class Queue;
public:
	Stack(){
		head=-1;
		size=10;
		arr=new int[size];
	}
	~Stack(){
		delete[] arr;
	}
	bool Push(int val){
		if(size==head+1){
			int temp[size];
			int i=0;
			while(i<size){
				temp[i]=arr[i];
				i++;
			}
			arr = new int[size*2];
			i=0;
			while(i<size){
				arr[i]=temp[i];
				i++;
			}
			size*=2;
			head=i;
			arr[head]=val;
			return true;
		}
		arr[++head] = val;
		return true;
	}
	int Pop(){
		if(head!=-1)
			return arr[head--];
		cout<<"Stack Underflow!";
		return 0;
	}
	int Top(){
		if(head!=-1)
			return arr[head];
		cout<<"Stack Underflow!";
		return 0;
	}
	bool IsEmpty(){
		return (head==-1);
	}
};
/*******Stack using array, constant amortized complexity for push operations***********/

/*******Queue using two Stacks********/
class Queue{
private:
	Stack left,right;
public:
	bool Enqueue(int val){
		left.Push(val);
	}
	int Dequeue(){
		if(right.head!=-1)
			return right.Pop();
		else{
			while(left.head!=-1)
				right.Push(left.Pop());
		}
		return right.Pop();
	}
	bool IsEmpty(){
		return ((left.head==-1) && (right.head==-1));
	}
	int Front(){
		if(right.head!=-1)
			return right.Pop();
		else{
			while(left.head!=-1)
				right.Push(left.Pop());
		}
		return right.Top();
	}
};

/*******Queue using two Stacks********/

/*******Stack using linked list, constant time operations************/
class Object{
public:
	Object *prev;
	int val;
	Object *next;
};

class StackLL{
	Object *top;
public:
	StackLL(){
		top = NULL;
	}
	~StackLL(){
		delete top;
	}
	bool Push(int val){
		if(top==NULL){
			Object *start = new Object;
			start->prev=NULL;
			start->next=NULL;
			start->val=val;
			top=start;
			return true;
		}
		else{
			Object *insert=new Object;
			insert->val = val;
			insert->prev = top;
			insert->next=NULL;
			top->next  = insert;
			top = insert;
			return true;
		}
		return false;
	}
	int Pop(){
		if(top!=NULL){
			int val = top->val;
			top = top->prev;
			//delete top->next;
			return val;
		}
		cout<<"Stack underflow!";
		return 0;
	}
	int Top(){
		if(top!=NULL)
			return top->val;
		else{
			cout<<"Stack underflow!";
			return 0;
		}
	}
	bool IsEmpty(){
		return (top==NULL);
	}
};
/*******Stack using linked list, constant time operations************/
