#include <cstdio>
#include <iostream>
#include <cstring>
#include "strlen.h"
void strstr_and_do(const char* str, auto (*strsearch)(const char*) -> size_t){
	const auto re = strsearch(str);
	if (0 == re){
		puts("�G���[�Ȃ񂾂�");
	}
	else{
		std::cout << re << "��������" << std::endl;
		printf("%d��������\n", re);
	}
}
int main(void){
	auto str = "arikitari_na_world!";

	printf("base_str : %s\n", str);

	puts("string.h��strstr�֐����Ăяo���܂�");
	strstr_and_do(str, strlen);
	puts("strstr.h��my_strstr�֐����Ăяo���܂�");
	strstr_and_do(str, my_strlen);
	return 0;
}
