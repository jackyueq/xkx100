// dadian.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR "���޴��" NOR);
 	set("long",HIW @LONG
������ۺ����۵Ĺ�������ܵظ������ۺ����ۣ�Ҳ������
��ۣ�������䴫˵�е����������߸ߵ����ڴ�����л����ı����ϣ�
������������˾������˾������˾�Ͳ��˾�Ĵ��й٣�����Э��������
�����ǵ���ǰ�ƶ��Ա�����������ֻ�ת�������Ǵ������������
�ࡣÿ����������������սս�����ġ�
LONG NOR 
	);
	set("no_fight", 1);
	set("exits", ([ 
		"south" : __DIR__"difu2",
		"east"  : __DIR__"tai",
	]));
	set("objects", ([
		__DIR__"npc/king": 1,
	        __DIR__"npc/shan": 1,
		__DIR__"npc/er"  : 1,
		__DIR__"npc/yinlu" :1,
		__DIR__"npc/chacha" :1,
	]) );

	setup();
	replace_program( ROOM );
}

