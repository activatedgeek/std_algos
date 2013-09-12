/*******Stack using array, constant amortized complexity for push operations***********/
class Stack{
int *arr,head,size;
public:
	Stack(){
		head=-1;
		size=3;
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
		if(head!=-1){
			return arr[head--];
		}
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
