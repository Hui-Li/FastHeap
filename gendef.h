#ifndef __GENERAL_DEFINITION
#define __GENERAL_DEFINITION

#include <stdio.h>
#include <ctype.h>

//-------------------All-------------------------------------
#define MAXREAL         1e20f
#define FLOATZERO       1e-8f


#define min(a, b) (((a) < (b))? (a) : (b)  )
#define max(a, b) (((a) > (b))? (a) : (b)  )



using namespace std;
#include <vector>
#include <queue>

struct HeapEntry {
	int level,son,count,owner;
	float key;
};

struct HeapComp {
	bool operator () (HeapEntry left,HeapEntry right) const
	{ return left.key > right.key; }
};

struct SortComp {
	bool operator () (HeapEntry left,HeapEntry right) const
	{ return left.key < right.key; }
};


template<typename _Tp, typename _Sequence, typename _Compare >
    class FAST_HEAP
    {

    public:
      typedef typename _Sequence::value_type                value_type;
      typedef typename _Sequence::reference                 reference;
      typedef typename _Sequence::const_reference           const_reference;
      typedef typename _Sequence::size_type                 size_type;

    protected:
      _Sequence  c;
      _Compare   comp;

    public:
      explicit
      FAST_HEAP(const _Compare& __x = _Compare(),
		     const _Sequence& __s = _Sequence())
      : c(__s), comp(__x)
      { std::make_heap(c.begin(), c.end(), comp); }

      bool empty() const { return c.empty(); }

      size_type size() const { return c.size(); }

      const_reference top() const {
		return c.front();
      }

      void push(const value_type& __x) {
          c.push_back(__x);
          std::push_heap(c.begin(), c.end(), comp);
      }

      void pop() {
          std::pop_heap(c.begin(), c.end(), comp);
          c.pop_back();
      }
};

//typedef	priority_queue<HeapEntry,vector<HeapEntry>,HeapComp> Heap;
typedef	FAST_HEAP<HeapEntry,vector<HeapEntry>,HeapComp> Heap;
typedef	FAST_HEAP<HeapEntry,vector<HeapEntry>,SortComp> RSLIST;


typedef vector<HeapEntry> EntryList;
typedef vector<int> IntVec;
typedef vector<float> FloatVec;


#endif

