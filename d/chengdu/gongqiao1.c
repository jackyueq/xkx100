// Room: /d/chengdu/gongqiao1.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long",@LONG
�����ֵ���ʾ���츮֮�����ֶ��ؽ��еķ��԰���ε�С�ź�
���ݹ�ɶ��ĸ��Ϻӡ����µ���ˮ����ƼȾ�ɰ��˵Ĵ��̡�ż��һ��ֻ
���ۻ����������źӱߵ���ź�沨�������������Ƿ���ͤ�� 
LONG
	);

	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"xiaojie2",
		"north" : __DIR__"fengyuting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


