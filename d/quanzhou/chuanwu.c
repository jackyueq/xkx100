// Room: /d/quanzhou/chuanwu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������Ƽ���ȫ����õ��촬��ʦ�͹�����һ����ȥ���������깤
�ͼ����깤�ĸ�����;�����ִ�С��ľ������������ææµµ��һƬ��
æ����
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west" : __DIR__"portroad4",
	]));
	set("objects", ([
		__DIR__"npc/kuli" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6620);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
