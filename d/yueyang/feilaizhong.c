// Room: /d/yueyang/feilaizhong.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ԭΪ��ʤ���ڹ��ӣ���ô����ʱ�Դ˱�������ô�߾١��ȹ������
ƶ�������죬�ٸ���ƶ�������񰮴������Գ��������һ�ڴ��ӣ���ҹ
͵������ɽͷ�����Ӷ������죬����ǧ�����˵��ˣ���Ҫ���ӵ��ţ�
��ο�һꡣ
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"   : __DIR__"longsheshan",
		"southdown" : __DIR__"longxianjing",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1720);
	set("coor/y", 2310);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
