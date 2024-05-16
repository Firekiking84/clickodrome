#ifndef			__VECTOR_PTR_H__

#define			__VECTOR_PTR_H__
#include                <stdio.h>
#include                <stddef.h>
#include                <stdbool.h>
#include                <stdlib.h>

typedef struct		s_vector_ptr
{
  size_t		*data_array;
  size_t		array_capacity;
  size_t		data_count;
}			t_vector_ptr;

// Créer un nouveau vector de pointeur
t_vector_ptr		*efvector_ptr_new(size_t			initial_capacity);

// Créer un nouveau vector de pointeur à partir d'un vector existant
t_vector_ptr		*efvector_ptr_new_vector(t_vector_ptr const	*other);

// Supprime un vector de pointeur
void  			efvector_ptr_delete(t_vector_ptr		*vec);

// Vide un vector de pointeur de son contenu
void  			efvector_ptr_clear(t_vector_ptr			*vec);

// Ajoute un pointeur à la fin d'un vector de pointeur
int 			efvector_ptr_push(t_vector_ptr			*vec,
					  const void			*ptr);

// Efface un pointeur à la fin d'un vector de pointeur
void			efvector_ptr_pop_back(t_vector_ptr		*vec);

// Efface un pointeur à la position index d'un vector de pointeur
void			efvector_ptr_erase(t_vector_ptr			*vec,
					   size_t			index);

// Retourne le pointeur à l'index choisi
void			*efvector_ptr_get(t_vector_ptr const		*vec,
					  size_t			index);

// Change la taille du vector de pointer à la taille passé en paramètre
int			efvector_ptr_resize(t_vector_ptr		*vec,
					    size_t			new_size);

#endif	//		__VECTOR_PTR_H__
