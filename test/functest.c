#include <ctest.h>
#include <functions.h>
#include <locale.h>

CTEST(equation_suite, crop_of_symbols)
{
	//Given
	char string[] = "...sad";
	
	//When
	char fstring[260];
	crop(string, fstring);

	//Then
	const int exp = fstring[0];
	const int real = 's';
	ASSERT_EQUAL(exp, real);

}

CTEST(equation_suite, crop_of_symbols_rus)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "äèä";
	
	//When
	char fstring[260];
	crop(string, fstring);
	const int exp = fstring[2];

	//Then
	const int real = 'ä';
	ASSERT_EQUAL(exp, real);

}

CTEST(strings_process, search_of_rus_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[] = "...ÿ÷ñìèð";
	char ch = 'ÿ';
	
	//When
	const int real = schr(string, ch);
	

	//Then
	const int exp = 3;

	ASSERT_EQUAL(real, exp);

}

CTEST(strings_process, search_of_rus_cap_word)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char string[8] = "ÀàààÀÀà";
	char ch = 'À';
	
	//When
	int real = schr(string, ch);
	

	//Then
	const int exp = 0;

	ASSERT_EQUAL(real, exp);

}

CTEST(string_process, search_of_eng_word)
{
	//Given
	char string[] = "twitter";
	char ch = 'w';
	
	//When
	int real = schr(string, ch);

	//Then
	const int exp = 1;
	ASSERT_EQUAL(real, exp);

}

CTEST(equation_suite, search_of_empty)
{
	
	//Given
	char string[] = "123456789";
	char ch = 'Z';
	
	//When
	int real = schr(string, ch);

	//Then
	const int exp = -1;

	ASSERT_EQUAL(real, exp);

}

CTEST(equation_suite, search_of_eng_word2)
{
	//Given
	char string[] = "TTT";
	char ch = 'T';
	
	//When
	int real = schr(string, ch);
	const int exp = 0;

	//Then
	ASSERT_EQUAL(real, exp);

}

CTEST(equation_suite, stok_multiple)
{
	//Given
	char string[]= "aaaay lmaaao";
	char *ptr[2];
	int size = stok(string, ptr);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];

	//When
	const int real_1 = tmp2[0];
	const int exp_1 = 'l';
	const int exp_2 = 'a';
	const int real_2 = tmp1[0];
	const int exp_size = 2;

	//Then
	ASSERT_EQUAL(exp_1, real_1);
	ASSERT_EQUAL(real_2, exp_2);
	ASSERT_EQUAL(exp_size, size);
}

CTEST(equation_suite, stok_single)
{
	//Given
	char string[]= "haallo";
	char *ptr[1];
	stok(string, ptr);
	char *tmp1 = ptr[0];

	//When
	const int real = tmp1[0];

	//Then
	const int expct = 'h';
	ASSERT_EQUAL(real, expct);
}

CTEST(equation_suite, sort_eng)
{
	//Given
	char *ptr[3];
	ptr[0]="b";
	ptr[1]="a";
	ptr[2]="c";
	sort(ptr, 3);
	char *tmp_a = ptr[0];
	char *tmp_b = ptr[1];
	char *tmp_c = ptr[2];

	//When
	const int real_a = tmp_a[0];
	const int real_b = tmp_b[0];
	const int real_c = tmp_c[0];


	//Then
	const int expct_a = 'a';
	const int expct_b = 'b';
	const int expct_c = 'c';

	ASSERT_EQUAL(expct_a, real_a);
	ASSERT_EQUAL(expct_b, real_b);
	ASSERT_EQUAL(expct_c, real_c);
}

CTEST(equation_suite, sort_rus)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char *ptr[4];
	ptr[0]="Á";
	ptr[1]="à";
	ptr[2]="Ä";
	ptr[3]="Ã";
	sort(ptr, 4);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];
	char *tmp3 = ptr[2];
	char *tmp4 = ptr[3];

	//When
	const int real_1 = tmp1[0];
	const int real_2 = tmp2[0];
	const int real_3 = tmp3[0];
	const int real_4 = tmp4[0];

	//Then
	const int expct_1 = 'à';
	const int expct_2 = 'Á';
	const int expct_3 = 'Ã';
	const int expct_4 = 'Ä';

	ASSERT_EQUAL(expct_1, real_1);
	ASSERT_EQUAL(expct_2, real_2);
	ASSERT_EQUAL(expct_3, real_3);
	ASSERT_EQUAL(expct_4, real_4);
}

CTEST(equation_suite, exchange_of_eng_words)
{
	//Given
	char *ptr[1];
	ptr[0]="lmao";
	ptr[1]="ay";
	exchange(ptr, 0);
	char *tmp1 = ptr[0];
	char *tmp2 = ptr[1];

	//When
	const int real_1 = tmp1[0];
	const int real_2 = tmp2[0];

	//Then
	const int expct_1 = 'a';
	const int expct_2 = 'l';
	ASSERT_EQUAL(expct_1, real_1);
	ASSERT_EQUAL(expct_2, real_2);

}

CTEST(equation_suite, exchange_of_rus_words)
{
	setlocale(LC_ALL, "Rus");
	//Given
	char *ptr[2];
	ptr[0]="áî";
	ptr[1]="ÿçü";
	ptr[2]="ø";

	//When
	exchange(ptr, 0);
	char *tmp1 = ptr[1];
	char *tmp = ptr[0];
	const int real = tmp[0];
	const int real_1 = tmp1[0];

	//Then
	const int expct_1 = 'á';
	const int expct = 'ÿ';

	ASSERT_EQUAL(real_1, expct_1);
	ASSERT_EQUAL(real, expct);
}