// Room: /qingcheng/zhuhezhuang.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "פ��ׯ");
	set("long", @LONG
פ��ׯ�ഫΪ������Ϣ����֮�������г�Ⱥ��������Ϣ������
���ּ䡣
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"south"    : __DIR__"tianran",
	]));
        set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -900);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}