#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ϸ̨");
	set("long", @LONG
������Ϸ̨����Ȼ��ЩС�����Ǻܸɾ���һ��Ϸ�����ڱ��ݡ���һ
̤��Ϸ̨���鲻�Խ��ؾͳ��������
LONG );
	set("exits", ([
		"down"      : __DIR__"xiyuan",
	        "southdown" :__DIR__"houtai",
	]));
	set("objects", ([
		__DIR__"npc/xizi": 1,
	]));
	set("coor/x", -200);
	set("coor/y", 4060);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	if(dir=="down")
	{
		message_vision("\n$Nһ�����գ�һҾ��������ƽ�ɣ���̨��Ծ����˫��أ��\n��ȭ�����������̬������������Ȳɡ�\n", me);
		i= me->query("meili");
		if(i<20) 
		{
			i=i+10;
			me->set("meili",i);
			message_vision(HIC "\n$N������ֵ����ˡ�\n" NOR, me);
		}
	}
	this_player()->delete_temp("hastryup");
	return ::valid_leave(me, dir);
}
