// Room: /d/quanzhou/wangzhouting.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ĵ��ƻ�Ȼ���ʣ��������ʯ������������ͷ�������ʳơ���
ʯ����������ǰ̽�����ƺ�Ҳ�ڼ����½��������ʯ��һͤͻأ�����
����ʣ��ֳơ�����ͤ����ƾ��Զ����Ȫ��ȫ���������۵ס�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu4",
		"northdown" : __DIR__"ruixiangyan",
	]));
	set("coor/x", 1850);
	set("coor/y", -6440);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
