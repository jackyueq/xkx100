// difu2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW "ۺ���ظ�" NOR);
	set("long",BLU @LONG
������������궼����ͨ����ۺ���ǣ���ڤ�������ġ����ϲ�Զ
�����������Ĺ��Źأ������˹��Źأ�����Ҳ���ܻ�ͷ�ˡ�������Ӱ
Ӱ����������ȴ�����������������ʱ�й�������߶�������ȴ����
������һ�ж���������һ����������һ��С�꣬����û�йأ�ȴ�޷���
�Σ����Ե��Ե��������š�������һ����������ġ�
LONG NOR );
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"difu1",
		"west"  : __DIR__"inn1",
		"east"  : __DIR__"inn2",
	]));
	set("objects", ([
		__DIR__"npc/yeyou": 1,
		__DIR__"npc/riyou": 1,
	]) );

	setup();
	replace_program( ROOM );
}

