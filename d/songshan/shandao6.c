// Room: /d/songshan/shandao6.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
��������ɽ����ɽ���ϣ����ɴ�أ�ɽ�����ʱ��Ʈ����Զ��ɽ
��Ȯ�ͼ��䣬�����ɷ�֮�С����������ɽ������Ժ��
LONG );
	set("exits", ([
		"northup"   : __DIR__"junjigate",
		"southdown" : __DIR__"chaotian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 840);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
