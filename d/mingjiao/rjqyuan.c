//RJQYUAN.C

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
���߽��������Ĵ�Ժ��ȴ����������Ӱϡ�裬�������������˵�
��������ȴ�����������̣��������ƺ��Ǵ���Զ�ĵ��´����ġ������ߣ�
��Ҫ������¥�ˡ�Ժ�����׿��������䳡����Լ����������������һ
��������������������᳡����
LONG );
	set("exits", ([
		"west" : __DIR__"rjqmenlou1",
		"north" : __DIR__"rjqdating",
		"south" : __DIR__"rjqlwch",
		"out": __DIR__"rjqmen",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}