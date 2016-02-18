FILE(REMOVE_RECURSE
  "CMakeFiles/testhello.dir/Hello.cpp.o"
  "testhello.pdb"
  "testhello.exe"
  "libtesthello.dll.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/testhello.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
