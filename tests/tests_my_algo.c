/*
** EPITECH PROJECT, 2019
** tests
** File description:
** units tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_the_crypt, check_crypt)
{
    char *sentence = strdup("azeRty");
    char key = 2;

    cr_assert_str_eq("cbgTva", my_crypt_again(sentence, key));
    free(sentence);
}

Test(check_the_crt, check_cry)
{
    char *sentence = strdup("aAZzeRty\n");
    char key = 0;

    cr_assert_str_eq("aAZzeRty\n", my_crypt_again(sentence, key));
    free(sentence);
}

Test(check_open_file, error, .init = redirect_all_std)
{
    char *str = strdup("zae");
    int ret = open_file("toto", &str);

    cr_assert_stderr_eq_str("Error: impossible to open it\n");
    cr_assert_eq(84, ret);
}
