// Room: /d/wuyi/tianyoupath.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
��������������ʯ���ϡ��������η����һ���Ȼ�Ĵ�ʯͷ������
�С�һ��ʯͷ����족��˵��������ʯ�������ڶ��͵�ʯ���ϣ��Ͽ���
�죬�����޵أ���ǰ���ǹ������ʯ�档̧ͷ����ǰһ���˵ĽŸ�����
����Ԩ���������䶯����Ⱥ�ų�һ�ߡ�
�ˡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"westup"   : __DIR__"tianyoufeng",
		"eastdown" : __DIR__"chadong",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -4970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

