// Room: /d/chengdu/beijie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ���
�⡣�ϱ��Եúܷ������֡�������һ�������¥�󣬹��š������Ŷ�����
���������Ŷ�������һ�����ҡ��鵽Ϊֹ�����ֲ�������������������
����ӵ��ֱʡ�����������ζ�˱Ƕ��������㴹�����Ρ�
    ���Ϸ��и��续��С̶��
LONG	);
	set("exits", ([
		"east"      : __DIR__"chenmapo",
		"north"     : __DIR__"beijie",
		"south"     : __DIR__"beijie2",
		"southwest" : __DIR__"huanhuaxi2",
	]));
	set("outdoors", "chengdu");
	set("coor/x", -8050);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


