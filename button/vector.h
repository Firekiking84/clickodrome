#ifndef                 __VECTOR_H__
#define                 __VECTOR_H__

#include                <stdio.h>
#include                <stddef.h>
#include                <stdbool.h>
#include                <stdlib.h>

typedef struct          s_vector
{
    void                *data_array; // L’espace de stockage
    size_t              sizeof_data; // Taille d’un element
    size_t              array_capacity; // Capacité en element
    size_t              data_count; // Nombre d’éléments contenu
    bool                is_view; // Vaut faux
}                       t_vector;

// Génère un vector de initial_capacity element
// de elem_size octets. Ces elements sont « innocupés »
// mais sont d’orès et déjà réservé avec malloc
t_vector                *_efvector_new(size_t           elem_size,
                                       size_t           initial_capacity);

#define                 efvector_new(type, icap)                \
                        _efvector_new(sizeof(type), (icap))

// Vide le vector. Cela ne signifie pas libérer l’espace mémoire
// Renvoi le nombre d’éléments supprimés
size_t                  efvector_clear(t_vector         *vec);

// Détruit le vecteur. Renvoi le nombre d’éléments supprimés
// Ne supprime pas data_array si is_view est vrai.
size_t                  efvector_delete(t_vector        *vec);

void                    *efmemcpy(void                  *target,
                                  const void            *src,
                                  size_t                size_elem);

// Ajoute un élément à la fin du vecteur
// Renvoie la donnée copiée dans le vecteur
void                    *efvector_push(t_vector         *vec,
                                       const void       *data);

// Efface un élément à la fin du vecteur
void                    efvector_pop_back(t_vector      *vec);

// Efface un élément à la position donne du vecteur
void                    efvector_pop(t_vector		*vec,
				     size_t		index);

t_vector                *efvector_view(t_vector         *vec,
                                       size_t           start,
                                       size_t           len);

#define                 efvector_at(vector, position, type) \
  (position < vector->array_capacity ?			    \
   ((type*)vector->data_array)[position] : NULL)

#define                 efvector_funcptr_at(vector, position, type) \
  (position < vector->array_capacity ?				    \
   ((type)vector->data_array)[position] : NULL)

#endif//                __VECTOR_H__
