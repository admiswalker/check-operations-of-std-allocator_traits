//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;
using namespace std;

//---

template <typename T>
inline void print(const T& rhs){ std::cout<<" = "<<rhs<<std::endl; }
template <typename T>
inline void print(const std::vector<T>& rhs){
    std::cout<<" = [ ";
    for(uint i=0; i<rhs.size(); ++i){ std::cout<<rhs[i]<<' '; }
    std::cout<<"]"<<std::endl;
}
template <typename T>
inline void print(const std::vector<std::vector<T>>& rhs){
    std::cout<<" = "<<std::endl;
    std::cout<<"[[ ";
    for(uint p=0; p<rhs.size(); ++p){
        if(p!=0){ std::cout<<" [ "; }
        for(uint q=0; q<rhs[p].size(); ++q){
            std::cout<<rhs[p][q]<<' ';
        }
        if(p!=rhs.size()-1){ std::cout<<"]"<<std::endl; }
    }
    std::cout<<"]]"<<std::endl;
}
template <typename TL, typename TR>
inline void print(const std::vector<std::pair<TR,TL>>& rhs){
    std::cout<<" = [";
    uint i=0;
    for(; i<rhs.size()-1; ++i){ std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"], "; }
    std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"]]" << std::endl;
}
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

/*
https://stackoverflow.com/questions/33265165/does-stdallocator-traits-define-rebind-alloc-if-rebind-not-present-in-custom-a

template<typename T>
using RebindAlloc =
  typename std::allocator_traits<MyAllocator<void>>::template rebind_alloc<T>;

*/

struct AB{
private:
public:
    AB(){}
    ~AB(){}
    
    int A;
    int B;
};


//template <class T_alloc_e=std::allocator_traits<struct AB>> class example_ac;

template <class T_alloc_e>
class example_ac{
 private:
    int ttSize;
    struct AB* pT;
    
 public:
    example_ac(){
        printf("in const\n");
        ttSize      = 100;
        
        auto alc_e = T_alloc_e();
        pT         = alc_e.allocate(ttSize);
    }
    ~example_ac(){
        printf("in dst\n");
    }
};


int main(){
    /*
    //--------------------------------------------------------------------
    
    using RebindAlloc = std::allocator_traits<std::allocator<int>>::template rebind_alloc<std::pair<int,int>>;

    auto ralc = RebindAlloc();
    std::pair<int,int>* pPair = ralc.allocate(10);
    for(uint i=0; i<10; ++i){
        pPair[i].first = i;
        pPair[i].second = i*10;
    }

    for(uint i=0; i<10; ++i){
        std::cout << pPair[i].first << ", " << pPair[i].second << std::endl;
    }
    
    ralc.deallocate(pPair, 10);
    
    //--------------------------------------------------------------------
    */
    
    example_ac<std::allocator_traits<struct AB>> ex;
    
    
    return 0;
}
