// Room: /d/heimuya/xiaoshe.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
����һ���ô����ɵ�С�ᡣһ���ţ����ŵ�һ��Ũ�ҵĻ��㣬��
�й���һ����Ůͼ�����������廨���棬������һ���ţ���������һ��
ĵ���Ľ����������ѵ�����˭�ҹ���Ĺ뷿��
LONG    );
	set("exits", ([
		"east" : __DIR__"neishi",
		"out"  : __DIR__"xiaohuayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4220);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}