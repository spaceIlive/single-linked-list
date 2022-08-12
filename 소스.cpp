 #define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};


Node node[MAX_NODE];
int nodeCnt;
Node head;



Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];	//후위연산자라 지금 cnt값을 리턴하고 그 후에 ++됨
}

void init()
{	
	head.next= nullptr;
	nodeCnt = 0;				
}

void addNode2Head(int data)
{	
	
	Node* node = getNode(data);
	node->next = head.next;
	head.next = node;

}

void addNode2Tail(int data)
{	
	Node* ptr = &head;
	if (ptr->next == nullptr) {
		Node* node = getNode(data);
		ptr->next = node;
	}
	else {
		while (true ) {
			ptr= ptr->next;
			if (ptr->next == nullptr) {
				break;
			}
		}
		Node* node = getNode(data);
		ptr->next = node;		//여기서 ptr->next의 ptr은 맨 마지막 node를 말하는 것이라 가정
								//즉 화살표로 가르킴받는 곳이 아니라 화살표의 시작점이라 가정

	}
}

void addNode2Num(int data, int num)
{
	Node* ptr = &head;
	for (int i = 0; i < num-1; i++) {
		ptr = ptr->next;
	}
	Node* node = getNode(data);
	node->next = ptr->next;			 
	ptr->next = node;

}

void removeNode(int data)
{
	Node* ptr = &head;
	while (true) {
		if (ptr->next->data == data) {
			ptr->next = (ptr->next)->next;
			break;
		}
		ptr = ptr->next;
		if (ptr->next == nullptr)break;
	}
}

int getList(int output[MAX_NODE])
{	
	int cnt = 0;
	Node* ptr = &head;
	while (true) {
		
		if (ptr->next == nullptr) {
			break;
		}
		ptr = ptr->next;
		output[cnt] = ptr->data;
		cnt += 1;
	}
	return cnt;
}

