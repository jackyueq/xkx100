// Room: /d/baituo/danfang.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
ŷ�����Ϊ�������������ڶ�ҩ��Ҳ����ʮ�־�ͨ���ⵤ������ǧ
��ҽҩ����ҩȫ�ð״�ƿ��װ�ţ����ϱ�ǩ�����ű���ط������ܵ�ҩ
���ϣ�����һĿ��Ȼ��ԽҲ������һ˿�־�֮�ġ�
LONG);
	set("exits", ([
	      "east" : __DIR__"tuitang",
	]));
	set("objects", ([
		__DIR__"obj/grass" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
	replace_program(ROOM);
}
