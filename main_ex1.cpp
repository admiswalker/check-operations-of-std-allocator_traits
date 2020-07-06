#include <bits/stdc++.h>


int main(){
    // ref: https://cpprefjp.github.io/reference/memory/allocator.html

    auto alc = std::allocator<int>();

    // 10要素のint型が入る領域を確保
    int* pArr = alc.allocate(10);

    // 確保した領域の各要素を構築する(コンストラクタを呼び出す)
    for(std::size_t i=0; i<10; ++i){
        alc.construct(&pArr[i]);
    }
    
    std::iota(&pArr[0], &pArr[10], 0);
    std::for_each(&pArr[0], &pArr[10], [](int i){ std::cout << i << " "; });
    std::cout << std::endl;

    // 配列の各要素を破棄する(デストラクタを呼び出す)
    for(std::size_t i=0; i<10; ++i){ alc.destroy(&pArr[i]); }

    // 領域を解放する
    alc.deallocate(pArr, 10);

    return 0;
}


