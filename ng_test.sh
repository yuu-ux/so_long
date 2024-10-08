for file in ng_map/*
do
    printf "\033[31m%s\033[0m \n" "${file}"
    valgrind --leak-check=full ./so_long ${file}
    echo '\n'
done
