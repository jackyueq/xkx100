// Room: /d/chengdu/gongqiao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long",@LONG
�����ֵ���ʾ���츮֮�����ֶ��ؽ��еķ��԰���ε�С�ź�
���ݹ�ɶ��ĸ��Ϻӡ����µ���ˮ����ƼȾ�ɰ��˵Ĵ��̡�ż��һ��ֻ
���ۻ����������źӱߵ���ź�沨�����������Ϳ��Ե��ϴ���ˡ� 
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"      : __DIR__"nanjie",
		"northeast" : __DIR__"funanhe3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


