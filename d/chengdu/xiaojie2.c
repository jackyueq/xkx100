// Room: /d/chengdu/xiaojie2.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����ʯ���̳ɵ�С�֣�·��ǳ��ɾ��������߿�����һ����
�Ƶ�С�ݡ�������һ�������¥�󣬹��š������Ŷ��������������Ŷ�
������һ�����ҡ��鵽Ϊֹ�����ֲ������������������������ֱʡ���
��������ζ�˱Ƕ���,���㴹�����Ρ�
LONG	);
	set("outdoor","chengdu");
	set("exits", ([
		"west"      : __DIR__"gongqiao1",
		"southeast" : __DIR__"niangjiuwu",
		"northwest" : __DIR__"xiaojie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

