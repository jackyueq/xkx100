// Room: /d/qilian/jiuquan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "��Ȫ");
	set("long", @LONG
�ഫ������Ǻ��󽫾���ȥ������¥��������֮�أ���������ƶ�
ʮƿ�������̶���������ʮȪ�ڣ������������������Ծ�Ȫ֮ˮ��ƣ�
���ɿڡ�
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"shalu2",
		"southwest" : __DIR__"loulan",
	]));
	set("coor/x", -20200);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}