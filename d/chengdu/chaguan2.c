// Room: /d/chengdu/chaguan2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "��ݶ�¥");
	set("long", @LONG
������������˶��Ǹ���֮ʿ��˵�������������໥��̸�Ÿ�����
���ĵá��ƿ���������ĿԶ����ܽ�س��������˵ķ�⾡���۵ף�����
΢�磬���������������һ���ϵȵġ������䡱���գ����գ�
LONG );
	set("exits", ([
		"down" : __DIR__"chaguan",
	]));
	set("objects", ([
		__DIR__"obj/chair" : 3,
	]));
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


