// Room: /d/tiezhang/chufang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ư�ĳ������������һ����¯�����ռȥ��һ��ķ�
�䡣�������кܶ���ۣ���ͬʱ���ܶ��ֲˡ���λ���и�нƸ���ĳ���
��������æµ�š��������������Ÿ��ַ��˵���ζ���������˴������Ρ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([ 
		__DIR__"obj/hsnr" : 1,
		__DIR__"obj/ruzhu" : 1,
		__DIR__"obj/fan" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -2060);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}