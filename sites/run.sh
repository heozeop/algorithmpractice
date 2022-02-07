if [ $# -lt 1 ] ; then
  echo "$# is illegal number of parameters"
  echo "Usage: $0 [file name] [?extension] [?site name]"
  echo "ex) run.sh 11286, run.sh 11286 cpp, run.sh 11286 cpp boj"
  exit 1
fi

current_file=$1
current_extension=$2
current_site=$3
input_file=$4

# current_dir=${PWD}/${current_site}
current_dir="${current_site:=boj}"
target_file=${current_dir}/${current_file}.${current_extension:=cpp}
target_input=${current_dir}/${current_file}.txt

g++ -o ${current_dir}/${current_file}.out ${current_dir}/${current_file}.cpp

echo "\nstart input\n"

./${current_dir}/${current_file}.out < ${target_input}

echo "\nend input\n"
