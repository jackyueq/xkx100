// Room: /d/tiezhang/hhyuan2.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"����"NOR);
	set("long", @LONG
ֻ�����������������ܰ�������١����ȡ���𡢺콶��������
��ʢ�����㻨��Ժǽ���ֹ��˼�ľ�����������������飬����ܰ��Ϯ�ˣ� 
�����԰��԰�����Ϸ��ż�����ź����ϡ����ˡ����ʹ��������϶���
һ�����ȣ������ǰ�����Ϣ�ĵط���
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"hhyuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2030);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}