// Room: /d/quanzhou/alabo.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������լ��");
	set("long", @LONG
����Ȫ�����������ó��������ఢ�����������˵ؾ�ס��������
�ö���֮�γ�����۾ӵء�ԶԶ��ȥ��ɫ��Բ�μⶥͻأ�����Եø�
�����ۡ�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"northwest" : __DIR__"southroad2",
		"south"     : __DIR__"qingjingsi",
	]));
	set("objects", ([
		__DIR__"npc/alabo" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
