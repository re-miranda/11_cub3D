#include "criterion/criterion.h"
#include "cub3d.h"
#include "parse.h"
#define ASCII_ZERO_OFFSET 48

static		t_map_info info;
static int	result;

void setup_7(void)
{
	info.m_height = 7;
	info.m_width = 7;
	info.map = malloc(sizeof(char *) * info.m_height);
	info.map[0] = ft_strdup("1111111");
	info.map[1] = ft_strdup("1000001");
	info.map[2] = ft_strdup("1000001");
	info.map[3] = ft_strdup("1000001");
	info.map[4] = ft_strdup("1000001");
	info.map[5] = ft_strdup("1000001");
	info.map[6] = ft_strdup("1111111");

	int y;
	int x = info.m_height;
	while (x--)
	{
		y = info.m_width;
		while (y--)
			info.map[x][y] -= ASCII_ZERO_OFFSET;
	}
}

void	teardown_7(void)
{
	int x = info.m_height;

	if (info.map)
	{
		while (x--)
			free(info.map[x]);
		free(info.map);
	}
	info.map = NULL;
}

Test(assert_is_not_surrounded_by_wall, when_valid_map_wants_0, setup_7, teardown_7)
{
	result = assert_is_not_surrounded_by_wall(info);

	cr_assert(result == 0);
}

Test(assert_is_not_surrounded_by_wall, when_floor_is_first_char_wants_not_0, setup_7, teardown_7)
{
	info.map[0][0] = 0;

	result = assert_is_not_surrounded_by_wall(info);

	cr_assert(result != 0);
}

Test(assert_is_not_surrounded_by_wall, when_space_is_first_char_wants_0, setup_7, teardown_7)
{
	info.map[0][0] = 2;

	result = assert_is_not_surrounded_by_wall(info);

	cr_assert(result == 0);
}

Test(assert_is_not_surrounded_by_wall, when_floor_is_second_char_wants_not_0, setup_7, teardown_7)
{
	info.map[0][1] = 0;

	result = assert_is_not_surrounded_by_wall(info);

	cr_assert(result != 0);
}

Test(assert_is_not_surrounded_by_wall, when_space_is_second_char_wants_not_0, setup_7, teardown_7)
{
	info.map[0][1] = 2;

	result = assert_is_not_surrounded_by_wall(info);

	cr_assert(result != 0);
}

Test(assert_is_not_surrounded_by_wall, when_floor_is_third_char_wants_not_0, setup_7, teardown_7)
{
	info.map[0][2] = 0;

	result = assert_is_not_surrounded_by_wall(info);

	cr_assert(result != 0);
}

Test(assert_is_not_surrounded_by_wall, when_space_is_third_char_wants_not_0, setup_7, teardown_7)
{
	info.map[0][2] = 2;

	result = assert_is_not_surrounded_by_wall(info);

	cr_assert(result != 0);
}
