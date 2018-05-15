#include <iostream>

template <class Key, class Value> class Map
{
private:
    struct data
	{
		data *next;
	    Key key;
	   	Value value;
		data(const Key& key, const Value& value): key(key), value(value) {}
	};
  	data *head;
 	data *current;
	unsigned int size = 0;
	
public:
	Map();
	Map(const Map& otherList);
	~Map();
	Map& operator=(const Map& otherList);
	Value* find(const Key key);
	void add(Key key, Value value);
	//size_t getSize(const Map target);
	friend std::ostream &operator<<(std::ostream &o, Map<Key, Value> &map)
	{
		map.current = map.head;
		while(map.current != nullptr) 
		{
			o <<"Prime Key: "<<map.current->key << " data: "<< map.current->value << std::endl;
			map.current = map.current->next;
		}
		map.current = map.head;
		return o;
    }
};

template <class Key, class Value> Map<Key, Value>::Map() 
{
    head = nullptr;
	current = nullptr;
	size = 0;
}

template <class Key, class Value> Map<Key, Value>::Map(const Map& otherList) 
{
    current = nullptr;
  	data *src, **dst;
	head = nullptr;
 	src = otherList.head;
  	dst = &head;
	size = 0;
  	while (src)
    {
		*dst = new data(src->key,src->value);
		
		if(src == otherList.current)
		{
			current=*dst;
		}
		
		src = src->next;
      	dst = &((*dst)->next);
		size++;
    }
}

template <class Key, class Value> Map<Key, Value>::~Map() 
{
    while (size)
	{
		data *t = head->next;
		delete head;
		head = t;
		--size;
	}
}

template <class Key, class Value> Map<Key, Value> &Map<Key, Value>::operator=(const Map<Key, Value> &otherList) {
    if (this == &otherList) 
	{
        return *this;
    }
    this->current = nullptr;
	//size_t LHS = getSize(this);
	//size_t RHS = getSize(otherList);
	int diff = size - otherList.size;
	
	if(diff > 0)
	{
		for(size_t i = 0; i < diff; i++)
		{
			data *t = head->next;
			delete head;
			--size;
			head = t;
		}
	}
	else if(diff < 0)
	{
		for(size_t i = 0; i > diff; i--)
		{
  			++size;
			data *t = new data(otherList.current->key,otherList.current->value);
  			t->next = head;
  			head = t;
		}
	}
  	data *src, **dst;
 	src = otherList.head;
  	dst = &head;
  		
  	for(size_t i = 0; i < otherList.size; i++)
    {
		(*dst)->key = src->key;
      	(*dst)->value = src->value;
		if(src == otherList.current)
		{
			current = *dst;
		}
		src = src->next;
      	dst = &((*dst)->next);	
    }
    return *this;
}

template <class Key, class Value> Value *Map<Key, Value>::find(const Key key) 
{
	current = head;
    //this->current = this->head;
	while(this->current != nullptr)
	{
	    if(this->current->key == key)
	    {
	    	return &this->current->value;
		}
		this->current = this->current->next;
	}
 	
	return nullptr;
}

template <class Key, class Value> void Map<Key, Value>::add(Key key, Value value)
{
	if(find(key) == nullptr)
	{
		++size;
		data *added = new data(key,value);
		added->next = head;
		head = added;
	}
	else
	{
		std::cout << "Prime Key: " << key <<" is already taken" << std::endl;
	}
}

/*template <class Key, class Value> size_t Map<Key, Value>::getSize(const Map target)
{
	size_t sizeCounter = 0;
	this->current = this->head;
	while(this->current != nullptr)
	{
	    sizeCounter++;
		this->current = this->current->next;
	}
 	
	return sizeCounter;
}*/