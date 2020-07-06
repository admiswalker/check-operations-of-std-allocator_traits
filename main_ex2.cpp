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

/*
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
    //--------------------------------------------------------------------
    // ref: https://cpprefjp.github.io/reference/memory/allocator.html

    auto alc = std::allocator<int>();

    // 10要素のint型が入る領域を確保
    int* arr = alc.allocate(10);

    // 確保した領域の各要素を構築する(コンストラクタを呼び出す)
    for (std::size_t i = 0; i != 10; ++i) alc.construct(arr + i);

    std::iota(arr, arr + 10, 0);
    std::for_each(arr, arr + 10, [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    // 配列の各要素を破棄する(デストラクタを呼び出す)
    for (std::size_t i = 0; i != 10; ++i) alc.destroy(arr + i);

    // 領域を解放する
    alc.deallocate(arr, 10);

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
    
    example_ac<std::allocator_traits<struct AB>> ex;
    
    return 0;
}
*/


/*
// ref: https://cpprefjp.github.io/reference/memory/allocator_traits.html
template <class T, class T_alloc_e>
class MyVector{
    T* pT;
    std::size_t ttSize;
    T_alloc_e aE_state; // current state of T_alloc_e allocation.
    
public:
    MyVector(std::size_t size){
        ttSize = size;

        // メモリを確保
        pT = std::allocator_traits<T_alloc_e>::allocate(aE_state, ttSize);

        // 要素を構築
        for(std::size_t i=0; i<ttSize; ++i) {
            std::allocator_traits<T_alloc_e>::construct(aE_state, &pT[i]);
        }
    }

    ~MyVector(){
        // 要素を破棄
        for(std::size_t i=0; i<ttSize; ++i) {
            std::allocator_traits<T_alloc_e>::destroy(aE_state, &pT[i]);
        }

        // メモリを解放
        std::allocator_traits<T_alloc_e>::deallocate(aE_state, pT, ttSize);
    }
};

int main()
{
    MyVector<int, std::allocator<int>> v(3);
}
*/


template <class T, class T_alloc_e>
class MyVector{
    T* pT;
    std::size_t ttSize;
    T_alloc_e aE_state; // current state of T_alloc_e allocation.
    
public:
    MyVector(std::size_t size){
        ttSize = size;

        aE_state = T_alloc_e();

        // メモリを確保
        pT = aE_state.allocate(ttSize);

        // 要素を構築
        for(std::size_t i=0; i<ttSize; ++i) {
            aE_state.construct(&pT[i]);
        }
    }

    ~MyVector(){
        // 要素を破棄
        for(std::size_t i=0; i<ttSize; ++i) {
            aE_state.destroy(&pT[i]);
        }

        // メモリを解放
        aE_state.deallocate(pT, ttSize);
    }
};

int main()
{
    MyVector<int, std::allocator<int>> v(3);
}


