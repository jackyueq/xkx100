// Room: /d/mingjiao/shanlu2.c
// Date: Java 97/04/9

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
��ǰ��Ȼ����һ��Ƭ���֡����ֳ��ü��ܣ�ʯ��ת���£�������
���˺��Ľ�Ƶ����롣���ڽ��£���������������һ��խС�Ļ���
С·�����������죬�������������ʧ��ãã�ֺ�֮�С�
LONG );
	set("exits", ([
		"eastdown" : __DIR__"shanlu1",
		"northup" : __DIR__"shanlu3",
		"west" : __DIR__"huangtulu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 800);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}