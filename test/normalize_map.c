#include "criterion/criterion.h"
#include "cub3d.h"
#include "parse.h"

static t_map_info info;
static char **result;

void setup(void)
{
	info.m_height = 1;
	info.m_width = 1;
	info.map = malloc(sizeof(char *));
}

void teardown(void)
{
	free(result[0]);
	free(result);
}

Test(normalize_map, when_ascii_space_wants_int_2, .init = setup, .fini = teardown) {
	info.map[0] = ft_strdup(" ");

	result = normalize_map(&info);

	cr_assert(result[0][0] == 2);
}

Test(normalize_map, when_ascii_1_wants_int_1, .init = setup, .fini = teardown) {
	info.map[0] = ft_strdup("1");

	result = normalize_map(&info);

	cr_assert(result[0][0] == 1);
}

Test(normalize_map, when_ascii_0_wants_int_0, .init = setup, .fini = teardown) {
	info.map[0] = ft_strdup("0");

	result = normalize_map(&info);

	cr_assert(result[0][0] == 0);
}

Test(normalize_map, when_ascii_01space_wants_int_012, .init = setup, .fini = teardown) {
	info.map[0] = ft_strdup("01 ");

	result = normalize_map(&info);

	cr_assert(result[0][0] == 0);
	cr_assert(result[0][1] == 1);
	cr_assert(result[0][2] == 2);
}

Test(normalize_map, when_ascii_01space110_wants_int_012110, .init = setup, .fini = teardown) {
	info.map[0] = ft_strdup("01 110 ");

	result = normalize_map(&info);

	cr_assert(result[0][0] == 0);
	cr_assert(result[0][1] == 1);
	cr_assert(result[0][2] == 2);
	cr_assert(result[0][3] == 1);
	cr_assert(result[0][4] == 1);
	cr_assert(result[0][5] == 0);
}

// TO DO

// DONE
// ' ' -> [2]
// '1' -> [1]
// '0' -> [0]
// '01 ' -> [0, 1, 2]
// '01 110 ' -> [0, 1, 2, 1, 1, 0]