// Room: /d/quanzhou/enyuanxiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��Թ��");
	set("long", @LONG
�߽����У��͸е�һ����ɱ֮���������ܡ�����һ�����������顸
��Թ�������ĸ����֣���ϸһ��������ָ���̻����ɣ��������������
�µ���̨�ˡ�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"eastroad2",
	]));
	set("coor/x", 1870);
	set("coor/y", -6520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
