#include "criterion/criterion.h"
#include "cub3d.h"
#include "parse.h"

static char	*line;

void	setup_color_syntax(void)
{
}

void	teardown_color_syntax(void)
{
	free(line);
}

Test(color_syntax_check, when_valid_wants_1, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("       123,       743,    322");

	int		result = color_syntax_check(line);

	cr_assert(result == 1);
}

Test(color_syntax_check, when_4digits_first_pos_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("       1423,       743,    322");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_4digits_second_pos_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("       123,       7543,    322");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_4digits_third_pos_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("       123,       743,    35ß22");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_incomplete_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("       123");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_incomplete2_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("13,9,");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_complete_wants_1, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("13,9,9");

	int		result = color_syntax_check(line);

	cr_assert(result == 1);
}

Test(color_syntax_check, when_incomplete3_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup("13,,9");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_incomplete4_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup(" ,8,9");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_with_letter_wants_0, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup(" 3,8g,9");

	int		result = color_syntax_check(line);

	cr_assert(result == 0);
}

Test(color_syntax_check, when_ok_wants_1, setup_color_syntax, teardown_color_syntax)
{
	line = ft_strdup(" 66,   36, 24");

	int		result = color_syntax_check(line);

	cr_assert(result == 1);
}
