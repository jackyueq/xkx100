// Room: /d/henshan/liangongfang.c
// Date: Sep.1 2001 by ahda

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ĵط����м���������ר�����µ����䣬��
�����ֱֳ������ڻ�����С����鶯�����紩������һ�㣬�㲻����
�����ۣ�����������ڵ��ϵ������Ͽ���������
LONG );
//      set("outdoors", "henshan");

	set("exits", ([
		"west" : __DIR__"liufudayuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -390);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

