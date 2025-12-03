#include "searchable_bag.hpp"
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
  t->print();
  a->print();


  for (int i = 1; i < argc; i++) {
	  int val = atoi(argv[i]);
    std::cout << val <<" is in tree? => " << t->has(atoi(argv[i])) << std::endl;
    std::cout << val <<" is in array? => " << a->has(atoi(argv[i])) << std::endl;
    std::cout << val -1 << " is in tree? => " << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << val -1 << " is in array? => " << a->has(atoi(argv[i]) - 1) << std::endl;
  }

 // t->clear();
  //a->clear();

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  std::cout << "1 is in the bag => " << tmp.has(1) << std::endl;
	t->clear();
	a->clear();
  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));
	int v = atoi(argv[i]);
    std::cout 	<< "Search if " << v << " is in sa (must be 1) " 
				<< sa.has(atoi(argv[i])) << std::endl;
    std::cout 	<< "Search if " << v << " is in st (must be 1) " 
				<< st.has(atoi(argv[i])) << std::endl;
    sa.print();
    sa.get_bag().print();
    st.print();
    std::cout << std::endl;
  }
    sa.clear();
    sa.insert(
        (int[]){
            1,
            2,
            3,
            4,
        },
        4);
    sa.print();
    std::cout << std::endl;
    st.insert(
        (int[]){
            1,
            2,
            3,
            4,
			85,
			42,
			42,
        },
        7);
    st.print();
	sa.insert(666);
	sa.print();
  

  return 0;
}
