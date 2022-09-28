#include <iostream>
#include <vtkUnstructuredGrid.h>
// #include <vtkXMLUnstructuredGridWrtier.h>
#include <vtkSmartPointer.h>
#include <hdf5.h>

int main(int argc, char **argv)
{
  vtkSmartPointer<vtkUnstructuredGrid> grid = vtkUnstructuredGrid::New();
  // grid->PrintSelf(std::cerr, vtkIndent(2));

  hid_t fid = H5Fopen(argv[1], H5F_ACC_RDONLY, H5P_DEFAULT);
  hid_t did = H5Dopen2(fid, argv[2], H5P_DEFAULT);
  hid_t sid = H5Dget_space(did);

  int ndims = H5Sget_simple_extent_ndims(sid);
  hsize_t dims[1];
  H5Sget_simple_extent_dims(sid, dims, NULL);

  std::vector<int> nextnode;
  nextnode.resize(dims[0]);
  H5Dread(did, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, &nextnode[0]);

  fprintf(stderr, "fid=%d, did=%d, ndims=%d, dim=%d\n", fid, did, ndims, dims[0]);
  // for (int i = 0; i < dims[0]; i ++) {
  //   fprintf(stderr, "i=%d, nextnode=%d\n", i, nextnode[i]);
  // }

  H5Dclose(did);
  H5Fclose(fid);

  return 0;
}
