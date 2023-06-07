import os
import shutil
import stat

os.system('bazel build //:compdb')

file_name = "compile_commands.json"
file_exists = os.path.exists(file_name)

if file_exists:
  os.chmod(file_name, stat.S_IRWXU|stat.S_IRWXG|stat.S_IRWXO)
  os.remove(os.path.abspath(file_name))

os.chdir("bazel-bin")
shutil.copy(file_name,"../"+file_name)