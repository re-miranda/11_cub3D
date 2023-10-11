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
	int x = info.m_height;

	while (x--)
		free(result[x]);
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

Test(normalize_map, when_ascii_ss10000000000001_wants_int_2210000000000001, .init = setup, .fini = teardown) {
	info.map[0] = ft_strdup("  10000000000001");

	result = normalize_map(&info);

	cr_assert(result[0][0] == 2);
	cr_assert(result[0][1] == 2);
	cr_assert(result[0][2] == 1);
	cr_assert(result[0][3] == 0);
	cr_assert(result[0][4] == 0);
	cr_assert(result[0][5] == 0);
	cr_assert(result[0][6] == 0);
	cr_assert(result[0][7] == 0);
	cr_assert(result[0][8] == 0);
	cr_assert(result[0][9] == 0);
	cr_assert(result[0][10] == 0);
	cr_assert(result[0][11] == 0);
	cr_assert(result[0][12] == 0);
	cr_assert(result[0][13] == 0);
	cr_assert(result[0][14] == 0);
	cr_assert(result[0][15] == 1);
}

Test(normalize_map, new_small_when_ascii_ss10000000000001_wants_int_2210000000000001, .init = setup, .fini = teardown) {
	char	want[] = {2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	info.m_width = sizeof(want);
	info.map[0] = ft_strdup("  10000000000001");

	result = normalize_map(&info);

   cr_assert_arr_eq(result[0], want, sizeof(want));
}

Test(normalize_map, new_3_when_ascii_ss10000000000001_wants_int_2210000000000001) {
	t_map_info info_local;
	info_local.m_width = 16;
	info_local.m_height = 3;
	info_local.map = malloc(sizeof(char *) * info_local.m_height);
	info_local.map[0] = ft_strdup("  10000000000001");
	info_local.map[1] = ft_strdup("  11111111111111");
	info_local.map[2] = ft_strdup("1110000000000001");

	result = normalize_map(&info_local);

	char	want_0[] = {2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	char	want_1[] = {2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	char	want_2[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
   cr_assert_arr_eq(result[0], want_0, sizeof(want_0));
   cr_assert_arr_eq(result[1], want_1, sizeof(want_1));
   cr_assert_arr_eq(result[2], want_2, sizeof(want_2));
}

Test(normalize_map, new_5x4_when_ascii_ss10000000000001_wants_int_2210000000000001) {
	t_map_info info_local;
	info_local.m_width = 5;
	info_local.m_height = 4;
	info_local.map = malloc(sizeof(char *) * info_local.m_height);
	info_local.map[0] = ft_strdup("1");
	info_local.map[1] = ft_strdup(" 101");
	info_local.map[2] = ft_strdup(" 11");
	info_local.map[3] = ft_strdup("   ");

	result = normalize_map(&info_local);

	char	want_0[] = {1, 2, 2, 2, 2};
	char	want_1[] = {2, 1, 0, 1, 2};
	char	want_2[] = {2, 1, 1, 2, 2};
	char	want_3[] = {2, 2, 2, 2, 2};
	char	want_n3[] = {2, 1, 2, 2, 2};
   cr_assert_arr_eq(result[0], want_0, sizeof(want_0));
   cr_assert_arr_eq(result[1], want_1, sizeof(want_1));
   cr_assert_arr_eq(result[2], want_2, sizeof(want_2));
   cr_assert_arr_eq(result[3], want_3, sizeof(want_3));
   cr_assert_arr_neq(result[3], want_n3, sizeof(want_n3));
}
