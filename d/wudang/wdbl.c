//Room: wdbl.c �䵱����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","�䵱����");
	set("long",@LONG
�㴩����һƬï�ܵİ����У���ɭ���䣬��ʯ��ᾣ�����û�ˡ���
����ʱ���������������ķ�ľ���죬��ʱ�ؾ������Ӵ������߷��ܶ�
����
LONG);
	set("objects", ([
		__DIR__"npc/yetu" : 2,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"yuzhengong",
		"southup"  : __DIR__"haohanpo",
		"west"     : __DIR__"wdbl1",
		"east"     : __DIR__"wdbl2",
	]));
	set("coor/x", -2050);
	set("coor/y", -830);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
