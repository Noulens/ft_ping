# This is a minimal set of ANSI/VT100 color codes
_END=$'\033[0m
_BOLD=$'\033[1m
_UNDER=$'\033[4m
_REV=$'\033[7m

# Colors
_GREY=$'\033[30m
_RED=$'\033[31m
_GREEN=$'\033[32m
_YELLOW=$'\033[33m
_BLUE=$'\033[34m
_PURPLE=$'\033[35m
_CYAN=$'\033[36m
_WHITE=$'\033[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\033[40m
_IRED=$'\033[41m
_IGREEN=$'\033[42m
_IYELLOW=$'\033[43m
_IBLUE=$'\033[44m
_IPURPLE=$'\033[45m
_ICYAN=$'\033[46m
_IWHITE=$'\033[47m

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_strlen.c\
				ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strncmp.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strnstr.c\
				ft_atoi.c\
				ft_atol.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_split.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c\
				ft_c.c\
				ft_s.c\
				ft_p.c\
				ft_di.c\
				ft_xupx.c\
				ft_uitoa.c\
				ft_printf.c\
				get_next_line_bonus.c\
				ft_free_split.c\
				ft_atoi_base.c\
				get_next_line_utils_bonus.c\
				ft_isspace.c\
				ft_fc.c\
				ft_fs.c\
				ft_fp.c\
				ft_fdi.c\
				ft_fxupx.c\
				ft_fprintf.c\
				ft_atof.c\
				ft_atod.c\
				ft_putfloat_fd.c\
				reverseEndianness.c\
				ft_ld.c\
				ft_ltoa.c\
				ft_lstsort.c


OBJS		=	${SRCS:.c=.o}

NAME		=	libft.a

HEADERS		=	libft.h

${NAME}	:	${HEADERS} ${OBJS}
	@echo "${_BOLD}${_PURPLE}Compiling library...${_END}"
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all 	: ${NAME}

clean	:
	rm -f ${OBJS}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	re fclean all clean
.SILENT :
