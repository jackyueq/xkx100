// Room: /d/quanzhou/daxixiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ͨͨ��һ��ʯ��С·���������棬Ҳ��������벻������
ʩ�Ž�������̨���Ϊ����ս��������ǳص���ʯ�˻��̳ɴ�·��
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"southroad1",
		"east" : __DIR__"jiangjunfu",
	]));
	set("coor/x", 1860);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
