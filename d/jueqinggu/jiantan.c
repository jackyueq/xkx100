// Room: /d/jueqinggu/jiantan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
ֻ��������ϡ����ϡ����ϡ����С����䣬�����������У�ʽ����
�࣬����ʮ֮�˾Ŷ��ǹŽ��������߳ߣ���̽����磬�е��������
�����е�ȴ�Ժ�����ˡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"sanqingxuan",
	]));
	set("no_clean_up", 0);
 	set("coor/x", -540);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

