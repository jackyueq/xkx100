// Room: /d/wuyi/sangufeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "���÷�");
	set("long", @LONG
���÷�Ϊһ���Ϸ�����Ϊ������ҵķ�ԣ�״������վ�����ɹá�
ɽ����һ��̶��������̶����̶�����µ�Ȫˮ���ͽ�����Ȫ���ഫԶ��
�󺵣�����ɿݣ�������㽹�࣬�ٰ���������������š������ɹ�
�ڰ��ռ�������֮ʱ��ͦ��ʩ�������¸��ء�����λ��ŮҲ�����ٻ���
����ʯ��ɽ�������˼䡣
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"path5",
		"southdown" : __DIR__"path4",
		"southwest" : __DIR__"huanguyan",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	set("coor/x", 1400);
	set("coor/y", -4950);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

