// Room: /d/wuyi/jiesunfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������𽽺�����У������������п�������������ڶ�����������
�������ɼ����·�������ʯճ�϶��ɣ�����ҡҡ��׹̬֮������������
η�����ֳ�С�����������ޱȣ�����ֱ�ϣ���ͬ���񡣺������ۣ��·�
������ɣ�������վ���
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shaibuyan",
		"south" : __DIR__"yunwo",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
	]));
	set("coor/x", 1360);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

