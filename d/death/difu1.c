// difu1.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW "ۺ���ظ�" NOR);
	set("long",BLU @LONG
����������һ����ɫ��¥֮ǰ����¥�Ͽ����������֣�ۺ���ǡ���
�ϲ�Զ����һ���ţ����Ϲ�Ӱ����������ȴ��������������������Ͼ�
�ǹ��Źأ�����һ�����˹��Źأ�����Ҳ���ܳ�ȥ�ˣ������߽���¥ֻ
��һƬ������ģ�ֻ��������ɫ�Ļ���������ֵ���˸������������
һ����
LONG NOR );
	set("no_fight", 1);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"difu2",
		"south" : __FILE__,
	]));
	set("objects", ([
		__DIR__"npc/niutou": 1,
		__DIR__"npc/mamian": 1,
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south")
	{
		return notify_fail("һ���ն������������������....\n"+
		"û�л�ͷ·��!\n");
	}
	else return 1;
}


