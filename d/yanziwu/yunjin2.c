// Room: /d/yanziwu/yunjin2.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "�ƽ���¥");
	set("long", @LONG
�ƽ�¥�ϳ��踻����һ�����û���ǿ�ȸ����������һ��ľ����д
���ǣ�����Ҷ�Ʋ��ܣ��軨ѩ����������¥����ȥ������һ�ߣ��̲���
�죬�Ŀ�⡣��������ҡҷ��������ǰ��
LONG );
	set("exits", ([
		"down"     : __DIR__"yunjin1",
	]));
	set("objects", ([
		"/d/dali/obj/chahua12" :1,
	]));
	set("coor/x", 1230);
	set("coor/y", -1260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}