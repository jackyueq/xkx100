//HTQMEN.C

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ǻ�����Ķ��ţ��Ŷ�����������ĺ������ڣ����Ϲ������£�
�����̵���˭Ҳ�����㡣�ű�����̸���Ʊ߷����죬���ź������֡�
LONG );
	set("exits", ([
		"enter" : __DIR__"htqdating",
		"south" : __DIR__"tohtq7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 930);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}