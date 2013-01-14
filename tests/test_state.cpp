#include <iostream>

#include "State.h"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

typedef boost::numeric::ublas::matrix<double> matrixD;
using namespace std;

int main(int argc, char** argv) {
  cout << endl << "Hello World!" << endl;

  // load some data
  matrixD data;
  LoadData("Synthetic_data.csv", data);
  int num_rows = data.size1();
  int num_cols = data.size2();
  //
  map<int, vector<double> > data_map = construct_data_map(data);

  // create the objects to test
  vector<int> global_row_indices = create_sequence(data.size1());
  vector<int> global_column_indices = create_sequence(data.size2());
  State s = State(data, global_row_indices, global_column_indices, 11);

  int num_views = s.get_num_views();
  cout << "s.num_views: " << num_views << endl;
  for(int view_idx=0; view_idx<num_views; view_idx++) {
    View &v = s.get_view(view_idx);
    cout << "view idx " << view_idx << ": ";
    v.print();
  }

  for(int view_idx=0; view_idx<num_views; view_idx++) {
    cout << "transitioning view: " << view_idx << endl;
    View &v = s.get_view(view_idx);
    vector<int> view_cols = get_indices_to_reorder(global_column_indices, v.global_to_local);
    MatrixD data_subset = extract_columns(data, view_cols);
    cout << "data_subset: " << data_subset << endl;
    map<int, vector<double> > data_subset_map = construct_data_map(data_subset);
    for(int i=0;i<4;i++) {
      cout << "transition #: " << i << endl;
      v.transition(data_subset_map);
    }
  }

  for(int view_idx=0; view_idx<num_views; view_idx++) {
    View &v = s.get_view(view_idx);
    cout << "view_idx " << view_idx << ": " << endl;
    v.print();
  }

  cout << endl << "Goodbye World!" << endl;
}