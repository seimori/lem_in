/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:52:35 by seimori           #+#    #+#             */
/*   Updated: 2020/03/05 23:12:55 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int             *initialize_rows(t_in *in, int *cols)
{
  int row;

  row = 0;
  while (row < in->room_count)
  {
    cols[row] = 0;
    row++;
  }
  return (cols);
}

int             **initialize_columns(t_in *in, int **matrix)
{
  int col;

  col = 0;
  while (col < in->room_count)
  {
    matrix[col] = (int*)ft_memalloc(sizeof(int) * in->room_count);
    matrix[col] = initialize_rows(in, matrix[col]);
    col++;
  }
  return (matrix);
}

int             **fill_matrix(t_in *in, int **matrix)
{
  while (in->tube)
  {
    matrix[in->tube->in][in->tube->out] = 1;
    matrix[in->tube->out][in->tube->in] = 1;
    in->tube = in->tube->next;
  }
  return (matrix);
}

int             **generate_matrix(t_in *in)
{
  int   **matrix;

  matrix = (int**)ft_memalloc(sizeof(int*) * in->room_count);
  matrix =initialize_columns(in, matrix);
  matrix = fill_matrix(in, matrix);
  return (matrix);
}