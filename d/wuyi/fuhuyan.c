// Room: /d/wuyi/fuhuyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ײ��ʯ���������������ķֽ�ʯ�������绢�׾ᣬʯ��
���������������ɳ�ʡ���ա����������֡��ഫ��ʱ�˴�Ⱥ��Ϊ����
��������������ʿ���������ս�Ⱥ������������ƿ��ס���һֻ�ƻ���
����ڶ����ɰ����ϣ�ƿ���������ڡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"yunwo",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

