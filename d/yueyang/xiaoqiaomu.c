// Room: /d/yueyang/xiaoqiaomu.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "С��Ĺ");
	set("long", @LONG
С��Ĺλ������¥�����磬Ĺ��С���ڹ�С���񣬾�����һͳ־
���أ�����߹�����ǹ���Ů�����ɴ��ǣ�����С�ǹ���褣�������
�ڴˡ������ڣ�ݳ������ɷ��ң����������ˡ�
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"yueyanglou1",
	]));
	set("coor/x", -1440);
	set("coor/y", -2250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
