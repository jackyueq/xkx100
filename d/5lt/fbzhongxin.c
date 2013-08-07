// Room: /d/5lt/fbzhongxin.c

#include <ansi.h>
inherit ROOM;
string look_board();

void create()
{
	set("short", "���ŷ�������");
	set("long", @LONG
���������ŷ������ģ���������ͷ����̨�����źͼ����д��ᶼ��
�����һʱ�䷢����ȥ�ġ������������ģ�����CCTVǿ���ˣ������
ǽ����һ���ܴ�ĵ���ͨ����(board)����ͷ�������������µ����š�
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"west"     : __DIR__"dating",
	]));
	set("item_desc",([
		"board"		:	(: look_board :),
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}

string look_board()
{
	return
	"��������	"HIY"���ӹ�����:"NOR"			��������\n"
	"��������	����������,�ػ����Ů�ѡ�	��������\n"
	"��������	ҥ�ԣ���˵ĳ�������ˡ�		��������\n";
}