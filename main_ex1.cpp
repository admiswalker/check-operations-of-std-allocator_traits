#include <bits/stdc++.h>


int main(){
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

    return 0;
}


