/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrabarij <nrabarij@student.42antanana>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:13:16 by nrabarij          #+#    #+#             */
/*   Updated: 2024/06/01 12:12:16 by nrabarij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */
/* libc libraries ----------------------------------------------------------- */
/* ************************************************************************** */

# include <math.h>
# include <stdio.h>
# include <fcntl.h>

/* ************************************************************************** */
/* custom libraries --------------------------------------------------------- */
/* ************************************************************************** */

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

/* ************************************************************************** */
/* constant definitions ----------------------------------------------------- */
/* ************************************************************************** */

# ifndef FDF_WINDOW
#  define FDF_WINDOW
#  define F_BUFF 4096
#  define F_WIDTH 720
#  define F_HEIGHT 720
#  define F_TITLE "fdf - nrabarij"
# endif

# ifndef FDF_BASES
#  define FDF_BASES
#  define F_B10 "0123456789"
#  define F_B16 "0123456789ABCDEF"
# endif

# ifndef FDF_COLOR
#  define FDF_COLOR
#  define CRED "\e[31m"
#  define CRESET "\e[0m"
#  define CGREEN "\e[32m"
#  define CYELLOW "\e[33m"
#  define F_WHITE 0xFFFFFF
# endif

# ifndef FDF_MESSAGE
#  define FDF_MESSAGE
#  define F_SCMP ": map created"
#  define F_ER "\e[31mError\e[0m"
#  define F_ERMP ": cannot parse map"
#  define F_SC "\e[32mSuccess\e[0m"
#  define F_USE "\e[33mUsage\e[0m"
#  define F_NONAME ": empty filname"
#  define F_FORMAT ": wrong file format"
#  define F_SCOP ": file opened"
#  define F_SCRD ": data fetched"
#  define F_SCCL ": file closed"
# endif

/* ************************************************************************** */
/* structure definitions ---------------------------------------------------- */
/* ************************************************************************** */

typedef struct s_view
{
	double			ang;
	double			zoom;
	int				xof;
	int				yof;
	double			zof;
	double			x_a;
	double			y_a;
}					t_view;

typedef struct s_point
{
	struct s_point	*prv;
	double			ox;
	double			oy;
	double			oz;
	double			x;
	double			y;
	double			z;
	int				col;
	struct s_point	*nxt;
	struct s_point	*rgt;
	struct s_point	*dwn;
}					t_point;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*adr;
	int				bpp;
	int				len;
	int				end;
	int				mx;
	int				my;
	struct s_view	cam;
	struct s_point	*map;
}					t_fdf;

/* ************************************************************************** */
/* functions ---------------------------------------------------------------- */
/* ************************************************************************** */

///		@brief Create a new element and set [x, y, z, col] values.
///		@param str The string to itereate in parallel with fdf_atoi().
///		@param i The current index of iteration.
///		@param xval The x value to assign to the point.
///		@param yval The y value to assign to the point.
///		@return The pointer to the newly allocated point.
t_point	*fdf_new_point(char *str, int *i, int xval, int yval);

///		@brief Adds a new point to the list. If the current list is empty,
///		The new point becomes the first element of the list.
///		The previous pointer is set accordingly, but the next pointer of
///		the last element will always be set to NULL for easier management.
///		@param first The pointer to the first element of the list.
///		@param next The new element to add to the list. (add_back).
void	fdf_add_point(t_point **first, t_point *next);

///		@brief Free a list of points.
///		@param p The pointer to the first point of the list.
void	fdf_clr_point(t_point **p);

///		@brief Iterate through a string and return the atoi value.
///		@param s The string to iterate through.
///		@param i The pointer to the current index in the string.
///		@param b The base of the input string.
///		@param bs The base size of the input string (10 or 16).
///		@return The value of the string in type int.
int		fdf_atoi(char *s, int *i, char *b, int bs);

///		@brief Create a new list of points [x, y, z, col] values.
///		If the color is not specified, it is set to white: 0xFFFFFF.
///		@param d The data structure.
///		@param fd The file descriptor to read from.
///		@return The pointer to the new linked list.
t_point	*fdf_parse(t_fdf *d, int fd);

///		@brief Allocate memory to initialize the data structure.
///		@param fd The file descriptor previously returned by open().
///		@return A pointer to the allocated memory area.
t_fdf	*fdf_alloc(int fd);

///		@brief Free memory of the initialized data structure.
///		@param d The data structure.
void	fdf_free(t_fdf *d);

///		@brief Controls the mlx_hook() and mlx_key_hook() functions.
///		@param d The data structure to free if needed
///		@return Zero on success.
int		fdf_ctrl(t_fdf *d);

///		@brief Create the connection with mlx. Print error on failure.
///		@param d The data structure to initialize.
///		@param fd The file descriptor preivously returned by open().
///		@return A non-zero value on error.
int		fdf_init(t_fdf *d, int fd);

///		@brief Open a file.
///		@param file The path to the file to open.
///		@return The return value of the open function.
int		fdf_open(char *file);

///		@brief Read a file.
///		@param fd The file descriptor previously returned by open().
///		@return The content which has been read.
char	*fdf_read(int fd);

///		@brief Close a file.
///		@param fd The file descriptor previously returned by open().
///		@return The return value of the close function.
int		fdf_close(int fd);

///		@brief Prints a USAGE message on stderr.
///		@param void This function takes no parameter.
void	fdf_use(void);

///		@brief Create a connection between adjacent points.
///		@param d The data structure for fdf.
///		@param p The pointer to the first element of the list.
void	fdf_link(t_fdf *d, t_point *p);

///		@brief Draw each point of the map and draw the line which links them.
///		@param data The structure containing the map.
void	*fdf_draw(void *data);

///		@brief Create a color to make gradient
///		form a starting point to and ending point.
///		@param pos The index of the current gradient to create.
///		@param step The distance between start and end points.
///		@param st The color value of the starting point.
///		@param en The color value of the ending point.
///		@return The gradient value of the current index.
int		fdf_grad(int pos, int step, int st, int en);

///		@brief Write pixels on a temporary image. Then put it to window.
///		Destroy the old image properly to avoid leaks.
///		@param d The structure containing mlx and win pointers.
void	fdf_image(t_fdf *d);

///		@brief Function to control movement on the screen depending on key.
///		@param keysym The keysym which is pressed.
///		@param d The structure containing zoom and axis information.
///		@return A zero value on success.
int		fdf_key(int keysym, t_fdf *d);

///		@brief Function to print each pixel from a point to another.
///		@param d The data structure with camera and view data.
///		@param xy The set of information related to starting and ending point.
///		@param dst The address where the point will be written to.
///		@param p The pointer to the current starting point.
void	fdf_bresenham_line(t_fdf *d, double xy[6], char *dst, t_point *p);

///		@brief Function to print each pixel from a point to another.
///		@param d The data structure with camera and view data.
///		@param xy The set of information related to starting and ending point.
///		@param dst The address where the point will be written to.
///		@param p The pointer to the current starting point.
void	fdf_bresenham_column(t_fdf *d, double xy[6], char *dst, t_point *p);

#endif
