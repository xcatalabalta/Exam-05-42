#include "searchable_bag.hpp"
#include <cstdlib>
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;
  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  std::cout << "The tree :\n";
  t->print();
  std::cout << "The array :\n";
  a->print();

  for (int i = 1; i < argc; i++) {
	int val = atoi(argv[i]);
	std::cout << "At tree we should get 1 => " << t->has(atoi(argv[i])) << std::endl;
    std::cout << "At array we should get 1 => " << a->has(atoi(argv[i])) << std::endl;
    std::cout << "At tree for " << val -1 << " we get => " << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << "At array we get => " << a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
//  a->clear();

  std::cout << "Casting\n";
  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  a->print();
  tmp.print();
  tmp.has(1);
  a->clear();
  std::cout << "NOTHING up?\n";
  {
	  std::cout << "New block testing casting\n";
	  for (int i = 1; i < argc; i++) 
	  {
		  //t->insert(atoi(argv[i]));
		  a->insert(atoi(argv[i]));
	  }
	  //t->print();
	  a->print();
	  const searchable_array_bag tmp_bis(static_cast<searchable_array_bag &>(*a));
	  tmp_bis.print();
	  std::cout << "1 is in tmp_bis (1 = true) "<< tmp_bis.has(1) << std::endl;
	  a->clear();
	  std::cout << "END OF New block testing casting\n";
  }

  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));
    //std::cout << "Should be 1 " << sa.has(atoi(argv[i])) << std::endl;
	std::cout << "Printing " << i << " values of sa (2 times) and st (once)\n"; 
	sa.print();   
	sa.get_bag().print();
    st.print();
    
	sa.clear();
    sa.insert(
        (int[]){
            1,
            2,
            3,
            4,
        },
        4);
    std::cout << std::endl;
  }
  std::cout << "Another testing (inserting odd nums from args after 1, 8, 7, 0)\n";
  sa.clear();
  st.clear();
  sa.insert((int[]){1, 8, 7, 0, 69}, 4);
  st.insert((int[]){1, 8, 7, 0, 69}, 4);
  int val;
  for (int i = 1; i < argc; ++i)
  {
	  val = atoi(argv[i]);
	  if (i % 2)
	  {
		  st.insert(val);
		  sa.insert(val);
	  }
  }
  std::cout << "The array :\n";
  sa.print();
  std::cout << "The tree :\n";
  st.print();
  // Added to the given main to avoid leaks
  delete static_cast<searchable_tree_bag*>(t);
  delete static_cast<searchable_array_bag*>(a);
  // End of the addition
  return 0;
}
