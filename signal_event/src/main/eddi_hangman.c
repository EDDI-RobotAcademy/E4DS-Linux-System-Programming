#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#define BUDDY_PAGE_SIZE			4096
#define SLAB_CACHE_SIZE			64

#define ALPHABET_SIZE			26
#define ONE_BYTE			1

char hangman_string[SLAB_CACHE_SIZE];
char matching_char[ALPHABET_SIZE];
char *matching_string;

int chance = 7;
char format[SLAB_CACHE_SIZE] = "어떤 알파벳을 입력하시겠습니까 ? ";

void use_chance(int signo)
{
	chance--;

	// -1 = 0xffffffff -> not 0xffffffff == 0
	if (chance <= 0)
	{
		printf("\nGame Over!\n");
		exit(0);
	}
	else
	{
		printf("\n기회 1번을 사용하였으며 남은 기회는 %d 회입니다!\n", chance);
		write(1, format, strlen(format));
		alarm(3);
	}
}

void init_hangman_config(void)
{
	int i, len = strlen(hangman_string);

	matching_string = (char *)malloc(sizeof(char) * len);

	memset(matching_string, '*', len);
}

void set_hangman_string(void)
{
	int len;

	printf("행맨 게임에 사용할 영문자열을 입력하세요!\n");

	read(0, hangman_string, sizeof(hangman_string));
	len = strlen(hangman_string);

	hangman_string[len - 1] = '\0';
}

void clean_stdin(void)
{
	int c;

	do
	{
		c = getchar();
	}
	while (c != '\n' && c != EOF);
}

bool check_char(char ch)
{
	if (ch == '\0')
	{
		return false;
	}
	else if ((ch >= 65 && ch < 90) || (ch >= 97 && ch < 122))
	{
		int idx;

		if (ch >= 97 && ch < 122)
		{
			ch ^= 0x20;
		}

		idx = ch - 65;

		if (!matching_char[idx])
		{
			matching_char[ch - 65] = 1;
		}
		else
		{
			printf("중복되었습니다.\n");
		}
	}
	else
	{
		printf("올바른 알파벳을 입력하세요.\n");
	}

	return true;
}

void check_matching_string(char ch)
{
	int i, len, cnt = 0;

	bool check_flag = check_char(ch);

	if (check_flag)
	{
		len = strlen(hangman_string);

		for (i = 0; i < len; i++)
		{
			if (!strncmp(&hangman_string[i], &ch, ONE_BYTE))
			{
				matching_string[i] = ch;
				cnt++;
			}
		}

		if (!cnt)
		{
			printf("없는 글자로 남은 기회는 %d 회입니다.\n", --chance);
		}

		printf("\n매칭된 결과를 보여줍니다.\n");
		printf("%s\n", matching_string);
	}
}

void start_hangman(void)
{
	char ch = '\0';
	int len = strlen(hangman_string);

	init_hangman_config();

	for(;;)
	{
		//__asm__ __volatile__("": : :"memory");

		signal(SIGALRM, use_chance);
		alarm(3);

		write(1, format, strlen(format));
		read(0, &ch, ONE_BYTE);
		clean_stdin();

		alarm(0);

		check_matching_string(ch);

		if (!strncmp(hangman_string, matching_string, len))
		{
			printf("You Win\n");
			break;
		}

		if (chance <= 0)
		{
			printf("Game Over!\n");
			break;
		}
	}
}

int main(void)
{
	char buf[BUDDY_PAGE_SIZE];
	int ret;

	set_hangman_string();

	start_hangman();

	return 0;
}
