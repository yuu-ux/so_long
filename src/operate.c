#include "so_long.h"

//int    move_player(int keycode, t_map_info *map)
//{
//    if (keycode == 0) //a
//    {
//
//    }
//    else if (keycode == 2) //d
//    {
//
//    }
//    else if (keycode == 1) //s
//    {
//
//    }
//    else if (keycode == 13) //w
//    {
//
//    }
//    return 0;
//}

void    operation(t_map_info *map)
{
    (void)map;
//    mlx_hook(vars->win, 2, 1L<<0, move_player, vars);
// イベント関数にmap1つしか引数渡せないから新しくmapも含めた構造体を作る必要がある
// イベントを受け取る
//w, a, s, dで移動できるようにする
//Pを中心に、wであればPの上の要素とPを入れ替える。
//dであればPの右の要素とスワップする
//aであればPの左の要素とスワップする
//sであればPの下の要素とスワップする
//で条件として1じゃなければスワップする
//アイテムと入れ替えた場合はアイテムカウントを1つ減らす
//ゴールした場合もend_countをデクリメントして0になったらプログラムを終了させる

}
