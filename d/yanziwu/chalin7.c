// Room: /d/yanziwu/chalin7.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�軨��");
	set("long", @LONG
���ڻ����е���ײײ�����Ƕ��У���֪�������ǳ��ڣ���ʱ������
��ֻ�ǲ軨�����˼���·�����ۼ�С·��һ������һ����Ҳ��֪��һ��
������·��Ҫ�ص�С��ͣ����ȴ�е�����ˣ����������룺�����ߵ�ˮ
����˵����
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"chalin7",
		"east"  : __DIR__"chalin7",
		"north" : __DIR__"dukou",
		"south" : __DIR__"chalin7",
	]));
	set("coor/x", 1200);
	set("coor/y", -1310);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "north")
		tell_object(me,HIY"��������˲軨�֡�\n"NOR);
        return ::valid_leave(me, dir);
}