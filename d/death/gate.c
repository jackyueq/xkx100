// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "���Ź�" NOR);
	set("long", HIW
"�������������������ڡ����Źء���������ǰ������һ���ߴ��\n"
"��ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n"
"�������ˡ�\n"NOR);
        set("no_fight", 1);
        set("exits", ([
		"north" : __DIR__"difu1",
		"south" : __DIR__"yellow3",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle" : 1,
	]) );
	setup();
}
void init()
{
	object me;
	me=this_player();
	if (!wizardp(me)) me->save();
	return;
}
 
