project (h5_vtk_example)

find_package (VTK REQUIRED)
find_package (HDF5 REQUIRED)

add_executable (xgc_vis main.cpp)
target_link_libraries (xgc_vis ${HDF5_LIBRARIES} ${VTK_LIBRARIES})
