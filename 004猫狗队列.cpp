#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/**
 * @author GK
 * @date 2020/8/5
 * @function 根据猫狗类，实现一种猫狗队列的结构，要求如下：
 * 			1. 用户可以调用add方法将cat类或dog类的实例放入队列中；
 *   		2. pollAll:将队列中所有的实例弹出FIFO	pollDog:将队列中dog类实例弹出FIFO  pollCat:将队列中cat类实例弹出FIFO
 *   		3. isEmpty:检查队列中是否还有dog或cat实例	isEmptyDog:检查队列中是否还有dog或cat实例  itEmptyCat:检查队列中是否还有dog或cat实例
**/

class Pet{
	string type;

public:
	Pet(string t):type(t){}
	Pet(const Pet& p){
		this->type = p.getPetType();
	}
	string getPetType() const{
		return this->type;
	}
};

class Dog: public Pet{

public:
	Dog():Pet("dog"){}
};

class Cat: public Pet{

public:
	Cat():Pet("cat"){}
};

class PetEnterQueue{
	Pet pet;
	unsigned long long count;

public:
	PetEnterQueue(Pet p, unsigned long long c):pet(p),count(c){}

	Pet& getPet(){
        return this->pet;
	}

	unsigned long long getCount(){
		return this->count;
	}

	string getEnterPetType(){
		return this->pet.getPetType();
	}
};

class CDQueue{
	queue<PetEnterQueue> dogq;
	queue<PetEnterQueue> catq;
	unsigned long long count;

public:
	CDQueue():count(0){}
    void add(Pet&);
    Pet* pollAll();
    Dog* pollDog();
    Cat* pollCat();
    bool isEmpty();
    bool isEmptyDog();
    bool isEmptyCat();
};

void CDQueue::add(Pet& pet){
	if(pet.getPetType().compare("dog") == 0)
		dogq.push(PetEnterQueue(pet,count++));
    else if(pet.getPetType().compare("cat") == 0)
		catq.push(PetEnterQueue(pet,count++));
	else
		cout << "Neither cat or dog..." << endl;
}

Pet* CDQueue::pollAll(){
	Pet* result = nullptr;
	if(dogq.empty() && catq.empty())
		return result;
	if(!catq.empty() && (dogq.empty() || dogq.front().getCount() > catq.front().getCount())){
		result = &catq.front().getPet();
		catq.pop();
	}else if(!dogq.empty() && (catq.empty() || dogq.front().getCount() <= catq.front().getCount())){
		result = &dogq.front().getPet();
		dogq.pop();
	}
		return result;
}

Dog* CDQueue::pollDog(){
	if(dogq.empty())
		return nullptr;
	Pet* result = &dogq.front().getPet();
    dogq.pop();
    return (Dog *)result;
}

Cat* CDQueue::pollCat(){
	if(catq.empty())
		return nullptr;
	Pet* result = &catq.front().getPet();
	catq.pop();
	return (Cat *)result;
}

bool CDQueue::isEmpty(){
    return !(catq.size() + dogq.size());
}

bool CDQueue::isEmptyDog(){
	return !dogq.size();
}

bool CDQueue::isEmptyCat(){
	return !catq.size();
}

int main(void){
	CDQueue q;
	Pet* p = nullptr;
	for (int i = 0; i < 10; ++i){
		if (i & 1 > 0)
			p = new Dog();
		else
			p = new Cat();
		q.add(*p);
	}

	for (int i = 0; i < 10; ++i){
        p = q.pollAll();
        if (p)
			printf("%2d: %s\n", i+1,  p->getPetType().c_str());
	}

    return 0;
}
