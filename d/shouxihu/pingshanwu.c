// Room: /yangzhou/pingshanwu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ƽɽ����");
	set("long",@LONG
������ƽɽ���롣�������ߣ��������²�����ͷ��ˮ������Ҳ����
���ˡ�����Ǭ¡����ѲҲȡ�˵����ɴ����ɽ��ʰ�׶��ϣ����þ�ʮ��
�����㵽���ɽ�з�Ĵ������ˡ�
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northup" : __DIR__"pailou",
		"south"   : __DIR__"changdi3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}