// Room: /d/suzhou/jiangbian.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@long
�����������ܶ𽭡��ഫ���͵�ʱ��������һ�����ߣ����в��죬
����������������գ��������У��齭��������Ů��ʮ���꣬�ƽ���
������ҹ�����벨�С������գ�����֮ʬ���ڽ��棬������֮���ߣ���
����
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"tulu2",
		"south"     : __DIR__"caoebei",
	]));
	set("no_clean_up", 0);
	set("coor/x", 770);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
