// Room: /d/lingxiao/sroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
ɽ����᫣���������ѩɽ֮�ϣ�˷�������Ƹ��졣�������ߣ�
ɽ��Ҳ�������գ�����Ⱥɽ��ƬƬ���ף�����������֮�£������ƺ���
�����岼�ĵ��졣��ʱ��������ʱ�֣�������ȴ������Ũ�����ܰ�ãã
��һƬ��Ω���ޱ߷�ѩ���׷�����ӿ�������������
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"sroad2",
		"eastup"    : __DIR__"shiya",
	]));
	set("objects", ([
		__DIR__"npc/huyan" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8980);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

