//ROOM: /d/yanziwu/linggong.c

inherit ROOM;

void create()
{
	set("short", "��̨");
	set("long",@LONG
�������Ľ�ݼ�����֮�����ıڿ��Ŵ��ڣ�������̫��������£�
ʱʱ������������ˮ�����ɫ�ͷ��㡣
LONG );
	set("exits", ([
		"west": __DIR__"qingyun",
	]));
	set("objects", ([
		"/d/shaolin/obj/mu-ren": 6,
	]));
	set("coor/x", 960);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}