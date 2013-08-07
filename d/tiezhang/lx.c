// Room: /d/tiezhang/lx.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��Ϫ");
	set("long", @LONG
������������һ��С����Ȼ�ش�ƫƧ��������������������Ȼ��
�ࡣ������һ�乩����Ϣ����С�͵ꡣ���Ϸ���ʮ�ﴦ�����Ǵ˴���
���ĺ�צɽ��
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"road1",
		"west"      : __DIR__"kedian",
		"northeast" : "/d/henshan/hsroad6",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2000);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}