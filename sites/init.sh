if [ $# -lt 1 ] ; then
  echo "$# is illegal number of parameters"
  echo "Usage: $0 [file name] [?extension] [?site name]"
  echo "ex) initiate.sh 11286, initiate.sh 11286 cpp, runinitiate.sh 11286 cpp boj"
  exit 1
fi

current_file=$1
current_extension=$2
current_extension=${current_extension:=cpp}
current_site=$3
current_site=${current_site:=boj}

current_dir=${current_site}
target_file=${current_dir}/${current_file}.${current_extension}
target_input=${current_dir}/${current_file}.txt
template_file=templates/${current_extension}.${current_extension}

echo "copy ${template_file} to ${target_file}"
cp ${template_file} ${target_file}
touch ${target_input}
