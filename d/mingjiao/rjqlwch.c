//RJQLWCH.C

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�߽������������䳡������������Щ��֡�����Ľ����ǲ�����
���໥�д裬���Ǵ��������ƵĻ��ߣ�ͬһ����ֵ�װ�ô򶷡�װ�ô�
���ƿ�ԭ�أ�ֻ�����ƺ��߱��ò���ĸ��ֱ�������������˿��������
�������֡�
LONG );
	set("exits", ([
		"north" : __DIR__"rjqyuan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 850);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}