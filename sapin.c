#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	my_print_char(int word, char c)
{
  int	a;
  a = 0;

  while (a < word)
    {
      write(1, &c , 1);
      a++;
    }
  return (0);
}

int	my_last_line(int size)
{
  int	stars_counter;
  int	stars;
  int	line_counter;
  int	line;
  int	level_counter;
  int	level;
  int   ret;
  int   size_last_line;
  
  stars_counter = 0;
  stars = 1;
  line_counter = 0;
  level_counter = 1; 
  line = level_counter + 3;
  level = size;
  ret = 0;
  size_last_line = 0;
  while (level_counter <= level)
    {
      line_counter = 1;
      while (line_counter <= line) 
	{
	  stars_counter = 0;
	  while (stars_counter < stars)
	    {
	      stars_counter++;
	    }
	  stars = stars + 2;
	  line_counter++;
	}	  
      if (level_counter %2 == 0)
	ret = level_counter;
      else
	ret = level_counter + 1;
      stars = (stars-2) - ret;
      line = line + 1;
      size_last_line = stars;
      level_counter++;
    }
  size_last_line = size_last_line + ret;
  return (size_last_line);
}


int	my_trunk(int size)
{
  int	level_counter;
  int	level;
  int	size_last_line;
  int	space;
  int	pipe;
  
  level = size;
  level_counter = 0;
  size_last_line = my_last_line(size);
  pipe = 1 + ((size / 2) * 2);
  if (level%2 == 0)
    space = ((size_last_line) - (level + 1)) / 2;
  else
    space = ((size_last_line - level) / 2);

  while (level_counter < level)
    {
      my_print_char(space, ' ');
      my_print_char(pipe, '|');
      if (level%2 == 0)
	pipe = level + 1;
      else
	pipe = level;
      write(1, "\n", 1);
      level_counter++;
    }
  return(0);
}


void	sapin(int size)
{
  int	stars;
  int	line_counter;
  int	level_counter;
  int	line;
  int	level;
  int	ret;
  int	size_last_line;
  int	space;

  stars = 1;
  line_counter = 0;
  level_counter = 1;
  line = level_counter + 3;
  level = size;
  ret = 0;
  size_last_line = my_last_line(size);
  space = ((size_last_line -1) /2);
  if (size <= 0)
    {
      return ;
    }
  while (level_counter <= level)
    {
      line_counter = 1;
      while (line_counter <= line)
  	{
	  my_print_char(space, ' ');	
	  my_print_char(stars, '*');
	  write(1, "\n", 1);
	  stars = stars + 2;
	  space = space - 1;
	  line_counter++;
  	}	  
      if (level_counter %2 == 0)
	ret = level_counter;
      else
	ret = level_counter + 1;
      level_counter++;
      space = (space + 1) + (ret / 2);
      stars = (stars - 2) - (ret);
      line = line + 1;
    }
  my_trunk(size);
}


int	main(int argc, char **argv)
{
  int	number;
  
  if(argc == 1)
     {
      printf("Error, please enter a number as parameter\n");
      return(-1);
    }
  
  number = atoi(argv[1]);
  sapin(number);
  return(0);
}
