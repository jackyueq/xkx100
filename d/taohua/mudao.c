// Room: /d/taohua/mudao.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
    set("short", "Ĺ��");
    set("long",@LONG
����ͨ��Ĺ�ҵ�ͨ����ͨ��ʮ�ֿ�������������һ�Ŵ���ҹ��
�飬�յ�����Ĺ����ͬ���硣Ĺ����ͷ����Ĺ�ҡ�
LONG);
	set("exits", ([
		"up"   : __DIR__"tomb",
		"down" : __DIR__"mushi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 9010);
	set("coor/y", -3100);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
