// yellow3.c ��Ȫ���

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU "��Ȫ·" NOR);
	set("long",BLU @LONG
�������Թ�˭���������ӹ�������һֱ�����е������࣬������
ʿ���ܱ���Ľ�֡���ǰ���������Ļ�Ȫ�������������ߣ�һ����ģ
ģ��������Ӱӿ���ţ����߲���һ��������֮����֪�ػ����ţ��ഺ
��פ������������ô�Ķ��ݣ��������ʱ��ȴ���Ƕ�ô������......
LONG NOR);
	set("exits", ([
		"north" : __DIR__"gate",
		"south" : __DIR__"yellow2",
	]) );
	set("objects",([
		__DIR__"npc/mengpo" : 1,
	]));
	set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south")
	{
		return notify_fail("һ���ն������������������....\nû�л�ͷ·�ˣ�\n");
	}
	else return 1;
}
